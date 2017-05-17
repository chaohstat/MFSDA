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
#include "stat_sif.h"
#include "permute.h"

/* Function Definitions */
void permute(const real_T a[4016016], real_T b[4016016])
{
  int16_T outsz[3];
  int32_T iwork[3];
  int32_T k;
  int32_T inc[3];
  static const int8_T iv0[3] = { 0, 2, 1 };

  int32_T idest;
  int32_T isrc;
  int32_T exitg1;
  outsz[0] = 1002;
  outsz[1] = 4;
  outsz[2] = 1002;
  for (k = 0; k < 3; k++) {
    iwork[k] = 1;
  }

  for (k = 0; k < 2; k++) {
    iwork[k + 1] = iwork[k] * 1002;
  }

  for (k = 0; k < 3; k++) {
    inc[k] = iwork[iv0[k]];
  }

  for (k = 0; k < 3; k++) {
    iwork[k] = 0;
  }

  idest = 0;
  do {
    isrc = 0;
    for (k = 0; k < 2; k++) {
      isrc += iwork[k + 1] * inc[k + 1];
    }

    for (k = 0; k < 1002; k++) {
      b[idest] = a[isrc];
      idest++;
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

/* End of code generation (permute.c) */
