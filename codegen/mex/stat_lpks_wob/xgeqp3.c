/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "xgeqp3.h"
#include "error.h"
#include "colon.h"
#include "stat_lpks_wob_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = { 14, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 37, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 38, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 45, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 64, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 67, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 76, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, real_T A_data[], int32_T A_size[2], real_T
            tau_data[], int32_T tau_size[1], int32_T jpvt_data[], int32_T
            jpvt_size[2])
{
  int32_T n;
  int32_T jpvt_t_size_idx_0;
  int32_T loop_ub;
  int32_T i10;
  ptrdiff_t jpvt_t_data[20];
  ptrdiff_t m_t;
  ptrdiff_t info_t;
  int32_T info;
  boolean_T p;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  n = A_size[1];
  b_st.site = &ic_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    tau_size[0] = 0;
    eml_signed_integer_colon(A_size[1], jpvt_data, jpvt_size);
  } else {
    tau_size[0] = muIntScalarMin_sint32(A_size[0], n);
    b_st.site = &kc_emlrtRSI;
    jpvt_t_size_idx_0 = A_size[1];
    loop_ub = A_size[1];
    for (i10 = 0; i10 < loop_ub; i10++) {
      jpvt_t_data[i10] = (ptrdiff_t)0;
    }

    b_st.site = &lc_emlrtRSI;
    m_t = (ptrdiff_t)A_size[0];
    b_st.site = &mc_emlrtRSI;
    info_t = LAPACKE_dgeqp3(102, m_t, (ptrdiff_t)A_size[1], &A_data[0], m_t,
      &jpvt_t_data[0], &tau_data[0]);
    info = (int32_T)info_t;
    b_st.site = &nc_emlrtRSI;
    if (info != 0) {
      p = true;
      b_p = false;
      if (info == -4) {
        b_p = true;
      }

      if (!b_p) {
        if (info == -1010) {
          c_st.site = &wb_emlrtRSI;
          b_error(&c_st);
        } else {
          c_st.site = &xb_emlrtRSI;
          d_error(&c_st, info);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      loop_ub = A_size[1];
      for (i10 = 0; i10 < loop_ub; i10++) {
        info = A_size[0];
        for (jpvt_t_size_idx_0 = 0; jpvt_t_size_idx_0 < info; jpvt_t_size_idx_0
             ++) {
          A_data[jpvt_t_size_idx_0 + A_size[0] * i10] = rtNaN;
        }
      }

      info = tau_size[0];
      for (i10 = 0; i10 < info; i10++) {
        tau_data[i10] = rtNaN;
      }

      eml_signed_integer_colon(n, jpvt_data, jpvt_size);
    } else {
      jpvt_size[0] = 1;
      jpvt_size[1] = jpvt_t_size_idx_0;
      for (i10 = 0; i10 < jpvt_t_size_idx_0; i10++) {
        jpvt_data[i10] = (int32_T)jpvt_t_data[i10];
      }
    }
  }
}

/* End of code generation (xgeqp3.c) */
