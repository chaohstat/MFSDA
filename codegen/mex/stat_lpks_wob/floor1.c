/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * floor1.c
 *
 * Code generation for function 'floor1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "floor1.h"

/* Function Definitions */
void b_floor(real_T x[6])
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    x[k] = muDoubleScalarFloor(x[k]);
  }
}

/* End of code generation (floor1.c) */
