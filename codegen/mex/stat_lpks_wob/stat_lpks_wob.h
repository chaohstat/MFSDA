/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wob.h
 *
 * Code generation for function 'stat_lpks_wob'
 *
 */

#ifndef STAT_LPKS_WOB_H
#define STAT_LPKS_WOB_H

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
extern void stat_lpks_wob(stat_lpks_wobStackData *SD, const emlrtStack *sp,
  const emxArray_real_T *Coord, const emxArray_real_T *Xdesign, const
  emxArray_real_T *Ydesign, real_T flag_data[], int32_T flag_size[2], real_T
  GCVs_data[], int32_T GCVs_size[2]);

#endif

/* End of code generation (stat_lpks_wob.h) */
