/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_sif_mexutil.c
 *
 * Code generation for function 'stat_sif_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_sif.h"
#include "stat_sif_mexutil.h"
#include "stat_sif_data.h"

/* Variable Definitions */
static stat_sifTLS *stat_sifTLSGlobal;

#pragma omp threadprivate (stat_sifTLSGlobal)

/* Function Definitions */
void emlrtFreeThreadStackData(const emlrtStack *sp)
{
  int32_T i;
  jmp_buf * volatile emlrtJBStack;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel for schedule(static)\
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (i = 1; i <= omp_get_max_threads(); i++) {
    free(stat_sifTLSGlobal);
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

stat_sifTLS *emlrtGetThreadStackData(void)
{
  return stat_sifTLSGlobal;
}

void emlrtInitThreadStackData(const emlrtStack *sp)
{
  int32_T i;
  jmp_buf * volatile emlrtJBStack;
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel for schedule(static)\
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs()))

  for (i = 1; i <= omp_get_max_threads(); i++) {
    stat_sifTLSGlobal = (stat_sifTLS *)malloc(1U * sizeof(stat_sifTLS));
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, const emlrtConstCTX aTLS,
  void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (stat_sif_mexutil.c) */
