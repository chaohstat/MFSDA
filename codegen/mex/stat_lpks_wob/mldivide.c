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
#include "stat_lpks_wob.h"
#include "mldivide.h"
#include "stat_lpks_wob_emxutil.h"
#include "lusolve.h"
#include "qrsolve.h"
#include "xgeqp3.h"
#include "stat_lpks_wob_data.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 1,  /* lineNo */
  "mldivide",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"/* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = { 1, /* lineNo */
  2,                                   /* colNo */
  "mldivide",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "mldivide",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.p"/* pName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A_data[], const int32_T A_size
              [2], const emxArray_real_T *B, emxArray_real_T *Y)
{
  emxArray_real_T *b_B;
  int16_T unnamed_idx_1;
  int32_T i4;
  int32_T b_A_size[2];
  int32_T loop_ub;
  real_T b_A_data[400];
  real_T tau_data[20];
  int32_T tau_size[1];
  int32_T jpvt_data[20];
  int32_T jpvt_size[2];
  int32_T rankR;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  if (B->size[0] != A_size[0]) {
    emlrtErrorWithMessageIdR2012b(sp, &v_emlrtRTEI, "Coder:MATLAB:dimagree", 0);
  }

  emxInit_real_T1(sp, &b_B, 2, &m_emlrtRTEI, true);
  if ((A_size[0] == 0) || (A_size[1] == 0) || ((B->size[0] == 0) || (B->size[1] ==
        0))) {
    unnamed_idx_1 = (int16_T)B->size[1];
    i4 = Y->size[0] * Y->size[1];
    Y->size[0] = (int16_T)A_size[1];
    Y->size[1] = unnamed_idx_1;
    emxEnsureCapacity(sp, (emxArray__common *)Y, i4, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    loop_ub = (int16_T)A_size[1] * unnamed_idx_1;
    for (i4 = 0; i4 < loop_ub; i4++) {
      Y->data[i4] = 0.0;
    }
  } else if (A_size[0] == A_size[1]) {
    st.site = &cb_emlrtRSI;
    lusolve(&st, A_data, A_size, B, Y);
  } else {
    st.site = &cb_emlrtRSI;
    b_A_size[0] = A_size[0];
    b_A_size[1] = A_size[1];
    loop_ub = A_size[0] * A_size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_A_data[i4] = A_data[i4];
    }

    b_st.site = &ec_emlrtRSI;
    xgeqp3(&b_st, b_A_data, b_A_size, tau_data, tau_size, jpvt_data, jpvt_size);
    b_st.site = &fc_emlrtRSI;
    rankR = rankFromQR(&b_st, b_A_data, b_A_size);
    i4 = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[0];
    b_B->size[1] = B->size[1];
    emxEnsureCapacity(&st, (emxArray__common *)b_B, i4, (int32_T)sizeof(real_T),
                      &m_emlrtRTEI);
    loop_ub = B->size[0] * B->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_B->data[i4] = B->data[i4];
    }

    b_st.site = &gc_emlrtRSI;
    LSQFromQR(&b_st, b_A_data, b_A_size, tau_data, jpvt_data, b_B, rankR, Y);
  }

  emxFree_real_T(&b_B);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (mldivide.c) */
