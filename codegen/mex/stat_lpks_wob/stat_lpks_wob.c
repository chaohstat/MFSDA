/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wob.c
 *
 * Code generation for function 'stat_lpks_wob'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "stat_lpks_wob_emxutil.h"
#include "EpKernel.h"
#include "mrdivide.h"
#include "eye.h"
#include "mldivide.h"
#include "sum.h"
#include "power.h"
#include "permute.h"
#include "floor1.h"
#include "linspace.h"
#include "stat_lpks_wob_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 60,    /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 63,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 71,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 73,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 74,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 77,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 82,  /* lineNo */
  "stat_lpks_wob",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 68,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 21,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 15, /* lineNo */
  "min",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  24,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 39,/* lineNo */
  1,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 52,/* lineNo */
  5,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 63,/* lineNo */
  5,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 67,/* lineNo */
  17,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 71,/* lineNo */
  21,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  30,                                  /* colNo */
  "Coord",                             /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  63,                                  /* colNo */
  "Coord",                             /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  43,                                  /* lineNo */
  22,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  1,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  43,                                  /* lineNo */
  15,                                  /* colNo */
  "Tmat0",                             /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  43,                                  /* lineNo */
  5,                                   /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  45,                                  /* colNo */
  "Tmat0",                             /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  60,                                  /* lineNo */
  14,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  27,                                  /* colNo */
  "Kmat",                              /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  56,                                  /* colNo */
  "Tmat",                              /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  67,                                  /* lineNo */
  20,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 69,    /* lineNo */
  36,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  69,                                  /* lineNo */
  36,                                  /* colNo */
  "indx",                              /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  49,                                  /* colNo */
  "Ydesign0",                          /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  84,                                  /* colNo */
  "Tmat",                              /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  71,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 74,  /* lineNo */
  68,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  68,                                  /* colNo */
  "Xdesign",                           /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  45,                                  /* colNo */
  "Ydesign",                           /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 74,  /* lineNo */
  33,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  33,                                  /* colNo */
  "efitYdesign",                       /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  51,                                  /* colNo */
  "efitYdesign",                       /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  55,                                  /* colNo */
  "efitYdesign",                       /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  74,                                  /* lineNo */
  21,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  66,                                  /* colNo */
  "efitYdesign",                       /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  77,                                  /* lineNo */
  33,                                  /* colNo */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m"/* pName */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  38,                                  /* colNo */
  "Xdesign",                           /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  38,                                  /* colNo */
  "Ydesign",                           /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = { 104,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 99,/* lineNo */
  23,                                  /* colNo */
  "eml_mtimes_helper",                 /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pName */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  19,                                  /* colNo */
  "GCVs",                              /* aName */
  "stat_lpks_wob",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wob.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void stat_lpks_wob(stat_lpks_wobStackData *SD, const emlrtStack *sp, const
                   emxArray_real_T *Coord, const emxArray_real_T *Xdesign, const
                   emxArray_real_T *Ydesign, real_T flag_data[], int32_T
                   flag_size[2], real_T GCVs_data[], int32_T GCVs_size[2])
{
  emxArray_real_T *efitYdesign;
  int32_T n;
  int32_T d;
  int32_T L;
  int32_T i0;
  int32_T loop_ub;
  emxArray_real_T *Tmat0;
  int32_T ix;
  int32_T Coord_idx_1;
  int16_T tmp_data[5000];
  int32_T indx_size[2];
  int16_T b_tmp_data[5000];
  int32_T b_Coord[2];
  int32_T dii;
  int32_T i1;
  emxArray_real_T *r0;
  emxArray_real_T *y;
  real_T ind[6];
  int32_T nhii;
  emxArray_real_T *Kmat;
  emxArray_real_T *Tmat;
  emxArray_real_T *KX;
  emxArray_real_T *PX0;
  emxArray_real_T *b_y;
  emxArray_real_T *a;
  emxArray_real_T *c_y;
  emxArray_real_T *d_y;
  emxArray_real_T *b;
  emxArray_real_T *b_Tmat0;
  emxArray_real_T *b_Ydesign;
  emxArray_real_T *b_Xdesign;
  emxArray_real_T *c_Ydesign;
  emxArray_real_T *b_efitYdesign;
  emxArray_real_T *b_Tmat;
  emxArray_real_T *d_Ydesign;
  int32_T iv0[2];
  int32_T e_y[2];
  int16_T unnamed_idx_0;
  int32_T mii;
  int16_T i2;
  int32_T Lii;
  int32_T i;
  int32_T iv1[2];
  int32_T iindx_data[5];
  static const real_T dv0[50] = { 0.01, 0.010985411419875583,
    0.012067926406393288, 0.013257113655901088, 0.014563484775012436,
    0.015998587196060583, 0.017575106248547922, 0.019306977288832496,
    0.021209508879201904, 0.023299518105153717, 0.025595479226995357,
    0.028117686979742307, 0.030888435964774818, 0.033932217718953279,
    0.037275937203149395, 0.040949150623804234, 0.044984326689694439,
    0.04941713361323833, 0.054286754393238594, 0.059636233165946427,
    0.0655128556859551, 0.071968567300115208, 0.079060432109076983,
    0.086851137375135251, 0.0954095476349994, 0.10481131341546858,
    0.1151395399326447, 0.12648552168552957, 0.13894954943731375,
    0.15264179671752334, 0.16768329368110074, 0.18420699693267154,
    0.20235896477251566, 0.22229964825261944, 0.2442053094548651,
    0.26826957952797248, 0.29470517025518095, 0.32374575428176433,
    0.35564803062231287, 0.39069399370546148, 0.42919342601287758,
    0.47148663634573923, 0.517947467923121, 0.56898660290182956,
    0.62505519252739694, 0.68664884500429979, 0.75431200633546147,
    0.82864277285468424, 0.9102981779915218, 1.0 };

  int32_T b_Kmat[2];
  int32_T iv2[2];
  real_T mtmp;
  int32_T cindx;
  int32_T e_Ydesign[2];
  int32_T b_ix;
  int32_T f_y[2];
  boolean_T exitg1;
  int32_T c_efitYdesign[2];
  int32_T c_Tmat[2];
  int32_T kk;
  int32_T c_tmp_data[5000];
  boolean_T guard4 = false;
  boolean_T guard3 = false;
  boolean_T guard2 = false;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  real_T a_data[25];
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T g_y[2];
  int32_T b_a[2];
  real_T d_tmp_data[5];
  int32_T tmp_size[2];
  real_T y_data[25];
  int32_T y_size[2];
  real_T b_a_data[20];
  boolean_T guard1 = false;
  real_T b_data[5000];
  int8_T y_idx_0;
  real_T efitBetas0_data[5000];
  int32_T C_size[1];
  real_T C_data[5000];
  int32_T iv3[1];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &efitYdesign, 3, &b_emlrtRTEI, true);

  /*  stat_lpks_wob is to implement Zhu's (2010) method of local polynomial kernel smoothing (order = 1) for optimal bandwidth selection */
  /*  */
  /*  Input: */
  /*      Coord      - a L x d matrix of the coordinates of all vertices aligned on the sphere. */
  /*      Xdesign    - a n x p0 normalized design matrix. */
  /*      Ydesign    - a n x L x m matrix of surface shape data. */
  /*  Output: */
  /*      flag       - a 1 x m vector of indice for optimal bandwidth. */
  /*      GCVs       - a nh x m matrix of GCVs. */
  /*  Reference: */
  /*  Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012. */
  /*  doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533. */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Please run */
  /*     Ydesign = stat_read_vtk(file_dir) */
  /*     Coord = stat_read_vtk(file_dir) */
  /*     Xdesign = stat_read_x(design_data, n_Interest, n_Con) */
  /*  before you use stat_lpks_wob */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  March, 2017 @ Chao Huang */
  /*  */
  /*  SetUp */
  n = Xdesign->size[0];

  /*    n  = sample size    p0  = number of covariates */
  d = Coord->size[1];
  L = Coord->size[0];

  /*    L = number of vertices     d  = dimension of corrdinate */
  /*    m  = number of shape features (here m=d) */
  i0 = efitYdesign->size[0] * efitYdesign->size[1] * efitYdesign->size[2];
  efitYdesign->size[0] = Ydesign->size[0];
  efitYdesign->size[1] = Ydesign->size[1];
  efitYdesign->size[2] = Ydesign->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)efitYdesign, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  loop_ub = Ydesign->size[0] * Ydesign->size[1] * Ydesign->size[2];
  for (i0 = 0; i0 < loop_ub; i0++) {
    efitYdesign->data[i0] = Ydesign->data[i0] * 0.0;
  }

  emxInit_real_T(sp, &Tmat0, 3, &c_emlrtRTEI, true);

  /*  fitted Ydesign */
  /*  bandwidth SetUp */
  /*  the number of candidate bandwidth */
  /*  GCV performance function */
  /*  GCV */
  i0 = Tmat0->size[0] * Tmat0->size[1] * Tmat0->size[2];
  Tmat0->size[0] = Coord->size[0];
  Tmat0->size[1] = Coord->size[0];
  Tmat0->size[2] = Coord->size[1] + 1;
  emxEnsureCapacity(sp, (emxArray__common *)Tmat0, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = Coord->size[0] * Coord->size[0] * (Coord->size[1] + 1);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Tmat0->data[i0] = 0.0;
  }

  /*  L x L x d+1 matrix */
  ix = Coord->size[0];
  loop_ub = (int16_T)((int16_T)ix - 1);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    tmp_data[i0] = (int16_T)i0;
  }

  Coord_idx_1 = Coord->size[0];
  loop_ub = (int16_T)((int16_T)Coord_idx_1 - 1);
  for (i0 = 0; i0 <= loop_ub; i0++) {
    b_tmp_data[i0] = (int16_T)i0;
  }

  indx_size[0] = (int16_T)((int16_T)ix - 1) + 1;
  indx_size[1] = (int16_T)((int16_T)Coord_idx_1 - 1) + 1;
  b_Coord[0] = Coord->size[0];
  b_Coord[1] = Coord->size[0];
  emlrtSubAssignSizeCheckR2012b(indx_size, 2, b_Coord, 2, &b_emlrtECI, sp);
  ix = Coord->size[0];
  Coord_idx_1 = Coord->size[0];
  for (i0 = 0; i0 < Coord_idx_1; i0++) {
    for (i1 = 0; i1 < ix; i1++) {
      Tmat0->data[tmp_data[i1] + Tmat0->size[0] * b_tmp_data[i0]] = 1.0;
    }
  }

  dii = 0;
  emxInit_real_T1(sp, &r0, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &y, 2, &emlrtRTEI, true);
  while (dii <= d - 1) {
    /*  go through all dimension */
    i0 = Coord->size[1];
    i1 = dii + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &emlrtBCI, sp);
    }

    loop_ub = Coord->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      SD->f0.Kmat_data[i0] = Coord->data[i0 + Coord->size[0] * dii];
    }

    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = loop_ub;
    r0->size[1] = L;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < L; i1++) {
        r0->data[i0 + r0->size[0] * i1] = SD->f0.Kmat_data[i0];
      }
    }

    i0 = Coord->size[1];
    i1 = dii + 1;
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &b_emlrtBCI, sp);
    }

    loop_ub = Coord->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      SD->f0.Kmat_data[i0] = Coord->data[i0 + Coord->size[0] * dii];
    }

    i0 = y->size[0] * y->size[1];
    y->size[0] = L;
    y->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < L; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        y->data[i0 + y->size[0] * i1] = SD->f0.Kmat_data[i1];
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = r0->size[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      e_y[i0] = y->size[i0];
    }

    if ((iv0[0] != e_y[0]) || (iv0[1] != e_y[1])) {
      emlrtSizeEqCheckNDR2012b(&iv0[0], &e_y[0], &emlrtECI, sp);
    }

    unnamed_idx_0 = (int16_T)((int16_T)Tmat0->size[0] - 1);
    loop_ub = unnamed_idx_0;
    for (i0 = 0; i0 <= loop_ub; i0++) {
      tmp_data[i0] = (int16_T)i0;
    }

    i2 = (int16_T)((int16_T)Tmat0->size[1] - 1);
    loop_ub = i2;
    for (i0 = 0; i0 <= loop_ub; i0++) {
      b_tmp_data[i0] = (int16_T)i0;
    }

    i0 = Tmat0->size[2];
    i1 = (int32_T)((1.0 + (real_T)dii) + 1.0);
    if (!((i1 >= 1) && (i1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, sp);
    }

    iv1[0] = unnamed_idx_0 + 1;
    iv1[1] = i2 + 1;
    emlrtSubAssignSizeCheckR2012b(iv1, 2, *(int32_T (*)[2])r0->size, 2,
      &c_emlrtECI, sp);
    loop_ub = r0->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i = r0->size[0];
      for (i1 = 0; i1 < i; i1++) {
        Tmat0->data[(tmp_data[i1] + Tmat0->size[0] * b_tmp_data[i0]) +
          Tmat0->size[0] * Tmat0->size[1] * (dii + 1)] = r0->data[i1 + r0->size
          [0] * i0] - y->data[i1 + y->size[0] * i0];
      }
    }

    dii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  number of floders */
  linspace(Xdesign->size[0], ind);
  b_floor(ind);
  GCVs_size[0] = 50;
  GCVs_size[1] = Ydesign->size[2];
  nhii = 0;
  emxInit_real_T1(sp, &Kmat, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &Tmat, 3, &e_emlrtRTEI, true);
  emxInit_real_T1(sp, &KX, 2, &f_emlrtRTEI, true);
  emxInit_real_T1(sp, &PX0, 2, &g_emlrtRTEI, true);
  emxInit_real_T1(sp, &b_y, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &a, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &c_y, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &d_y, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Tmat0, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Ydesign, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Xdesign, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &c_Ydesign, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_efitYdesign, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_Tmat, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &d_Ydesign, 3, &emlrtRTEI, true);
  while (nhii < 50) {
    /*  go through all candidate bandwidth */
    i0 = Kmat->size[0] * Kmat->size[1];
    Kmat->size[0] = L;
    Kmat->size[1] = L;
    emxEnsureCapacity(sp, (emxArray__common *)Kmat, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = L * L;
    for (i0 = 0; i0 < loop_ub; i0++) {
      Kmat->data[i0] = 1.0;
    }

    dii = 0;
    while (dii <= d - 1) {
      /*  go through all dimension */
      /*  minimum bandwidth */
      /*  maximum bandwidth */
      /*  candidate bandwidth */
      i0 = Tmat0->size[2];
      i1 = (int32_T)((1.0 + (real_T)dii) + 1.0);
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &d_emlrtBCI, sp);
      }

      loop_ub = Tmat0->size[0];
      i = Tmat0->size[1];
      i0 = b_Tmat0->size[0] * b_Tmat0->size[1];
      b_Tmat0->size[0] = loop_ub;
      b_Tmat0->size[1] = i;
      emxEnsureCapacity(sp, (emxArray__common *)b_Tmat0, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_Tmat0->data[i1 + b_Tmat0->size[0] * i0] = Tmat0->data[(i1 +
            Tmat0->size[0] * i0) + Tmat0->size[0] * Tmat0->size[1] * (dii + 1)] /
            dv0[nhii];
        }
      }

      st.site = &emlrtRSI;
      EpKernel(&st, b_Tmat0, dv0[nhii], r0);
      for (i0 = 0; i0 < 2; i0++) {
        b_Kmat[i0] = Kmat->size[i0];
      }

      for (i0 = 0; i0 < 2; i0++) {
        iv2[i0] = r0->size[i0];
      }

      if ((b_Kmat[0] != iv2[0]) || (b_Kmat[1] != iv2[1])) {
        emlrtSizeEqCheckNDR2012b(&b_Kmat[0], &iv2[0], &d_emlrtECI, sp);
      }

      i0 = Kmat->size[0] * Kmat->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Kmat, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ix = Kmat->size[0];
      Coord_idx_1 = Kmat->size[1];
      loop_ub = ix * Coord_idx_1;
      for (i0 = 0; i0 < loop_ub; i0++) {
        Kmat->data[i0] *= r0->data[i0];
      }

      /*  Epanechnikov kernel smoothing function */
      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    st.site = &b_emlrtRSI;
    permute(&st, Tmat0, Tmat);

    /*  L x d+1 x L matrix */
    mii = 0;
    while (mii <= Ydesign->size[2] - 1) {
      /*  go through all features */
      Lii = 0;
      while (Lii <= L - 1) {
        /*  go through all vertex */
        i0 = Kmat->size[1];
        i1 = Lii + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, sp);
        }

        loop_ub = Kmat->size[0];
        ix = d + 1;
        for (i0 = 0; i0 < loop_ub; i0++) {
          SD->f0.Kmat_data[i0] = Kmat->data[i0 + Kmat->size[0] * Lii];
        }

        i0 = y->size[0] * y->size[1];
        y->size[0] = loop_ub;
        y->size[1] = ix;
        emxEnsureCapacity(sp, (emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          for (i1 = 0; i1 < ix; i1++) {
            y->data[i0 + y->size[0] * i1] = SD->f0.Kmat_data[i0];
          }
        }

        i0 = Tmat->size[2];
        i1 = Lii + 1;
        if (!((i1 >= 1) && (i1 <= i0))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &f_emlrtBCI, sp);
        }

        for (i0 = 0; i0 < 2; i0++) {
          f_y[i0] = y->size[i0];
        }

        loop_ub = Tmat->size[0];
        i = Tmat->size[1];
        i0 = b_Tmat->size[0] * b_Tmat->size[1];
        b_Tmat->size[0] = loop_ub;
        b_Tmat->size[1] = i;
        emxEnsureCapacity(sp, (emxArray__common *)b_Tmat, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        for (i0 = 0; i0 < i; i0++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_Tmat->data[i1 + b_Tmat->size[0] * i0] = Tmat->data[(i1 +
              Tmat->size[0] * i0) + Tmat->size[0] * Tmat->size[1] * Lii];
          }
        }

        for (i0 = 0; i0 < 2; i0++) {
          c_Tmat[i0] = b_Tmat->size[i0];
        }

        if ((f_y[0] != c_Tmat[0]) || (f_y[1] != c_Tmat[1])) {
          emlrtSizeEqCheckNDR2012b(&f_y[0], &c_Tmat[0], &e_emlrtECI, sp);
        }

        i0 = KX->size[0] * KX->size[1];
        KX->size[0] = y->size[0];
        KX->size[1] = y->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)KX, i0, (int32_T)sizeof(real_T),
                          &emlrtRTEI);
        loop_ub = y->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          i = y->size[0];
          for (i1 = 0; i1 < i; i1++) {
            KX->data[i1 + KX->size[0] * i0] = y->data[i1 + y->size[0] * i0] *
              Tmat->data[(i1 + Tmat->size[0] * i0) + Tmat->size[0] * Tmat->size
              [1] * Lii];
          }
        }

        /*  L0 x d+1 matrix */
        kk = 0;
        while (kk < 5) {
          for (i0 = 0; i0 < n; i0++) {
            SD->f0.indx_data[i0] = 1.0;
          }

          if (ind[kk] > ind[1 + kk]) {
            i0 = 0;
            i1 = 0;
          } else {
            if (ind[kk] != (int32_T)muDoubleScalarFloor(ind[kk])) {
              emlrtIntegerCheckR2012b(ind[kk], &emlrtDCI, sp);
            }

            i0 = (int32_T)ind[kk];
            if (!((i0 >= 1) && (i0 <= n))) {
              emlrtDynamicBoundsCheckR2012b(i0, 1, n, &g_emlrtBCI, sp);
            }

            i0--;
            mtmp = ind[1 + kk];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &emlrtDCI, sp);
            }

            i1 = (int32_T)mtmp;
            if (!((i1 >= 1) && (i1 <= n))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, n, &g_emlrtBCI, sp);
            }
          }

          loop_ub = i1 - i0;
          for (dii = 0; dii < loop_ub; dii++) {
            c_tmp_data[dii] = i0 + dii;
          }

          loop_ub = i1 - i0;
          for (i0 = 0; i0 < loop_ub; i0++) {
            SD->f0.indx_data[c_tmp_data[i0]] = 0.0;
          }

          for (i = 0; i < n; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              i0 = Xdesign->size[0];
              if (!((i + 1 >= 1) && (i + 1 <= i0))) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &p_emlrtBCI, sp);
              }
            }
          }

          ix = n - 1;
          b_ix = 0;
          for (i = 0; i <= ix; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              b_ix++;
            }
          }

          cindx = 0;
          for (i = 0; i <= ix; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              c_tmp_data[cindx] = i + 1;
              cindx++;
            }
          }

          st.site = &c_emlrtRSI;
          loop_ub = Xdesign->size[1];
          i0 = a->size[0] * a->size[1];
          a->size[0] = loop_ub;
          a->size[1] = b_ix;
          emxEnsureCapacity(&st, (emxArray__common *)a, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          for (i0 = 0; i0 < b_ix; i0++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              a->data[i1 + a->size[0] * i0] = Xdesign->data[(c_tmp_data[i0] +
                Xdesign->size[0] * i1) - 1];
            }
          }

          loop_ub = Xdesign->size[1];
          i0 = y->size[0] * y->size[1];
          y->size[0] = b_ix;
          y->size[1] = loop_ub;
          emxEnsureCapacity(&st, (emxArray__common *)y, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          for (i0 = 0; i0 < loop_ub; i0++) {
            for (i1 = 0; i1 < b_ix; i1++) {
              y->data[i1 + y->size[0] * i0] = Xdesign->data[(c_tmp_data[i1] +
                Xdesign->size[0] * i0) - 1];
            }
          }

          b_st.site = &u_emlrtRSI;
          if (!(a->size[1] == b_ix)) {
            guard4 = false;
            if ((a->size[0] == 1) && (a->size[1] == 1)) {
              guard4 = true;
            } else {
              i0 = Xdesign->size[1];
              if ((b_ix == 1) && (i0 == 1)) {
                guard4 = true;
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                  "Coder:MATLAB:innerdim", 0);
              }
            }

            if (guard4) {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            }
          }

          if ((a->size[1] == 1) || (b_ix == 1)) {
            i0 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = a->size[0];
            b_y->size[1] = y->size[1];
            emxEnsureCapacity(&st, (emxArray__common *)b_y, i0, (int32_T)sizeof
                              (real_T), &emlrtRTEI);
            loop_ub = a->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              i = y->size[1];
              for (i1 = 0; i1 < i; i1++) {
                b_y->data[i0 + b_y->size[0] * i1] = 0.0;
                ix = a->size[1];
                for (dii = 0; dii < ix; dii++) {
                  b_y->data[i0 + b_y->size[0] * i1] += a->data[i0 + a->size[0] *
                    dii] * y->data[dii + y->size[0] * i1];
                }
              }
            }
          } else {
            i0 = Xdesign->size[1];
            unnamed_idx_0 = (int16_T)a->size[0];
            i1 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = unnamed_idx_0;
            b_y->size[1] = (int16_T)i0;
            emxEnsureCapacity(&st, (emxArray__common *)b_y, i1, (int32_T)sizeof
                              (real_T), &emlrtRTEI);
            loop_ub = b_y->size[1];
            for (i0 = 0; i0 < loop_ub; i0++) {
              i = b_y->size[0];
              for (i1 = 0; i1 < i; i1++) {
                b_y->data[i1 + b_y->size[0] * i0] = 0.0;
              }
            }

            b_st.site = &t_emlrtRSI;
            if (a->size[0] < 1) {
            } else {
              i0 = Xdesign->size[1];
              if ((i0 < 1) || (a->size[1] < 1)) {
              } else {
                mtmp = 1.0;
                beta1 = 0.0;
                TRANSB = 'N';
                TRANSA = 'N';
                m_t = (ptrdiff_t)a->size[0];
                i0 = Xdesign->size[1];
                n_t = (ptrdiff_t)i0;
                k_t = (ptrdiff_t)a->size[1];
                lda_t = (ptrdiff_t)a->size[0];
                ldb_t = (ptrdiff_t)a->size[1];
                ldc_t = (ptrdiff_t)a->size[0];
                dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &a->data[0],
                      &lda_t, &y->data[0], &ldb_t, &beta1, &b_y->data[0], &ldc_t);
              }
            }
          }

          loop_ub = Xdesign->size[1];
          i0 = b_Xdesign->size[0] * b_Xdesign->size[1];
          b_Xdesign->size[0] = loop_ub;
          b_Xdesign->size[1] = b_ix;
          emxEnsureCapacity(sp, (emxArray__common *)b_Xdesign, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          for (i0 = 0; i0 < b_ix; i0++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_Xdesign->data[i1 + b_Xdesign->size[0] * i0] = Xdesign->data
                [(c_tmp_data[i0] + Xdesign->size[0] * i1) - 1];
            }
          }

          st.site = &c_emlrtRSI;
          mldivide(&st, b_y->data, b_y->size, b_Xdesign, PX0);
          for (i = 0; i < n; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              i0 = Ydesign->size[0];
              if (!((i + 1 >= 1) && (i + 1 <= i0))) {
                emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &q_emlrtBCI, sp);
              }
            }
          }

          st.site = &d_emlrtRSI;
          i0 = a->size[0] * a->size[1];
          a->size[0] = KX->size[1];
          a->size[1] = KX->size[0];
          emxEnsureCapacity(&st, (emxArray__common *)a, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = KX->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            i = KX->size[1];
            for (i1 = 0; i1 < i; i1++) {
              a->data[i1 + a->size[0] * i0] = KX->data[i0 + KX->size[0] * i1];
            }
          }

          loop_ub = Tmat->size[0];
          i = Tmat->size[1];
          i0 = Tmat->size[2];
          i1 = 1 + Lii;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &i_emlrtBCI, &st);
          }

          i0 = y->size[0] * y->size[1];
          y->size[0] = loop_ub;
          y->size[1] = i;
          emxEnsureCapacity(&st, (emxArray__common *)y, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          for (i0 = 0; i0 < i; i0++) {
            for (dii = 0; dii < loop_ub; dii++) {
              y->data[dii + y->size[0] * i0] = Tmat->data[(dii + Tmat->size[0] *
                i0) + Tmat->size[0] * Tmat->size[1] * (i1 - 1)];
            }
          }

          b_st.site = &u_emlrtRSI;
          i0 = Tmat->size[0];
          if (!(a->size[1] == i0)) {
            guard3 = false;
            if ((a->size[0] == 1) && (a->size[1] == 1)) {
              guard3 = true;
            } else {
              i0 = Tmat->size[0];
              i1 = Tmat->size[1];
              if ((i0 == 1) && (i1 == 1)) {
                guard3 = true;
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                  "Coder:MATLAB:innerdim", 0);
              }
            }

            if (guard3) {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            }
          }

          guard2 = false;
          if (a->size[1] == 1) {
            guard2 = true;
          } else {
            i0 = Tmat->size[0];
            if (i0 == 1) {
              guard2 = true;
            } else {
              i0 = Tmat->size[1];
              unnamed_idx_0 = (int16_T)a->size[0];
              i1 = c_y->size[0] * c_y->size[1];
              c_y->size[0] = unnamed_idx_0;
              c_y->size[1] = (int16_T)i0;
              emxEnsureCapacity(&st, (emxArray__common *)c_y, i1, (int32_T)
                                sizeof(real_T), &emlrtRTEI);
              loop_ub = c_y->size[1];
              for (i0 = 0; i0 < loop_ub; i0++) {
                i = c_y->size[0];
                for (i1 = 0; i1 < i; i1++) {
                  c_y->data[i1 + c_y->size[0] * i0] = 0.0;
                }
              }

              b_st.site = &t_emlrtRSI;
              i0 = Tmat->size[1];
              if ((i0 < 1) || (a->size[1] < 1)) {
              } else {
                mtmp = 1.0;
                beta1 = 0.0;
                TRANSB = 'N';
                TRANSA = 'N';
                m_t = (ptrdiff_t)a->size[0];
                i0 = Tmat->size[1];
                n_t = (ptrdiff_t)i0;
                k_t = (ptrdiff_t)a->size[1];
                lda_t = (ptrdiff_t)a->size[0];
                ldb_t = (ptrdiff_t)a->size[1];
                ldc_t = (ptrdiff_t)a->size[0];
                dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &a->data[0],
                      &lda_t, &y->data[0], &ldb_t, &beta1, &c_y->data[0], &ldc_t);
              }
            }
          }

          if (guard2) {
            i0 = c_y->size[0] * c_y->size[1];
            c_y->size[0] = a->size[0];
            c_y->size[1] = y->size[1];
            emxEnsureCapacity(&st, (emxArray__common *)c_y, i0, (int32_T)sizeof
                              (real_T), &emlrtRTEI);
            loop_ub = a->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              i = y->size[1];
              for (i1 = 0; i1 < i; i1++) {
                c_y->data[i0 + c_y->size[0] * i1] = 0.0;
                ix = a->size[1];
                for (dii = 0; dii < ix; dii++) {
                  c_y->data[i0 + c_y->size[0] * i1] += a->data[i0 + a->size[0] *
                    dii] * y->data[dii + y->size[0] * i1];
                }
              }
            }
          }

          st.site = &d_emlrtRSI;
          eye(&st, (real_T)d + 1.0, a_data, indx_size);
          loop_ub = indx_size[0] * indx_size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            a_data[i0] *= 0.0001;
          }

          for (i0 = 0; i0 < 2; i0++) {
            g_y[i0] = c_y->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            b_a[i0] = indx_size[i0];
          }

          if ((g_y[0] != b_a[0]) || (g_y[1] != b_a[1])) {
            emlrtSizeEqCheckNDR2012b(&g_y[0], &b_a[0], &f_emlrtECI, sp);
          }

          ix = n - 1;
          b_ix = 0;
          for (i = 0; i <= ix; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              b_ix++;
            }
          }

          cindx = 0;
          for (i = 0; i <= ix; i++) {
            if ((int8_T)SD->f0.indx_data[i] == 1) {
              c_tmp_data[cindx] = i + 1;
              cindx++;
            }
          }

          tmp_size[0] = 1;
          tmp_size[1] = 1 + d;
          d_tmp_data[0] = 1.0;
          for (i0 = 0; i0 < d; i0++) {
            d_tmp_data[i0 + 1] = 0.0;
          }

          y_size[0] = c_y->size[0];
          y_size[1] = c_y->size[1];
          loop_ub = c_y->size[0] * c_y->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_data[i0] = c_y->data[i0] + a_data[i0];
          }

          st.site = &d_emlrtRSI;
          mrdivide(&st, d_tmp_data, tmp_size, y_data, y_size, b_a_data,
                   indx_size);
          st.site = &d_emlrtRSI;
          loop_ub = Ydesign->size[1];
          i0 = Ydesign->size[2];
          i = Ydesign->size[1];
          ix = Ydesign->size[2];
          i1 = 1 + mii;
          if (!((i1 >= 1) && (i1 <= i0))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &h_emlrtBCI, &st);
          }

          i0 = d_Ydesign->size[0] * d_Ydesign->size[1] * d_Ydesign->size[2];
          d_Ydesign->size[0] = b_ix;
          d_Ydesign->size[1] = i;
          d_Ydesign->size[2] = ix;
          emxEnsureCapacity(&st, (emxArray__common *)d_Ydesign, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          for (i0 = 0; i0 < ix; i0++) {
            for (i1 = 0; i1 < i; i1++) {
              for (dii = 0; dii < b_ix; dii++) {
                d_Ydesign->data[(dii + d_Ydesign->size[0] * i1) +
                  d_Ydesign->size[0] * d_Ydesign->size[1] * i0] = Ydesign->data
                  [((c_tmp_data[dii] + Ydesign->size[0] * i1) + Ydesign->size[0]
                    * Ydesign->size[1] * i0) - 1];
              }
            }
          }

          i0 = y->size[0] * y->size[1];
          y->size[0] = b_ix;
          y->size[1] = loop_ub;
          emxEnsureCapacity(&st, (emxArray__common *)y, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          for (i0 = 0; i0 < loop_ub; i0++) {
            for (i1 = 0; i1 < b_ix; i1++) {
              y->data[i1 + y->size[0] * i0] = d_Ydesign->data[(i1 +
                d_Ydesign->size[0] * i0) + d_Ydesign->size[0] * d_Ydesign->size
                [1] * mii];
            }
          }

          b_st.site = &u_emlrtRSI;
          if (!(PX0->size[1] == b_ix)) {
            guard1 = false;
            if ((PX0->size[0] == 1) && (PX0->size[1] == 1)) {
              guard1 = true;
            } else {
              i0 = Ydesign->size[1];
              if ((b_ix == 1) && (i0 == 1)) {
                guard1 = true;
              } else {
                emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                  "Coder:MATLAB:innerdim", 0);
              }
            }

            if (guard1) {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            }
          }

          if ((PX0->size[1] == 1) || (b_ix == 1)) {
            i0 = d_y->size[0] * d_y->size[1];
            d_y->size[0] = PX0->size[0];
            d_y->size[1] = y->size[1];
            emxEnsureCapacity(&st, (emxArray__common *)d_y, i0, (int32_T)sizeof
                              (real_T), &emlrtRTEI);
            loop_ub = PX0->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              i = y->size[1];
              for (i1 = 0; i1 < i; i1++) {
                d_y->data[i0 + d_y->size[0] * i1] = 0.0;
                ix = PX0->size[1];
                for (dii = 0; dii < ix; dii++) {
                  d_y->data[i0 + d_y->size[0] * i1] += PX0->data[i0 + PX0->size
                    [0] * dii] * y->data[dii + y->size[0] * i1];
                }
              }
            }
          } else {
            i0 = Ydesign->size[1];
            unnamed_idx_0 = (int16_T)PX0->size[0];
            i1 = d_y->size[0] * d_y->size[1];
            d_y->size[0] = unnamed_idx_0;
            d_y->size[1] = (int16_T)i0;
            emxEnsureCapacity(&st, (emxArray__common *)d_y, i1, (int32_T)sizeof
                              (real_T), &emlrtRTEI);
            loop_ub = d_y->size[1];
            for (i0 = 0; i0 < loop_ub; i0++) {
              i = d_y->size[0];
              for (i1 = 0; i1 < i; i1++) {
                d_y->data[i1 + d_y->size[0] * i0] = 0.0;
              }
            }

            b_st.site = &t_emlrtRSI;
            if (PX0->size[0] < 1) {
            } else {
              i0 = Ydesign->size[1];
              if ((i0 < 1) || (PX0->size[1] < 1)) {
              } else {
                mtmp = 1.0;
                beta1 = 0.0;
                TRANSB = 'N';
                TRANSA = 'N';
                m_t = (ptrdiff_t)PX0->size[0];
                i0 = Ydesign->size[1];
                n_t = (ptrdiff_t)i0;
                k_t = (ptrdiff_t)PX0->size[1];
                lda_t = (ptrdiff_t)PX0->size[0];
                ldb_t = (ptrdiff_t)PX0->size[1];
                ldc_t = (ptrdiff_t)PX0->size[0];
                dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &PX0->data[0],
                      &lda_t, &y->data[0], &ldb_t, &beta1, &d_y->data[0], &ldc_t);
              }
            }
          }

          st.site = &d_emlrtRSI;
          i0 = b->size[0] * b->size[1];
          b->size[0] = KX->size[1];
          b->size[1] = KX->size[0];
          emxEnsureCapacity(&st, (emxArray__common *)b, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = KX->size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            i = KX->size[1];
            for (i1 = 0; i1 < i; i1++) {
              b->data[i1 + b->size[0] * i0] = KX->data[i0 + KX->size[0] * i1];
            }
          }

          b_st.site = &u_emlrtRSI;
          if (!(indx_size[1] == b->size[0])) {
            if ((indx_size[1] == 1) || ((b->size[0] == 1) && (b->size[1] == 1)))
            {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                "Coder:MATLAB:innerdim", 0);
            }
          }

          if ((indx_size[1] == 1) || (b->size[0] == 1)) {
            ix = b->size[1];
            loop_ub = b->size[1];
            for (i0 = 0; i0 < loop_ub; i0++) {
              SD->f0.y_data[i0] = 0.0;
              i = indx_size[1];
              for (i1 = 0; i1 < i; i1++) {
                SD->f0.y_data[i0] += b_a_data[indx_size[0] * i1] * b->data[i1 +
                  b->size[0] * i0];
              }
            }
          } else {
            unnamed_idx_0 = (int16_T)b->size[1];
            ix = unnamed_idx_0;
            loop_ub = unnamed_idx_0;
            for (i0 = 0; i0 < loop_ub; i0++) {
              SD->f0.y_data[i0] = 0.0;
            }

            b_st.site = &t_emlrtRSI;
            if (!(b->size[1] < 1)) {
              mtmp = 1.0;
              beta1 = 0.0;
              TRANSB = 'N';
              TRANSA = 'N';
              m_t = (ptrdiff_t)1;
              n_t = (ptrdiff_t)b->size[1];
              k_t = (ptrdiff_t)indx_size[1];
              lda_t = (ptrdiff_t)1;
              ldb_t = (ptrdiff_t)indx_size[1];
              ldc_t = (ptrdiff_t)1;
              dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &b_a_data[0],
                    &lda_t, &b->data[0], &ldb_t, &beta1, &SD->f0.y_data[0],
                    &ldc_t);
            }
          }

          st.site = &d_emlrtRSI;
          i0 = y->size[0] * y->size[1];
          y->size[0] = d_y->size[0];
          y->size[1] = d_y->size[1];
          emxEnsureCapacity(&st, (emxArray__common *)y, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = d_y->size[0] * d_y->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            y->data[i0] = d_y->data[i0];
          }

          for (i0 = 0; i0 < ix; i0++) {
            b_data[i0] = SD->f0.y_data[i0];
          }

          b_st.site = &u_emlrtRSI;
          if (!(d_y->size[1] == ix)) {
            if (((d_y->size[0] == 1) && (d_y->size[1] == 1)) || (ix == 1)) {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                "Coder:MATLAB:innerdim", 0);
            }
          }

          if ((d_y->size[1] == 1) || (ix == 1)) {
            cindx = d_y->size[0];
            loop_ub = d_y->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              efitBetas0_data[i0] = 0.0;
              i = d_y->size[1];
              for (i1 = 0; i1 < i; i1++) {
                mtmp = efitBetas0_data[i0] + d_y->data[i0 + d_y->size[0] * i1] *
                  b_data[i1];
                efitBetas0_data[i0] = mtmp;
              }
            }
          } else {
            y_idx_0 = (int8_T)d_y->size[0];
            ix = y_idx_0;
            cindx = y_idx_0;
            for (i0 = 0; i0 < ix; i0++) {
              efitBetas0_data[i0] = 0.0;
            }

            b_st.site = &t_emlrtRSI;
            if ((d_y->size[0] < 1) || (d_y->size[1] < 1)) {
            } else {
              mtmp = 1.0;
              beta1 = 0.0;
              TRANSB = 'N';
              TRANSA = 'N';
              m_t = (ptrdiff_t)d_y->size[0];
              n_t = (ptrdiff_t)1;
              k_t = (ptrdiff_t)d_y->size[1];
              lda_t = (ptrdiff_t)d_y->size[0];
              ldb_t = (ptrdiff_t)d_y->size[1];
              ldc_t = (ptrdiff_t)d_y->size[0];
              dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &y->data[0],
                    &lda_t, &b_data[0], &ldb_t, &beta1, &efitBetas0_data[0],
                    &ldc_t);
            }
          }

          if (ind[kk] > ind[1 + kk]) {
            i1 = 1;
            i0 = 1;
            b_ix = 1;
            Coord_idx_1 = 0;
          } else {
            if (ind[kk] != (int32_T)muDoubleScalarFloor(ind[kk])) {
              emlrtIntegerCheckR2012b(ind[kk], &b_emlrtDCI, sp);
            }

            i0 = Xdesign->size[0];
            i1 = (int32_T)ind[kk];
            if (!((i1 >= 1) && (i1 <= i0))) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &j_emlrtBCI, sp);
            }

            mtmp = ind[1 + kk];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &b_emlrtDCI, sp);
            }

            i0 = Xdesign->size[0];
            dii = (int32_T)mtmp;
            if (!((dii >= 1) && (dii <= i0))) {
              emlrtDynamicBoundsCheckR2012b(dii, 1, i0, &j_emlrtBCI, sp);
            }

            i0 = dii + 1;
            if (ind[kk] != (int32_T)muDoubleScalarFloor(ind[kk])) {
              emlrtIntegerCheckR2012b(ind[kk], &c_emlrtDCI, sp);
            }

            dii = efitYdesign->size[0];
            b_ix = (int32_T)ind[kk];
            if (!((b_ix >= 1) && (b_ix <= dii))) {
              emlrtDynamicBoundsCheckR2012b(b_ix, 1, dii, &l_emlrtBCI, sp);
            }

            mtmp = ind[1 + kk];
            if (mtmp != (int32_T)muDoubleScalarFloor(mtmp)) {
              emlrtIntegerCheckR2012b(mtmp, &c_emlrtDCI, sp);
            }

            dii = efitYdesign->size[0];
            Coord_idx_1 = (int32_T)mtmp;
            if (!((Coord_idx_1 >= 1) && (Coord_idx_1 <= dii))) {
              emlrtDynamicBoundsCheckR2012b(Coord_idx_1, 1, dii, &l_emlrtBCI, sp);
            }
          }

          loop_ub = (int16_T)((int16_T)Coord_idx_1 - (int16_T)b_ix);
          for (dii = 0; dii <= loop_ub; dii++) {
            tmp_data[dii] = (int16_T)((int16_T)((int16_T)b_ix + dii) - 1);
          }

          dii = efitYdesign->size[1];
          ix = Lii + 1;
          if (!((ix >= 1) && (ix <= dii))) {
            emlrtDynamicBoundsCheckR2012b(ix, 1, dii, &m_emlrtBCI, sp);
          }

          dii = efitYdesign->size[2];
          ix = mii + 1;
          if (!((ix >= 1) && (ix <= dii))) {
            emlrtDynamicBoundsCheckR2012b(ix, 1, dii, &n_emlrtBCI, sp);
          }

          st.site = &e_emlrtRSI;
          loop_ub = Xdesign->size[1];
          dii = y->size[0] * y->size[1];
          y->size[0] = i0 - i1;
          y->size[1] = loop_ub;
          emxEnsureCapacity(&st, (emxArray__common *)y, dii, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          for (dii = 0; dii < loop_ub; dii++) {
            i = i0 - i1;
            for (ix = 0; ix < i; ix++) {
              y->data[ix + y->size[0] * dii] = Xdesign->data[((i1 + ix) +
                Xdesign->size[0] * dii) - 1];
            }
          }

          b_st.site = &u_emlrtRSI;
          dii = Xdesign->size[1];
          if (!(dii == cindx)) {
            dii = Xdesign->size[1];
            if (((i0 - i1 == 1) && (dii == 1)) || (cindx == 1)) {
              emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI,
                "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
            } else {
              emlrtErrorWithMessageIdR2012b(&b_st, &q_emlrtRTEI,
                "Coder:MATLAB:innerdim", 0);
            }
          }

          dii = Xdesign->size[1];
          if ((dii == 1) || (cindx == 1)) {
            C_size[0] = y->size[0];
            loop_ub = y->size[0];
            for (i0 = 0; i0 < loop_ub; i0++) {
              C_data[i0] = 0.0;
              i = y->size[1];
              for (i1 = 0; i1 < i; i1++) {
                mtmp = C_data[i0] + y->data[i0 + y->size[0] * i1] *
                  efitBetas0_data[i1];
                C_data[i0] = mtmp;
              }
            }
          } else {
            ix = (int16_T)(i0 - i1);
            C_size[0] = (int16_T)(i0 - i1);
            for (dii = 0; dii < ix; dii++) {
              C_data[dii] = 0.0;
            }

            b_st.site = &t_emlrtRSI;
            if (i0 - i1 < 1) {
            } else {
              dii = Xdesign->size[1];
              if (dii < 1) {
              } else {
                mtmp = 1.0;
                beta1 = 0.0;
                TRANSB = 'N';
                TRANSA = 'N';
                m_t = (ptrdiff_t)(i0 - i1);
                n_t = (ptrdiff_t)1;
                dii = Xdesign->size[1];
                k_t = (ptrdiff_t)dii;
                lda_t = (ptrdiff_t)(i0 - i1);
                dii = Xdesign->size[1];
                ldb_t = (ptrdiff_t)dii;
                ldc_t = (ptrdiff_t)(i0 - i1);
                dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &y->data[0],
                      &lda_t, &efitBetas0_data[0], &ldb_t, &beta1, &C_data[0],
                      &ldc_t);
              }
            }
          }

          iv3[0] = (int16_T)((int16_T)Coord_idx_1 - (int16_T)b_ix) + 1;
          emlrtSubAssignSizeCheckR2012b(iv3, 1, C_size, 1, &g_emlrtECI, sp);
          loop_ub = C_size[0];
          for (i0 = 0; i0 < loop_ub; i0++) {
            efitYdesign->data[(tmp_data[i0] + efitYdesign->size[0] * Lii) +
              efitYdesign->size[0] * efitYdesign->size[1] * mii] = C_data[i0];
          }

          kk++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        Lii++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      i0 = Ydesign->size[2];
      i1 = mii + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &k_emlrtBCI, sp);
      }

      i0 = efitYdesign->size[2];
      i1 = mii + 1;
      if (!((i1 >= 1) && (i1 <= i0))) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, sp);
      }

      loop_ub = Ydesign->size[0];
      i = Ydesign->size[1];
      i0 = c_Ydesign->size[0] * c_Ydesign->size[1];
      c_Ydesign->size[0] = loop_ub;
      c_Ydesign->size[1] = i;
      emxEnsureCapacity(sp, (emxArray__common *)c_Ydesign, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_Ydesign->data[i1 + c_Ydesign->size[0] * i0] = Ydesign->data[(i1 +
            Ydesign->size[0] * i0) + Ydesign->size[0] * Ydesign->size[1] * mii];
        }
      }

      for (i0 = 0; i0 < 2; i0++) {
        e_Ydesign[i0] = c_Ydesign->size[i0];
      }

      loop_ub = efitYdesign->size[0];
      i = efitYdesign->size[1];
      i0 = b_efitYdesign->size[0] * b_efitYdesign->size[1];
      b_efitYdesign->size[0] = loop_ub;
      b_efitYdesign->size[1] = i;
      emxEnsureCapacity(sp, (emxArray__common *)b_efitYdesign, i0, (int32_T)
                        sizeof(real_T), &emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_efitYdesign->data[i1 + b_efitYdesign->size[0] * i0] =
            efitYdesign->data[(i1 + efitYdesign->size[0] * i0) +
            efitYdesign->size[0] * efitYdesign->size[1] * mii];
        }
      }

      for (i0 = 0; i0 < 2; i0++) {
        c_efitYdesign[i0] = b_efitYdesign->size[i0];
      }

      if ((e_Ydesign[0] != c_efitYdesign[0]) || (e_Ydesign[1] != c_efitYdesign[1]))
      {
        emlrtSizeEqCheckNDR2012b(&e_Ydesign[0], &c_efitYdesign[0], &h_emlrtECI,
          sp);
      }

      loop_ub = Ydesign->size[0];
      i = Ydesign->size[1];
      i0 = b_Ydesign->size[0] * b_Ydesign->size[1];
      b_Ydesign->size[0] = loop_ub;
      b_Ydesign->size[1] = i;
      emxEnsureCapacity(sp, (emxArray__common *)b_Ydesign, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_Ydesign->data[i1 + b_Ydesign->size[0] * i0] = Ydesign->data[(i1 +
            Ydesign->size[0] * i0) + Ydesign->size[0] * Ydesign->size[1] * mii]
            - efitYdesign->data[(i1 + efitYdesign->size[0] * i0) +
            efitYdesign->size[0] * efitYdesign->size[1] * mii];
        }
      }

      st.site = &f_emlrtRSI;
      power(&st, b_Ydesign, r0);
      st.site = &f_emlrtRSI;
      sum(&st, r0, SD->f0.indx_data, indx_size);
      st.site = &f_emlrtRSI;
      mtmp = b_sum(&st, SD->f0.indx_data, indx_size);
      i0 = 1 + mii;
      if (!((i0 >= 1) && (i0 <= GCVs_size[1]))) {
        emlrtDynamicBoundsCheckR2012b(i0, 1, GCVs_size[1], &r_emlrtBCI, sp);
      }

      GCVs_data[nhii + 50 * (i0 - 1)] = mtmp / (real_T)(n * L);
      mii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    nhii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&d_Ydesign);
  emxFree_real_T(&b_Tmat);
  emxFree_real_T(&b_efitYdesign);
  emxFree_real_T(&c_Ydesign);
  emxFree_real_T(&b_Xdesign);
  emxFree_real_T(&b_Ydesign);
  emxFree_real_T(&b_Tmat0);
  emxFree_real_T(&b);
  emxFree_real_T(&d_y);
  emxFree_real_T(&c_y);
  emxFree_real_T(&a);
  emxFree_real_T(&b_y);
  emxFree_real_T(&y);
  emxFree_real_T(&r0);
  emxFree_real_T(&PX0);
  emxFree_real_T(&KX);
  emxFree_real_T(&Tmat);
  emxFree_real_T(&Kmat);
  emxFree_real_T(&Tmat0);
  emxFree_real_T(&efitYdesign);
  st.site = &g_emlrtRSI;
  b_st.site = &jd_emlrtRSI;
  loop_ub = (int8_T)GCVs_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    iindx_data[i0] = 1;
  }

  for (i = 0; i + 1 <= GCVs_size[1]; i++) {
    ix = i * 50;
    Coord_idx_1 = i * 50 + 1;
    mtmp = GCVs_data[ix];
    dii = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(GCVs_data[ix])) {
      b_ix = Coord_idx_1;
      exitg1 = false;
      while ((!exitg1) && (b_ix + 1 <= ix + 50)) {
        cindx++;
        Coord_idx_1 = b_ix + 1;
        if (!muDoubleScalarIsNaN(GCVs_data[b_ix])) {
          mtmp = GCVs_data[b_ix];
          dii = cindx;
          exitg1 = true;
        } else {
          b_ix++;
        }
      }
    }

    if (Coord_idx_1 < ix + 50) {
      while (Coord_idx_1 + 1 <= ix + 50) {
        cindx++;
        if (GCVs_data[Coord_idx_1] < mtmp) {
          mtmp = GCVs_data[Coord_idx_1];
          dii = cindx;
        }

        Coord_idx_1++;
      }
    }

    iindx_data[i] = dii;
  }

  flag_size[0] = 1;
  flag_size[1] = (int8_T)GCVs_size[1];
  loop_ub = (int8_T)GCVs_size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    flag_data[i0] = iindx_data[i0];
  }

  /*  optimal bandwidth */
  /* mh=vh(flag);   % optimal bandwidth */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (stat_lpks_wob.c) */
