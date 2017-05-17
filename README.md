# MFSDA (Multivariate Functional Shape Data Analysis)

This MFSDA package is developed by Chao Huang and Hongtu Zhu from the [BIG-S2 lab](http://odin.mdacc.tmc.edu/bigs2/). 

Multivariate Functional Shape Data Analysis (MFSDA) is a Matlab based package for statistical shape analysis. A multivariate varying coefficient model is introduced to build the association between the multivariate shape measurements and demographic information and other clinical variables. Statistical inference, i.e., hypothesis testing, is also included in this package, which can be used in investigating whether some covariates of interest are significantly associated with the shape information. The hypothesis testing results are further used in clustering based analysis, i.e., significant suregion detection. 

# GUI Interface
This toolbox is written in a user-friendly GUI interface. Here are some explainations of the interface:

1. Load raw data

In this panel, you need to select (a). the folder where coordinate data (template file, vtk format) is stored; (b). the file containing the covariate matrix (could be either txt format or mat format); (c). the file indicating which covariates you are interested in the statistical analysis (could be either txt format or mat format); (d). the file indicating which covariates are continuous (1 is continuous and 0 otherwise, could be either txt format or mat format); (e). the folder where shape dataset (vtk format) is stored
