@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=stat_sif_mex
set MEX_NAME=stat_sif_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for stat_sif > stat_sif_mex.mki
echo COMPILER=%COMPILER%>> stat_sif_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> stat_sif_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> stat_sif_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> stat_sif_mex.mki
echo LINKER=%LINKER%>> stat_sif_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> stat_sif_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> stat_sif_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> stat_sif_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> stat_sif_mex.mki
echo BORLAND=%BORLAND%>> stat_sif_mex.mki
echo OMPFLAGS=/openmp >> stat_sif_mex.mki
echo OMPLINKFLAGS=/nodefaultlib:vcomp /LIBPATH:"C:\PROGRA~1\MATLAB\R2016b\bin\win64" >> stat_sif_mex.mki
echo EMC_COMPILER=msvc140>> stat_sif_mex.mki
echo EMC_CONFIG=optim>> stat_sif_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f stat_sif_mex.mk
