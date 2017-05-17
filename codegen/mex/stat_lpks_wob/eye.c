/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eye.c
 *
 * Code generation for function 'eye'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "eye.h"
#include "eml_int_forloop_overflow_check.h"
#include "stat_lpks_wob_data.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 92, /* lineNo */
  "eye",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 51, /* lineNo */
  "eye",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m"/* pathName */
};

static emlrtRTEInfo w_emlrtRTEI = { 53,/* lineNo */
  23,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\assertValidSizeArg.m"/* pName */
};

/* Function Definitions */
void eye(const emlrtStack *sp, real_T varargin_1, real_T I_data[], int32_T
         I_size[2])
{
  boolean_T guard1 = false;
  boolean_T p;
  int32_T loop_ub;
  int32_T i7;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  guard1 = false;
  if (!(varargin_1 != varargin_1)) {
    if ((-2.147483648E+9 > varargin_1) || (2.147483647E+9 < varargin_1)) {
      p = false;
    } else {
      p = true;
    }

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&st, &w_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }

  I_size[0] = (int32_T)varargin_1;
  I_size[1] = (int32_T)varargin_1;
  loop_ub = (int32_T)varargin_1 * (int32_T)varargin_1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    I_data[i7] = 0.0;
  }

  st.site = &bd_emlrtRSI;
  if ((!(1 > (int32_T)varargin_1)) && ((int32_T)varargin_1 > 2147483646)) {
    b_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (loop_ub = 0; loop_ub + 1 <= (int32_T)varargin_1; loop_ub++) {
    I_data[loop_ub + (int32_T)varargin_1 * loop_ub] = 1.0;
  }
}

/* End of code generation (eye.c) */
