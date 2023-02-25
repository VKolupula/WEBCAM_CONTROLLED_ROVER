/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: simulink_rover_control.c
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

#include "simulink_rover_control.h"
#include "simulink_rover_control_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "simulink_rover_control_private.h"
#include <stddef.h>
#include <math.h>

/* Block signals (default storage) */
B_simulink_rover_control_T simulink_rover_control_B;

/* Block states (default storage) */
DW_simulink_rover_control_T simulink_rover_control_DW;

/* Real-time model */
static RT_MODEL_simulink_rover_contr_T simulink_rover_control_M_;
RT_MODEL_simulink_rover_contr_T *const simulink_rover_control_M =
  &simulink_rover_control_M_;

/* Forward declaration for local functions */
static void mkrmotorcarrier_ServoMotor_Serv(const
  motorcarrier_blocks_mkrmo_hvv_T *obj, int32_T value);
static void simulink__SystemCore_setup_hvv2(motorcarrier_blocks_mkrmo_hvv_T *obj);
static void simulink_rover_SystemCore_setup(motorcarrier_blocks_mkrmoto_h_T *obj);
static void simulink_rov_SystemCore_setup_h(motorcarrier_blocks_mkrmoto_h_T *obj);
static void simulink_r_SystemCore_setup_hvv(motorcarrier_blocks_mkrmot_hv_T *obj);
static void simulink_ro_SystemCore_setup_hv(motorcarrier_blocks_mkrmot_hv_T *obj);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Hi;
  uint32_T in0Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if ((in0 != 0) && ((in1 != 0) && ((in0 > 0) != (in1 > 0)))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0U) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void mkrmotorcarrier_ServoMotor_Serv(const
  motorcarrier_blocks_mkrmo_hvv_T *obj, int32_T value)
{
  int32_T x;
  int32_T z;
  uint32_T q;
  uint32_T y;
  uint8_T SwappedDataBytes[6];
  uint8_T data_uint8[4];
  x = mul_s32_sat(value, 21);
  if (x >= 0) {
    y = (uint32_T)x;
  } else if (x == MIN_int32_T) {
    y = 2147483648U;
  } else {
    y = (uint32_T)-x;
  }

  q = y / 180U;
  y -= q * 180U;
  if ((y > 0U) && (y >= 90U)) {
    q++;
  }

  z = (int32_T)q;
  if (x < 0) {
    z = -(int32_T)q;
  }

  x = z + 7;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  simulink_rover_control_B.final_data_to_write_m[0] = 3U;
  simulink_rover_control_B.final_data_to_write_m[1] = 2U;
  simulink_rover_control_B.final_data_to_write_m[2] = data_uint8[0];
  simulink_rover_control_B.final_data_to_write_m[3] = data_uint8[1];
  simulink_rover_control_B.final_data_to_write_m[4] = data_uint8[2];
  simulink_rover_control_B.final_data_to_write_m[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)
         &simulink_rover_control_B.final_data_to_write_m[0], (size_t)6 * sizeof
         (uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
}

static void simulink__SystemCore_setup_hvv2(motorcarrier_blocks_mkrmo_hvv_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 100;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 4U;
  final_data_to_write[1] = 2U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void simulink_rover_SystemCore_setup(motorcarrier_blocks_mkrmoto_h_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 0;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 8U;
  final_data_to_write[1] = 0U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void simulink_rov_SystemCore_setup_h(motorcarrier_blocks_mkrmoto_h_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 0;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 8U;
  final_data_to_write[1] = 1U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void simulink_r_SystemCore_setup_hvv(motorcarrier_blocks_mkrmot_hv_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 100;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 6U;
  final_data_to_write[1] = 0U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

static void simulink_ro_SystemCore_setup_hv(motorcarrier_blocks_mkrmot_hv_T *obj)
{
  MW_I2C_Mode_Type modename;
  uint32_T i2cname;
  f_codertarget_arduinobase_int_T *obj_0;
  int32_T x;
  uint32_T varargin_1;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj_0 = &obj->i2cObj;
  modename = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, modename);
  obj->i2cObj.BusSpeed = 100000U;
  varargin_1 = obj->i2cObj.BusSpeed;
  MW_I2C_SetBusSpeed(obj_0->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
  x = 100;
  memcpy((void *)&data_uint8[0], (void *)&x, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 6U;
  final_data_to_write[1] = 1U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void simulink_rover_control_step(void)
{
  f_codertarget_arduinobase_int_T *obj;
  int32_T In;
  uint32_T out;
  uint8_T out_raw[5];
  uint8_T output_raw[5];
  uint8_T data_uint8[4];
  uint8_T SwappedDataBytes[2];
  uint8_T final_data_to_write[2];
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(simulink_rover_control_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(simulink_rover_control_DW.Servo_Test_Enabled_Subsystem_Su);

  /* MATLABSystem: '<Root>/Battery Read' */
  if (simulink_rover_control_DW.obj.SampleTime !=
      simulink_rover_control_P.BatteryRead_SampleTime) {
    simulink_rover_control_DW.obj.SampleTime =
      simulink_rover_control_P.BatteryRead_SampleTime;
  }

  obj = &simulink_rover_control_DW.obj.i2cObj;
  final_data_to_write[0] = 13U;
  final_data_to_write[1] = 0U;
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         2 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes[0],
                     2U, false, false);
  obj = &simulink_rover_control_DW.obj.i2cObj;
  MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &output_raw[0], 5U,
                    false, false);
  memcpy((void *)&out_raw[0], (void *)&output_raw[0], (size_t)5 * sizeof(uint8_T));
  memcpy((void *)&out, (void *)&out_raw[1], (size_t)1 * sizeof(uint32_T));
  if (out > 65535U) {
    out = 65535U;
  }

  /* MATLABSystem: '<Root>/Battery Read' */
  simulink_rover_control_B.BatteryRead = (uint16_T)out;

  /* Gain: '<Root>/ADC Value to Voltage Conversion' */
  simulink_rover_control_B.ADCValuetoVoltageConversion = (uint32_T)
    simulink_rover_control_P.ADCValuetoVoltageConversion_Gai *
    simulink_rover_control_B.BatteryRead;

  /* Constant: '<Root>/Constant' */
  simulink_rover_control_B.Constant = simulink_rover_control_P.Constant_Value;

  /* Outputs for Enabled SubSystem: '<Root>/Servo_Test_Enabled_Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Constant: '<Root>/Servo enable' */
  if (simulink_rover_control_P.Servoenable_Value > 0.0) {
    /* MATLABSystem: '<S4>/ForkliftMotor' */
    simulink_rover_control_B.Product = rt_roundd_snf
      (simulink_rover_control_B.Constant);
    if (simulink_rover_control_B.Product < 2.147483648E+9) {
      if (simulink_rover_control_B.Product >= -2.147483648E+9) {
        In = (int32_T)simulink_rover_control_B.Product;
      } else {
        In = MIN_int32_T;
      }
    } else {
      In = MAX_int32_T;
    }

    mkrmotorcarrier_ServoMotor_Serv(&simulink_rover_control_DW.obj_f, In);

    /* End of MATLABSystem: '<S4>/ForkliftMotor' */
    srUpdateBC(simulink_rover_control_DW.Servo_Test_Enabled_Subsystem_Su);
  }

  /* End of Constant: '<Root>/Servo enable' */
  /* End of Outputs for SubSystem: '<Root>/Servo_Test_Enabled_Subsystem' */

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S1>/Enable'
   */
  /* Constant: '<Root>/Encoder enable' */
  if (simulink_rover_control_P.Encoderenable_Value > 0.0) {
    /* MATLABSystem: '<S1>/Encoder1' */
    final_data_to_write[0] = 7U;
    final_data_to_write[1] = 0U;
    obj = &simulink_rover_control_DW.obj_n.i2cObj;
    memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
           (size_t)2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes
                       [0], 2U, false, false);
    obj = &simulink_rover_control_DW.obj_n.i2cObj;
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &output_raw[0], 5U,
                      false, false);
    memcpy((void *)&out_raw[0], (void *)&output_raw[0], (size_t)5 * sizeof
           (uint8_T));
    memcpy((void *)&simulink_rover_control_B.Encoder1, (void *)&out_raw[1],
           (size_t)1 * sizeof(int32_T));

    /* MATLABSystem: '<S1>/Encoder2' */
    final_data_to_write[0] = 7U;
    final_data_to_write[1] = 1U;
    obj = &simulink_rover_control_DW.obj_l.i2cObj;
    memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
           (size_t)2 * sizeof(uint8_T));
    MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes
                       [0], 2U, false, false);
    obj = &simulink_rover_control_DW.obj_l.i2cObj;
    MW_I2C_MasterRead(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &output_raw[0], 5U,
                      false, false);
    memcpy((void *)&out_raw[0], (void *)&output_raw[0], (size_t)5 * sizeof
           (uint8_T));
    memcpy((void *)&simulink_rover_control_B.Encoder2, (void *)&out_raw[1],
           (size_t)1 * sizeof(int32_T));
    srUpdateBC(simulink_rover_control_DW.EnabledSubsystem_SubsysRanBC);
  }

  /* End of Constant: '<Root>/Encoder enable' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
  /* Outputs for Atomic SubSystem: '<Root>/Run Motor' */
  /* Product: '<S3>/Product' incorporates:
   *  Constant: '<Root>/Motor enable'
   *  Constant: '<Root>/PWM'
   */
  simulink_rover_control_B.Product = simulink_rover_control_P.PWM_Value *
    simulink_rover_control_P.Motorenable_Value;

  /* MATLABSystem: '<S3>/M1 M2 DC Motors4' */
  if (simulink_rover_control_B.Product > 100.0) {
    In = 100;
  } else if (simulink_rover_control_B.Product < -100.0) {
    In = -100;
  } else {
    simulink_rover_control_B.Product = rt_roundd_snf
      (simulink_rover_control_B.Product);
    if (simulink_rover_control_B.Product < 2.147483648E+9) {
      In = (int32_T)simulink_rover_control_B.Product;
    } else {
      In = MAX_int32_T;
    }
  }

  memcpy((void *)&data_uint8[0], (void *)&In, (size_t)4 * sizeof(uint8_T));
  simulink_rover_control_B.final_data_to_write[0] = 5U;
  simulink_rover_control_B.final_data_to_write[1] = 0U;
  simulink_rover_control_B.final_data_to_write[2] = data_uint8[0];
  simulink_rover_control_B.final_data_to_write[3] = data_uint8[1];
  simulink_rover_control_B.final_data_to_write[4] = data_uint8[2];
  simulink_rover_control_B.final_data_to_write[5] = data_uint8[3];
  obj = &simulink_rover_control_DW.obj_b.i2cObj;
  memcpy((void *)&simulink_rover_control_B.SwappedDataBytes[0], (void *)
         &simulink_rover_control_B.final_data_to_write[0], (size_t)6 * sizeof
         (uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &simulink_rover_control_B.SwappedDataBytes[0], 6U, false,
                     false);

  /* End of MATLABSystem: '<S3>/M1 M2 DC Motors4' */
  /* End of Outputs for SubSystem: '<Root>/Run Motor' */

  /* Outputs for Atomic SubSystem: '<Root>/Run Innertial Wheel' */
  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<Root>/Motor enable1'
   *  Constant: '<Root>/PWM1'
   */
  simulink_rover_control_B.Product = simulink_rover_control_P.PWM1_Value *
    simulink_rover_control_P.Motorenable1_Value;

  /* MATLABSystem: '<S2>/M1 M2 DC Motors4' */
  if (simulink_rover_control_B.Product > 100.0) {
    In = 100;
  } else if (simulink_rover_control_B.Product < -100.0) {
    In = -100;
  } else {
    simulink_rover_control_B.Product = rt_roundd_snf
      (simulink_rover_control_B.Product);
    if (simulink_rover_control_B.Product < 2.147483648E+9) {
      In = (int32_T)simulink_rover_control_B.Product;
    } else {
      In = MAX_int32_T;
    }
  }

  memcpy((void *)&data_uint8[0], (void *)&In, (size_t)4 * sizeof(uint8_T));
  simulink_rover_control_B.final_data_to_write[0] = 5U;
  simulink_rover_control_B.final_data_to_write[1] = 1U;
  simulink_rover_control_B.final_data_to_write[2] = data_uint8[0];
  simulink_rover_control_B.final_data_to_write[3] = data_uint8[1];
  simulink_rover_control_B.final_data_to_write[4] = data_uint8[2];
  simulink_rover_control_B.final_data_to_write[5] = data_uint8[3];
  obj = &simulink_rover_control_DW.obj_p.i2cObj;
  memcpy((void *)&simulink_rover_control_B.SwappedDataBytes[0], (void *)
         &simulink_rover_control_B.final_data_to_write[0], (size_t)6 * sizeof
         (uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &simulink_rover_control_B.SwappedDataBytes[0], 6U, false,
                     false);

  /* End of MATLABSystem: '<S2>/M1 M2 DC Motors4' */
  /* End of Outputs for SubSystem: '<Root>/Run Innertial Wheel' */

  /* Constant: '<Root>/On//Off LED' */
  simulink_rover_control_B.OnOffLED = simulink_rover_control_P.OnOffLED_Value;

  /* MATLABSystem: '<Root>/On-board LED' */
  simulink_rover_control_B.Product = rt_roundd_snf
    (simulink_rover_control_B.OnOffLED);
  if (simulink_rover_control_B.Product < 256.0) {
    if (simulink_rover_control_B.Product >= 0.0) {
      tmp = (uint8_T)simulink_rover_control_B.Product;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(13, tmp);

  /* End of MATLABSystem: '<Root>/On-board LED' */
  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  simulink_rover_control_M->Timing.taskTime0 =
    ((time_T)(++simulink_rover_control_M->Timing.clockTick0)) *
    simulink_rover_control_M->Timing.stepSize0;
}

/* Model initialize function */
void simulink_rover_control_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(simulink_rover_control_M, -1);
  simulink_rover_control_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  simulink_rover_control_M->Sizes.checksums[0] = (2692881762U);
  simulink_rover_control_M->Sizes.checksums[1] = (8602872U);
  simulink_rover_control_M->Sizes.checksums[2] = (582924568U);
  simulink_rover_control_M->Sizes.checksums[3] = (796909228U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    simulink_rover_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &simulink_rover_control_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &simulink_rover_control_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &simulink_rover_control_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &simulink_rover_control_DW.Servo_Test_Enabled_Subsystem_Su;
    systemRan[11] = (sysRanDType *)
      &simulink_rover_control_DW.Servo_Test_Enabled_Subsystem_Su;
    rteiSetModelMappingInfoPtr(simulink_rover_control_M->extModeInfo,
      &simulink_rover_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(simulink_rover_control_M->extModeInfo,
                        simulink_rover_control_M->Sizes.checksums);
    rteiSetTPtr(simulink_rover_control_M->extModeInfo, rtmGetTPtr
                (simulink_rover_control_M));
  }

  {
    f_codertarget_arduinobase_int_T *obj;
    uint32_T varargin_1;

    /* Start for MATLABSystem: '<S4>/ForkliftMotor' */
    simulink_rover_control_DW.obj_f.isInitialized = 0;
    obj = &simulink_rover_control_DW.obj_f.i2cObj;
    simulink_rover_control_DW.obj_f.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj_f.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj_f.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_f.matlabCodegenIsDeleted = false;
    simulink__SystemCore_setup_hvv2(&simulink_rover_control_DW.obj_f);

    /* End of SystemInitialize for SubSystem: '<Root>/Servo_Test_Enabled_Subsystem' */
    /* Start for MATLABSystem: '<S1>/Encoder1' */
    simulink_rover_control_DW.obj_n.isInitialized = 0;
    obj = &simulink_rover_control_DW.obj_n.i2cObj;
    simulink_rover_control_DW.obj_n.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj_n.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj_n.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_n.matlabCodegenIsDeleted = false;
    simulink_rover_SystemCore_setup(&simulink_rover_control_DW.obj_n);

    /* Start for MATLABSystem: '<S1>/Encoder2' */
    simulink_rover_control_DW.obj_l.isInitialized = 0;
    obj = &simulink_rover_control_DW.obj_l.i2cObj;
    simulink_rover_control_DW.obj_l.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj_l.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj_l.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_l.matlabCodegenIsDeleted = false;
    simulink_rov_SystemCore_setup_h(&simulink_rover_control_DW.obj_l);

    /* SystemInitialize for MATLABSystem: '<S1>/Encoder1' incorporates:
     *  Outport: '<S1>/Out1'
     */
    simulink_rover_control_B.Encoder1 = simulink_rover_control_P.Out1_Y0;

    /* SystemInitialize for MATLABSystem: '<S1>/Encoder2' incorporates:
     *  Outport: '<S1>/Out2'
     */
    simulink_rover_control_B.Encoder2 = simulink_rover_control_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Run Motor' */
    /* Start for MATLABSystem: '<S3>/M1 M2 DC Motors4' */
    simulink_rover_control_DW.obj_b.isInitialized = 0;
    obj = &simulink_rover_control_DW.obj_b.i2cObj;
    simulink_rover_control_DW.obj_b.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj_b.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj_b.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_b.matlabCodegenIsDeleted = false;
    simulink_r_SystemCore_setup_hvv(&simulink_rover_control_DW.obj_b);

    /* End of SystemInitialize for SubSystem: '<Root>/Run Motor' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Run Innertial Wheel' */
    /* Start for MATLABSystem: '<S2>/M1 M2 DC Motors4' */
    simulink_rover_control_DW.obj_p.isInitialized = 0;
    obj = &simulink_rover_control_DW.obj_p.i2cObj;
    simulink_rover_control_DW.obj_p.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj_p.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj_p.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_p.matlabCodegenIsDeleted = false;
    simulink_ro_SystemCore_setup_hv(&simulink_rover_control_DW.obj_p);

    /* End of SystemInitialize for SubSystem: '<Root>/Run Innertial Wheel' */

    /* Start for MATLABSystem: '<Root>/Battery Read' */
    obj = &simulink_rover_control_DW.obj.i2cObj;
    simulink_rover_control_DW.obj.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    simulink_rover_control_DW.obj.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    simulink_rover_control_DW.obj.i2cObj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj.SampleTime =
      simulink_rover_control_P.BatteryRead_SampleTime;
    simulink_rover_control_DW.obj.isSetupComplete = false;
    simulink_rover_control_DW.obj.isInitialized = 1;
    obj = &simulink_rover_control_DW.obj.i2cObj;
    simulink_rover_control_B.modename = MW_I2C_MASTER;
    simulink_rover_control_B.i2cname = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = MW_I2C_Open
      (simulink_rover_control_B.i2cname, simulink_rover_control_B.modename);
    simulink_rover_control_DW.obj.i2cObj.BusSpeed = 100000U;
    varargin_1 = simulink_rover_control_DW.obj.i2cObj.BusSpeed;
    MW_I2C_SetBusSpeed(obj->I2CDriverObj.MW_I2C_HANDLE, varargin_1);
    simulink_rover_control_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/On-board LED' */
    simulink_rover_control_DW.obj_j.matlabCodegenIsDeleted = false;
    simulink_rover_control_DW.obj_j.isInitialized = 1;
    digitalIOSetup(13, 1);
    simulink_rover_control_DW.obj_j.isSetupComplete = true;
  }
}

/* Model terminate function */
void simulink_rover_control_terminate(void)
{
  f_codertarget_arduinobase_int_T *obj;
  int32_T value;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];

  /* Terminate for MATLABSystem: '<Root>/Battery Read' */
  if (!simulink_rover_control_DW.obj.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj.isInitialized == 1) &&
        simulink_rover_control_DW.obj.isSetupComplete) {
      obj = &simulink_rover_control_DW.obj.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &simulink_rover_control_DW.obj.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Battery Read' */
  /* Terminate for Enabled SubSystem: '<Root>/Servo_Test_Enabled_Subsystem' */
  /* Terminate for MATLABSystem: '<S4>/ForkliftMotor' */
  if (!simulink_rover_control_DW.obj_f.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj_f.isInitialized == 1) &&
        simulink_rover_control_DW.obj_f.isSetupComplete) {
      mkrmotorcarrier_ServoMotor_Serv(&simulink_rover_control_DW.obj_f, 0);
      obj = &simulink_rover_control_DW.obj_f.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &simulink_rover_control_DW.obj_f.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ForkliftMotor' */
  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S1>/Encoder1' */
  if (!simulink_rover_control_DW.obj_n.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj_n.isInitialized == 1) &&
        simulink_rover_control_DW.obj_n.isSetupComplete) {
      obj = &simulink_rover_control_DW.obj_n.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &simulink_rover_control_DW.obj_n.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder1' */
  /* Terminate for MATLABSystem: '<S1>/Encoder2' */
  if (!simulink_rover_control_DW.obj_l.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj_l.isInitialized == 1) &&
        simulink_rover_control_DW.obj_l.isSetupComplete) {
      obj = &simulink_rover_control_DW.obj_l.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &simulink_rover_control_DW.obj_l.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Encoder2' */
  /* Terminate for Atomic SubSystem: '<Root>/Run Motor' */
  /* Terminate for MATLABSystem: '<S3>/M1 M2 DC Motors4' */
  if (!simulink_rover_control_DW.obj_b.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj_b.isInitialized == 1) &&
        simulink_rover_control_DW.obj_b.isSetupComplete) {
      value = 0;
      memcpy((void *)&data_uint8[0], (void *)&value, (size_t)4 * sizeof(uint8_T));
      final_data_to_write[0] = 5U;
      final_data_to_write[1] = 0U;
      final_data_to_write[2] = data_uint8[0];
      final_data_to_write[3] = data_uint8[1];
      final_data_to_write[4] = data_uint8[2];
      final_data_to_write[5] = data_uint8[3];
      obj = &simulink_rover_control_DW.obj_b.i2cObj;
      memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
             (size_t)6 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                         &SwappedDataBytes[0], 6U, false, false);
    }
  }

  obj = &simulink_rover_control_DW.obj_b.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/M1 M2 DC Motors4' */
  /* End of Terminate for SubSystem: '<Root>/Run Motor' */

  /* Terminate for Atomic SubSystem: '<Root>/Run Innertial Wheel' */
  /* Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors4' */
  if (!simulink_rover_control_DW.obj_p.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((simulink_rover_control_DW.obj_p.isInitialized == 1) &&
        simulink_rover_control_DW.obj_p.isSetupComplete) {
      value = 0;
      memcpy((void *)&data_uint8[0], (void *)&value, (size_t)4 * sizeof(uint8_T));
      final_data_to_write[0] = 5U;
      final_data_to_write[1] = 1U;
      final_data_to_write[2] = data_uint8[0];
      final_data_to_write[3] = data_uint8[1];
      final_data_to_write[4] = data_uint8[2];
      final_data_to_write[5] = data_uint8[3];
      obj = &simulink_rover_control_DW.obj_p.i2cObj;
      memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
             (size_t)6 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                         &SwappedDataBytes[0], 6U, false, false);
    }
  }

  obj = &simulink_rover_control_DW.obj_p.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors4' */
  /* End of Terminate for SubSystem: '<Root>/Run Innertial Wheel' */

  /* Terminate for MATLABSystem: '<Root>/On-board LED' */
  if (!simulink_rover_control_DW.obj_j.matlabCodegenIsDeleted) {
    simulink_rover_control_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/On-board LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
