/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * stat_lpks_wb1_mexutil.c
 *
 * Code generation for function 'stat_lpks_wb1_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "stat_lpks_wb1.h"
#include "stat_lpks_wb1_mexutil.h"
#include "stat_lpks_wb1_data.h"

/* Variable Definitions */
static stat_lpks_wb1TLS *stat_lpks_wb1TLSGlobal;

#pragma omp threadprivate (stat_lpks_wb1TLSGlobal)

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
    free(stat_lpks_wb1TLSGlobal);
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

stat_lpks_wb1TLS *emlrtGetThreadStackData(void)
{
  return stat_lpks_wb1TLSGlobal;
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
    stat_lpks_wb1TLSGlobal = (stat_lpks_wb1TLS *)malloc(1U * sizeof
      (stat_lpks_wb1TLS));
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

/* End of code generation (stat_lpks_wb1_mexutil.c) */
