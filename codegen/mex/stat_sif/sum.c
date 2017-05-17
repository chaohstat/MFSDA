/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "sum.h"

/* Function Definitions */
real_T b_sum(const real_T x[1002])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 1001; k++) {
    y += x[k + 1];
  }

  return y;
}

void sum(const real_T x[40080], real_T y[1002])
{
  int32_T i;
  int32_T xoffset;
  real_T s;
  int32_T k;
  for (i = 0; i < 1002; i++) {
    xoffset = i * 40;
    s = x[xoffset];
    for (k = 0; k < 39; k++) {
      s += x[(xoffset + k) + 1];
    }

    y[i] = s;
  }
}

/* End of code generation (sum.c) */
