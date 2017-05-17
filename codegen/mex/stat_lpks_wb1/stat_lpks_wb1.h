/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1.h
 *
 * Code generation for function 'stat_lpks_wb1'
 *
 */

#ifndef STAT_LPKS_WB1_H
#define STAT_LPKS_WB1_H

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
extern void stat_lpks_wb1(stat_lpks_wb1StackData *SD, const emlrtStack *sp,
  const real_T Coord[3006], const real_T Xdesign[200], const real_T Ydesign
  [120240], const real_T flag[3], real_T efitBetas[15030], real_T efitYdesign
  [120240]);

#endif

/* End of code generation (stat_lpks_wb1.h) */
