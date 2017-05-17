/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_stat_lpks_wb1_api.c
 *
 * Code generation for function '_coder_stat_lpks_wb1_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "_coder_stat_lpks_wb1_api.h"
#include "stat_lpks_wb1_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3006];
static const mxArray *b_emlrt_marshallOut(const real_T u[120240]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xdesign,
  const char_T *identifier))[200];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[200];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ydesign,
  const char_T *identifier))[120240];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *Coord,
  const char_T *identifier))[3006];
static const mxArray *emlrt_marshallOut(const real_T u[15030]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[120240];
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *flag,
  const char_T *identifier))[3];
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3006];
static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[200];
static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[120240];
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3006]
{
  real_T (*y)[3006];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[120240])
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv7[3] = { 0, 0, 0 };

  static const int32_T iv8[3] = { 40, 1002, 3 };

  y = NULL;
  m2 = emlrtCreateNumericArray(3, iv7, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m2, iv8, 3);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xdesign,
  const char_T *identifier))[200]
{
  real_T (*y)[200];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(Xdesign), &thisId);
  emlrtDestroyArray(&Xdesign);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[200]
{
  real_T (*y)[200];
  y = j_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ydesign,
  const char_T *identifier))[120240]
{
  real_T (*y)[120240];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(Ydesign), &thisId);
  emlrtDestroyArray(&Ydesign);
  return y;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *Coord,
  const char_T *identifier))[3006]
{
  real_T (*y)[3006];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(Coord), &thisId);
  emlrtDestroyArray(&Coord);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[15030])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv5[3] = { 0, 0, 0 };

  static const int32_T iv6[3] = { 5, 1002, 3 };

  y = NULL;
  m1 = emlrtCreateNumericArray(3, iv5, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv6, 3);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[120240]
{
  real_T (*y)[120240];
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *flag,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(flag), &thisId);
  emlrtDestroyArray(&flag);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3006]
{
  real_T (*ret)[3006];
  static const int32_T dims[2] = { 1002, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3006])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[200]
{
  real_T (*ret)[200];
  static const int32_T dims[2] = { 40, 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[200])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[120240]
{
  real_T (*ret)[120240];
  static const int32_T dims[3] = { 40, 1002, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims);
  ret = (real_T (*)[120240])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void stat_lpks_wb1_api(stat_lpks_wb1StackData *SD, const mxArray * const prhs
  [4], const mxArray *plhs[2])
{
  real_T (*efitBetas)[15030];
  real_T (*efitYdesign)[120240];
  real_T (*Coord)[3006];
  real_T (*Xdesign)[200];
  real_T (*Ydesign)[120240];
  real_T (*flag)[3];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  efitBetas = (real_T (*)[15030])mxMalloc(sizeof(real_T [15030]));
  efitYdesign = (real_T (*)[120240])mxMalloc(sizeof(real_T [120240]));

  /* Marshall function inputs */
  Coord = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Coord");
  Xdesign = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Xdesign");
  Ydesign = e_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Ydesign");
  flag = g_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "flag");

  /* Invoke the target function */
  stat_lpks_wb1(SD, &st, *Coord, *Xdesign, *Ydesign, *flag, *efitBetas,
                *efitYdesign);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*efitBetas);
  plhs[1] = b_emlrt_marshallOut(*efitYdesign);
}

/* End of code generation (_coder_stat_lpks_wb1_api.c) */
