function [Gpval,clu_pval,Gstatvec,a,b,d] = stat_bstrp_pvalue(Coord,Xdesign,Ydesign,cdesign,Gstat,flag,GG,thres,areas)
%
% stat_bstrp_pvalue is to implement Zhu's (2010) method of calculating p value using bootstrap generated sample
%
% Input:
%     Coord      - a L x d matrix of the coordinates of all vertices aligned on the sphere.
%     Xdesign    - a n x p0 normalized design matrix.
%     Ydesign    - a n x L x m matrix of surface shape data.
%     cdesign    - a 1 x p0 matrix for characterizing the r linear constriants among mp parameters
%     Gstat      - an over all test statitsics
%     flag       - index of optimal bandwidth choice
%     GG         - number of bootstrap
%     thres      - thresholding for clustering
%     areas      - aeras of all connected regions
% Output:
%     Gpval         - an over all p value
%     clu_pval      - p value for significant clustering
% Reference:
% Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. 
% doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533.
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Please run
%    [Gstat,Lstat] = stat_ht_stat(Xdesign,efitBetas,eSigEta,cdesign) 
% before you use stat_bstrp_pvalue
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% March, 2017 @ Chao Huang
% 

%%  under the null hypothesis

Xdesign0=Xdesign; Xdesign0(:,cdesign==1)=[];

% optimal bandwidth selection
flag1=stat_lpks_wob(Coord,Xdesign0,Ydesign);

% local polynomial kernel smoothing (order = 1) with preselected bandwidth
[~,H0efitYdesign]=stat_lpks_wb1(Coord,Xdesign0,Ydesign,flag1);

% kernel smoothing (order = 1) for smooth functions (eta)
ResYdesign=Ydesign-H0efitYdesign;
[H0efitEtas,H0ResEtas,H0eSigEta]=stat_sif(Coord,ResYdesign);


%% Bootstrap procedures

Gstatvec=zeros(1,GG);
SimLpval_area=zeros(1,GG);


for gii=1:GG
    
    SimYdesign=stat_grs(H0efitYdesign,H0efitEtas,H0ResEtas);
    
    SimefitBetas=stat_lpks_wb1(Coord,Xdesign,SimYdesign,flag);
    
    [SimGstat,SimLstat]=stat_ht_wald(Xdesign,SimefitBetas,H0eSigEta,cdesign);
    
    SimLpval=1-chi2cdf(SimLstat,size(SimYdesign,3));
    Simindd_thres=-log10(SimLpval)>=thres;
    if sum(Simindd_thres)<=10
        SimLpval_area(1,gii)=sum(Simindd_thres);
    else
        Coord_thres=Coord(Simindd_thres,:);
        clust = zeros(size(Coord_thres,1),4);
        for i=1:4
            clust(:,i) = kmeans(Coord_thres,i,'emptyaction','singleton','replicate',5);
        end
        eva=evalclusters( Coord_thres,clust,'CalinskiHarabasz');
        label=clust(:,eva.OptimalK);
        Sim_areas=zeros(1,eva.OptimalK);
        for k=1:eva.OptimalK
            Sim_areas(k)=sum(label==k);
        end
        SimLpval_area(1,gii)=max(Sim_areas);
    end
    Gstatvec(1,gii)=SimGstat;
    
end

k1=mean(Gstatvec);
k2=var(Gstatvec);
k3=mean((Gstatvec-k1).^3);
a=k3/(4*k2);
b=k1-2*k2^2/k3;
d=8*k2^3/k3^2;
Gpval=1-cdf('chi2',(Gstat-b)/a,d);

clu_pval=zeros(size(areas));
for jj=1:length(areas)
    clu_pval(jj)=sum(SimLpval_area>=areas(jj))/GG;
end


end