/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.c
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "warning.h"

/* Variable Definitions */
static emlrtMCInfo b_emlrtMCI = { 14,  /* lineNo */
  25,                                  /* colNo */
  "warning",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"/* pName */
};

static emlrtMCInfo c_emlrtMCI = { 14,  /* lineNo */
  9,                                   /* colNo */
  "warning",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"/* pName */
};

static emlrtRSInfo pd_emlrtRSI = { 14, /* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"/* pathName */
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 4, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 2, pArrays, "feval", true, location);
}

void b_warning(const emlrtStack *sp, int32_T varargin_1, const char_T
               varargin_2[14])
{
  int32_T i6;
  char_T msgID[32];
  static const char_T cv5[32] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'r', 'a', 'n', 'k', 'D', 'e', 'f', 'i', 'c', 'i', 'e',
    'n', 't', 'M', 'a', 't', 'r', 'i', 'x' };

  const mxArray *y;
  char_T u[7];
  static const char_T cv6[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m2;
  static const int32_T iv12[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv7[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv13[2] = { 1, 7 };

  const mxArray *c_y;
  static const int32_T iv14[2] = { 1, 32 };

  const mxArray *d_y;
  const mxArray *e_y;
  static const int32_T iv15[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i6 = 0; i6 < 32; i6++) {
    msgID[i6] = cv5[i6];
  }

  for (i6 = 0; i6 < 7; i6++) {
    u[i6] = cv6[i6];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  for (i6 = 0; i6 < 7; i6++) {
    b_u[i6] = cv7[i6];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv13);
  emlrtInitCharArrayR2013a(sp, 7, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv14);
  emlrtInitCharArrayR2013a(sp, 32, m2, &msgID[0]);
  emlrtAssign(&c_y, m2);
  d_y = NULL;
  m2 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m2) = varargin_1;
  emlrtAssign(&d_y, m2);
  e_y = NULL;
  m2 = emlrtCreateCharArray(2, iv15);
  emlrtInitCharArrayR2013a(sp, 14, m2, &varargin_2[0]);
  emlrtAssign(&e_y, m2);
  st.site = &pd_emlrtRSI;
  b_feval(&st, y, c_feval(&st, b_y, c_y, d_y, e_y, &b_emlrtMCI), &c_emlrtMCI);
}

void warning(const emlrtStack *sp)
{
  int32_T i5;
  char_T msgID[27];
  static const char_T cv0[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  const mxArray *y;
  char_T u[7];
  static const char_T cv1[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m0;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv2[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv9[2] = { 1, 7 };

  const mxArray *c_y;
  static const int32_T iv10[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i5 = 0; i5 < 27; i5++) {
    msgID[i5] = cv0[i5];
  }

  for (i5 = 0; i5 < 7; i5++) {
    u[i5] = cv1[i5];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i5 = 0; i5 < 7; i5++) {
    b_u[i5] = cv2[i5];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 27, m0, &msgID[0]);
  emlrtAssign(&c_y, m0);
  st.site = &pd_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, &b_emlrtMCI), &c_emlrtMCI);
}

/* End of code generation (warning.c) */
