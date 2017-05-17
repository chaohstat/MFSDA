/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef SUM_H
#define SUM_H

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
extern real_T b_sum(const emlrtStack *sp, const real_T x_data[], const int32_T
                    x_size[2]);

#ifdef __WATCOMC__

#pragma aux b_sum value [8087];

#endif

extern void sum(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
                int32_T y_size[2]);

#endif

/* End of code generation (sum.h) */
