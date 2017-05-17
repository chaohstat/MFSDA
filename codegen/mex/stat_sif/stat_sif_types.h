/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif_types.h
 *
 * Code generation for function 'stat_sif'
 *
 */

#ifndef STAT_SIF_TYPES_H
#define STAT_SIF_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef typedef_stat_sifStackData
#define typedef_stat_sifStackData

typedef struct {
  union
  {
    struct {
      real_T y[1004004];
    } f0;

    struct {
      real_T x[40080];
    } f1;
  } u1;

  struct {
    real_T Tmat0[4016016];
    real_T Tmat[4016016];
    real_T Kmat[1004004];
    real_T dv0[1004004];
    real_T b_Tmat0[1004004];
    real_T ResYdesign[40080];
    real_T a[40080];
  } f2;
} stat_sifStackData;

#endif                                 /*typedef_stat_sifStackData*/

#ifndef typedef_stat_sifTLS
#define typedef_stat_sifTLS

typedef struct {
  union
  {
    struct {
      boolean_T bv0[1004004];
    } f0;
  } u1;
} stat_sifTLS;

#endif                                 /*typedef_stat_sifTLS*/
#endif

/* End of code generation (stat_sif_types.h) */
