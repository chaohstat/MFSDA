/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colon.c
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wob.h"
#include "colon.h"

/* Function Definitions */
void eml_signed_integer_colon(int32_T b, int32_T y_data[], int32_T y_size[2])
{
  int32_T n;
  int32_T yk;
  int32_T k;
  if (b < 1) {
    n = 0;
  } else {
    n = b;
  }

  y_size[0] = 1;
  y_size[1] = n;
  if (n > 0) {
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.c) */
