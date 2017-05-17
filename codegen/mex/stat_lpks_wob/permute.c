/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * permute.c
 *
 * Code generation for function 'permute'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "permute.h"
#include "stat_lpks_wob_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "permute",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m"/* pName */
};

/* Function Definitions */
void permute(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *b)
{
  int16_T insz[3];
  int32_T plast;
  int16_T outsz[3];
  boolean_T b_b;
  int32_T k;
  int32_T iwork[3];
  boolean_T exitg2;
  boolean_T guard1 = false;
  static const int8_T iv6[3] = { 1, 3, 2 };

  int32_T inc[3];
  static const int8_T iv7[3] = { 0, 2, 1 };

  int32_T isrc;
  int32_T exitg1;
  for (plast = 0; plast < 3; plast++) {
    insz[plast] = (int16_T)a->size[plast];
  }

  outsz[0] = insz[0];
  outsz[1] = insz[2];
  outsz[2] = insz[1];
  plast = b->size[0] * b->size[1] * b->size[2];
  b->size[0] = insz[0];
  b->size[1] = insz[2];
  b->size[2] = insz[1];
  emxEnsureCapacity(sp, (emxArray__common *)b, plast, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  b_b = true;
  if (!((a->size[0] == 0) || (a->size[1] == 0))) {
    plast = 0;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k + 1 < 4)) {
      guard1 = false;
      if (a->size[iv6[k] - 1] != 1) {
        if (plast > iv6[k]) {
          b_b = false;
          exitg2 = true;
        } else {
          plast = iv6[k];
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        k++;
      }
    }
  }

  if (b_b) {
    plast = a->size[0] * a->size[1] * a->size[2];
    for (k = 0; k + 1 <= plast; k++) {
      b->data[k] = a->data[k];
    }
  } else {
    for (plast = 0; plast < 3; plast++) {
      iwork[plast] = 1;
    }

    for (k = 0; k < 2; k++) {
      iwork[k + 1] = iwork[k] * insz[k];
    }

    for (plast = 0; plast < 3; plast++) {
      inc[plast] = iwork[iv7[plast]];
    }

    for (plast = 0; plast < 3; plast++) {
      iwork[plast] = 0;
    }

    plast = 0;
    do {
      isrc = 0;
      for (k = 0; k < 2; k++) {
        isrc += iwork[k + 1] * inc[k + 1];
      }

      for (k = 1; k <= outsz[0]; k++) {
        b->data[plast] = a->data[isrc];
        plast++;
        isrc += inc[0];
      }

      k = 1;
      do {
        exitg1 = 0;
        iwork[k]++;
        if (iwork[k] < outsz[k]) {
          exitg1 = 2;
        } else if (k + 1 == 3) {
          exitg1 = 1;
        } else {
          iwork[1] = 0;
          k = 2;
        }
      } while (exitg1 == 0);
    } while (!(exitg1 == 1));
  }
}

/* End of code generation (permute.c) */
