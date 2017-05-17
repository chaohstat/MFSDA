/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif_mexutil.h
 *
 * Code generation for function 'stat_sif_mexutil'
 *
 */

#ifndef STAT_SIF_MEXUTIL_H
#define STAT_SIF_MEXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "stat_sif_types.h"

/* Function Declarations */
extern void emlrtFreeThreadStackData(const emlrtStack *sp);
extern emlrtCTX emlrtGetRootTLSGlobal(void);
extern stat_sifTLS *emlrtGetThreadStackData(void);
extern void emlrtInitThreadStackData(const emlrtStack *sp);
extern void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX
  aTLS, void *aData);

#endif

/* End of code generation (stat_sif_mexutil.h) */
