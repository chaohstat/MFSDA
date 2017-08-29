% Command line scripts for MFSDA 
% MFSDA (Multivariate Functional Shape Data Analysis)
% Copyright @ Chao Huang May 18, 2017

%% Set the home directory, data directory, and the output directory 
%%
home_dir = pwd;
data_dir = [home_dir,'/data'];
output_dir = [home_dir,'/result'];
addpath(genpath([home_dir,'/functions']));

%% Step1. read the surface shape data, sphere coordinate data, and design matrix for functional linear model
%%
fprintf('+++++++Read the surface shape data+++++++\n');
ShapeFolderName = sprintf('%s/Aligned_shapes', data_dir);
Ydesign = stat_read_vtk(ShapeFolderName);    % n*L*d matrix
% Ydesign: the text file containing surface shape information of all vertices.
% Ydesign is a n x L x m matrix, here m=d
% n denotes the number of subjects
% L denotes the number of vertices
% d denotes the the dimension of the coordinates (2 or 3).
fprintf('The dimension of shape matrix is %i x %i x %i .\n',size(Ydesign));

%%
fprintf('+++++++Read the sphere coordinate data+++++++\n');
CoordFolderName= sprintf('%s/Template', data_dir);
Coord = squeeze(stat_read_vtk(CoordFolderName));   % L*d matrix
% Coord: the text file containing coordinates of all vertices aligned on the sphere.
% Coord is a L x d matrix
% L denotes the number of vertices
% d denotes the the dimension of the coordinates (2 or 3).

%%
fprintf('+++++++Read the design matrix+++++++\n');
DemoName= sprintf('%s/covariate_data.txt', data_dir);
Demo_data=load(DemoName);
Demo_data(:,4:end)=[];
CovariatesName_1= sprintf('%s/tmp/covariate_pain.mat', data_dir);
temp=load(CovariatesName_1);
temp1=whos('-file',CovariatesName_1);
design_data_tp_1=temp.(temp1.name);
CovariatesName_2= sprintf('%s/tmp/covariate_saliva.mat', data_dir);
temp=load(CovariatesName_2);
temp1=whos('-file',CovariatesName_2);
design_data_tp_2=temp.(temp1.name);
CovariatesName_3= sprintf('%s/tmp/covariate_plasma.mat', data_dir);
temp=load(CovariatesName_3);
temp1=whos('-file',CovariatesName_3);
design_data_tp_3=temp.(temp1.name);
design_data=[Demo_data design_data_tp_1(:,1) design_data_tp_2(:,5) design_data_tp_3(:,[2 5])];
% design_data: the text file containing covariates of interest. Please always include the intercept in the first column.
% design_data is a n x p matrix
% n denotes the number of subjects
% p denotes the number of all covariates.

%%
% read the covariates of interest
n_Interest=ones(7,1); 

%%
% read the covariate type
n_Con=[0 1 0 0 1 1 1];

%%
fprintf('+++++++Construct the design matrix: including (1) picking up covariates of interest and (2) normalization+++++++\n');
Xdesign = stat_read_x(design_data, n_Interest, n_Con);
fprintf('The dimension of design matrix is %i x %i .\n',size(Xdesign));

%% Step 2. Statistical analysis: including (1) smoothing and (2) hypothesis testing
%% 
fprintf('+++++++Optimal bandwidth selection+++++++\n');
tic;
flag=stat_lpks_wob(Coord,Xdesign,Ydesign);
toc;

%% 
fprintf('+++++++Local polynomial kernel smoothing (order = 1) with preselected bandwidth+++++++\n');
tic;
[efitBetas,efitYdesign]=stat_lpks_wb1(Coord,Xdesign,Ydesign,flag);
toc;

%% 
fprintf('+++++++Kernel smoothing (order = 1) for smooth functions (eta)+++++++\n');
ResYdesign=Ydesign-efitYdesign;
tic;
[efitEtas,~,eSigEta]=stat_sif(Coord,ResYdesign);
toc;

%% 
fprintf('+++++++Hypothesis testing+++++++\n');
% hypothesis: beta_pj(d)=0 v.s. beta_pj(d)~=0 for all j and d
tic;
[~, p0]=size(Xdesign);     %   n  = sample size    p  = number of covariates
[L, ~]=size(Coord);    %   L = number of location of imaging measurement    d  = dimension of corrdinate
m=size(Ydesign,3);     %   m  = number of features

Lpvals=zeros(L,p0-1);
Lpvals_fdr=zeros(L,p0-1);
Gpvals=zeros(1,p0-1);
clu_pvals=cell(1,p0-1);
Lpval_area=cell(1,p0-1);
GG=500;   % number of bootstrap samples
thres=2;

for pp=2:p0 % go through all covariate
    
    %individual and global statistics calculation
    cdesign=zeros(1,p0);
    cdesign(pp)=1;
    [Gstat,Lstat] = stat_ht_wald(Xdesign,efitBetas,eSigEta,cdesign);
    Lpval=1-chi2cdf(Lstat,m);
    [~,~,Lpval_fdr]=stat_fdr(Lpval);
    indd_thres=-log10(Lpval)>=thres;
    if sum(indd_thres)<=10
        Lpval_area{1,pp-1}=sum(indd_thres);
    else
        Coord_thres=Coord(indd_thres,:);
        clust = zeros(size(Coord_thres,1),4);
        for i=1:4
            clust(:,i) = kmeans(Coord_thres,i,'emptyaction','singleton','replicate',5);
        end
        eva=evalclusters(Coord_thres,clust,'CalinskiHarabasz');
        label=clust(:,eva.OptimalK);
        areas=zeros(1,eva.OptimalK);
        for k=1:eva.OptimalK
            areas(k)=sum(label==k);
        end
        Lpval_area{1,pp-1}=areas;
    end
    Lpvals(:,pp-1)=Lpval;
    Lpvals_fdr(:,pp-1)=Lpval_fdr;
    
    % Generate random samples and calculate the corresponding statistics and pvalues
    [Gpval,clu_pval] = stat_bstrp_pvalue(Coord,Xdesign,Ydesign,cdesign,Gstat,flag,GG,thres,areas);
    Gpvals(1,pp-1)=Gpval;
    clu_pvals{1,pp-1}=clu_pval;
    
end
toc;

%% Step3. Save all the results
%% 
fprintf('+++++++Save all the results+++++++\n');
str=fullfile(output_dir,'efit.mat');
save(str,'efitYdesign','efitBetas','efitEtas')

str=fullfile(output_dir,'pvalues.mat');
save(str,'Gpvals','Lpvals_fdr','Lpval_area','clu_pvals')

fprintf('+++++++Your job is finished!!+++++++\n');

%% Step4. report the global p-values 
%%
str=fullfile(output_dir,'pvalues.mat');
load(str);
fprintf('The global p-values for all the covariates of interest are listed below:\n');
for ii=1:length(Gpvals)
fprintf('%d\n',Gpvals(ii));
end
fprintf('The global p-values of significant cluster for all the covariates of interest are listed below:\n');
for ii=1:length(clu_pvals)
    clu_pvals_ii=clu_pvals{1,ii};
    for jj=1:(length(clu_pvals_ii)-1)
        fprintf('%d\t',clu_pvals_ii(jj));
    end
    fprintf('%d\n',clu_pvals_ii(length(clu_pvals_ii)));
end

%% Step4. plot the coefficient curve estimates and -log_{10} transformed local p-values (optional)
%%
% fprintf('+++++++Plot the coefficient curve estimates over the surface+++++++\n');
% str=fullfile(output_dir,'efit.mat');
% load(str);
% [p,~,m]=size(efitBetas);
% y_label={'x-coordinate','y-coordinate','z-coordinate'};
% for mm=1:m
%     for ii=2:p
%         figure
%         scatter3(Coord(:,1),Coord(:,2),Coord(:,3),[],squeeze(efitBetas(ii,:,mm)));
%         colorbar
%         title(sprintf('Coefficients in %s for covariate %i',y_label{1,mm},ii))
%         savefig(sprintf('%s/fitBeta_%i_%i.fig',output_dir,mm,ii))
%     end
% end
% 
% %%
fprintf('+++++++Plot the -log_{10} transformed local p-values over the surface+++++++\n');
str=fullfile(output_dir,'pvalues.mat');
load(str);
Coord0FolderName= sprintf('%s/Template0', data_dir);
Coord0 = squeeze(stat_read_vtk(Coord0FolderName));   % L*d matrix
[L,p]=size(Lpvals_fdr);
for ii=1:p
    figure
    scatter3(Coord0(:,1),Coord0(:,2),Coord0(:,3),[],-log10(Lpvals_fdr(:,ii)));
    colorbar
    title(sprintf('-log_{10} transformed local p-values for covariate %i',ii))
    set(gca,'xgrid','off','ygrid','off','zgrid','off')
    savefig(sprintf('%s/Lpvals_%i.fig',output_dir,ii))
end
% 
% 



