@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=stat_lpks_wob_mex
set MEX_NAME=stat_lpks_wob_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for stat_lpks_wob > stat_lpks_wob_mex.mki
echo COMPILER=%COMPILER%>> stat_lpks_wob_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> stat_lpks_wob_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> stat_lpks_wob_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> stat_lpks_wob_mex.mki
echo LINKER=%LINKER%>> stat_lpks_wob_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> stat_lpks_wob_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> stat_lpks_wob_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> stat_lpks_wob_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> stat_lpks_wob_mex.mki
echo BORLAND=%BORLAND%>> stat_lpks_wob_mex.mki
echo OMPFLAGS=/openmp >> stat_lpks_wob_mex.mki
echo OMPLINKFLAGS=/nodefaultlib:vcomp /LIBPATH:"C:\PROGRA~1\MATLAB\R2016b\bin\win64" >> stat_lpks_wob_mex.mki
echo EMC_COMPILER=msvc140>> stat_lpks_wob_mex.mki
echo EMC_CONFIG=optim>> stat_lpks_wob_mex.mki
"C:\Program Files\MATLAB\R2016b\bin\win64\gmake" -B -f stat_lpks_wob_mex.mk
