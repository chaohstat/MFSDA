clc
clear all

% add the paths of dataset and code - DO NOT EDIT
pathname=pwd;
%addpath([pathname,'/data']);
addpath([pathname,'/functions']);

file_dir = 'C:/Users/Administrator/Desktop/SALT_STAT/data/testing_data/';
n_Interest = [1 1 1 1]';
n_Con = [0 1 1 0];
[Gpvals,Lpvals_fdr_log10,efitBetas,efitEtas,eSigEta] = stat_main(file_dir, n_Interest, n_Con);
