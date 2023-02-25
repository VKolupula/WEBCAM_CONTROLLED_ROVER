/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: simulink_rover_control_types.h
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

#ifndef RTW_HEADER_simulink_rover_control_types_h_
#define RTW_HEADER_simulink_rover_control_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S4>/ForkliftMotor' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_si_T
#define typedef_c_arduinodriver_ArduinoI2C_si_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_si_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_si_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_si_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_f_codertarget_arduinobase_int_T
#define typedef_f_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG f_codertarget_arduinobase_int_T;

#endif                             /* typedef_f_codertarget_arduinobase_int_T */

#ifndef struct_tag_EmKWWlznjKlEpXleb4tCkH
#define struct_tag_EmKWWlznjKlEpXleb4tCkH

struct tag_EmKWWlznjKlEpXleb4tCkH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
  real_T SampleTime;
};

#endif                                 /* struct_tag_EmKWWlznjKlEpXleb4tCkH */

#ifndef typedef_motorcarrier_blocks_mkrmotorc_T
#define typedef_motorcarrier_blocks_mkrmotorc_T

typedef struct tag_EmKWWlznjKlEpXleb4tCkH motorcarrier_blocks_mkrmotorc_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmotorc_T */

#ifndef struct_tag_7gi4MQy35pU3EJY2pB6u1G
#define struct_tag_7gi4MQy35pU3EJY2pB6u1G

struct tag_7gi4MQy35pU3EJY2pB6u1G
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_7gi4MQy35pU3EJY2pB6u1G */

#ifndef typedef_motorcarrier_blocks_mkrmoto_h_T
#define typedef_motorcarrier_blocks_mkrmoto_h_T

typedef struct tag_7gi4MQy35pU3EJY2pB6u1G motorcarrier_blocks_mkrmoto_h_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmoto_h_T */

#ifndef struct_tag_9aqKbsbsI7JI0RwgnVwU0C
#define struct_tag_9aqKbsbsI7JI0RwgnVwU0C

struct tag_9aqKbsbsI7JI0RwgnVwU0C
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_9aqKbsbsI7JI0RwgnVwU0C */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_9aqKbsbsI7JI0RwgnVwU0C b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_qrLkTWTW64zZK0sqwALTyG
#define struct_tag_qrLkTWTW64zZK0sqwALTyG

struct tag_qrLkTWTW64zZK0sqwALTyG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_qrLkTWTW64zZK0sqwALTyG */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_qrLkTWTW64zZK0sqwALTyG codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_b5s9DWaQUh2sFO58PNDokH
#define struct_tag_b5s9DWaQUh2sFO58PNDokH

struct tag_b5s9DWaQUh2sFO58PNDokH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_b5s9DWaQUh2sFO58PNDokH */

#ifndef typedef_motorcarrier_blocks_mkrmot_hv_T
#define typedef_motorcarrier_blocks_mkrmot_hv_T

typedef struct tag_b5s9DWaQUh2sFO58PNDokH motorcarrier_blocks_mkrmot_hv_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmot_hv_T */

#ifndef struct_tag_Mv9GUUZtpzLk5JKfq427VD
#define struct_tag_Mv9GUUZtpzLk5JKfq427VD

struct tag_Mv9GUUZtpzLk5JKfq427VD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_codertarget_arduinobase_int_T i2cObj;
};

#endif                                 /* struct_tag_Mv9GUUZtpzLk5JKfq427VD */

#ifndef typedef_motorcarrier_blocks_mkrmo_hvv_T
#define typedef_motorcarrier_blocks_mkrmo_hvv_T

typedef struct tag_Mv9GUUZtpzLk5JKfq427VD motorcarrier_blocks_mkrmo_hvv_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmo_hvv_T */

/* Parameters (default storage) */
typedef struct P_simulink_rover_control_T_ P_simulink_rover_control_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_simulink_rover_contro_T RT_MODEL_simulink_rover_contr_T;

#endif                          /* RTW_HEADER_simulink_rover_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
