/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1_mexutil.h
 *
 * Code generation for function 'stat_lpks_wb1_mexutil'
 *
 */

#ifndef STAT_LPKS_WB1_MEXUTIL_H
#define STAT_LPKS_WB1_MEXUTIL_H

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
#include "stat_lpks_wb1_types.h"

/* Function Declarations */
extern void emlrtFreeThreadStackData(const emlrtStack *sp);
extern emlrtCTX emlrtGetRootTLSGlobal(void);
extern stat_lpks_wb1TLS *emlrtGetThreadStackData(void);
extern void emlrtInitThreadStackData(const emlrtStack *sp);
extern void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX
  aTLS, void *aData);

#endif

/* End of code generation (stat_lpks_wb1_mexutil.h) */
