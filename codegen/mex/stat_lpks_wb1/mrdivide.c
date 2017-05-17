/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide.c
 *
 * Code generation for function 'mrdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "mrdivide.h"
#include "warning.h"
#include "xgetrf.h"
#include "stat_lpks_wb1_data.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 1,  /* lineNo */
  "mrdivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 112,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 114,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Definitions */
void mrdivide(const emlrtStack *sp, real_T A[4], const real_T B[16])
{
  real_T b_A[16];
  int32_T ipiv[4];
  int32_T info;
  int32_T jAcol;
  int32_T k;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &m_emlrtRSI;
  memcpy(&b_A[0], &B[0], sizeof(real_T) << 4);
  c_st.site = &o_emlrtRSI;
  b_xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &n_emlrtRSI;
    if (!emlrtSetWarningFlag(&c_st)) {
      d_st.site = &hb_emlrtRSI;
      warning(&d_st);
    }
  }

  c_st.site = &qb_emlrtRSI;
  for (info = 0; info < 4; info++) {
    jAcol = info << 2;
    for (k = 1; k <= info; k++) {
      if (b_A[(k + jAcol) - 1] != 0.0) {
        A[info] -= b_A[(k + jAcol) - 1] * A[k - 1];
      }
    }

    A[info] *= 1.0 / b_A[info + jAcol];
  }

  c_st.site = &rb_emlrtRSI;
  for (info = 3; info >= 0; info += -1) {
    jAcol = info << 2;
    for (k = info + 1; k + 1 < 5; k++) {
      if (b_A[k + jAcol] != 0.0) {
        A[info] -= b_A[k + jAcol] * A[k];
      }
    }
  }

  for (info = 2; info >= 0; info += -1) {
    if (ipiv[info] != info + 1) {
      temp = A[info];
      A[info] = A[ipiv[info] - 1];
      A[ipiv[info] - 1] = temp;
    }
  }
}

/* End of code generation (mrdivide.c) */
