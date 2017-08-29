function [efitBetas,efitYdesign] =stat_lpks_wb1(Coord,Xdesign,Ydesign,flag)
%#codegen
% stat_lpks_wb1 is to implement Zhu's (2010) method of local polynomial kernel smoothing (order = 1) with preselected bandwidth
%
% Input:
%     Coord      - a L x d matrix of the coordinates of all vertices aligned on the sphere.
%     Xdesign    - a n x p0 normalized design matrix.
%     Ydesign    - a n x L x m matrix of surface shape data.
%     flag       - a 1 x m vector of indice for optimal bandwidth.
% Output:
%     efitBetas    - a p0 x L x m matrix of estimated coefficients.
%     efitYdesign  - a n x L x m matrix of estimated shape measuments.
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. 
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Please run
%    [flag,GCVs,vh] = stat_lpks_wob(Coord,Xdesign,Ydesign)
% before you use stat_lpks_wb1
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang
%


%% SetUp
[n, p0]=size(Xdesign);     %   n  = sample size    p0  = number of covariates
[L,d]=size(Coord);    %   L = number of vertices     d  = dimension of corrdinate
m=size(Ydesign,3);     %   m  = number of shape features (here m=d)

efitBetas=zeros(p0,L,m);    % p0 x L x m matrix of estimated coefficients
efitYdesign=zeros(n,L,m);  % n x L x m matrix of estimated shape measuments

%% Optimal bandwidth
nh=50;      % the number of candidate bandwidth

Tmat0=zeros(L,L,d+1);    % L x L x d+1 matrix
Tmat0(:,:,1)=ones(L);

for dii=1:d   % go through all dimension
    Tmat0(:,:,dii+1)=Coord(:,dii)*ones(1,L)-ones(L,1)*Coord(:,dii)';
end

PX0=(Xdesign'*Xdesign+eye(size(Xdesign,2))*0.00001)\Xdesign';    %  'hat' matrix

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
    
    Tmat=permute(Tmat0,[1,3,2]);   % L0 x d+1 x L0 matrix
    
    for L0ii=1:L   % go through all vertex
        KX=Kmat(:,L0ii)*ones(1,(d+1)).*Tmat(:,:,L0ii);      % L0 x d+1 matrix
        efitBetas(:,L0ii,mii)=PX0*Ydesign(:,:,mii)*([1 zeros(1,d)]/(KX'*Tmat(:,:,L0ii)+eye(d+1)*0.0001)*KX')';
    end
    efitYdesign(:,:,mii)=Xdesign*efitBetas(:,:,mii);
end

end

