clc
clear all
%% Create a MEX configuration object
cfg = coder.config('mex');
% Turn on dynamic memory allocation
cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
%% Generate MEX function
% Generate mex files for stat_lpks_wob.m and stat_sif.m
% The settings of arguments should be configured according to n, L, d, p0, m
% Here n=40, L=1002, d=3, p0=5, m=3
codegen -config cfg stat_lpks_wob -args {zeros(1002,3), zeros(40,5), zeros(40,1002,3)}
codegen -config cfg stat_lpks_wb1 -args {zeros(1002,3), zeros(40,5), zeros(40,1002,3), zeros(1,3)}
codegen -config cfg stat_sif -args {zeros(1002,3), zeros(40,1002,3)}
disp('MEX generation complete!')