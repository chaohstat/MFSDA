/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eye.h
 *
 * Code generation for function 'eye'
 *
 */

#ifndef EYE_H
#define EYE_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "stat_lpks_wob_types.h"

/* Function Declarations */
extern void eye(const emlrtStack *sp, real_T varargin_1, real_T I_data[],
                int32_T I_size[2]);

#endif

/* End of code generation (eye.h) */
