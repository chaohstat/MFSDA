/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "power.h"
#include "stat_sif_data.h"

/* Function Definitions */
void power(stat_sifStackData *SD, const emlrtStack *sp, const real_T a[40080],
           real_T y[40080])
{
  int32_T k;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &h_emlrtRSI;
  memcpy(&SD->u1.f1.x[0], &a[0], 40080U * sizeof(real_T));
  emlrtEnterParallelRegion(&st, omp_in_parallel());
  emlrtPushJmpBuf(&st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 firstprivate(SD)

  for (k = 1; k < 40081; k++) {
    y[k - 1] = muDoubleScalarPower(SD->u1.f1.x[k - 1], 2.0);
  }

  emlrtPopJmpBuf(&st, &emlrtJBStack);
  emlrtExitParallelRegion(&st, omp_in_parallel());
}

/* End of code generation (power.c) */
