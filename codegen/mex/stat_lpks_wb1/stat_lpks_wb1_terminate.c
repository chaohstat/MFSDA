/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1_terminate.c
 *
 * Code generation for function 'stat_lpks_wb1_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "stat_lpks_wb1_terminate.h"
#include "stat_lpks_wb1_mexutil.h"
#include "_coder_stat_lpks_wb1_mex.h"
#include "stat_lpks_wb1_data.h"

/* Function Definitions */
void stat_lpks_wb1_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void stat_lpks_wb1_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtFreeThreadStackData(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (stat_lpks_wb1_terminate.c) */
