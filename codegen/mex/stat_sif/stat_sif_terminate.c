/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif_terminate.c
 *
 * Code generation for function 'stat_sif_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "stat_sif_terminate.h"
#include "stat_sif_mexutil.h"
#include "_coder_stat_sif_mex.h"
#include "stat_sif_data.h"

/* Function Definitions */
void stat_sif_atexit(void)
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

void stat_sif_terminate(void)
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

/* End of code generation (stat_sif_terminate.c) */
