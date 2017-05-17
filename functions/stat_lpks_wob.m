function [flag,GCVs] = stat_lpks_wob(Coord,Xdesign,Ydesign)
%#codegen
% stat_lpks_wob is to implement Zhu's (2010) method of local polynomial kernel smoothing (order = 1) for optimal bandwidth selection
%
% Input:
%     Coord      - a L x d matrix of the coordinates of all vertices aligned on the sphere.
%     Xdesign    - a n x p0 normalized design matrix.
%     Ydesign    - a n x L x m matrix of surface shape data.
% Output:
%     flag       - a 1 x m vector of indice for optimal bandwidth.
%     GCVs       - a nh x m matrix of GCVs.
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012.
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Please run
%    Ydesign = stat_read_vtk(file_dir)
%    Coord = stat_read_vtk(file_dir)
%    Xdesign = stat_read_x(design_data, n_Interest, n_Con)
% before you use stat_lpks_wob
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang
%

%% SetUp
n=size(Xdesign,1);     %   n  = sample size    p0  = number of covariates
[L,d]=size(Coord);    %   L = number of vertices     d  = dimension of corrdinate
m=size(Ydesign,3);     %   m  = number of shape features (here m=d)

efitYdesign=Ydesign*0;  % fitted Ydesign


%% bandwidth SetUp
nh=50;      % the number of candidate bandwidth
GCVs=zeros(nh,m);      % GCV performance function


%% GCV
Tmat0=zeros(L,L,d+1);    % L x L x d+1 matrix
Tmat0(:,:,1)=ones(L);

for dii=1:d   % go through all dimension
    Tmat0(:,:,dii+1)=Coord(:,dii)*ones(1,L)-ones(L,1)*Coord(:,dii)';
end

K = 5; % number of floders
ind=floor(linspace(1,n,K+1));


for nhii=1:nh   % go through all candidate bandwidth
    
    Kmat=ones(L);
    
    for dii=1:d   % go through all dimension
        Coord_range=range(Coord(:,dii));
        hmin=0.01;  % minimum bandwidth
        hmax=0.5*Coord_range;    % maximum bandwidth
        vh=logspace(log10(hmin),log10(hmax),nh);    % candidate bandwidth
        h=vh(nhii);
        Kmat=Kmat.*(real(EpKernel(Tmat0(:,:,dii+1)/h,h)));    % Epanechnikov kernel smoothing function
    end
    
    Tmat=permute(Tmat0,[1,3,2]);   % L x d+1 x L matrix
    
    for mii=1:m  % go through all features
            for Lii=1:L   % go through all vertex
                KX=Kmat(:,Lii)*ones(1,(d+1)).*Tmat(:,:,Lii);      % L0 x d+1 matrix
                indx=ones(1,n);
                for kk=1:K
                    indx(ind(kk):ind(kk+1))=0;
                    Xdesign0=Xdesign(indx==1,:);
                    PX0=(Xdesign0'*Xdesign0+eye(size(Xdesign0,2))*0.00001)\Xdesign0';
                    Ydesign0=Ydesign(indx==1,:,:);
                    efitBetas0=PX0*Ydesign0(:,:,mii)*([1 zeros(1,d)]/(KX'*Tmat(:,:,Lii)+eye(d+1)*0.00001)*KX')';
                    efitYdesign(ind(kk):ind(kk+1),Lii,mii)=Xdesign(ind(kk):ind(kk+1),:)*efitBetas0;
                end
            end
        GCVs(nhii,mii)=sum(sum((Ydesign(:,:,mii)-efitYdesign(:,:,mii)).^2))/(n*L);
    end

end

[~,flag]=min(GCVs);   % optimal bandwidth
%mh=vh(flag);   % optimal bandwidth

end

