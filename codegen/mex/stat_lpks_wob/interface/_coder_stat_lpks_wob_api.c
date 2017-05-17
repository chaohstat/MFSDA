/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_stat_lpks_wob_api.c
 *
 * Code generation for function '_coder_stat_lpks_wob_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "_coder_stat_lpks_wob_api.h"
#include "stat_lpks_wob_emxutil.h"
#include "stat_lpks_wob_data.h"

/* Variable Definitions */
static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_stat_lpks_wob_api",          /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Coord, const
  char_T *identifier, emxArray_real_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xdesign,
  const char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ydesign,
  const char_T *identifier, emxArray_real_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv17[2] = { 0, 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv17, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m4, u_size, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Coord, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(Coord), &thisId, y);
  emlrtDestroyArray(&Coord);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Xdesign,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Xdesign), &thisId, y);
  emlrtDestroyArray(&Xdesign);
}

static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv16[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv16, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m3, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m3, u_size, 2);
  emlrtAssign(&y, m3);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Ydesign,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(Ydesign), &thisId, y);
  emlrtDestroyArray(&Ydesign);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 5000, 4 };

  boolean_T bv0[2] = { true, true };

  int32_T iv18[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv18);
  ret->size[0] = iv18[0];
  ret->size[1] = iv18[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 5000, 20 };

  boolean_T bv1[2] = { true, true };

  int32_T iv19[2];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv19);
  ret->size[0] = iv19[0];
  ret->size[1] = iv19[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[3] = { 5000, 5000, 5 };

  boolean_T bv2[3] = { true, true, true };

  int32_T iv20[3];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims, &bv2[0],
    iv20);
  ret->size[0] = iv20[0];
  ret->size[1] = iv20[1];
  ret->size[2] = iv20[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void stat_lpks_wob_api(stat_lpks_wobStackData *SD, const mxArray * const prhs[3],
  const mxArray *plhs[2])
{
  real_T (*flag_data)[5];
  real_T (*GCVs_data)[250];
  emxArray_real_T *Coord;
  emxArray_real_T *Xdesign;
  emxArray_real_T *Ydesign;
  int32_T flag_size[2];
  int32_T GCVs_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  flag_data = (real_T (*)[5])mxMalloc(sizeof(real_T [5]));
  GCVs_data = (real_T (*)[250])mxMalloc(sizeof(real_T [250]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T1(&st, &Coord, 2, &p_emlrtRTEI, true);
  emxInit_real_T1(&st, &Xdesign, 2, &p_emlrtRTEI, true);
  emxInit_real_T(&st, &Ydesign, 3, &p_emlrtRTEI, true);

  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Coord", Coord);
  e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Xdesign", Xdesign);
  g_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Ydesign", Ydesign);

  /* Invoke the target function */
  stat_lpks_wob(SD, &st, Coord, Xdesign, Ydesign, *flag_data, flag_size,
                *GCVs_data, GCVs_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*flag_data, flag_size);
  plhs[1] = b_emlrt_marshallOut(*GCVs_data, GCVs_size);
  Ydesign->canFreeData = false;
  emxFree_real_T(&Ydesign);
  Xdesign->canFreeData = false;
  emxFree_real_T(&Xdesign);
  Coord->canFreeData = false;
  emxFree_real_T(&Coord);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_stat_lpks_wob_api.c) */
