function varargout = MFSDA_GUI(varargin)
%figure1 MATLAB code file for figure1.fig
%      figure1, by itself, creates a new figure1 or raises the existing
%      singleton*.
%
%      H = figure1 returns the handle to a new figure1 or the handle to
%      the existing singleton*.
%
%      figure1('Property','Value',...) creates a new figure1 using the
%      given property value pairs. Unrecognized properties are passed via
%      varargin to MFSDA_GUI_OpeningFcn.  This calling syntax produces a
%      warning when there is an existing singleton*.
%
%      figure1('CALLBACK') and figure1('CALLBACK',hObject,...) call the
%      local function named CALLBACK in figure1.M with the given input
%      arguments.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help figure1

% Last Modified by GUIDE v2.5 29-Mar-2017 11:30:11
%%
% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @MFSDA_GUI_OpeningFcn, ...
    'gui_OutputFcn',  @MFSDA_GUI_OutputFcn, ...
    'gui_LayoutFcn',  [], ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

%% Ddd the paths of dataset and code - DO NOT EDIT
pathname=pwd;
addpath(genpath([pathname,'/data']));
addpath(genpath([pathname,'/functions']));


%%
% --- Executes just before figure1 is made visible.
function MFSDA_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   unrecognized PropertyName/PropertyValue pairs from the
%            command line (see VARARGIN)

clr=[0.84,0.84,0.84];
%set(gcf,'Color',clr);
%set(gcf, 'Units','characters');
set(handles.Run,'BackgroundColor',clr);
set(handles.CoordData,'BackgroundColor',clr);
set(handles.CovariateData,'BackgroundColor',clr);
set(handles.CovariateofInterest,'BackgroundColor',clr);
set(handles.CovariateType,'BackgroundColor',clr);
set(handles.ShapeData,'BackgroundColor',clr);
set(handles.FitYdesign,'BackgroundColor',clr);
set(handles.FitBetas,'BackgroundColor',clr);
set(handles.Gpvals,'BackgroundColor',clr);
set(handles.Lpvals,'BackgroundColor',clr);
set(handles.Output,'BackgroundColor',clr);
set(handles.Clear,'BackgroundColor',clr);

% Choose default command line output for figure1
handles.output = hObject;

set(hObject, 'Name','MFSDA for Windows (64-bit) V1.0');

im=imread('/logo/BIGS2-LOGO.png');
handles.h1 = image(im,'Parent',handles.axes1);
set(handles.axes1,'Visible','off')

% im=imread('BIGS2-LOGO2.png');
% handles.h2 = image(im,'Parent',handles.axes2);
% set(handles.axes1,'Visible','off')

% Update handles structure
guidata(hObject, handles);
% UIWAIT makes figure1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);

%%
% --- Outputs from this function are returned to the command line.
function varargout = MFSDA_GUI_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


%% callback functions in Block 1
%%
% --- Executes on button press in CoordData.
function CoordData_Callback(hObject, eventdata, handles)
% hObject    handle to CoordData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    CoordDataDir= uigetdir(' ','Select coordinate data folder');
    if CoordDataDir~=0
        set(handles.CoordData,'UserData',CoordDataDir);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of CoordData

%%
% --- Executes on button press in CovariateData.
function CovariateData_Callback(hObject, eventdata, handles)
% hObject    handle to CovariateData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    CovariateDataFn_str = uigetfile({'*.txt';'*.mat'},'Select data file');
    if CovariateDataFn_str~=0
        set(handles.CovariateData,'UserData',CovariateDataFn_str);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of CovariateData

%%
% --- Executes on button press in CovariateofInterest.
function CovariateofInterest_Callback(hObject, eventdata, handles)
% hObject    handle to CovariateData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    CovariateofInterestFn_str = uigetfile({'*.txt';'*.mat'},'Select data file');
    if CovariateofInterestFn_str~=0
        set(handles.CovariateofInterest,'UserData',CovariateofInterestFn_str);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of CovariateofInterest

%%
% --- Executes on button press in CovariateType.
function CovariateType_Callback(hObject, eventdata, handles)
% hObject    handle to CovariateData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    CovariateTypeFn_str = uigetfile({'*.txt';'*.mat'},'Select data file');
    if CovariateTypeFn_str~=0
        set(handles.CovariateType,'UserData',CovariateTypeFn_str);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of CovariateType

%%
% --- Executes on button press in ShapeData.
function ShapeData_Callback(hObject, eventdata, handles)
% hObject    handle to ShapeData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    ShapeDataDir= uigetdir(' ','Select shape data folder');
    if ShapeDataDir~=0
        set(handles.ShapeData,'UserData',ShapeDataDir);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of ShapeData

%% callback functions in Block 2
%%
% --- Executes on button press in Output.
function Output_Callback(hObject, eventdata, handles)
% hObject    handle to Output (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
button_state = get(hObject,'Value');
if button_state == get(hObject,'Max')
    OutputDir= uigetdir(' ','Select Output folder');
    if OutputDir~=0
        set(handles.Output,'UserData',OutputDir);
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of Output

%%
% --- Executes on button press in Run.
function Run_Callback(hObject, eventdata, handles)
% hObject    handle to Run (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clc
tic

%% read the surface shape data, sphere coordinate data, and design matrix for functional linear model
%%
fprintf('+++++++Read the surface shape data+++++++\n');
ShapeDataName= get(handles.ShapeData,'UserData');
if isempty(ShapeDataName)
    warndlg('Please select the shape data folder by pressing "Shape Data" button')
    return;
end
Ydesign = stat_read_vtk(ShapeDataName);    % n*L*d matrix
% Ydesign: the text file containing surface shape information of all vertices.
% Ydesign is a n x L x m matrix, here m=d
% n denotes the number of subjects
% L denotes the number of vertices
% d denotes the the dimension of the coordinates (2 or 3).
fprintf('The dimension of shape matrix is %i x %i x %i .\n',size(Ydesign));

%%
fprintf('+++++++Read the sphere coordinate data+++++++\n');
CoordDataName= get(handles.CoordData,'UserData');
if isempty(CoordDataName)
    warndlg('Please select the coordinate data folder by pressing "Coordinate Data" button')
    return;
end
Coord = squeeze(stat_read_vtk(CoordDataName));   % L*d matrix
% Coord: the text file containing coordinates of all vertices aligned on the sphere.
% Coord is a L x d matrix
% L denotes the number of vertices
% d denotes the the dimension of the coordinates (2 or 3).

%[azimuth,elevation] = cart2sph(Coord(:,1),Coord(:,2),Coord(:,3));
%azimuth0=unique(azimuth); elevation0=unique(elevation);
%azimuth0_sort=sort(azimuth0); elevation0_sort=sort(elevation0);
%xind=zeros(size(Coord,1),1); yind=zeros(size(Coord,1),1);
%for ll=1:size(Coord,1)
%    xind(ll)=find(azimuth0_sort==azimuth(ll));
%    yind(ll)=find(elevation0_sort==elevation(ll));
%end
%new_2D_img=zeros(length(azimuth0),length(elevation0));
%fprintf('The dimension of 2D image (Cartesian coordinates to spherical) is %i x %i.\n',size(new_2D_img));
%indd=sub2ind(size(new_2D_img),xind,yind);

%%
fprintf('+++++++Read the design matrix+++++++\n');
CovariatesName= get(handles.CovariateData,'UserData');
if isempty(CovariatesName)
    warndlg('Please select the Covariates file by pressing "Covariate Data" button')
    return;
end
if strcmp(CovariatesName(end-2:end),'mat')
    temp=load(CovariatesName);
    temp1=whos('-file',CovariatesName);
    design_data=temp.(temp1.name);
else
    design_data=load(CovariatesName);
end
% design_data: the text file containing covariates of interest. Please always include the intercept in the first column.
% design_data is a n x p matrix
% n denotes the number of subjects
% p denotes the number of all covariates.

%%
% read the covariates of interest
CovariateofInterestName= get(handles.CovariateofInterest,'UserData');
if isempty(CovariateofInterestName)
    warndlg('Please select the covariate of interest file by pressing "Covariate of Interest" button')
    return;
end
if strcmp(CovariateofInterestName(end-2:end),'mat')
    temp=load(CovariateofInterestName);
    temp1=whos('-file',CovariateofInterestName);
    n_Interest=temp.(temp1.name);
else
    n_Interest=load(CovariateofInterestName);
end

%%
% read the covariate type
CovariateTypeName= get(handles.CovariateType,'UserData');
if isempty(CovariateTypeName)
    warndlg('Please select the covariate type file by pressing "Covariate of Interest" button')
    return;
end
if strcmp(CovariateTypeName(end-2:end),'mat')
    temp=load(CovariateTypeName);
    temp1=whos('-file',CovariateTypeName);
    n_Con=temp.(temp1.name);
else
    n_Con=load(CovariateTypeName);
end

%%
fprintf('+++++++Read the output directory+++++++\n');
Output0= get(handles.Output,'UserData');
if isempty(Output0)
    warndlg('Please select the output folder by pressing "Output Directory" button')
    return;
end
Output=Output0{1,1};
fprintf('The output directory is %s .\n',Output);

%% 
fprintf('+++++++Construct the design matrix including (1) picking up covariates of interest and (2) normalization+++++++\n');
Xdesign = stat_read_x(design_data, n_Interest, n_Con);
fprintf('The dimension of design matrix is %i x %i .\n',size(Xdesign));

%% 
fprintf('+++++++Optimal bandwidth selection+++++++\n');
tic;
flag=stat_lpks_wob(Coord,Xdesign,Ydesign);
toc;

%% 
fprintf('+++++++Local polynomial kernel smoothing (order = 1) with preselected bandwidth+++++++\n');
tic;
[efitBetas,efitYdesign]=stat_lpks_wb1(Coord,Xdesign,Ydesign,flag);
toc;

%% 
fprintf('+++++++Kernel smoothing (order = 1) for smooth functions (eta)+++++++\n');
ResYdesign=Ydesign-efitYdesign;
tic;
[efitEtas,~,eSigEta]=stat_sif(Coord,ResYdesign);
toc;

%% 
fprintf('+++++++Hypothesis testing+++++++\n');
% hypothesis: beta_pj(d)=0 v.s. beta_pj(d)~=0 for all j and d

[~, p0]=size(Xdesign);     %   n  = sample size    p  = number of covariates
[L, ~]=size(Coord);    %   L = number of location of imaging measurement    d  = dimension of corrdinate
m=size(Ydesign,3);     %   m  = number of features

Lpvals=zeros(L,p0-1);
Lpvals_fdr=zeros(L,p0-1);
Gpvals=zeros(1,p0-1);
clu_pvals=cell(1,p0-1);
Lpval_area=cell(1,p0-1);
GG=500;   % number of bootstrap samples
thres=2;

for pp=2:p0 % go through all covariate
    
    %individual and global statistics calculation
    cdesign=zeros(1,p0);
    cdesign(pp)=1;
    [Gstat,Lstat] = stat_ht_wald(Xdesign,efitBetas,eSigEta,cdesign);
    Lpval=1-chi2cdf(Lstat,m);
    [~,~,Lpval_fdr]=stat_fdr(Lpval);
    indd_thres=-log10(Lpval)>=thres;
    if sum(indd_thres)<=10
        Lpval_area{1,pp-1}=[sum(indd_thres)];
    else
        Coord_thres=Coord(indd_thres,:);
        clust = zeros(size(Coord_thres,1),4);
        for i=1:4
            clust(:,i) = kmeans(Coord_thres,i,'emptyaction','singleton','replicate',5);
        end
        eva=evalclusters(Coord_thres,clust,'CalinskiHarabasz');
        label=clust(:,eva.OptimalK);
        areas=zeros(1,eva.OptimalK);
        for k=1:eva.OptimalK
            areas(k)=sum(label==k);
        end
        Lpval_area{1,pp-1}=areas;
    end
    Lpvals(:,pp-1)=Lpval;
    Lpvals_fdr(:,pp-1)=Lpval_fdr;
    
    % Generate random samples and calculate the corresponding statistics and pvalues
    [Gpval,clu_pval] = stat_bstrp_pvalue(Coord,Xdesign,Ydesign,cdesign,Gstat,flag,GG,thres,areas);
    Gpvals(1,pp-1)=Gpval;
    clu_pvals{1,pp-1}=clu_pval;
    
end

toc

%%
fprintf('+++++++Save all the results+++++++\n');
str=fullfile(Output,'efit.mat');
save(str,'efitYdesign','efitBetas','efitEtas')

str=fullfile(Output,'pvalues.mat');
save(str,'Gpvals','Lpvals_fdr','Lpval_area','clu_pvals')

fprintf('+++++++Your job is finished!!+++++++\n');

guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of Run

%%
% --- Executes on button press in FitYdesign.
function FitYdesign_Callback(hObject, eventdata, handles)
% hObject    handle to FitYdesign (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%%
% read the output directory
Output0= get(handles.Output,'UserData');
if isempty(Output0)
    warndlg('Please select the output folder by pressing "Output Directory" button')
    return;
end
Output=Output0{1,1};
%%
str=fullfile(Output,'efit.mat');
load(str);
[n,L,m]=size(efitYdesign);
y_label={'x-coordinate','y-coordinate','z-coordinate'};
for mm=1:m
    figure
    for ii=1:n
        plot(1:L,squeeze(efitYdesign(ii,:,mm)));hold on
    end
    hold off
    title(sprintf('Fitted shape response in %s',y_label{1,mm}))
    xlabel('Vertex index')
    ylabel(y_label{1,mm})
    savefig(sprintf('%s/fitted_y_%i.fig',Output,mm))
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of FitYdesign

%%
% --- Executes on button press in FitBetas.
function FitBetas_Callback(hObject, eventdata, handles)
% hObject    handle to FitBetas (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%%
% read the output directory
Output0= get(handles.Output,'UserData');
if isempty(Output0)
    warndlg('Please select the output folder by pressing "Output Directory" button')
    return;
end
Output=Output0{1,1};

CoordDataName= get(handles.CoordData,'UserData');
if isempty(CoordDataName)
    warndlg('Please select the coordinate data folder by pressing "Coordinate Data" button')
    return;
end
Coord = squeeze(stat_read_vtk(CoordDataName));   % L*d matrix

%%
str=fullfile(Output,'efit.mat');
load(str);
[p,L,m]=size(efitBetas);
y_label={'x-coordinate','y-coordinate','z-coordinate'};
for mm=1:m
    for ii=2:p
        figure
        scatter3(Coord(:,1),Coord(:,2),Coord(:,3),[],squeeze(efitBetas(ii,:,mm)));
        colorbar
        title(sprintf('Coefficients in %s for covariate %i',y_label{1,mm},ii))
        savefig(sprintf('%s/fitBeta_%i_%i.fig',Output,mm,ii))
    end
end
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of FitBetas

%%
% --- Executes on button press in Gpvals.
function Gpvals_Callback(hObject, eventdata, handles)
% hObject    handle to Gpvals (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%%
% read the output directory
Output0= get(handles.Output,'UserData');
if isempty(Output0)
    warndlg('Please select the output folder by pressing "Output Directory" button')
    return;
end
Output=Output0{1,1};

%%
str=fullfile(Output,'pvalues.mat');
load(str);
fprintf('The global p-values for all the covariates of interest are listed below:\n');
for ii=1:length(Gpvals)
fprintf('%d\n',Gpvals(ii));
end
fprintf('The global p-values of significant cluster for all the covariates of interest are listed below:\n');
for ii=1:length(clu_pvals)
    clu_pvals_ii=clu_pvals{1,ii};
    for jj=1:(length(clu_pvals_ii)-1)
        fprintf('%d\t',clu_pvals_ii(jj));
    end
    fprintf('%d\n',clu_pvals_ii(length(clu_pvals_ii)));
end

guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of Gpvals

%%
% --- Executes on button press in Lpvals.
function Lpvals_Callback(hObject, eventdata, handles)
% hObject    handle to Lpvals (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%%
% read the output directory
Output0= get(handles.Output,'UserData');
if isempty(Output0)
    warndlg('Please select the output folder by pressing "Output Directory" button')
    return;
end
Output=Output0{1,1};

CoordDataName= get(handles.CoordData,'UserData');
if isempty(CoordDataName)
    warndlg('Please select the coordinate data folder by pressing "Coordinate Data" button')
    return;
end
Coord = squeeze(stat_read_vtk(CoordDataName));   % L*d matrix

%%
str=fullfile(Output,'pvalues.mat');
load(str);
[L,p]=size(Lpvals_fdr);
for ii=1:p
    figure
    scatter3(Coord(:,1),Coord(:,2),Coord(:,3),[],-log10(Lpvals_fdr(:,ii)));
    colorbar
    title(sprintf('-log_{10} transformed local p values for covariate %i',ii))
    savefig(sprintf('%s/Lpvals_%i.fig',Output,ii))
end


guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of Gpvals

%%
% --- Executes on button press in Clear.
function Clear_Callback(hObject, eventdata, handles)
% hObject    handle to Clear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.CoordData,'UserData','');
set(handles.CovariateData,'UserData','');
set(handles.CovariateofInterest,'UserData','');
set(handles.CovariateType,'UserData','');
set(handles.ShapeData,'UserData','');
set(handles.FitYdesign,'UserData','');
set(handles.FitBetas,'UserData','');
set(handles.Gpvals,'UserData','');
set(handles.Lpvals,'UserData','');
set(handles.Output,'UserData','');
guidata(hObject,handles);
% Hint: get(hObject,'Value') returns toggle state of Clear
