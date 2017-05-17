/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * linspace.c
 *
 * Code generation for function 'linspace'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "linspace.h"

/* Function Definitions */
void linspace(real_T d2, real_T y[6])
{
  real_T delta1;
  int32_T k;
  y[5] = d2;
  y[0] = 1.0;
  delta1 = (d2 - 1.0) / 5.0;
  for (k = 0; k < 4; k++) {
    y[1 + k] = 1.0 + (1.0 + (real_T)k) * delta1;
  }
}

/* End of code generation (linspace.c) */
