/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "abs.h"
#include "stat_lpks_wob_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 16,  /* lineNo */
  "abs",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "abs",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int16_T iv4[2];
  int32_T n;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  for (n = 0; n < 2; n++) {
    iv4[n] = (int16_T)x->size[n];
  }

  n = y->size[0] * y->size[1];
  y->size[0] = iv4[0];
  y->size[1] = iv4[1];
  emxEnsureCapacity(&st, (emxArray__common *)y, n, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  n = x->size[0] * x->size[1];
  for (k = 0; k + 1 <= n; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
