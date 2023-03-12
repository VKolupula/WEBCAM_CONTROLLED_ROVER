/*
 * rover_finalEx.h
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

#ifndef RTW_HEADER_rover_finalEx_h_
#define RTW_HEADER_rover_finalEx_h_
#ifndef rover_finalEx_COMMON_INCLUDES_
#define rover_finalEx_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_WiFiTCP.h"
#endif                                 /* rover_finalEx_COMMON_INCLUDES_ */

#include "rover_finalEx_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S4>/angCtrl' */
typedef struct {
  real_T Sum;                          /* '<S50>/Sum' */
} B_angCtrl_rover_finalEx_T;

/* Block states (default storage) for system '<S4>/angCtrl' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
} DW_angCtrl_rover_finalEx_T;

/* Block signals for system '<S4>/distCtrl' */
typedef struct {
  real_T Sum;                          /* '<S99>/Sum' */
} B_distCtrl_rover_finalEx_T;

/* Block states (default storage) for system '<S4>/distCtrl' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S90>/Integrator' */
} DW_distCtrl_rover_finalEx_T;

/* Block signals (default storage) */
typedef struct {
  real_T waypoints[6];                 /* '<Root>/calcWaypoints' */
  real_T st;                           /* '<Root>/calcWaypoints' */
  real_T v;                            /* '<Root>/StateLogic' */
  real_T w;                            /* '<Root>/StateLogic' */
  real_T FLAng;                        /* '<Root>/StateLogic' */
  real_T active;                       /* '<Root>/StateLogic' */
  real_T cmXout;                       /* '<Root>/Chart' */
  real_T cmYout;                       /* '<Root>/Chart' */
  real_T headingOut;                   /* '<Root>/Chart' */
  real_T cmX;                          /* '<Root>/Product' */
  real_T cmY;                          /* '<Root>/Product1' */
  real_T heading;                      /* '<Root>/Product2' */
  B_distCtrl_rover_finalEx_T distCtrl; /* '<S4>/distCtrl' */
  B_angCtrl_rover_finalEx_T angCtrl;   /* '<S4>/angCtrl' */
} B_rover_finalEx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  motorcarrier_blocks_mkrmotorc_T obj; /* '<Root>/ForkliftMotor' */
  motorcarrier_blocks_mkrmoto_i_T obj_n;/* '<S3>/M1 M2 DC Motors' */
  motorcarrier_blocks_mkrmoto_i_T obj_f;/* '<S2>/M1 M2 DC Motors' */
  codertarget_arduinobase_inter_T obj_o;/* '<Root>/active1' */
  codertarget_arduinobase_int_i_T obj_a;/* '<Root>/waypointData' */
  codertarget_arduinobase_int_i_T obj_l;/* '<Root>/heading' */
  codertarget_arduinobase_int_i_T obj_b;/* '<Root>/cmY' */
  codertarget_arduinobase_int_i_T obj_lw;/* '<Root>/cmX' */
  real_T row;                          /* '<Root>/calcWaypoints' */
  real_T col;                          /* '<Root>/calcWaypoints' */
  real_T way[6];                       /* '<Root>/calcWaypoints' */
  real_T desDist;                      /* '<Root>/StateLogic' */
  real_T desAng;                       /* '<Root>/StateLogic' */
  real_T WPIndex;                      /* '<Root>/StateLogic' */
  real_T cmXOldValue;                  /* '<Root>/Chart' */
  real_T cmYOldValue;                  /* '<Root>/Chart' */
  real_T headingOldValue;              /* '<Root>/Chart' */
  uint8_T is_c1_rover_finalEx;         /* '<Root>/calcWaypoints' */
  uint8_T is_active_c1_rover_finalEx;  /* '<Root>/calcWaypoints' */
  uint8_T is_c3_rover_finalEx;         /* '<Root>/StateLogic' */
  uint8_T is_MoveForwardAndDrop;       /* '<Root>/StateLogic' */
  uint8_T is_MoveForwardAndPickUp;     /* '<Root>/StateLogic' */
  uint8_T is_active_c3_rover_finalEx;  /* '<Root>/StateLogic' */
  uint8_T temporalCounter_i1;          /* '<Root>/StateLogic' */
  uint8_T is_c2_rover_finalEx;         /* '<Root>/Chart' */
  uint8_T is_active_c2_rover_finalEx;  /* '<Root>/Chart' */
  DW_distCtrl_rover_finalEx_T distCtrl;/* '<S4>/distCtrl' */
  DW_angCtrl_rover_finalEx_T angCtrl;  /* '<S4>/angCtrl' */
} DW_rover_finalEx_T;

/* Parameters for system: '<S4>/angCtrl' */
struct P_angCtrl_rover_finalEx_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S38>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S41>/Integrator'
                               */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S41>/Integrator'
                                        */
};

/* Parameters for system: '<S4>/distCtrl' */
struct P_distCtrl_rover_finalEx_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S87>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S90>/Integrator'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S95>/Proportional Gain'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S90>/Integrator'
                                        */
};

/* Parameters (default storage) */
struct P_rover_finalEx_T_ {
  real_T PWMcmdMono_L[30];             /* Variable: PWMcmdMono_L
                                        * Referenced by: '<S2>/Lookup table'
                                        */
  real_T PWMcmdMono_R[27];             /* Variable: PWMcmdMono_R
                                        * Referenced by: '<S3>/Lookup table'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<S6>/ Gain'
                                        */
  real_T speedMono_L[30];              /* Variable: speedMono_L
                                        * Referenced by: '<S2>/Lookup table'
                                        */
  real_T speedMono_R[27];              /* Variable: speedMono_R
                                        * Referenced by: '<S3>/Lookup table'
                                        */
  real_T Gain1_Gain;                   /* Expression: pi/180
                                        * Referenced by: '<S107>/Gain1'
                                        */
  real_T Matrixmultiplication_Gain[4]; /* Expression: [1 -L/2; 1 L/2]
                                        * Referenced by: '<S6>/Matrix multiplication'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T degsectorpm_Gain;             /* Expression: 60/360
                                        * Referenced by: '<S2>/deg//sec to rpm'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 100
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 180/pi
                                        * Referenced by: '<S109>/Gain'
                                        */
  real_T degsectorpm_Gain_d;           /* Expression: 60/360
                                        * Referenced by: '<S3>/deg//sec to rpm'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -70
                                        * Referenced by: '<S3>/Gain'
                                        */
  P_distCtrl_rover_finalEx_T distCtrl; /* '<S4>/distCtrl' */
  P_angCtrl_rover_finalEx_T angCtrl;   /* '<S4>/angCtrl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_rover_finalEx_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_rover_finalEx_T rover_finalEx_P;

/* Block signals (default storage) */
extern B_rover_finalEx_T rover_finalEx_B;

/* Block states (default storage) */
extern DW_rover_finalEx_T rover_finalEx_DW;

/* Model entry point functions */
extern void rover_finalEx_initialize(void);
extern void rover_finalEx_step(void);
extern void rover_finalEx_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rover_finalEx_T *const rover_finalEx_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S7>/Scope' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rover_finalEx'
 * '<S1>'   : 'rover_finalEx/Chart'
 * '<S2>'   : 'rover_finalEx/LeftMotor'
 * '<S3>'   : 'rover_finalEx/RightMotor'
 * '<S4>'   : 'rover_finalEx/StateLogic'
 * '<S5>'   : 'rover_finalEx/calcWaypoints'
 * '<S6>'   : 'rover_finalEx/convToWheelVel'
 * '<S7>'   : 'rover_finalEx/StateLogic/angCtrl'
 * '<S8>'   : 'rover_finalEx/StateLogic/distCtrl'
 * '<S9>'   : 'rover_finalEx/StateLogic/angCtrl/PID Controller1'
 * '<S10>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Anti-windup'
 * '<S11>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/D Gain'
 * '<S12>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Filter'
 * '<S13>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Filter ICs'
 * '<S14>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/I Gain'
 * '<S15>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Ideal P Gain'
 * '<S16>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Ideal P Gain Fdbk'
 * '<S17>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Integrator'
 * '<S18>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Integrator ICs'
 * '<S19>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/N Copy'
 * '<S20>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/N Gain'
 * '<S21>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/P Copy'
 * '<S22>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Parallel P Gain'
 * '<S23>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Reset Signal'
 * '<S24>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Saturation'
 * '<S25>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Saturation Fdbk'
 * '<S26>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Sum'
 * '<S27>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Sum Fdbk'
 * '<S28>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tracking Mode'
 * '<S29>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tracking Mode Sum'
 * '<S30>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tsamp - Integral'
 * '<S31>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tsamp - Ngain'
 * '<S32>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/postSat Signal'
 * '<S33>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/preSat Signal'
 * '<S34>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Anti-windup/Passthrough'
 * '<S35>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/D Gain/Disabled'
 * '<S36>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Filter/Disabled'
 * '<S37>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Filter ICs/Disabled'
 * '<S38>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/I Gain/Internal Parameters'
 * '<S39>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Ideal P Gain/Passthrough'
 * '<S40>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Integrator/Discrete'
 * '<S42>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Integrator ICs/Internal IC'
 * '<S43>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/N Gain/Disabled'
 * '<S45>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/P Copy/Disabled'
 * '<S46>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Reset Signal/Disabled'
 * '<S48>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Saturation/Passthrough'
 * '<S49>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Saturation Fdbk/Disabled'
 * '<S50>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Sum/Sum_PI'
 * '<S51>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Sum Fdbk/Disabled'
 * '<S52>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tracking Mode/Disabled'
 * '<S53>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S55>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/postSat Signal/Forward_Path'
 * '<S57>'  : 'rover_finalEx/StateLogic/angCtrl/PID Controller1/preSat Signal/Forward_Path'
 * '<S58>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller'
 * '<S59>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Anti-windup'
 * '<S60>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/D Gain'
 * '<S61>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Filter'
 * '<S62>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Filter ICs'
 * '<S63>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/I Gain'
 * '<S64>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Ideal P Gain'
 * '<S65>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Ideal P Gain Fdbk'
 * '<S66>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Integrator'
 * '<S67>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Integrator ICs'
 * '<S68>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/N Copy'
 * '<S69>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/N Gain'
 * '<S70>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/P Copy'
 * '<S71>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Parallel P Gain'
 * '<S72>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Reset Signal'
 * '<S73>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Saturation'
 * '<S74>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Saturation Fdbk'
 * '<S75>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Sum'
 * '<S76>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Sum Fdbk'
 * '<S77>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tracking Mode'
 * '<S78>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tracking Mode Sum'
 * '<S79>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tsamp - Integral'
 * '<S80>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tsamp - Ngain'
 * '<S81>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/postSat Signal'
 * '<S82>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/preSat Signal'
 * '<S83>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Anti-windup/Passthrough'
 * '<S84>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/D Gain/Disabled'
 * '<S85>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Filter/Disabled'
 * '<S86>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Filter ICs/Disabled'
 * '<S87>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/I Gain/Internal Parameters'
 * '<S88>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Ideal P Gain/Passthrough'
 * '<S89>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Integrator/Discrete'
 * '<S91>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Integrator ICs/Internal IC'
 * '<S92>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S93>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/N Gain/Disabled'
 * '<S94>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/P Copy/Disabled'
 * '<S95>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Reset Signal/Disabled'
 * '<S97>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Saturation/Passthrough'
 * '<S98>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Saturation Fdbk/Disabled'
 * '<S99>'  : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Sum/Sum_PI'
 * '<S100>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Sum Fdbk/Disabled'
 * '<S101>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tracking Mode/Disabled'
 * '<S102>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tsamp - Integral/Passthrough'
 * '<S104>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/postSat Signal/Forward_Path'
 * '<S106>' : 'rover_finalEx/StateLogic/distCtrl/PID Controller/preSat Signal/Forward_Path'
 * '<S107>' : 'rover_finalEx/convToWheelVel/Degrees to Radians'
 * '<S108>' : 'rover_finalEx/convToWheelVel/Radians to Degrees'
 * '<S109>' : 'rover_finalEx/convToWheelVel/Radians to Degrees1'
 */
#endif                                 /* RTW_HEADER_rover_finalEx_h_ */
