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
#include "stat_lpks_wob.h"
#include "EpKernel.h"
#include "stat_lpks_wob_emxutil.h"
#include "power.h"
#include "abs.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 4,   /* lineNo */
  "EpKernel",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 6,   /* lineNo */
  "EpKernel",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m"/* pathName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  12,                                  /* colNo */
  "EpKernel",                          /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m"/* pName */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  4,                                   /* lineNo */
  1,                                   /* colNo */
  "X",                                 /* aName */
  "EpKernel",                          /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\EpKernel.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void EpKernel(const emlrtStack *sp, emxArray_real_T *X, real_T h,
              emxArray_real_T *K)
{
  emxArray_boolean_T *r1;
  emxArray_real_T *r2;
  int32_T i3;
  int32_T loop_ub;
  int32_T end;
  int32_T trueCount;
  emxArray_int32_T *r3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &r1, 2, &h_emlrtRTEI, true);
  emxInit_real_T1(sp, &r2, 2, &h_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  b_abs(&st, X, r2);
  i3 = r1->size[0] * r1->size[1];
  r1->size[0] = r2->size[0];
  r1->size[1] = r2->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r1, i3, (int32_T)sizeof(boolean_T),
                    &h_emlrtRTEI);
  loop_ub = r2->size[0] * r2->size[1];
  for (i3 = 0; i3 < loop_ub; i3++) {
    r1->data[i3] = (r2->data[i3] > 1.0);
  }

  emxFree_real_T(&r2);
  end = r1->size[0] * r1->size[1] - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (r1->data[loop_ub]) {
      trueCount++;
    }
  }

  emxInit_int32_T(sp, &r3, 1, &h_emlrtRTEI, true);
  i3 = r3->size[0];
  r3->size[0] = trueCount;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i3, (int32_T)sizeof(int32_T),
                    &h_emlrtRTEI);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (r1->data[loop_ub]) {
      r3->data[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }

  emxFree_boolean_T(&r1);
  end = X->size[0];
  trueCount = X->size[1];
  end *= trueCount;
  loop_ub = r3->size[0];
  for (i3 = 0; i3 < loop_ub; i3++) {
    trueCount = r3->data[i3];
    if (!((trueCount >= 1) && (trueCount <= end))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, end, &s_emlrtBCI, sp);
    }

    X->data[trueCount - 1] = 1.0;
  }

  emxFree_int32_T(&r3);
  st.site = &i_emlrtRSI;
  power(&st, X, K);
  i3 = K->size[0] * K->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)K, i3, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  trueCount = K->size[0];
  loop_ub = K->size[1];
  loop_ub *= trueCount;
  for (i3 = 0; i3 < loop_ub; i3++) {
    K->data[i3] = 1.0 - K->data[i3];
  }

  i3 = K->size[0] * K->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)K, i3, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  trueCount = K->size[0];
  loop_ub = K->size[1];
  loop_ub *= trueCount;
  for (i3 = 0; i3 < loop_ub; i3++) {
    K->data[i3] = 0.75 * K->data[i3] / h;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (EpKernel.c) */
