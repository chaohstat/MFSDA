function [efitEtas,ResEtas,eSigEta] = stat_sif(Coord,ResYdesign)
%#codegen
% stat_sif is to implement Zhu's (2010) method of smoothing individual function without preselected bandwidth
%
% Input:
%     Coord       - a L x d matrix of the coordinates of all vertices aligned on the sphere.
%     ResYdesign  - a n x L x m matrix of difference between observed shape measurements and fitted measurements.
% Output:
%     efitEtas    - a n x L x m matrix of estimated eta.
%     ResEtas     - a n x L x m matrix of of difference between ResYdesign and fitted eta.
%     eSigEta     - a m x m x L x L matrix of covariance matrix of etas.
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. 
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Please run
%    [efitBetas,efitYdesign] =stat_lpks_wb1(Coord,Xdesign,Ydesign,flag)
% before you use stat_sif
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang
%

%% bandwidth SetUp

[n, L, m]=size(ResYdesign);
d=size(Coord,2);    %   L = number of vertices    d  = dimension of corrdinate

nh=50;      % the number of candidate bandwidth

GCVs=zeros(nh,m);      % GCV performance function
efitEtas=zeros(n,L,m);

%% GCV
Tmat0=zeros(L,L,d+1);    % L x L x d+1 matrix
Tmat0(:,:,1)=ones(L);

for dii=1:d   % go through all dimension
    Tmat0(:,:,dii+1)=Coord(:,dii)*ones(1,L)-ones(L,1)*Coord(:,dii)';
end

for nhii=1:nh   % go through all candidate bandwidth
    
    Kmat=ones(L);
    
    for dii=1:d   % go through all dimension
        Coordrange=range(Coord(:,dii));
        hmin=0.01;  % minimum bandwidth
        hmax=0.5*Coordrange;    % maximum bandwidth
        vh=logspace(log10(hmin),log10(hmax),nh);    % candidate bandwidth
        h=vh(nhii);
        Kmat=Kmat.*(real(EpKernel(Tmat0(:,:,dii+1)/h,h)));    % Epanechnikov kernel smoothing function
    end
    
    Tmat=permute(Tmat0,[1,3,2]);   % L0 x d+1 x L0 matrix
    
    for mii=1:m  % go through all features
        for L0ii=1:L   % go through all vertex
            KX=Kmat(:,L0ii)*ones(1,(d+1)).*Tmat(:,:,L0ii);      % L0 x d+1 matrix
            efitEtas(:,L0ii,mii)=ResYdesign(:,:,mii)*([1 zeros(1,d)]/(KX'*Tmat(:,:,L0ii)+eye(d+1)*0.0001)*KX')';
        end
        GCVs(nhii,mii)=sum(sum((ResYdesign(:,:,mii)-efitEtas(:,:,mii)).^2))/(n*L);
    end
    
end

[~,flag]=min(GCVs);   % optimal bandwidth
%mh=vh(flag);   % optimal bandwidth

%% estimate smooth function with optimal bandwidth


for mii=1:m  % go through all features
    
    Kmat=ones(L);
    
    
    for dii=1:d   % go through all dimension
        Coordrange=range(Coord(:,dii));
        hmin=0.01;  % minimum bandwidth
        hmax=0.5*Coordrange;    % maximum bandwidth
        vh=logspace(log10(hmin),log10(hmax),nh);    % candidate bandwidth
        h=vh(flag(mii));
        Kmat=Kmat.*(real(EpKernel(Tmat0(:,:,dii+1)/h,h)));    % Epanechnikov kernel smoothing function
    end
    
    Tmat=permute(Tmat0,[1,3,2]);   % L x d+1 x L matrix
    
    for L0ii=1:L   % go through all vertex
        KX=Kmat(:,L0ii)*ones(1,(d+1)).*Tmat(:,:,L0ii);      % L x d+1 matrix
        efitEtas(:,L0ii,mii)=ResYdesign(:,:,mii)*([1 zeros(1,d)]/(KX'*Tmat(:,:,L0ii)+eye(d+1)*0.0001)*KX')';
    end
end

ResEtas=ResYdesign-efitEtas;   % n x L x m matrix of of difference between ResYdesign and fitted eta


%% estimate the covariance matrix for each smooth function at each vertex

eSigEta=zeros(m,m,L,L);
for L0ii=1:L
    for L0jj=1:L
        eSigEta(:,:,L0ii,L0jj)=(squeeze(efitEtas(:,L0ii,:)))'*squeeze(efitEtas(:,L0jj,:))/n;
    end
end




end