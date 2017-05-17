/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qrsolve.h
 *
 * Code generation for function 'qrsolve'
 *
 */

#ifndef QRSOLVE_H
#define QRSOLVE_H

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
#include "stat_lpks_wob_types.h"

/* Function Declarations */
extern void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                      A_size[2], const real_T tau_data[], const int32_T
                      jpvt_data[], emxArray_real_T *B, int32_T rankA,
                      emxArray_real_T *Y);
extern void qrsolve(const emlrtStack *sp, const real_T A_data[], const int32_T
                    A_size[2], const real_T B_data[], const int32_T B_size[1],
                    real_T Y_data[], int32_T Y_size[1]);
extern int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const
  int32_T A_size[2]);

#endif

/* End of code generation (qrsolve.h) */
