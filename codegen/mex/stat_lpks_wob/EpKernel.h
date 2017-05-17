/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EpKernel.h
 *
 * Code generation for function 'EpKernel'
 *
 */

#ifndef EPKERNEL_H
#define EPKERNEL_H

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
extern void EpKernel(const emlrtStack *sp, emxArray_real_T *X, real_T h,
                     emxArray_real_T *K);

#endif

/* End of code generation (EpKernel.h) */
