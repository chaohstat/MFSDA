/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * qrsolve.c
 *
 * Code generation for function 'qrsolve'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "qrsolve.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "warning.h"
#include "xgeqp3.h"
#include "stat_lpks_wob_emxutil.h"
#include "stat_lpks_wob_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = { 121,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 120,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 72, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 78, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo sc_emlrtRSI = { 79, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo tc_emlrtRSI = { 89, /* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 29, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 101,/* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 91, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 78, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 77, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 57, /* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtMCInfo d_emlrtMCI = { 52,  /* lineNo */
  19,                                  /* colNo */
  "flt2str",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 54,/* lineNo */
  14,                                  /* colNo */
  "qrsolve",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pName */
};

static emlrtRSInfo rd_emlrtRSI = { 52, /* lineNo */
  "flt2str",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\flt2str.m"/* pathName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  i_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(c_sprintf), &thisId, y);
  emlrtDestroyArray(&c_sprintf);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = { 1, 14 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

void LSQFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
               A_size[2], const real_T tau_data[], const int32_T jpvt_data[],
               emxArray_real_T *B, int32_T rankA, emxArray_real_T *Y)
{
  int32_T nb;
  int16_T unnamed_idx_1;
  int32_T info;
  int32_T loop_ub;
  ptrdiff_t nrc_t;
  int32_T j;
  ptrdiff_t info_t;
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
  nb = B->size[1];
  unnamed_idx_1 = (int16_T)B->size[1];
  info = Y->size[0] * Y->size[1];
  Y->size[0] = (int16_T)A_size[1];
  Y->size[1] = unnamed_idx_1;
  emxEnsureCapacity(sp, (emxArray__common *)Y, info, (int32_T)sizeof(real_T),
                    &o_emlrtRTEI);
  loop_ub = (int16_T)A_size[1] * unnamed_idx_1;
  for (info = 0; info < loop_ub; info++) {
    Y->data[info] = 0.0;
  }

  st.site = &qc_emlrtRSI;
  b_st.site = &uc_emlrtRSI;
  c_st.site = &ad_emlrtRSI;
  if ((!((A_size[0] == 0) || (A_size[1] == 0))) && (!((B->size[0] == 0) ||
        (B->size[1] == 0)))) {
    c_st.site = &yc_emlrtRSI;
    c_st.site = &xc_emlrtRSI;
    nrc_t = (ptrdiff_t)B->size[0];
    c_st.site = &wc_emlrtRSI;
    info_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)B->size[1],
      (ptrdiff_t)muIntScalarMin_sint32(A_size[0], A_size[1]), &A_data[0],
      (ptrdiff_t)A_size[0], &tau_data[0], &B->data[0], nrc_t);
    info = (int32_T)info_t;
    c_st.site = &vc_emlrtRSI;
    if (info != 0) {
      if (info == -1010) {
        d_st.site = &wb_emlrtRSI;
        b_error(&d_st);
      } else {
        d_st.site = &xb_emlrtRSI;
        e_error(&d_st, info);
      }
    }
  }

  st.site = &rc_emlrtRSI;
  for (info = 0; info + 1 <= nb; info++) {
    st.site = &sc_emlrtRSI;
    if ((!(1 > rankA)) && (rankA > 2147483646)) {
      b_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (loop_ub = 0; loop_ub + 1 <= rankA; loop_ub++) {
      Y->data[(jpvt_data[loop_ub] + Y->size[0] * info) - 1] = B->data[loop_ub +
        B->size[0] * info];
    }

    for (j = rankA - 1; j + 1 > 0; j--) {
      Y->data[(jpvt_data[j] + Y->size[0] * info) - 1] /= A_data[j + A_size[0] *
        j];
      st.site = &tc_emlrtRSI;
      for (loop_ub = 0; loop_ub + 1 <= j; loop_ub++) {
        Y->data[(jpvt_data[loop_ub] + Y->size[0] * info) - 1] -= Y->data
          [(jpvt_data[j] + Y->size[0] * info) - 1] * A_data[loop_ub + A_size[0] *
          j];
      }
    }
  }
}

void qrsolve(const emlrtStack *sp, const real_T A_data[], const int32_T A_size[2],
             const real_T B_data[], const int32_T B_size[1], real_T Y_data[],
             int32_T Y_size[1])
{
  int32_T b_A_size[2];
  int32_T info;
  int32_T i;
  real_T b_A_data[400];
  real_T tau_data[20];
  int32_T tau_size[1];
  int32_T jpvt_data[20];
  int32_T jpvt_size[2];
  int32_T rankA;
  real_T b_tau_data[5];
  real_T b_B_data[5];
  ptrdiff_t nrc_t;
  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_A_size[0] = A_size[0];
  b_A_size[1] = A_size[1];
  info = A_size[0] * A_size[1];
  for (i = 0; i < info; i++) {
    b_A_data[i] = A_data[i];
  }

  st.site = &ec_emlrtRSI;
  xgeqp3(&st, b_A_data, b_A_size, tau_data, tau_size, jpvt_data, jpvt_size);
  info = tau_size[0];
  for (i = 0; i < info; i++) {
    b_tau_data[i] = tau_data[i];
  }

  st.site = &fc_emlrtRSI;
  rankA = rankFromQR(&st, b_A_data, b_A_size);
  st.site = &gc_emlrtRSI;
  Y_size[0] = (int8_T)b_A_size[1];
  info = (int8_T)b_A_size[1];
  for (i = 0; i < info; i++) {
    Y_data[i] = 0.0;
  }

  b_st.site = &qc_emlrtRSI;
  c_st.site = &uc_emlrtRSI;
  info = B_size[0];
  for (i = 0; i < info; i++) {
    b_B_data[i] = B_data[i];
  }

  d_st.site = &ad_emlrtRSI;
  if (!((b_A_size[0] == 0) || (b_A_size[1] == 0))) {
    d_st.site = &yc_emlrtRSI;
    d_st.site = &xc_emlrtRSI;
    nrc_t = (ptrdiff_t)B_size[0];
    d_st.site = &wc_emlrtRSI;
    info_t = LAPACKE_dormqr(102, 'L', 'T', nrc_t, (ptrdiff_t)1, (ptrdiff_t)
      muIntScalarMin_sint32(b_A_size[0], b_A_size[1]), &b_A_data[0], (ptrdiff_t)
      b_A_size[0], &b_tau_data[0], &b_B_data[0], nrc_t);
    info = (int32_T)info_t;
    d_st.site = &vc_emlrtRSI;
    if (info != 0) {
      if (info == -1010) {
        e_st.site = &wb_emlrtRSI;
        b_error(&e_st);
      } else {
        e_st.site = &xb_emlrtRSI;
        e_error(&e_st, info);
      }
    }
  }

  b_st.site = &sc_emlrtRSI;
  if ((!(1 > rankA)) && (rankA > 2147483646)) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (i = 0; i + 1 <= rankA; i++) {
    Y_data[jpvt_data[i] - 1] = b_B_data[i];
  }

  for (info = rankA - 1; info + 1 > 0; info--) {
    Y_data[jpvt_data[info] - 1] /= b_A_data[info + b_A_size[0] * info];
    b_st.site = &tc_emlrtRSI;
    for (i = 0; i + 1 <= info; i++) {
      Y_data[jpvt_data[i] - 1] -= Y_data[jpvt_data[info] - 1] * b_A_data[i +
        b_A_size[0] * info];
    }
  }
}

int32_T rankFromQR(const emlrtStack *sp, const real_T A_data[], const int32_T
                   A_size[2])
{
  int32_T r;
  real_T tol;
  int32_T minmn;
  int32_T maxmn;
  const mxArray *y;
  char_T rfmt[6];
  static const char_T cv3[6] = { '%', '1', '4', '.', '6', 'e' };

  const mxArray *m1;
  static const int32_T iv11[2] = { 1, 6 };

  const mxArray *b_y;
  char_T cv4[14];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0;
  tol = 0.0;
  if (A_size[0] < A_size[1]) {
    minmn = A_size[0];
    maxmn = A_size[1];
  } else {
    minmn = A_size[1];
    maxmn = A_size[0];
  }

  if (minmn > 0) {
    tol = (real_T)maxmn * muDoubleScalarAbs(A_data[0]) * 2.2204460492503131E-16;
    while ((r < minmn) && (muDoubleScalarAbs(A_data[r + A_size[0] * r]) >= tol))
    {
      r++;
    }
  }

  if ((r < minmn) && (!emlrtSetWarningFlag(sp))) {
    st.site = &oc_emlrtRSI;
    for (minmn = 0; minmn < 6; minmn++) {
      rfmt[minmn] = cv3[minmn];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv11);
    emlrtInitCharArrayR2013a(&st, 6, m1, &rfmt[0]);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateDoubleScalar(tol);
    emlrtAssign(&b_y, m1);
    b_st.site = &rd_emlrtRSI;
    emlrt_marshallIn(&b_st, b_sprintf(&b_st, y, b_y, &d_emlrtMCI), "sprintf",
                     cv4);
    st.site = &pc_emlrtRSI;
    b_warning(&st, r, cv4);
  }

  return r;
}

/* End of code generation (qrsolve.c) */
