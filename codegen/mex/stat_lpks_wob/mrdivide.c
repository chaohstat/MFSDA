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
#include "stat_lpks_wob.h"
#include "mrdivide.h"
#include "warning.h"
#include "xgetrf.h"
#include "qrsolve.h"
#include "stat_lpks_wob_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo dd_emlrtRSI = { 1,  /* lineNo */
  "mrdivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 112,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 114,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRTEInfo x_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "mrdivide",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mrdivide.p"/* pName */
};

/* Function Definitions */
void mrdivide(const emlrtStack *sp, const real_T A_data[], const int32_T A_size
              [2], const real_T B_data[], const int32_T B_size[2], real_T
              y_data[], int32_T y_size[2])
{
  real_T b_B_data[25];
  int32_T b_B_size[2];
  int32_T loop_ub;
  int32_T i8;
  real_T b_A_data[5];
  int32_T b_loop_ub;
  int32_T b_A_size[1];
  int32_T i9;
  real_T c_A_data[400];
  int32_T ipiv_data[20];
  int32_T ipiv_size[2];
  real_T tmp_data[20];
  int32_T tmp_size[1];
  real_T temp;
  char_T DIAGA;
  char_T TRANSA;
  char_T UPLO;
  char_T SIDE;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (B_size[1] != A_size[1]) {
    emlrtErrorWithMessageIdR2012b(sp, &x_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  if (B_size[0] == B_size[1]) {
    st.site = &dd_emlrtRSI;
    b_st.site = &db_emlrtRSI;
    b_B_size[0] = B_size[0];
    b_B_size[1] = B_size[1];
    loop_ub = B_size[0] * B_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      c_A_data[i8] = B_data[i8];
    }

    c_st.site = &fb_emlrtRSI;
    xgetrf(&c_st, B_size[1], B_size[1], c_A_data, b_B_size, B_size[1], ipiv_data,
           ipiv_size, &b_loop_ub);
    loop_ub = b_B_size[0] * b_B_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_B_data[i8] = c_A_data[i8];
    }

    if (b_loop_ub > 0) {
      c_st.site = &eb_emlrtRSI;
      if (!emlrtSetWarningFlag(&c_st)) {
        d_st.site = &yb_emlrtRSI;
        warning(&d_st);
      }
    }

    c_st.site = &ed_emlrtRSI;
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'R';
    loop_ub = A_size[0] * A_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_A_data[i8] = A_data[i8];
    }

    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)B_size[1];
    lda_t = (ptrdiff_t)B_size[1];
    ldb_t = (ptrdiff_t)1;
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_B_data[0], &lda_t,
          &b_A_data[0], &ldb_t);
    c_st.site = &fd_emlrtRSI;
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'R';
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)B_size[1];
    lda_t = (ptrdiff_t)B_size[1];
    ldb_t = (ptrdiff_t)1;
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_B_data[0], &lda_t,
          &b_A_data[0], &ldb_t);
    for (b_loop_ub = B_size[1] - 2; b_loop_ub + 1 > 0; b_loop_ub--) {
      if (ipiv_data[b_loop_ub] != b_loop_ub + 1) {
        temp = b_A_data[b_loop_ub];
        b_A_data[b_loop_ub] = b_A_data[ipiv_data[b_loop_ub] - 1];
        b_A_data[ipiv_data[b_loop_ub] - 1] = temp;
      }
    }

    y_size[0] = 1;
    y_size[1] = A_size[1];
    loop_ub = A_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      y_data[i8] = b_A_data[i8];
    }
  } else {
    b_B_size[0] = B_size[1];
    b_B_size[1] = B_size[0];
    loop_ub = B_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_loop_ub = B_size[1];
      for (i9 = 0; i9 < b_loop_ub; i9++) {
        b_B_data[i9 + b_B_size[0] * i8] = B_data[i8 + B_size[0] * i9];
      }
    }

    b_A_size[0] = A_size[1];
    loop_ub = A_size[1];
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_A_data[i8] = A_data[A_size[0] * i8];
    }

    st.site = &dd_emlrtRSI;
    qrsolve(&st, b_B_data, b_B_size, b_A_data, b_A_size, tmp_data, tmp_size);
    y_size[0] = 1;
    y_size[1] = tmp_size[0];
    loop_ub = tmp_size[0];
    for (i8 = 0; i8 < loop_ub; i8++) {
      y_data[i8] = tmp_data[i8];
    }
  }
}

/* End of code generation (mrdivide.c) */
