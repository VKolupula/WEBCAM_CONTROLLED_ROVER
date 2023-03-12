/*
 * rover_finalEx_types.h
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

#ifndef RTW_HEADER_rover_finalEx_types_h_
#define RTW_HEADER_rover_finalEx_types_h_
#include "MW_SVD.h"
#include "rtwtypes.h"

/* Custom Type definition for MATLABSystem: '<S3>/M1 M2 DC Motors' */
#include "MW_SVD.h"
#ifndef struct_tag_jbIFaTBEZATkkvPSmnoPa
#define struct_tag_jbIFaTBEZATkkvPSmnoPa

struct tag_jbIFaTBEZATkkvPSmnoPa
{
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_jbIFaTBEZATkkvPSmnoPa */

#ifndef typedef_c_arduinodriver_ArduinoI2C_ro_T
#define typedef_c_arduinodriver_ArduinoI2C_ro_T

typedef struct tag_jbIFaTBEZATkkvPSmnoPa c_arduinodriver_ArduinoI2C_ro_T;

#endif                             /* typedef_c_arduinodriver_ArduinoI2C_ro_T */

#ifndef struct_tag_9AnIRoZpmWNSR76ytV7oUG
#define struct_tag_9AnIRoZpmWNSR76ytV7oUG

struct tag_9AnIRoZpmWNSR76ytV7oUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_arduinodriver_ArduinoI2C_ro_T I2CDriverObj;
  uint32_T BusSpeed;
  real_T DefaultMaximumBusSpeedInHz;
};

#endif                                 /* struct_tag_9AnIRoZpmWNSR76ytV7oUG */

#ifndef typedef_f_codertarget_arduinobase_int_T
#define typedef_f_codertarget_arduinobase_int_T

typedef struct tag_9AnIRoZpmWNSR76ytV7oUG f_codertarget_arduinobase_int_T;

#endif                             /* typedef_f_codertarget_arduinobase_int_T */

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

#ifndef typedef_motorcarrier_blocks_mkrmotorc_T
#define typedef_motorcarrier_blocks_mkrmotorc_T

typedef struct tag_Mv9GUUZtpzLk5JKfq427VD motorcarrier_blocks_mkrmotorc_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmotorc_T */

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

#ifndef typedef_motorcarrier_blocks_mkrmoto_i_T
#define typedef_motorcarrier_blocks_mkrmoto_i_T

typedef struct tag_b5s9DWaQUh2sFO58PNDokH motorcarrier_blocks_mkrmoto_i_T;

#endif                             /* typedef_motorcarrier_blocks_mkrmoto_i_T */

#ifndef struct_tag_sWVUrVbuTOsQAIqNnx9hVC
#define struct_tag_sWVUrVbuTOsQAIqNnx9hVC

struct tag_sWVUrVbuTOsQAIqNnx9hVC
{
  int32_T isInitialized;
  real_T isServer_;
};

#endif                                 /* struct_tag_sWVUrVbuTOsQAIqNnx9hVC */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_sWVUrVbuTOsQAIqNnx9hVC codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_232UF1UZUWHwxF67i1BPZ
#define struct_tag_232UF1UZUWHwxF67i1BPZ

struct tag_232UF1UZUWHwxF67i1BPZ
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T isServer_;
};

#endif                                 /* struct_tag_232UF1UZUWHwxF67i1BPZ */

#ifndef typedef_codertarget_arduinobase_int_i_T
#define typedef_codertarget_arduinobase_int_i_T

typedef struct tag_232UF1UZUWHwxF67i1BPZ codertarget_arduinobase_int_i_T;

#endif                             /* typedef_codertarget_arduinobase_int_i_T */

/* Parameters for system: '<S4>/angCtrl' */
typedef struct P_angCtrl_rover_finalEx_T_ P_angCtrl_rover_finalEx_T;

/* Parameters for system: '<S4>/distCtrl' */
typedef struct P_distCtrl_rover_finalEx_T_ P_distCtrl_rover_finalEx_T;

/* Parameters (default storage) */
typedef struct P_rover_finalEx_T_ P_rover_finalEx_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_rover_finalEx_T RT_MODEL_rover_finalEx_T;

#endif                                 /* RTW_HEADER_rover_finalEx_types_h_ */
