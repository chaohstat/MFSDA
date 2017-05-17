function Xdesign = stat_read_x(design_data, n_Interest, n_Con)  

% stat_read_x is to read the design matrix for functional linear model
%   Can use first  2 or 3 arguments.
%
% Inputs:
%     design_data: 
%                 the text file containing covariates of interest. 
%                 design_data is a n x p matrix
%                 n denotes the number of subjects
%                 p denotes the number of all the covariates. 
%      n_Interest:  
%                 p0 x 1 vector indicating which covariates are of interest.
%           n_Con:  
%                 p0 x 1 vector indicating which covariates of interest are continuous.
% Output:
%     Xdesign    - a n x p0 normalized design matrix. 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
% October, 2016 @ C. Huang
%

%%  Set parameters and defaults according to number of input arguments
%
if nargin < 2 || nargin > 3    %  less than 3 argument inputs,  quit 
   exit(1); 
end;

if nargin == 2     %  3 arguments input, i.e., the number of continuous covariates is 0
  n_Con = zeros(sum(n_Interest),1);
end ;

%% Normalize the design matrix     
 
if size(design_data, 1)< size(design_data, 2) 
   design_data=design_data'; 
end
Xdesign=design_data(:,n_Interest==1); 

% normalization all the continuous covariates
Xdesign(:,n_Con==1)=normc(Xdesign(:,n_Con==1));

Xdesign=[ones(size(Xdesign,1),1) Xdesign];

