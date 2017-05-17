/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.h
 *
 * Code generation for function 'mldivide'
 *
 */

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

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
extern void mldivide(const emlrtStack *sp, const real_T A_data[], const int32_T
                     A_size[2], const emxArray_real_T *B, emxArray_real_T *Y);

#endif

/* End of code generation (mldivide.h) */
