/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lusolve.c
 *
 * Code generation for function 'lusolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "lusolve.h"
#include "stat_lpks_wob_emxutil.h"
#include "warning.h"
#include "xgetrf.h"
#include "stat_lpks_wob_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = { 132,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 135,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 143,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 145,/* lineNo */
  "lusolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pathName */
};

static emlrtRTEInfo n_emlrtRTEI = { 1, /* lineNo */
  19,                                  /* colNo */
  "lusolve",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m"/* pName */
};

/* Function Definitions */
void lusolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const emxArray_real_T *B, emxArray_real_T *X)
{
  int32_T b_A_size[2];
  int32_T loop_ub;
  int32_T ip;
  real_T b_A_data[400];
  int32_T ipiv_data[20];
  int32_T ipiv_size[2];
  int32_T nb;
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
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  loop_ub = A_size[0] * A_size[1];
  for (ip = 0; ip < loop_ub; ip++) {
    b_A_data[ip] = A_data[ip];
  }

  b_st.site = &fb_emlrtRSI;
  xgetrf(&b_st, A_size[1], A_size[1], b_A_data, b_A_size, A_size[1], ipiv_data,
         ipiv_size, &loop_ub);
  if (loop_ub > 0) {
    b_st.site = &eb_emlrtRSI;
    if (!emlrtSetWarningFlag(&b_st)) {
      c_st.site = &yb_emlrtRSI;
      warning(&c_st);
    }
  }

  nb = B->size[1];
  ip = X->size[0] * X->size[1];
  X->size[0] = B->size[0];
  X->size[1] = B->size[1];
  emxEnsureCapacity(&st, (emxArray__common *)X, ip, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  loop_ub = B->size[0] * B->size[1];
  for (ip = 0; ip < loop_ub; ip++) {
    X->data[ip] = B->data[ip];
  }

  b_st.site = &gb_emlrtRSI;
  for (loop_ub = 0; loop_ub + 1 < A_size[1]; loop_ub++) {
    if (ipiv_data[loop_ub] != loop_ub + 1) {
      ip = ipiv_data[loop_ub] - 1;
      b_st.site = &hb_emlrtRSI;
      for (xj = 0; xj + 1 <= nb; xj++) {
        temp = X->data[loop_ub + X->size[0] * xj];
        X->data[loop_ub + X->size[0] * xj] = X->data[ip + X->size[0] * xj];
        X->data[ip + X->size[0] * xj] = temp;
      }
    }
  }

  b_st.site = &ib_emlrtRSI;
  if ((A_size[1] < 1) || (B->size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'U';
    TRANSA = 'N';
    UPLO = 'L';
    SIDE = 'L';
    m_t = (ptrdiff_t)A_size[1];
    n_t = (ptrdiff_t)B->size[1];
    lda_t = (ptrdiff_t)A_size[1];
    ldb_t = (ptrdiff_t)A_size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A_data[0], &lda_t,
          &X->data[0], &ldb_t);
  }

  b_st.site = &jb_emlrtRSI;
  if ((A_size[1] < 1) || (B->size[1] < 1)) {
  } else {
    temp = 1.0;
    DIAGA = 'N';
    TRANSA = 'N';
    UPLO = 'U';
    SIDE = 'L';
    m_t = (ptrdiff_t)A_size[1];
    n_t = (ptrdiff_t)B->size[1];
    lda_t = (ptrdiff_t)A_size[1];
    ldb_t = (ptrdiff_t)A_size[1];
    dtrsm(&SIDE, &UPLO, &TRANSA, &DIAGA, &m_t, &n_t, &temp, &b_A_data[0], &lda_t,
          &X->data[0], &ldb_t);
  }
}

/* End of code generation (lusolve.c) */
