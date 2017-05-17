/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif.h
 *
 * Code generation for function 'stat_sif'
 *
 */

#ifndef STAT_SIF_H
#define STAT_SIF_H

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
#include "stat_sif_types.h"

/* Function Declarations */
extern void stat_sif(stat_sifStackData *SD, const emlrtStack *sp, const real_T
                     Coord[3006], const real_T ResYdesign[120240], real_T
                     efitEtas[120240], real_T ResEtas[120240], real_T eSigEta
                     [9036036]);

#endif

/* End of code generation (stat_sif.h) */
