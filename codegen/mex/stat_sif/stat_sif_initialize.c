/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif_initialize.c
 *
 * Code generation for function 'stat_sif_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "stat_sif_initialize.h"
#include "stat_sif_mexutil.h"
#include "_coder_stat_sif_mex.h"
#include "stat_sif_data.h"

/* Function Definitions */
void stat_sif_initialize(void)
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

/* End of code generation (stat_sif_initialize.c) */
