/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "mldivide.h"
#include "warning.h"
#include "xgetrf.h"
#include "stat_lpks_wb1_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 1,   /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 143, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 145, /* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[25], real_T B[200])
{
  real_T b_A[25];
  int32_T ipiv[5];
  int32_T info;
  int32_T ip;
  int32_T xj;
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
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &m_emlrtRSI;
  memcpy(&b_A[0], &A[0], 25U * sizeof(real_T));
  c_st.site = &o_emlrtRSI;
  xgetrf(&c_st, b_A, ipiv, &info);
  if (info > 0) {
    c_st.site = &n_emlrtRSI;
    if (!emlrtSetWarningFlag(&c_st)) {
      d_st.site = &hb_emlrtRSI;
      warning(&d_st);
    }
  }

  for (info = 0; info < 4; info++) {
    if (ipiv[info] != info + 1) {
      ip = ipiv[info] - 1;
      for (xj = 0; xj < 40; xj++) {
        temp = B[info + 5 * xj];
        B[info + 5 * xj] = B[ip + 5 * xj];
        B[ip + 5 * xj] = temp;
      }
    }
  }

  c_st.site = &p_emlrtRSI;
  temp = 1.0;
  DIAGA = 'U';
  TRANSA = 'N';
  UPLO = 'L';
  SIDE = 'L';
  m_t = (ptrdiff_t)5;
  n_t = (ptrdiff_t)40;
  lda_t = (ptrdiff_t)5;
  ldb_t = (ptrdiff_t)5;
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A[0], &lda_t, &B[0],
        &ldb_t);
  c_st.site = &q_emlrtRSI;
  temp = 1.0;
  DIAGA = 'N';
  TRANSA = 'N';
  UPLO = 'U';
  SIDE = 'L';
  m_t = (ptrdiff_t)5;
  n_t = (ptrdiff_t)40;
  lda_t = (ptrdiff_t)5;
  ldb_t = (ptrdiff_t)5;
  dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A[0], &lda_t, &B[0],
        &ldb_t);
}

/* End of code generation (mldivide.c) */
