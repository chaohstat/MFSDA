function [Gpvals,Lpvals_fdr_log10,efitBetas,efitEtas,eSigEta] = stat_main(file_dir, n_Interest, n_Con)

% stat_main is the main function to run the MVCM package

% Inputs:
%        file_dir:
%                 the string indicating the directory where all vtk files are stored.
%      n_Interest:  
%                 p0 x 1 vector indicating which covariates are of interest.
%           n_Con:
%                 p x 1 vector indicating which covariates are continuous
% Output:
%     Gpvals            - a 1 x p0-1 vector : the global p values for covariates
%     Lstats_fdr_log10  - a L0 x p0-1 matrix of -log10(fdr corrected local p value) for each vertex
%     efitBetas         - a p0 x L x m matrix of estimated coefficients.
%     efitEtas          - a n x L0 x m matrix of estimated eta.
%     eSigEta           - a m x m x L0 x L0 matrix of covariance matrix of etas.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang


%% read the surface shape data, sphere coordinate data, and design matrix for functional linear model

Ydesign = stat_read_vtk(sprintf('%s/shape',file_dir));    % n*L*d matrix
% Ydesign: the text file containing surface shape information of all vertices.
% Ydesign is a n x L x m matrix, here m=d
% n denotes the number of subjects
% L denotes the number of vertices 
% d denotes the the dimension of the coordinates (2 or 3).

Coord = squeeze(stat_read_vtk(sprintf('%s/coordinate',file_dir)));   % L*d matrix
% Coord: the text file containing coordinates of all vertices aligned on the sphere.
% Coord is a L x d matrix
% L denotes the number of vertices 
% d denotes the the dimension of the coordinates (2 or 3).

design_data = load(sprintf('%s/covariate_data.txt',file_dir));   % n*p matrix
% design_data: the text file containing covariates of interest. Please always include the intercept in the first column.
% design_data is a n x p matrix
% n denotes the number of subjects
% p denotes the number of all covariates.

%% construct the design matrix including (1) picking up covariates of interest and (2) normalization 
Xdesign = stat_read_x(design_data, n_Interest, n_Con);


%% optimal bandwidth selection
tic;
flag=stat_lpks_wob_mex(Coord,Xdesign,Ydesign);
toc;

%% local polynomial kernel smoothing (order = 1) with preselected bandwidth
[efitBetas,efitYdesign]=stat_lpks_wb1(Coord,Xdesign,Ydesign,flag);

%% kernel smoothing (order = 1) for smooth functions (eta)
ResYdesign=Ydesign-efitYdesign;
tic;
[efitEtas,~,eSigEta]=stat_sif(Coord,ResYdesign);
toc;

%% functional PCA for smooth functions (eta)
%[mSigEtaEig, mSigEta]=MVCM_eigen(efitEtas);

%% Hypothesis testing
tic;
% hypothesis: beta_pj(d)=0 v.s. beta_pj(d)~=0 for all j and d

[~, p0]=size(Xdesign);     %   n  = sample size    p  = number of covariates
[L, ~]=size(Coord);    %   L0 = number of location of imaging measurement    d  = dimension of corrdinate
m=size(Ydesign,3);     %   m  = number of features

%Gstats=zeros(1,p0-1);
%Lstats=zeros(L,p0-1);
Lpvals=zeros(L,p0-1);
Lpvals_fdr=zeros(L,p0-1);
Lpvals_fdr_log10=zeros(L,p0-1);
Gpvals=zeros(1,p0-1);

GG=500;   % number of bootstrap samples

for pp=2:p0 % go through all covariate
    
    %individual and global statistics calculation
    cdesign=zeros(1,p0);
    cdesign(pp)=1;
    [Gstat,Lstat] = stat_ht_wald(Xdesign,efitBetas,eSigEta,cdesign);
    Lpval=1-chi2cdf(Lstat,m);
    [~,~,Lpval_fdr]=stat_fdr(Lpval);
    Lpval_fdr_log10=-log10(Lpval_fdr);
    % Gstats(1,pp-1)=Gstat;
    % Lstats(:,pp-1)=Lstat;
    Lpvals(:,pp-1)=Lpval;
    Lpvals_fdr(:,pp-1)=Lpval_fdr;
    Lpvals_fdr_log10(:,pp-1)=Lpval_fdr_log10;
    
    % Generate random samples and calculate the corresponding statistics and pvalues
    Gpval = stat_bstrp_pvalue(Coord,Xdesign,Ydesign,cdesign,Gstat,flag,GG);
    Gpvals(1,pp-1)=Gpval;
    
end
toc;

% %% confidence band
% GG=500;
% [Gvalue]=MVCM_cb_Gval(Coord,Xdesign,ResYdesign,InvSigmats,mh,GG);
% alpha=0.05;
% CBands=MVCM_CBands(NoSetup(1),alpha,Gvalue,efitBetas,ebiasBetas);

