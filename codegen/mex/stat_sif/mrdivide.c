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
#include "stat_sif.h"
#include "mrdivide.h"
#include "warning.h"
#include "xgetrf.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 1,   /* lineNo */
  "mrdivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 42,  /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 102, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 100, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 112, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 114, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 76, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Definitions */
void mrdivide(const emlrtStack *sp, const real_T B[16], real_T y[4])
{
  real_T A[16];
  int32_T ipiv[4];
  int32_T info;
  static const int8_T b_B[4] = { 1, 0, 0, 0 };

  int32_T jAcol;
  int32_T k;
  real_T temp;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &q_emlrtRSI;
  memcpy(&A[0], &B[0], sizeof(real_T) << 4);
  c_st.site = &s_emlrtRSI;
  xgetrf(&c_st, A, ipiv, &info);
  if (info > 0) {
    c_st.site = &r_emlrtRSI;
    if (!emlrtSetWarningFlag(&c_st)) {
      d_st.site = &lb_emlrtRSI;
      warning(&d_st);
    }
  }

  c_st.site = &t_emlrtRSI;
  for (info = 0; info < 4; info++) {
    y[info] = b_B[info];
  }

  for (info = 0; info < 4; info++) {
    jAcol = info << 2;
    for (k = 1; k <= info; k++) {
      if (A[(k + jAcol) - 1] != 0.0) {
        y[info] -= A[(k + jAcol) - 1] * y[k - 1];
      }
    }

    y[info] *= 1.0 / A[info + jAcol];
  }

  c_st.site = &u_emlrtRSI;
  for (info = 3; info >= 0; info += -1) {
    jAcol = info << 2;
    for (k = info + 1; k + 1 < 5; k++) {
      if (A[k + jAcol] != 0.0) {
        y[info] -= A[k + jAcol] * y[k];
      }
    }
  }

  for (info = 2; info >= 0; info += -1) {
    if (ipiv[info] != info + 1) {
      temp = y[info];
      y[info] = y[ipiv[info] - 1];
      y[ipiv[info] - 1] = temp;
    }
  }
}

/* End of code generation (mrdivide.c) */
