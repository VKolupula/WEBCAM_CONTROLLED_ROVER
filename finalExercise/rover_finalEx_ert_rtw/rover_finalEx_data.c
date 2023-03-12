/*
 * rover_finalEx_data.c
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

#include "rover_finalEx.h"

/* Block parameters (default storage) */
P_rover_finalEx_T rover_finalEx_P = {
  /* Variable: PWMcmdMono_L
   * Referenced by: '<S2>/Lookup table'
   */
  { -1.0, -0.9, -0.8, -0.75, -0.7, -0.6, -0.55, -0.5, -0.44999999999999996,
    -0.39999999999999991, -0.35, -0.29999999999999993, -0.25,
    -0.19999999999999996, -0.14999999999999991, 0.0, 0.14999999999999991,
    0.19999999999999996, 0.25, 0.29999999999999993, 0.35, 0.39999999999999991,
    0.44999999999999996, 0.5, 0.6, 0.64999999999999991, 0.7, 0.75, 0.8, 0.95 },

  /* Variable: PWMcmdMono_R
   * Referenced by: '<S3>/Lookup table'
   */
  { -0.95, -0.8, -0.7, -0.64999999999999991, -0.55, -0.5, -0.44999999999999996,
    -0.39999999999999991, -0.35, -0.29999999999999993, -0.25,
    -0.19999999999999996, -0.14999999999999991, 0.0, 0.19999999999999996, 0.25,
    0.29999999999999993, 0.35, 0.44999999999999996, 0.5, 0.55,
    0.64999999999999991, 0.7, 0.75, 0.8, 0.9, 0.95 },

  /* Variable: r
   * Referenced by: '<S6>/ Gain'
   */
  4.5,

  /* Variable: speedMono_L
   * Referenced by: '<S2>/Lookup table'
   */
  { -300.0, -290.0, -285.0, -275.0, -270.0, -265.0, -255.0, -245.0, -235.0,
    -220.0, -200.0, -175.0, -140.0, -100.0, -25.0, 0.0, 15.0, 90.0, 135.0, 165.0,
    200.0, 210.0, 235.0, 245.0, 250.0, 270.0, 275.0, 280.0, 285.0, 295.0 },

  /* Variable: speedMono_R
   * Referenced by: '<S3>/Lookup table'
   */
  { -295.0, -290.0, -280.0, -270.0, -265.0, -240.0, -235.0, -230.0, -215.0,
    -190.0, -155.0, -115.0, -60.0, 0.0, 60.0, 120.0, 155.0, 185.0, 210.0, 235.0,
    250.0, 265.0, 275.0, 280.0, 285.0, 290.0, 295.0 },

  /* Expression: pi/180
   * Referenced by: '<S107>/Gain1'
   */
  0.017453292519943295,

  /* Expression: [1 -L/2; 1 L/2]
   * Referenced by: '<S6>/Matrix multiplication'
   */
  { 1.0, 1.0, -4.25, 4.25 },

  /* Expression: 180/pi
   * Referenced by: '<S108>/Gain'
   */
  57.295779513082323,

  /* Expression: 60/360
   * Referenced by: '<S2>/deg//sec to rpm'
   */
  0.16666666666666666,

  /* Expression: 100
   * Referenced by: '<S2>/Gain'
   */
  100.0,

  /* Expression: 180/pi
   * Referenced by: '<S109>/Gain'
   */
  57.295779513082323,

  /* Expression: 60/360
   * Referenced by: '<S3>/deg//sec to rpm'
   */
  0.16666666666666666,

  /* Expression: -70
   * Referenced by: '<S3>/Gain'
   */
  -70.0,

  /* Start of '<S4>/distCtrl' */
  {
    /* Mask Parameter: PIDController_I
     * Referenced by: '<S87>/Integral Gain'
     */
    0.9,

    /* Mask Parameter: PIDController_InitialConditionF
     * Referenced by: '<S90>/Integrator'
     */
    0.0,

    /* Mask Parameter: PIDController_P
     * Referenced by: '<S95>/Proportional Gain'
     */
    2.5,

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S90>/Integrator'
     */
    0.01
  }
  ,

  /* End of '<S4>/distCtrl' */

  /* Start of '<S4>/angCtrl' */
  {
    /* Mask Parameter: PIDController1_I
     * Referenced by: '<S38>/Integral Gain'
     */
    1.0,

    /* Mask Parameter: PIDController1_InitialCondition
     * Referenced by: '<S41>/Integrator'
     */
    0.0,

    /* Mask Parameter: PIDController1_P
     * Referenced by: '<S46>/Proportional Gain'
     */
    3.0,

    /* Computed Parameter: Integrator_gainval
     * Referenced by: '<S41>/Integrator'
     */
    0.01
  }
  /* End of '<S4>/angCtrl' */
};
