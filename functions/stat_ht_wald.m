function [Gstat,Lstat] = stat_ht_wald(Xdesign,efitBetas,eSigEta,cdesign) 
% 
% stat_ht_wald is to implement Zhu's (2010) method of calculating the test statitics and p value
% 
% hypothesis: beta_pj(d)=0 v.s. beta_pj(d)~=0 for all j and d
%
% Input:
%     Xdesign       - a n x p0 normalized design matrix.
%     efitBetas     - a p x L x m matrix of the estimated coefficients.
%     eSigEta       - a m x m x L x L matrix of the covariance of etas.
%     cdesign       - a 1 x p0 vector for characterizing the linear constriant among each p0 parameters.
% Output:
%     Lstat         - a L x 1 columan vector of test statistics for each vertex 
%     Gstat         - an over all test statitsics
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. 
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% Please run  
%    [efitEtas,ResEtas,eSigEta] = stat_sif(Coord,ResYdesign)
% before you use stat_ht_stat
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang
%    

[p, L, m]=size(efitBetas);

deltaBeta=zeros(m*p,L);

for mii=1:m
    deltaBeta((mii-1)*p+1:mii*p,:)=efitBetas(:,:,mii);        
end 

Cdesign=kron(eye(m),cdesign);  % m x (m*p0) matrix
dd=Cdesign*deltaBeta;
Omegax=1/(cdesign/(Xdesign'*Xdesign)*cdesign');
Lstat=zeros(L,1);
for L0ii=1:L
    inveSigEta=pinv(squeeze(eSigEta(:,:,L0ii,L0ii)));
    Lstat(L0ii)=dd(:,L0ii)'*inveSigEta*dd(:,L0ii);
end
Lstat=Omegax*Lstat;

Gstat=sum(Lstat)/L;

end