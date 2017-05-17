/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgetrf.c
 *
 * Code generation for function 'xgetrf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "xgetrf.h"
#include "error.h"
#include "stat_lpks_wob_data.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 7,  /* lineNo */
  "int",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\int.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 25, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 94, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 88, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 80, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 76, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 56, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 55, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 48, /* lineNo */
  "xgetrf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgetrf.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 18, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 8,  /* lineNo */
  "majority",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\majority.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 31, /* lineNo */
  "infocheck",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pathName */
};

static emlrtMCInfo emlrtMCI = { 37,    /* lineNo */
  5,                                   /* colNo */
  "repmat",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pName */
};

static emlrtRSInfo qd_emlrtRSI = { 37, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

/* Function Declarations */
static void f_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static void f_error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", true, location);
}

void xgetrf(const emlrtStack *sp, int32_T m, int32_T n, real_T A_data[], int32_T
            A_size[2], int32_T lda, int32_T ipiv_data[], int32_T ipiv_size[2],
            int32_T *info)
{
  int32_T varargin_1;
  int32_T k;
  ptrdiff_t ipiv_t_data[20];
  const mxArray *y;
  char_T u[15];
  static const char_T cv8[15] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'm',
    'a', 'x', 's', 'i', 'z', 'e' };

  const mxArray *m8;
  static const int32_T iv21[2] = { 1, 15 };

  ptrdiff_t info_t;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sb_emlrtRSI;
  if ((A_size[0] == 0) || (A_size[1] == 0)) {
    ipiv_size[0] = 1;
    ipiv_size[1] = 0;
    *info = 0;
  } else {
    b_st.site = &rb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    varargin_1 = muIntScalarMin_sint32(m, n);
    varargin_1 = muIntScalarMax_sint32(varargin_1, 1);
    b_st.site = &rb_emlrtRSI;
    c_st.site = &tb_emlrtRSI;
    if ((int8_T)varargin_1 != varargin_1) {
      for (k = 0; k < 15; k++) {
        u[k] = cv8[k];
      }

      y = NULL;
      m8 = emlrtCreateCharArray(2, iv21);
      emlrtInitCharArrayR2013a(&b_st, 15, m8, &u[0]);
      emlrtAssign(&y, m8);
      c_st.site = &qd_emlrtRSI;
      f_error(&c_st, y, &emlrtMCI);
    }

    b_st.site = &qb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    b_st.site = &pb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    b_st.site = &ob_emlrtRSI;
    c_st.site = &ub_emlrtRSI;
    info_t = LAPACKE_dgetrf_work(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
      (ptrdiff_t)lda, &ipiv_t_data[0]);
    *info = (int32_T)info_t;
    ipiv_size[0] = 1;
    ipiv_size[1] = (int8_T)varargin_1;
    b_st.site = &nb_emlrtRSI;
    c_st.site = &vb_emlrtRSI;
    if (*info < 0) {
      if (*info == -1010) {
        c_st.site = &wb_emlrtRSI;
        b_error(&c_st);
      } else {
        c_st.site = &xb_emlrtRSI;
        c_error(&c_st, *info);
      }
    }

    b_st.site = &mb_emlrtRSI;
    for (k = 0; k < (int8_T)varargin_1; k++) {
      ipiv_data[k] = (int32_T)ipiv_t_data[k];
    }
  }
}

/* End of code generation (xgetrf.c) */
