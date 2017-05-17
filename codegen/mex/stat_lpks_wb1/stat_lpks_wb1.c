/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1.c
 *
 * Code generation for function 'stat_lpks_wb1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "EpKernel.h"
#include "mrdivide.h"
#include "permute.h"
#include "mldivide.h"
#include "stat_lpks_wb1_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 43,    /* lineNo */
  "stat_lpks_wb1",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wb1.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 55,  /* lineNo */
  "stat_lpks_wb1",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wb1.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 62,  /* lineNo */
  "stat_lpks_wb1",                     /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wb1.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  50,                                  /* iLast */
  54,                                  /* lineNo */
  11,                                  /* colNo */
  "vh",                                /* aName */
  "stat_lpks_wb1",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wb1.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 54,    /* lineNo */
  11,                                  /* colNo */
  "stat_lpks_wb1",                     /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_lpks_wb1.m",/* pName */
  1                                    /* checkKind */
};

/* Function Definitions */
void stat_lpks_wb1(stat_lpks_wb1StackData *SD, const emlrtStack *sp, const
                   real_T Coord[3006], const real_T Xdesign[200], const real_T
                   Ydesign[120240], const real_T flag[3], real_T efitBetas[15030],
                   real_T efitYdesign[120240])
{
  int32_T i0;
  int32_T dii;
  int32_T i1;
  real_T PX0[200];
  real_T alpha1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  real_T dv1[25];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T mii;
  real_T b[5010];
  real_T Kmat[4008];
  real_T KX[4008];
  static const real_T dv2[50] = { 0.01, 0.010985411419875583,
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

  real_T b_b[4008];
  real_T y[16];
  real_T a[4];
  real_T b_y[16];
  static const int8_T iv0[4] = { 1, 0, 0, 0 };

  static const real_T c_y[16] = { 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
    0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0001 };

  real_T d_y[1002];
  real_T c_b[1002];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  stat_lpks_wb1 is to implement Zhu's (2010) method of local polynomial kernel smoothing (order = 1) with preselected bandwidth */
  /*  */
  /*  Input: */
  /*      Coord      - a L x d matrix of the coordinates of all vertices aligned on the sphere. */
  /*      Xdesign    - a n x p0 normalized design matrix. */
  /*      Ydesign    - a n x L x m matrix of surface shape data. */
  /*      flag       - a 1 x m vector of indice for optimal bandwidth. */
  /*  Output: */
  /*      efitBetas    - a p0 x L x m matrix of estimated coefficients. */
  /*      efitYdesign  - a n x L x m matrix of estimated shape measuments. */
  /*  Reference: */
  /*  Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012.  */
  /*  doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533. */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Please run */
  /*     [flag,GCVs,vh] = stat_lpks_wob(Coord,Xdesign,Ydesign) */
  /*  before you use stat_lpks_wb1 */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  March, 2017 @ Chao Huang */
  /*  */
  /*  SetUp */
  /*    n  = sample size    p0  = number of covariates */
  /*    L = number of vertices     d  = dimension of corrdinate */
  /*    m  = number of shape features (here m=d) */
  memset(&efitBetas[0], 0, 15030U * sizeof(real_T));

  /*  p0 x L x m matrix of estimated coefficients */
  /*  n x L x m matrix of estimated shape measuments */
  /*  Optimal bandwidth */
  /*  the number of candidate bandwidth */
  memset(&SD->f1.Tmat0[0], 0, 4016016U * sizeof(real_T));

  /*  L x L x d+1 matrix */
  for (i0 = 0; i0 < 1002; i0++) {
    for (i1 = 0; i1 < 1002; i1++) {
      SD->f1.Tmat0[i1 + 1002 * i0] = 1.0;
    }
  }

  dii = 0;
  while (dii < 3) {
    /*  go through all dimension */
    for (i0 = 0; i0 < 1002; i0++) {
      for (i1 = 0; i1 < 1002; i1++) {
        SD->f1.Kmat[i0 + 1002 * i1] = Coord[i0 + 1002 * dii];
        SD->f1.dv0[i0 + 1002 * i1] = Coord[i1 + 1002 * dii];
      }
    }

    for (i0 = 0; i0 < 1002; i0++) {
      for (i1 = 0; i1 < 1002; i1++) {
        SD->f1.Tmat0[(i1 + 1002 * i0) + 1004004 * (dii + 1)] = SD->f1.Kmat[i1 +
          1002 * i0] - SD->f1.dv0[i1 + 1002 * i0];
      }
    }

    dii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i0 = 0; i0 < 40; i0++) {
    for (i1 = 0; i1 < 5; i1++) {
      PX0[i1 + 5 * i0] = Xdesign[i0 + 40 * i1];
    }
  }

  alpha1 = 1.0;
  beta1 = 0.0;
  TRANSB = 'N';
  TRANSA = 'N';
  memset(&dv1[0], 0, 25U * sizeof(real_T));
  m_t = (ptrdiff_t)5;
  n_t = (ptrdiff_t)5;
  k_t = (ptrdiff_t)40;
  lda_t = (ptrdiff_t)5;
  ldb_t = (ptrdiff_t)40;
  ldc_t = (ptrdiff_t)5;
  dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &PX0[0], &lda_t, &Xdesign[0],
        &ldb_t, &beta1, &dv1[0], &ldc_t);
  for (i0 = 0; i0 < 40; i0++) {
    for (i1 = 0; i1 < 5; i1++) {
      PX0[i1 + 5 * i0] = Xdesign[i0 + 40 * i1];
    }
  }

  st.site = &emlrtRSI;
  mldivide(&st, dv1, PX0);

  /*   'hat' matrix */
  mii = 0;
  while (mii < 3) {
    /*  go through all features */
    for (i0 = 0; i0 < 1004004; i0++) {
      SD->f1.Kmat[i0] = 1.0;
    }

    dii = 0;
    while (dii < 3) {
      /*  go through all dimension */
      /*  minimum bandwidth */
      /*  maximum bandwidth */
      /*  candidate bandwidth */
      if (flag[mii] != (int32_T)muDoubleScalarFloor(flag[mii])) {
        emlrtIntegerCheckR2012b(flag[mii], &emlrtDCI, sp);
      }

      i0 = (int32_T)flag[mii];
      if (!((i0 >= 1) && (i0 <= 50))) {
        emlrtDynamicBoundsCheckR2012b(i0, 1, 50, &emlrtBCI, sp);
      }

      for (i0 = 0; i0 < 1002; i0++) {
        for (i1 = 0; i1 < 1002; i1++) {
          SD->f1.b_Tmat0[i1 + 1002 * i0] = SD->f1.Tmat0[(i1 + 1002 * i0) +
            1004004 * (dii + 1)] / dv2[(int32_T)flag[mii] - 1];
        }
      }

      st.site = &b_emlrtRSI;
      EpKernel(SD, &st, SD->f1.b_Tmat0, dv2[(int32_T)flag[mii] - 1], SD->f1.dv0);
      for (i0 = 0; i0 < 1004004; i0++) {
        SD->f1.Kmat[i0] *= SD->f1.dv0[i0];
      }

      /*  Epanechnikov kernel smoothing function */
      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    permute(SD->f1.Tmat0, SD->f1.Tmat);

    /*  L0 x d+1 x L0 matrix */
    dii = 0;
    while (dii < 1002) {
      /*  go through all vertex */
      for (i0 = 0; i0 < 1002; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          Kmat[i0 + 1002 * i1] = SD->f1.Kmat[i0 + 1002 * dii];
        }
      }

      for (i0 = 0; i0 < 4; i0++) {
        for (i1 = 0; i1 < 1002; i1++) {
          KX[i1 + 1002 * i0] = Kmat[i1 + 1002 * i0] * SD->f1.Tmat[(i1 + 1002 *
            i0) + 4008 * dii];
        }
      }

      /*  L0 x d+1 matrix */
      for (i0 = 0; i0 < 1002; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          Kmat[i1 + (i0 << 2)] = KX[i0 + 1002 * i1];
        }
      }

      for (i0 = 0; i0 < 4; i0++) {
        memcpy(&b_b[i0 * 1002], &SD->f1.Tmat[i0 * 1002 + dii * 4008], 1002U *
               sizeof(real_T));
      }

      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      memset(&y[0], 0, sizeof(real_T) << 4);
      m_t = (ptrdiff_t)4;
      n_t = (ptrdiff_t)4;
      k_t = (ptrdiff_t)1002;
      lda_t = (ptrdiff_t)4;
      ldb_t = (ptrdiff_t)1002;
      ldc_t = (ptrdiff_t)4;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Kmat[0], &lda_t, &b_b
            [0], &ldb_t, &beta1, &y[0], &ldc_t);
      for (i0 = 0; i0 < 4; i0++) {
        a[i0] = iv0[i0];
      }

      for (i0 = 0; i0 < 16; i0++) {
        b_y[i0] = y[i0] + c_y[i0];
      }

      st.site = &c_emlrtRSI;
      mrdivide(&st, a, b_y);
      for (i0 = 0; i0 < 1002; i0++) {
        memcpy(&SD->f1.b[i0 * 40], &Ydesign[i0 * 40 + mii * 40080], 40U * sizeof
               (real_T));
      }

      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      memset(&b[0], 0, 5010U * sizeof(real_T));
      m_t = (ptrdiff_t)5;
      n_t = (ptrdiff_t)1002;
      k_t = (ptrdiff_t)40;
      lda_t = (ptrdiff_t)5;
      ldb_t = (ptrdiff_t)40;
      ldc_t = (ptrdiff_t)5;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &PX0[0], &lda_t,
            &SD->f1.b[0], &ldb_t, &beta1, &b[0], &ldc_t);
      for (i0 = 0; i0 < 1002; i0++) {
        for (i1 = 0; i1 < 4; i1++) {
          Kmat[i1 + (i0 << 2)] = KX[i0 + 1002 * i1];
        }
      }

      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      memset(&d_y[0], 0, 1002U * sizeof(real_T));
      m_t = (ptrdiff_t)1;
      n_t = (ptrdiff_t)1002;
      k_t = (ptrdiff_t)4;
      lda_t = (ptrdiff_t)1;
      ldb_t = (ptrdiff_t)4;
      ldc_t = (ptrdiff_t)1;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &Kmat[0],
            &ldb_t, &beta1, &d_y[0], &ldc_t);
      memcpy(&c_b[0], &d_y[0], 1002U * sizeof(real_T));
      for (i0 = 0; i0 < 5; i0++) {
        efitBetas[(i0 + 5 * dii) + 5010 * mii] = 0.0;
      }

      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)5;
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)1002;
      lda_t = (ptrdiff_t)5;
      ldb_t = (ptrdiff_t)1002;
      ldc_t = (ptrdiff_t)5;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &b[0], &lda_t, &c_b[0],
            &ldb_t, &beta1, &efitBetas[5 * dii + 5010 * mii], &ldc_t);
      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    for (i0 = 0; i0 < 1002; i0++) {
      for (i1 = 0; i1 < 5; i1++) {
        b[i1 + 5 * i0] = efitBetas[(i1 + 5 * i0) + 5010 * mii];
      }
    }

    for (i0 = 0; i0 < 1002; i0++) {
      memset(&efitYdesign[i0 * 40 + mii * 40080], 0, 40U * sizeof(real_T));
    }

    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB = 'N';
    TRANSA = 'N';
    m_t = (ptrdiff_t)40;
    n_t = (ptrdiff_t)1002;
    k_t = (ptrdiff_t)5;
    lda_t = (ptrdiff_t)40;
    ldb_t = (ptrdiff_t)5;
    ldc_t = (ptrdiff_t)40;
    dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Xdesign[0], &lda_t, &b[0],
          &ldb_t, &beta1, &efitYdesign[40080 * mii], &ldc_t);
    mii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (stat_lpks_wb1.c) */
