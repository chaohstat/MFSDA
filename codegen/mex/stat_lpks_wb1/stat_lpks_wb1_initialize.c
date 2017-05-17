/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1_initialize.c
 *
 * Code generation for function 'stat_lpks_wb1_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "stat_lpks_wb1_initialize.h"
#include "stat_lpks_wb1_mexutil.h"
#include "_coder_stat_lpks_wb1_mex.h"
#include "stat_lpks_wb1_data.h"

/* Function Definitions */
void stat_lpks_wb1_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
  emlrtInitThreadStackData(&st);
}

/* End of code generation (stat_lpks_wb1_initialize.c) */
