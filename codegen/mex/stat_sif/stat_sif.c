/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif.c
 *
 * Code generation for function 'stat_sif'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "EpKernel.h"
#include "power.h"
#include "mrdivide.h"
#include "sum.h"
#include "permute.h"
#include "squeeze.h"
#include "stat_sif_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 51,    /* lineNo */
  "stat_sif",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 59,  /* lineNo */
  "stat_sif",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 61,  /* lineNo */
  "stat_sif",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 83,  /* lineNo */
  "stat_sif",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 90,  /* lineNo */
  "stat_sif",                          /* fcnName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  50,                                  /* iLast */
  82,                                  /* lineNo */
  11,                                  /* colNo */
  "vh",                                /* aName */
  "stat_sif",                          /* fName */
  "C:\\Users\\Administrator\\Desktop\\SALT_STAT\\stat_sif.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void stat_sif(stat_sifStackData *SD, const emlrtStack *sp, const real_T Coord
              [3006], const real_T ResYdesign[120240], real_T efitEtas[120240],
              real_T ResEtas[120240], real_T eSigEta[9036036])
{
  int32_T cindx;
  int32_T dii;
  int32_T ix;
  real_T GCVs[150];
  int32_T b_ix;
  int32_T iindx[3];
  int32_T indx[3];
  int32_T mii;
  real_T alpha1;
  int32_T L0ii;
  static const real_T dv1[50] = { 0.01, 0.010985411419875583,
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

  boolean_T exitg1;
  real_T Kmat[4008];
  real_T dv2[1002];
  real_T KX[4008];
  real_T b[4008];
  real_T b_efitEtas[120];
  real_T dv3[120];
  real_T c_efitEtas[120];
  real_T dv4[120];
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  real_T y[16];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  real_T b_y[16];
  real_T a[4];
  static const real_T c_y[16] = { 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0001, 0.0, 0.0,
    0.0, 0.0, 0.0001, 0.0, 0.0, 0.0, 0.0, 0.0001 };

  real_T d_y[1002];
  real_T b_b[1002];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /*  stat_sif is to implement Zhu's (2010) method of smoothing individual function without preselected bandwidth */
  /*  */
  /*  Input: */
  /*      Coord       - a L x d matrix of the coordinates of all vertices aligned on the sphere. */
  /*      ResYdesign  - a n x L x m matrix of difference between observed shape measurements and fitted measurements. */
  /*  Output: */
  /*      efitEtas    - a n x L x m matrix of estimated eta. */
  /*      ResEtas     - a n x L x m matrix of of difference between ResYdesign and fitted eta. */
  /*      eSigEta     - a m x m x L x L matrix of covariance matrix of etas. */
  /*  Reference: */
  /*  Zhu, Hongtu; Li, Runze; Kong, Linglong. Multivariate varying coefficient model for functional responses. Ann. Statist. 40, 2634--2666, 2012.  */
  /*  doi:10.1214/12-AOS1045. http://projecteuclid.org/euclid.aos/1359987533. */
  /*  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  Please run */
  /*     [efitBetas,efitYdesign] =stat_lpks_wb1(Coord,Xdesign,Ydesign,flag) */
  /*  before you use stat_sif */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  March, 2017 @ Chao Huang */
  /*  */
  /*  bandwidth SetUp */
  /*    L = number of vertices    d  = dimension of corrdinate */
  /*  the number of candidate bandwidth */
  /*  GCV performance function */
  memset(&efitEtas[0], 0, 120240U * sizeof(real_T));

  /*  GCV */
  memset(&SD->f2.Tmat0[0], 0, 4016016U * sizeof(real_T));

  /*  L x L x d+1 matrix */
  for (cindx = 0; cindx < 1002; cindx++) {
    for (ix = 0; ix < 1002; ix++) {
      SD->f2.Tmat0[ix + 1002 * cindx] = 1.0;
    }
  }

  dii = 0;
  while (dii < 3) {
    /*  go through all dimension */
    for (cindx = 0; cindx < 1002; cindx++) {
      for (ix = 0; ix < 1002; ix++) {
        SD->f2.Kmat[cindx + 1002 * ix] = Coord[cindx + 1002 * dii];
        SD->f2.dv0[cindx + 1002 * ix] = Coord[ix + 1002 * dii];
      }
    }

    for (cindx = 0; cindx < 1002; cindx++) {
      for (ix = 0; ix < 1002; ix++) {
        SD->f2.Tmat0[(ix + 1002 * cindx) + 1004004 * (dii + 1)] = SD->f2.Kmat[ix
          + 1002 * cindx] - SD->f2.dv0[ix + 1002 * cindx];
      }
    }

    dii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  b_ix = 0;
  while (b_ix < 50) {
    /*  go through all candidate bandwidth */
    for (cindx = 0; cindx < 1004004; cindx++) {
      SD->f2.Kmat[cindx] = 1.0;
    }

    dii = 0;
    while (dii < 3) {
      /*  go through all dimension */
      /*  minimum bandwidth */
      /*  maximum bandwidth */
      /*  candidate bandwidth */
      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 1002; ix++) {
          SD->f2.b_Tmat0[ix + 1002 * cindx] = SD->f2.Tmat0[(ix + 1002 * cindx) +
            1004004 * (dii + 1)] / dv1[b_ix];
        }
      }

      st.site = &emlrtRSI;
      EpKernel(SD, &st, SD->f2.b_Tmat0, dv1[b_ix], SD->f2.dv0);
      for (cindx = 0; cindx < 1004004; cindx++) {
        SD->f2.Kmat[cindx] *= SD->f2.dv0[cindx];
      }

      /*  Epanechnikov kernel smoothing function */
      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    permute(SD->f2.Tmat0, SD->f2.Tmat);

    /*  L0 x d+1 x L0 matrix */
    mii = 0;
    while (mii < 3) {
      /*  go through all features */
      L0ii = 0;
      while (L0ii < 1002) {
        /*  go through all vertex */
        for (cindx = 0; cindx < 1002; cindx++) {
          for (ix = 0; ix < 4; ix++) {
            Kmat[cindx + 1002 * ix] = SD->f2.Kmat[cindx + 1002 * L0ii];
          }
        }

        for (cindx = 0; cindx < 4; cindx++) {
          for (ix = 0; ix < 1002; ix++) {
            KX[ix + 1002 * cindx] = Kmat[ix + 1002 * cindx] * SD->f2.Tmat[(ix +
              1002 * cindx) + 4008 * L0ii];
          }
        }

        /*  L0 x d+1 matrix */
        for (cindx = 0; cindx < 1002; cindx++) {
          for (ix = 0; ix < 4; ix++) {
            Kmat[ix + (cindx << 2)] = KX[cindx + 1002 * ix];
          }
        }

        for (cindx = 0; cindx < 4; cindx++) {
          memcpy(&b[cindx * 1002], &SD->f2.Tmat[cindx * 1002 + L0ii * 4008],
                 1002U * sizeof(real_T));
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
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Kmat[0], &lda_t, &b
              [0], &ldb_t, &beta1, &y[0], &ldc_t);
        for (cindx = 0; cindx < 16; cindx++) {
          b_y[cindx] = y[cindx] + c_y[cindx];
        }

        st.site = &b_emlrtRSI;
        mrdivide(&st, b_y, a);
        for (cindx = 0; cindx < 1002; cindx++) {
          for (ix = 0; ix < 4; ix++) {
            Kmat[ix + (cindx << 2)] = KX[cindx + 1002 * ix];
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
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &a[0], &lda_t, &Kmat
              [0], &ldb_t, &beta1, &d_y[0], &ldc_t);
        for (cindx = 0; cindx < 1002; cindx++) {
          memcpy(&SD->f2.a[cindx * 40], &ResYdesign[cindx * 40 + mii * 40080],
                 40U * sizeof(real_T));
          b_b[cindx] = d_y[cindx];
        }

        memset(&efitEtas[L0ii * 40 + mii * 40080], 0, 40U * sizeof(real_T));
        alpha1 = 1.0;
        beta1 = 0.0;
        TRANSB = 'N';
        TRANSA = 'N';
        m_t = (ptrdiff_t)40;
        n_t = (ptrdiff_t)1;
        k_t = (ptrdiff_t)1002;
        lda_t = (ptrdiff_t)40;
        ldb_t = (ptrdiff_t)1002;
        ldc_t = (ptrdiff_t)40;
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &SD->f2.a[0], &lda_t,
              &b_b[0], &ldb_t, &beta1, &efitEtas[40 * L0ii + 40080 * mii],
              &ldc_t);
        L0ii++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 40; ix++) {
          SD->f2.ResYdesign[ix + 40 * cindx] = ResYdesign[(ix + 40 * cindx) +
            40080 * mii] - efitEtas[(ix + 40 * cindx) + 40080 * mii];
        }
      }

      st.site = &c_emlrtRSI;
      power(SD, &st, SD->f2.ResYdesign, SD->f2.a);
      sum(SD->f2.a, dv2);
      GCVs[b_ix + 50 * mii] = b_sum(dv2) / 40080.0;
      mii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    b_ix++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (dii = 0; dii < 3; dii++) {
    b_ix = dii * 50;
    mii = dii * 50 + 1;
    alpha1 = GCVs[b_ix];
    L0ii = 1;
    cindx = 1;
    if (muDoubleScalarIsNaN(GCVs[b_ix])) {
      ix = mii;
      exitg1 = false;
      while ((!exitg1) && (ix + 1 <= b_ix + 50)) {
        cindx++;
        mii = ix + 1;
        if (!muDoubleScalarIsNaN(GCVs[ix])) {
          alpha1 = GCVs[ix];
          L0ii = cindx;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (mii < b_ix + 50) {
      while (mii + 1 <= b_ix + 50) {
        cindx++;
        if (GCVs[mii] < alpha1) {
          alpha1 = GCVs[mii];
          L0ii = cindx;
        }

        mii++;
      }
    }

    iindx[dii] = L0ii;
  }

  for (cindx = 0; cindx < 3; cindx++) {
    indx[cindx] = iindx[cindx];
  }

  /*  optimal bandwidth */
  /* mh=vh(flag);   % optimal bandwidth */
  /*  estimate smooth function with optimal bandwidth */
  mii = 0;
  while (mii < 3) {
    /*  go through all features */
    for (cindx = 0; cindx < 1004004; cindx++) {
      SD->f2.Kmat[cindx] = 1.0;
    }

    dii = 0;
    while (dii < 3) {
      /*  go through all dimension */
      /*  minimum bandwidth */
      /*  maximum bandwidth */
      /*  candidate bandwidth */
      if (!((indx[mii] >= 1) && (indx[mii] <= 50))) {
        emlrtDynamicBoundsCheckR2012b(indx[mii], 1, 50, &emlrtBCI, sp);
      }

      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 1002; ix++) {
          SD->f2.b_Tmat0[ix + 1002 * cindx] = SD->f2.Tmat0[(ix + 1002 * cindx) +
            1004004 * (dii + 1)] / dv1[indx[mii] - 1];
        }
      }

      st.site = &e_emlrtRSI;
      EpKernel(SD, &st, SD->f2.b_Tmat0, dv1[indx[mii] - 1], SD->f2.dv0);
      for (cindx = 0; cindx < 1004004; cindx++) {
        SD->f2.Kmat[cindx] *= SD->f2.dv0[cindx];
      }

      /*  Epanechnikov kernel smoothing function */
      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    permute(SD->f2.Tmat0, SD->f2.Tmat);

    /*  L x d+1 x L matrix */
    L0ii = 0;
    while (L0ii < 1002) {
      /*  go through all vertex */
      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 4; ix++) {
          Kmat[cindx + 1002 * ix] = SD->f2.Kmat[cindx + 1002 * L0ii];
        }
      }

      for (cindx = 0; cindx < 4; cindx++) {
        for (ix = 0; ix < 1002; ix++) {
          KX[ix + 1002 * cindx] = Kmat[ix + 1002 * cindx] * SD->f2.Tmat[(ix +
            1002 * cindx) + 4008 * L0ii];
        }
      }

      /*  L x d+1 matrix */
      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 4; ix++) {
          Kmat[ix + (cindx << 2)] = KX[cindx + 1002 * ix];
        }
      }

      for (cindx = 0; cindx < 4; cindx++) {
        memcpy(&b[cindx * 1002], &SD->f2.Tmat[cindx * 1002 + L0ii * 4008], 1002U
               * sizeof(real_T));
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
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &Kmat[0], &lda_t, &b[0],
            &ldb_t, &beta1, &y[0], &ldc_t);
      for (cindx = 0; cindx < 16; cindx++) {
        b_y[cindx] = y[cindx] + c_y[cindx];
      }

      st.site = &f_emlrtRSI;
      mrdivide(&st, b_y, a);
      for (cindx = 0; cindx < 1002; cindx++) {
        for (ix = 0; ix < 4; ix++) {
          Kmat[ix + (cindx << 2)] = KX[cindx + 1002 * ix];
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
      for (cindx = 0; cindx < 1002; cindx++) {
        memcpy(&SD->f2.a[cindx * 40], &ResYdesign[cindx * 40 + mii * 40080], 40U
               * sizeof(real_T));
        b_b[cindx] = d_y[cindx];
      }

      memset(&efitEtas[L0ii * 40 + mii * 40080], 0, 40U * sizeof(real_T));
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      m_t = (ptrdiff_t)40;
      n_t = (ptrdiff_t)1;
      k_t = (ptrdiff_t)1002;
      lda_t = (ptrdiff_t)40;
      ldb_t = (ptrdiff_t)1002;
      ldc_t = (ptrdiff_t)40;
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &alpha1, &SD->f2.a[0], &lda_t,
            &b_b[0], &ldb_t, &beta1, &efitEtas[40 * L0ii + 40080 * mii], &ldc_t);
      L0ii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    mii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (cindx = 0; cindx < 120240; cindx++) {
    ResEtas[cindx] = ResYdesign[cindx] - efitEtas[cindx];
  }

  /*  n x L x m matrix of of difference between ResYdesign and fitted eta */
  /*  estimate the covariance matrix for each smooth function at each vertex */
  L0ii = 0;
  while (L0ii < 1002) {
    dii = 0;
    while (dii < 1002) {
      for (cindx = 0; cindx < 3; cindx++) {
        memcpy(&b_efitEtas[cindx * 40], &efitEtas[cindx * 40080 + L0ii * 40],
               40U * sizeof(real_T));
      }

      squeeze(b_efitEtas, dv3);
      for (cindx = 0; cindx < 3; cindx++) {
        memcpy(&c_efitEtas[cindx * 40], &efitEtas[cindx * 40080 + dii * 40], 40U
               * sizeof(real_T));
      }

      squeeze(c_efitEtas, dv4);
      for (cindx = 0; cindx < 3; cindx++) {
        for (ix = 0; ix < 3; ix++) {
          alpha1 = 0.0;
          for (b_ix = 0; b_ix < 40; b_ix++) {
            alpha1 += dv3[b_ix + 40 * cindx] * dv4[b_ix + 40 * ix];
          }

          eSigEta[((cindx + 3 * ix) + 9 * L0ii) + 9018 * dii] = alpha1 / 40.0;
        }
      }

      dii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    L0ii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }
}

/* End of code generation (stat_sif.c) */
