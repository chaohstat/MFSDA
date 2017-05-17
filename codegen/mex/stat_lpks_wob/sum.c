/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo gd_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

/* Function Definitions */
real_T b_sum(const emlrtStack *sp, const real_T x_data[], const int32_T x_size[2])
{
  real_T y;
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  if ((x_size[1] == 1) || (x_size[1] != 1)) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&st, &ab_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (x_size[k] != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_p) {
    p = true;
  }

  if (p) {
    emlrtErrorWithMessageIdR2012b(&st, &y_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  if (x_size[1] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[1]; k++) {
      y += x_data[k - 1];
    }
  }

  return y;
}

void sum(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
         int32_T y_size[2])
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T vlen;
  int32_T i;
  int32_T xoffset;
  real_T s;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  if (((x->size[0] == 1) && (x->size[1] == 1)) || (x->size[0] != 1)) {
    p = true;
  } else {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&st, &ab_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (x->size[k] != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (b_p) {
    p = true;
  }

  if (p) {
    emlrtErrorWithMessageIdR2012b(&st, &y_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  y_size[0] = 1;
  y_size[1] = (int16_T)x->size[1];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    y_size[0] = 1;
    k = y_size[1];
    for (vlen = 0; vlen < k; vlen++) {
      y_data[vlen] = 0.0;
    }
  } else {
    vlen = x->size[0];
    for (i = 0; i + 1 <= x->size[1]; i++) {
      xoffset = i * vlen;
      s = x->data[xoffset];
      for (k = 2; k <= vlen; k++) {
        s += x->data[(xoffset + k) - 1];
      }

      y_data[i] = s;
    }
  }
}

/* End of code generation (sum.c) */
