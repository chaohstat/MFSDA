function [SimYdesign] = stat_grs(efitYdesign,efitEtas,ResEtas)
% 
% stat_grs is to implement Zhu's (2010) method of generating samples
%
% Input:
%     efitYdesign  - a n x L x m matrix of estimated shape measurements.
%     efitEtas     - a n x L x m matrix of estimated etas.
%     ResEtas      - a n x L x m matrix of epsilons.  
% Output:
%     SimYdesign   - a n x L x m matrix for simulated shape data
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. 
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% March, 2017 @ Chao Huang
%            
[n, L, m]=size(ResEtas);
SimYdesign=zeros(n,L,m);

Temptaus=normrnd(0,1,n,L+1);
taus=Temptaus(:,1)*ones(1,L);
taumat=Temptaus(:,2:end);
for mii=1:m
    SimYdesign(:,:,mii)=efitYdesign(:,:,mii)+taus.*squeeze(efitEtas(:,:,mii))+taumat.*squeeze(ResEtas(:,:,mii));
 end
   
end 
 
 

 


  