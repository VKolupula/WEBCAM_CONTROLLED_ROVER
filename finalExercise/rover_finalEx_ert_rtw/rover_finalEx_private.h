/*
 * rover_finalEx_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rover_finalEx".
 *
 * Model version              : 6.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sat Mar 11 14:32:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rover_finalEx_private_h_
#define RTW_HEADER_rover_finalEx_private_h_
#include "rtwtypes.h"
#include "rover_finalEx.h"
#include "rover_finalEx_types.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern int32_T mul_s32_sat(int32_T a, int32_T b);
extern void rover_finalEx_angCtrl_Init(DW_angCtrl_rover_finalEx_T *localDW,
  P_angCtrl_rover_finalEx_T *localP);
extern void rover_finalEx_angCtrl(real_T rtu_desAng, B_angCtrl_rover_finalEx_T
  *localB, DW_angCtrl_rover_finalEx_T *localDW, P_angCtrl_rover_finalEx_T
  *localP);
extern void rover_finalEx_distCtrl_Init(DW_distCtrl_rover_finalEx_T *localDW,
  P_distCtrl_rover_finalEx_T *localP);
extern void rover_finalEx_distCtrl(real_T rtu_desDist,
  B_distCtrl_rover_finalEx_T *localB, DW_distCtrl_rover_finalEx_T *localDW,
  P_distCtrl_rover_finalEx_T *localP);

#endif                                 /* RTW_HEADER_rover_finalEx_private_h_ */
