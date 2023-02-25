/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: simulink_rover_control.h
 *
 * Code generated for Simulink model 'simulink_rover_control'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Feb 25 16:40:47 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_simulink_rover_control_h_
#define RTW_HEADER_simulink_rover_control_h_
#ifndef simulink_rover_control_COMMON_INCLUDES_
#define simulink_rover_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_I2C.h"
#include "MW_arduino_digitalio.h"
#endif                             /* simulink_rover_control_COMMON_INCLUDES_ */

#include "simulink_rover_control_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T i2cname;
  MW_I2C_Mode_Type modename;
  real_T Constant;                     /* '<Root>/Constant' */
  real_T OnOffLED;                     /* '<Root>/On//Off LED' */
  real_T Product;                      /* '<S3>/Product' */
  uint8_T final_data_to_write[6];
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write_m[6];
  uint32_T ADCValuetoVoltageConversion;
                                  /* '<Root>/ADC Value to Voltage Conversion' */
  int32_T Encoder2;                    /* '<S1>/Encoder2' */
  int32_T Encoder1;                    /* '<S1>/Encoder1' */
  uint16_T BatteryRead;                /* '<Root>/Battery Read' */
} B_simulink_rover_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  motorcarrier_blocks_mkrmotorc_T obj; /* '<Root>/Battery Read' */
  motorcarrier_blocks_mkrmoto_h_T obj_l;/* '<S1>/Encoder2' */
  motorcarrier_blocks_mkrmoto_h_T obj_n;/* '<S1>/Encoder1' */
  motorcarrier_blocks_mkrmot_hv_T obj_b;/* '<S3>/M1 M2 DC Motors4' */
  motorcarrier_blocks_mkrmot_hv_T obj_p;/* '<S2>/M1 M2 DC Motors4' */
  motorcarrier_blocks_mkrmo_hvv_T obj_f;/* '<S4>/ForkliftMotor' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/On-board LED' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S4>/Scope' */

  int8_T Servo_Test_Enabled_Subsystem_Su;
                                     /* '<Root>/Servo_Test_Enabled_Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<Root>/Enabled Subsystem' */
} DW_simulink_rover_control_T;

/* Parameters (default storage) */
struct P_simulink_rover_control_T_ {
  real_T BatteryRead_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Battery Read'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Servoenable_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Servo enable'
                                        */
  real_T Encoderenable_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/Encoder enable'
                                        */
  real_T PWM_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/PWM'
                                        */
  real_T Motorenable_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Motor enable'
                                        */
  real_T PWM1_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/PWM1'
                                        */
  real_T Motorenable1_Value;           /* Expression: 0
                                        * Referenced by: '<Root>/Motor enable1'
                                        */
  real_T OnOffLED_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/On//Off LED'
                                        */
  int32_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  int32_T Out2_Y0;                     /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S1>/Out2'
                                        */
  uint16_T ADCValuetoVoltageConversion_Gai;
                          /* Computed Parameter: ADCValuetoVoltageConversion_Gai
                           * Referenced by: '<Root>/ADC Value to Voltage Conversion'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_simulink_rover_contro_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_simulink_rover_control_T simulink_rover_control_P;

/* Block signals (default storage) */
extern B_simulink_rover_control_T simulink_rover_control_B;

/* Block states (default storage) */
extern DW_simulink_rover_control_T simulink_rover_control_DW;

/* Model entry point functions */
extern void simulink_rover_control_initialize(void);
extern void simulink_rover_control_step(void);
extern void simulink_rover_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_simulink_rover_contr_T *const simulink_rover_control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'simulink_rover_control'
 * '<S1>'   : 'simulink_rover_control/Enabled Subsystem'
 * '<S2>'   : 'simulink_rover_control/Run Innertial Wheel'
 * '<S3>'   : 'simulink_rover_control/Run Motor'
 * '<S4>'   : 'simulink_rover_control/Servo_Test_Enabled_Subsystem'
 */
#endif                                /* RTW_HEADER_simulink_rover_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
