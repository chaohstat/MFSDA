/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * squeeze.c
 *
 * Code generation for function 'squeeze'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "squeeze.h"

/* Function Definitions */
void squeeze(const real_T a[120], real_T b[120])
{
  memcpy(&b[0], &a[0], 120U * sizeof(real_T));
}

/* End of code generation (squeeze.c) */
