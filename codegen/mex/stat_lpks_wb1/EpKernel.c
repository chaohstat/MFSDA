/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EpKernel.c
 *
 * Code generation for function 'EpKernel'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "EpKernel.h"
#include "stat_lpks_wb1_emxutil.h"
#include "stat_lpks_wb1_mexutil.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 6,  /* lineNo */
  "EpKernel",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  12,                                  /* colNo */
  "EpKernel",                          /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m"/* pName */
};

/* Function Definitions */
void EpKernel(stat_lpks_wb1StackData *SD, const emlrtStack *sp, real_T X[1004004],
              real_T h, real_T K[1004004])
{
  int32_T trueCount;
  int32_T k;
  emxArray_int32_T *r0;
  boolean_T b0;
  int32_T i3;
  int32_T b_k;
  jmp_buf * volatile emlrtJBStack;
  stat_lpks_wb1TLS *stat_lpks_wb1TLSThread;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  stat_lpks_wb1TLSThread = emlrtGetThreadStackData();
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  trueCount = 0;
  for (k = 0; k < 1004004; k++) {
    b0 = (muDoubleScalarAbs(X[k]) > 1.0);
    if (b0) {
      trueCount++;
    }

    stat_lpks_wb1TLSThread->f0.bv0[k] = b0;
  }

  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  i3 = r0->size[0];
  r0->size[0] = trueCount;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i3, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  k = 0;
  for (trueCount = 0; trueCount < 1004004; trueCount++) {
    if (stat_lpks_wb1TLSThread->f0.bv0[trueCount]) {
      r0->data[k] = trueCount + 1;
      k++;
    }
  }

  k = r0->size[0];
  for (i3 = 0; i3 < k; i3++) {
    X[r0->data[i3] - 1] = 1.0;
  }

  emxFree_int32_T(&r0);
  st.site = &nb_emlrtRSI;
  b_st.site = &ob_emlrtRSI;
  memcpy(&SD->f0.y[0], &X[0], 1004004U * sizeof(real_T));
  emlrtEnterParallelRegion(&b_st, omp_in_parallel());
  emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 firstprivate(SD)

  for (b_k = 1; b_k < 1004005; b_k++) {
    K[b_k - 1] = muDoubleScalarPower(SD->f0.y[b_k - 1], 2.0);
  }

  emlrtPopJmpBuf(&b_st, &emlrtJBStack);
  emlrtExitParallelRegion(&b_st, omp_in_parallel());
  for (i3 = 0; i3 < 1004004; i3++) {
    K[i3] = 0.75 * (1.0 - K[i3]) / h;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (EpKernel.c) */
