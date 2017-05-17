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
#include "stat_lpks_wob.h"
#include "power.h"
#include "stat_lpks_wob_emxutil.h"
#include "error.h"
#include "scalexpAlloc.h"

/* Variable Definitions */
static emlrtRSInfo m_emlrtRSI = { 49,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 58,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 61,  /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 73,  /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 132, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "power",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 17,/* lineNo */
  19,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc.m"/* pName */
};

/* Function Declarations */
static boolean_T fltpower_domain_error(void);

/* Function Definitions */
static boolean_T fltpower_domain_error(void)
{
  return false;
}

void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emxArray_real_T *x;
  int32_T n;
  int32_T loop_ub;
  int16_T iv5[2];
  int32_T k;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T1(sp, &x, 2, &j_emlrtRTEI, true);
  st.site = &m_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  n = x->size[0] * x->size[1];
  x->size[0] = a->size[0];
  x->size[1] = a->size[1];
  emxEnsureCapacity(&b_st, (emxArray__common *)x, n, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  loop_ub = a->size[0] * a->size[1];
  for (n = 0; n < loop_ub; n++) {
    x->data[n] = a->data[n];
  }

  c_st.site = &p_emlrtRSI;
  for (n = 0; n < 2; n++) {
    iv5[n] = (int16_T)a->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = iv5[0];
  y->size[1] = iv5[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  if (!dimagree(y, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &u_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  n = a->size[0] * a->size[1];
  c_st.site = &q_emlrtRSI;
  emlrtEnterParallelRegion(&b_st, omp_in_parallel());
  emlrtPushJmpBuf(&b_st, &emlrtJBStack);

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(b_st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (k = 1; k <= n; k++) {
    y->data[k - 1] = x->data[k - 1] * x->data[k - 1];
  }

  emlrtPopJmpBuf(&b_st, &emlrtJBStack);
  emlrtExitParallelRegion(&b_st, omp_in_parallel());
  emxFree_real_T(&x);
  if (fltpower_domain_error()) {
    b_st.site = &o_emlrtRSI;
    error(&b_st);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (power.c) */
