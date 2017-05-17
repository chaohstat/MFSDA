/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_stat_sif_api.c
 *
 * Code generation for function '_coder_stat_sif_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "_coder_stat_sif_api.h"
#include "stat_sif_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3006];
static const mxArray *b_emlrt_marshallOut(const real_T u[9036036]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ResYdesign, const char_T *identifier))[120240];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[120240];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3006];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *Coord,
  const char_T *identifier))[3006];
static const mxArray *emlrt_marshallOut(const real_T u[120240]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[120240];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3006]
{
  real_T (*y)[3006];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const real_T u[9036036])
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv6[4] = { 0, 0, 0, 0 };

  static const int32_T iv7[4] = { 3, 3, 1002, 1002 };

  y = NULL;
  m2 = emlrtCreateNumericArray(4, iv6, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m2, iv7, 4);
  emlrtAssign(&y, m2);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ResYdesign, const char_T *identifier))[120240]
{
  real_T (*y)[120240];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(ResYdesign), &thisId);
  emlrtDestroyArray(&ResYdesign);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[120240]
{
  real_T (*y)[120240];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3006]
{
  real_T (*ret)[3006];
  static const int32_T dims[2] = { 1002, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3006])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
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

static const mxArray *emlrt_marshallOut(const real_T u[120240])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv4[3] = { 0, 0, 0 };

  static const int32_T iv5[3] = { 40, 1002, 3 };

  y = NULL;
  m1 = emlrtCreateNumericArray(3, iv4, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv5, 3);
  emlrtAssign(&y, m1);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[120240]
{
  real_T (*ret)[120240];
  static const int32_T dims[3] = { 40, 1002, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 3U, dims);
  ret = (real_T (*)[120240])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  void stat_sif_api(stat_sifStackData *SD, const mxArray * const prhs[2], const
                    mxArray *plhs[3])
{
  real_T (*efitEtas)[120240];
  real_T (*ResEtas)[120240];
  real_T (*eSigEta)[9036036];
  real_T (*Coord)[3006];
  real_T (*ResYdesign)[120240];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  efitEtas = (real_T (*)[120240])mxMalloc(sizeof(real_T [120240]));
  ResEtas = (real_T (*)[120240])mxMalloc(sizeof(real_T [120240]));
  eSigEta = (real_T (*)[9036036])mxMalloc(sizeof(real_T [9036036]));

  /* Marshall function inputs */
  Coord = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Coord");
  ResYdesign = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "ResYdesign");

  /* Invoke the target function */
  stat_sif(SD, &st, *Coord, *ResYdesign, *efitEtas, *ResEtas, *eSigEta);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*efitEtas);
  plhs[1] = emlrt_marshallOut(*ResEtas);
  plhs[2] = b_emlrt_marshallOut(*eSigEta);
}

/* End of code generation (_coder_stat_sif_api.c) */
