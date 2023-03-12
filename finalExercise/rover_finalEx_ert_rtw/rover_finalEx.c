/*
 * rover_finalEx.c
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
#include "rtwtypes.h"
#include "rover_finalEx_types.h"
#include "rover_finalEx_private.h"
#include <math.h>
#include <string.h>
#include <stddef.h>

/* Named constants for Chart: '<Root>/Chart' */
#define rover_finalE_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define rover_finalEx_IN_Send          ((uint8_T)1U)
#define rover_finalEx_IN_modifyCMX     ((uint8_T)2U)
#define rover_finalEx_IN_modifyCMY     ((uint8_T)3U)
#define rover_finalEx_IN_modifyHEADING ((uint8_T)4U)

/* Named constants for Chart: '<Root>/StateLogic' */
#define rover_f_IN_MoveForwardAndPickUp ((uint8_T)2U)
#define rover_f_IN_MoveToNextWayPoint_a ((uint8_T)4U)
#define rover_fin_IN_MoveForwardAndDrop ((uint8_T)1U)
#define rover_fin_IN_MoveToNextWayPoint ((uint8_T)2U)
#define rover_finalEx_IN_DropForklift  ((uint8_T)1U)
#define rover_finalEx_IN_LiftForklift1 ((uint8_T)2U)
#define rover_finalEx_IN_MoveRemaining ((uint8_T)3U)
#define rover_finalEx_IN_Pause         ((uint8_T)3U)
#define rover_finalEx_IN_Pause1        ((uint8_T)4U)
#define rover_finalEx_IN_Stop          ((uint8_T)5U)
#define rover_finalEx_IN_Turn          ((uint8_T)6U)

/* Named constants for Chart: '<Root>/calcWaypoints' */
#define rover_finalEx_IN_calc          ((uint8_T)1U)
#define rover_finalEx_IN_modPos        ((uint8_T)2U)
#define rover_finalEx_IN_send          ((uint8_T)3U)
#define rover_finalEx_IN_waitForCalc   ((uint8_T)4U)

/* Block signals (default storage) */
B_rover_finalEx_T rover_finalEx_B;

/* Block states (default storage) */
DW_rover_finalEx_T rover_finalEx_DW;

/* Real-time model */
static RT_MODEL_rover_finalEx_T rover_finalEx_M_;
RT_MODEL_rover_finalEx_T *const rover_finalEx_M = &rover_finalEx_M_;

/* Forward declaration for local functions */
static real_T rover_finalEx_calcAngle(real_T Index);
static real_T rover_finalEx_calcDist(real_T Index);
static void mkrmotorcarrier_ServoMotor_Serv(const
  motorcarrier_blocks_mkrmotorc_T *obj, int32_T value);
static void rover_fina_SystemCore_setup_iac(codertarget_arduinobase_int_i_T *obj);
static void rover_fin_SystemCore_setup_iacf(codertarget_arduinobase_int_i_T *obj);
static void rover_fi_SystemCore_setup_iacfj(codertarget_arduinobase_int_i_T *obj);
static void rover_f_SystemCore_setup_iacfjg(codertarget_arduinobase_int_i_T *obj);
static void rover_finalEx_SystemCore_setup(motorcarrier_blocks_mkrmotorc_T *obj);
static void rover_finalE_SystemCore_setup_i(motorcarrier_blocks_mkrmoto_i_T *obj);
static void rover_final_SystemCore_setup_ia(motorcarrier_blocks_mkrmoto_i_T *obj);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

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

/* System initialize for function-call system: '<S4>/angCtrl' */
void rover_finalEx_angCtrl_Init(DW_angCtrl_rover_finalEx_T *localDW,
  P_angCtrl_rover_finalEx_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  localDW->Integrator_DSTATE = localP->PIDController1_InitialCondition;
}

/* Output and update for function-call system: '<S4>/angCtrl' */
void rover_finalEx_angCtrl(real_T rtu_desAng, B_angCtrl_rover_finalEx_T *localB,
  DW_angCtrl_rover_finalEx_T *localDW, P_angCtrl_rover_finalEx_T *localP)
{
  /* Sum: '<S50>/Sum' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   */
  localB->Sum = localP->PIDController1_P * rtu_desAng +
    localDW->Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
   *  Gain: '<S38>/Integral Gain'
   */
  localDW->Integrator_DSTATE += localP->PIDController1_I * rtu_desAng *
    localP->Integrator_gainval;
}

/* System initialize for function-call system: '<S4>/distCtrl' */
void rover_finalEx_distCtrl_Init(DW_distCtrl_rover_finalEx_T *localDW,
  P_distCtrl_rover_finalEx_T *localP)
{
  /* InitializeConditions for DiscreteIntegrator: '<S90>/Integrator' */
  localDW->Integrator_DSTATE = localP->PIDController_InitialConditionF;
}

/* Output and update for function-call system: '<S4>/distCtrl' */
void rover_finalEx_distCtrl(real_T rtu_desDist, B_distCtrl_rover_finalEx_T
  *localB, DW_distCtrl_rover_finalEx_T *localDW, P_distCtrl_rover_finalEx_T
  *localP)
{
  /* Sum: '<S99>/Sum' incorporates:
   *  DiscreteIntegrator: '<S90>/Integrator'
   *  Gain: '<S95>/Proportional Gain'
   */
  localB->Sum = localP->PIDController_P * rtu_desDist +
    localDW->Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S90>/Integrator' incorporates:
   *  Gain: '<S87>/Integral Gain'
   */
  localDW->Integrator_DSTATE += localP->PIDController_I * rtu_desDist *
    localP->Integrator_gainval;
}

/* Function for Chart: '<Root>/StateLogic' */
static real_T rover_finalEx_calcAngle(real_T Index)
{
  real_T desAngle;
  real_T distX_tmp;
  real_T distY_tmp;
  int32_T tmp;
  distX_tmp = rover_finalEx_B.waypoints[(int32_T)(Index + 1.0) - 1] -
    rover_finalEx_B.cmXout;
  distY_tmp = rover_finalEx_B.waypoints[(int32_T)(Index + 1.0) + 2] -
    rover_finalEx_B.cmYout;
  desAngle = atan(distY_tmp / distX_tmp) * 57.295779513082323;
  if ((distX_tmp > 0.0) && (distY_tmp >= 0.0)) {
    tmp = 1;
  } else if ((distX_tmp <= 0.0) && (distY_tmp > 0.0)) {
    tmp = 2;
  } else if ((distX_tmp < 0.0) && (distY_tmp <= 0.0)) {
    tmp = 3;
  } else if ((distX_tmp >= 0.0) && (distY_tmp < 0.0)) {
    tmp = 4;
  } else {
    tmp = 0;
  }

  switch (tmp) {
   case 1:
    break;

   case 2:
    desAngle = 180.0 - fabs(desAngle);
    break;

   case 3:
    desAngle += 180.0;
    break;

   case 4:
    desAngle += 360.0;
    break;

   default:
    desAngle = 0.0;
    break;
  }

  if (desAngle > 360.0) {
    desAngle -= 360.0;
  }

  desAngle -= 180.0;
  desAngle += rover_finalEx_B.headingOut;
  if (desAngle > 180.0) {
    desAngle -= 360.0;
  } else if (desAngle < -180.0) {
    desAngle += 360.0;
  }

  return desAngle;
}

/* Function for Chart: '<Root>/StateLogic' */
static real_T rover_finalEx_calcDist(real_T Index)
{
  real_T a;
  real_T b_a;
  a = rover_finalEx_B.waypoints[(int32_T)(Index + 1.0) - 1] -
    rover_finalEx_B.cmXout;
  b_a = rover_finalEx_B.waypoints[(int32_T)(Index + 1.0) + 2] -
    rover_finalEx_B.cmYout;
  return sqrt(a * a + b_a * b_a);
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
  motorcarrier_blocks_mkrmotorc_T *obj, int32_T value)
{
  int32_T x;
  int32_T z;
  uint32_T q;
  uint32_T y;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
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
  final_data_to_write[0] = 3U;
  final_data_to_write[1] = 2U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->i2cObj.I2CDriverObj.MW_I2C_HANDLE, 102U,
                     &SwappedDataBytes[0], 6U, false, false);
}

static void rover_fina_SystemCore_setup_iac(codertarget_arduinobase_int_i_T *obj)
{
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(1, 25000.0, obj->isServer_, 192, 168, 1, 2);
  obj->TunablePropsChanged = false;
}

static void rover_fin_SystemCore_setup_iacf(codertarget_arduinobase_int_i_T *obj)
{
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(2, 25001.0, obj->isServer_, 192, 168, 1, 2);
  obj->TunablePropsChanged = false;
}

static void rover_fi_SystemCore_setup_iacfj(codertarget_arduinobase_int_i_T *obj)
{
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(3, 25002.0, obj->isServer_, 192, 168, 1, 2);
  obj->TunablePropsChanged = false;
}

static void rover_f_SystemCore_setup_iacfjg(codertarget_arduinobase_int_i_T *obj)
{
  obj->isInitialized = 1;
  obj->isServer_ = 1.0;
  MW_WifiAndWifiTCPServerBegin(4, 25003.0, obj->isServer_, 192, 168, 1, 2);
  obj->TunablePropsChanged = false;
}

static void rover_finalEx_SystemCore_setup(motorcarrier_blocks_mkrmotorc_T *obj)
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

static void rover_finalE_SystemCore_setup_i(motorcarrier_blocks_mkrmoto_i_T *obj)
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

static void rover_final_SystemCore_setup_ia(motorcarrier_blocks_mkrmoto_i_T *obj)
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

/* Model step function */
void rover_finalEx_step(void)
{
  f_codertarget_arduinobase_int_T *obj;
  int32_T In;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];
  boolean_T guard1 = false;

  /* MATLABSystem: '<Root>/cmX' */
  if (rover_finalEx_DW.obj_lw.TunablePropsChanged) {
    rover_finalEx_DW.obj_lw.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(1, &rover_finalEx_B.heading, 8, &In,
                      rover_finalEx_DW.obj_lw.isServer_, 0U);

  /* Product: '<Root>/Product' incorporates:
   *  MATLABSystem: '<Root>/cmX'
   */
  rover_finalEx_B.cmX = rover_finalEx_B.heading * (real_T)In;

  /* MATLABSystem: '<Root>/cmY' */
  if (rover_finalEx_DW.obj_b.TunablePropsChanged) {
    rover_finalEx_DW.obj_b.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(2, &rover_finalEx_B.heading, 8, &In,
                      rover_finalEx_DW.obj_b.isServer_, 0U);

  /* Product: '<Root>/Product1' incorporates:
   *  MATLABSystem: '<Root>/cmY'
   */
  rover_finalEx_B.cmY = rover_finalEx_B.heading * (real_T)In;

  /* MATLABSystem: '<Root>/heading' */
  if (rover_finalEx_DW.obj_l.TunablePropsChanged) {
    rover_finalEx_DW.obj_l.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(3, &rover_finalEx_B.heading, 8, &In,
                      rover_finalEx_DW.obj_l.isServer_, 0U);

  /* Product: '<Root>/Product2' incorporates:
   *  MATLABSystem: '<Root>/heading'
   */
  rover_finalEx_B.heading *= (real_T)In;

  /* Chart: '<Root>/Chart' */
  if (rover_finalEx_DW.is_active_c2_rover_finalEx == 0U) {
    rover_finalEx_DW.is_active_c2_rover_finalEx = 1U;
    rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_Send;
    rover_finalEx_B.cmXout = rover_finalEx_DW.cmXOldValue;
    rover_finalEx_B.cmYout = rover_finalEx_DW.cmYOldValue;
    rover_finalEx_B.headingOut = rover_finalEx_DW.headingOldValue;
  } else {
    switch (rover_finalEx_DW.is_c2_rover_finalEx) {
     case rover_finalEx_IN_Send:
      if (rover_finalEx_B.cmX != 0.0) {
        rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_modifyCMX;
        rover_finalEx_DW.cmXOldValue = rover_finalEx_B.cmX;
      } else if (rover_finalEx_B.heading != 0.0) {
        rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_modifyHEADING;
        rover_finalEx_DW.headingOldValue = rover_finalEx_B.heading;
      } else if (rover_finalEx_B.cmY != 0.0) {
        rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_modifyCMY;
        rover_finalEx_DW.cmYOldValue = rover_finalEx_B.cmY;
      }
      break;

     case rover_finalEx_IN_modifyCMX:
      rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_Send;
      rover_finalEx_B.cmXout = rover_finalEx_DW.cmXOldValue;
      rover_finalEx_B.cmYout = rover_finalEx_DW.cmYOldValue;
      rover_finalEx_B.headingOut = rover_finalEx_DW.headingOldValue;
      break;

     case rover_finalEx_IN_modifyCMY:
      rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_Send;
      rover_finalEx_B.cmXout = rover_finalEx_DW.cmXOldValue;
      rover_finalEx_B.cmYout = rover_finalEx_DW.cmYOldValue;
      rover_finalEx_B.headingOut = rover_finalEx_DW.headingOldValue;
      break;

     default:
      /* case IN_modifyHEADING: */
      rover_finalEx_DW.is_c2_rover_finalEx = rover_finalEx_IN_Send;
      rover_finalEx_B.cmXout = rover_finalEx_DW.cmXOldValue;
      rover_finalEx_B.cmYout = rover_finalEx_DW.cmYOldValue;
      rover_finalEx_B.headingOut = rover_finalEx_DW.headingOldValue;
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/waypointData' */
  if (rover_finalEx_DW.obj_a.TunablePropsChanged) {
    rover_finalEx_DW.obj_a.TunablePropsChanged = false;
  }

  MW_WifiTCPFinalread(4, &rover_finalEx_B.heading, 8, &In,
                      rover_finalEx_DW.obj_a.isServer_, 0U);

  /* Product: '<Root>/Product3' incorporates:
   *  MATLABSystem: '<Root>/waypointData'
   */
  rover_finalEx_B.cmX = rover_finalEx_B.heading * (real_T)In;

  /* Chart: '<Root>/calcWaypoints' */
  if (rover_finalEx_DW.is_active_c1_rover_finalEx == 0U) {
    rover_finalEx_DW.is_active_c1_rover_finalEx = 1U;
    rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_waitForCalc;
    rover_finalEx_B.st = 0.0;
  } else {
    switch (rover_finalEx_DW.is_c1_rover_finalEx) {
     case rover_finalEx_IN_calc:
      if (rover_finalEx_DW.col >= 2.0) {
        rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_modPos;
        rover_finalEx_DW.col = 0.0;
        rover_finalEx_DW.row++;
        rover_finalEx_B.st = 0.0;
      } else {
        rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_waitForCalc;
        rover_finalEx_B.st = 0.0;
      }
      break;

     case rover_finalEx_IN_modPos:
      rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_waitForCalc;
      rover_finalEx_B.st = 0.0;
      break;

     case rover_finalEx_IN_send:
      break;

     default:
      /* case IN_waitForCalc: */
      if ((rover_finalEx_B.cmX != 0.0) && (rover_finalEx_DW.row <= 3.0)) {
        rover_finalEx_DW.col++;
        rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_calc;
        rover_finalEx_DW.way[((int32_T)rover_finalEx_DW.row + 3 * ((int32_T)
          rover_finalEx_DW.col - 1)) - 1] = rover_finalEx_B.cmX;
        rover_finalEx_B.st = 0.0;
      } else if (rover_finalEx_DW.row > 3.0) {
        rover_finalEx_DW.is_c1_rover_finalEx = rover_finalEx_IN_send;
        for (In = 0; In < 6; In++) {
          rover_finalEx_B.waypoints[In] = rover_finalEx_DW.way[In];
        }

        rover_finalEx_B.st = 1.0;
      } else {
        rover_finalEx_B.st = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/calcWaypoints' */

  /* Chart: '<Root>/StateLogic' */
  if (rover_finalEx_DW.temporalCounter_i1 < 127U) {
    rover_finalEx_DW.temporalCounter_i1++;
  }

  if (rover_finalEx_DW.is_active_c3_rover_finalEx == 0U) {
    rover_finalEx_DW.is_active_c3_rover_finalEx = 1U;
    rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Pause;
    rover_finalEx_B.v = 0.0;
    rover_finalEx_B.w = 0.0;
    rover_finalEx_B.FLAng = 160.0;
    rover_finalEx_B.active = 1.0;
  } else {
    guard1 = false;
    switch (rover_finalEx_DW.is_c3_rover_finalEx) {
     case rover_fin_IN_MoveForwardAndDrop:
      if (rover_finalEx_DW.is_MoveForwardAndDrop ==
          rover_finalEx_IN_DropForklift) {
        if (rover_finalEx_B.FLAng < 80.0) {
          if (rover_finalEx_DW.WPIndex == 3.0) {
            rover_finalEx_B.FLAng--;
            rover_finalEx_DW.is_MoveForwardAndDrop =
              rover_finalE_IN_NO_ACTIVE_CHILD;
            rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Stop;
            rover_finalEx_B.v = 0.0;
            rover_finalEx_B.w = 0.0;
            rover_finalEx_B.active = 0.0;
          } else {
            rover_finalEx_B.v = 0.0;
            rover_finalEx_B.FLAng--;
            rover_finalEx_DW.is_MoveForwardAndDrop =
              rover_finalE_IN_NO_ACTIVE_CHILD;
            rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Turn;
            rover_finalEx_DW.desAng = rover_finalEx_calcAngle
              (rover_finalEx_DW.WPIndex);

            /* Outputs for Function Call SubSystem: '<S4>/angCtrl' */
            rover_finalEx_angCtrl(rover_finalEx_DW.desAng,
                                  &rover_finalEx_B.angCtrl,
                                  &rover_finalEx_DW.angCtrl,
                                  &rover_finalEx_P.angCtrl);

            /* End of Outputs for SubSystem: '<S4>/angCtrl' */
            rover_finalEx_B.w = rover_finalEx_B.angCtrl.Sum;
          }
        } else {
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng--;
        }

        /* case IN_MoveToNextWayPoint: */
      } else if (fabs(rover_finalEx_DW.desDist) < 6.0) {
        rover_finalEx_DW.WPIndex++;
        rover_finalEx_DW.desDist = rover_finalEx_calcDist
          (rover_finalEx_DW.WPIndex) - 10.0;

        /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
        rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
          &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
          &rover_finalEx_P.distCtrl);

        /* End of Outputs for SubSystem: '<S4>/distCtrl' */
        rover_finalEx_DW.is_MoveForwardAndDrop = rover_finalEx_IN_DropForklift;
        rover_finalEx_B.v = 0.0;
        rover_finalEx_B.w = 0.0;
        rover_finalEx_B.FLAng--;
      } else {
        rover_finalEx_DW.desDist = rover_finalEx_calcDist
          (rover_finalEx_DW.WPIndex) - 10.0;

        /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
        rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
          &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
          &rover_finalEx_P.distCtrl);

        /* End of Outputs for SubSystem: '<S4>/distCtrl' */
        rover_finalEx_B.v = rover_finalEx_B.distCtrl.Sum;
        rover_finalEx_B.w = 0.0;
      }
      break;

     case rover_f_IN_MoveForwardAndPickUp:
      switch (rover_finalEx_DW.is_MoveForwardAndPickUp) {
       case rover_finalEx_IN_DropForklift:
        if (rover_finalEx_B.FLAng < 80.0) {
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng--;
          rover_finalEx_DW.is_MoveForwardAndPickUp =
            rover_finalEx_IN_MoveRemaining;
        } else {
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng--;
        }
        break;

       case rover_finalEx_IN_LiftForklift1:
        if (rover_finalEx_B.FLAng > 160.0) {
          if (rover_finalEx_DW.WPIndex == 3.0) {
            rover_finalEx_B.FLAng++;
            rover_finalEx_DW.is_MoveForwardAndPickUp =
              rover_finalE_IN_NO_ACTIVE_CHILD;
            rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Stop;
            rover_finalEx_B.v = 0.0;
            rover_finalEx_B.w = 0.0;
            rover_finalEx_B.active = 0.0;
          } else {
            rover_finalEx_B.v = 0.0;
            rover_finalEx_B.FLAng++;
            rover_finalEx_DW.is_MoveForwardAndPickUp =
              rover_finalE_IN_NO_ACTIVE_CHILD;
            rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Turn;
            rover_finalEx_DW.desAng = rover_finalEx_calcAngle
              (rover_finalEx_DW.WPIndex);

            /* Outputs for Function Call SubSystem: '<S4>/angCtrl' */
            rover_finalEx_angCtrl(rover_finalEx_DW.desAng,
                                  &rover_finalEx_B.angCtrl,
                                  &rover_finalEx_DW.angCtrl,
                                  &rover_finalEx_P.angCtrl);

            /* End of Outputs for SubSystem: '<S4>/angCtrl' */
            rover_finalEx_B.w = rover_finalEx_B.angCtrl.Sum;
          }
        } else {
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng++;
        }
        break;

       case rover_finalEx_IN_MoveRemaining:
        if (fabs(rover_finalEx_DW.desDist) < 6.0) {
          rover_finalEx_DW.WPIndex++;
          rover_finalEx_DW.desDist = rover_finalEx_calcDist
            (rover_finalEx_DW.WPIndex);

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_DW.is_MoveForwardAndPickUp =
            rover_finalEx_IN_LiftForklift1;
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng++;
        } else {
          rover_finalEx_DW.desDist = rover_finalEx_calcDist
            (rover_finalEx_DW.WPIndex);

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_B.v = rover_finalEx_B.distCtrl.Sum;
          rover_finalEx_B.w = 0.0;
        }
        break;

       default:
        /* case IN_MoveToNextWayPoint: */
        if (fabs(rover_finalEx_DW.desDist) < 20.0) {
          rover_finalEx_DW.desDist = rover_finalEx_calcDist
            (rover_finalEx_DW.WPIndex);

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_DW.is_MoveForwardAndPickUp =
            rover_finalEx_IN_DropForklift;
          rover_finalEx_B.v = 0.0;
          rover_finalEx_B.w = 0.0;
          rover_finalEx_B.FLAng--;
        } else {
          rover_finalEx_DW.desDist = rover_finalEx_calcDist
            (rover_finalEx_DW.WPIndex);

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_B.v = rover_finalEx_B.distCtrl.Sum;
          rover_finalEx_B.w = 0.0;
        }
        break;
      }
      break;

     case rover_finalEx_IN_Pause:
      rover_finalEx_B.active = 1.0;
      if ((rover_finalEx_B.st == 1.0) && (rover_finalEx_B.cmXout != 0.0) &&
          (rover_finalEx_B.cmYout != 0.0)) {
        rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Pause1;
        rover_finalEx_DW.temporalCounter_i1 = 0U;
        rover_finalEx_B.v = 0.0;
        rover_finalEx_B.w = 0.0;
        rover_finalEx_B.FLAng = 160.0;
      }
      break;

     case rover_finalEx_IN_Pause1:
      rover_finalEx_B.active = 1.0;
      if (rover_finalEx_DW.temporalCounter_i1 >= 100U) {
        rover_finalEx_DW.is_c3_rover_finalEx = rover_finalEx_IN_Turn;
        rover_finalEx_DW.desAng = rover_finalEx_calcAngle
          (rover_finalEx_DW.WPIndex);

        /* Outputs for Function Call SubSystem: '<S4>/angCtrl' */
        rover_finalEx_angCtrl(rover_finalEx_DW.desAng, &rover_finalEx_B.angCtrl,
                              &rover_finalEx_DW.angCtrl,
                              &rover_finalEx_P.angCtrl);

        /* End of Outputs for SubSystem: '<S4>/angCtrl' */
        rover_finalEx_B.w = rover_finalEx_B.angCtrl.Sum;
      }
      break;

     case rover_finalEx_IN_Stop:
      rover_finalEx_B.active = 0.0;
      break;

     default:
      /* case IN_Turn: */
      if (fabs(rover_finalEx_DW.desAng) < 8.0) {
        if (rover_finalEx_DW.WPIndex == 1.0) {
          rover_finalEx_B.w = 0.0;
          rover_finalEx_DW.is_c3_rover_finalEx = rover_f_IN_MoveForwardAndPickUp;
          rover_finalEx_DW.is_MoveForwardAndPickUp =
            rover_f_IN_MoveToNextWayPoint_a;
          rover_finalEx_DW.desDist = rover_finalEx_calcDist(1.0);

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_B.v = rover_finalEx_B.distCtrl.Sum;
        } else if (rover_finalEx_DW.WPIndex == 2.0) {
          rover_finalEx_B.w = 0.0;
          rover_finalEx_DW.is_c3_rover_finalEx = rover_fin_IN_MoveForwardAndDrop;
          rover_finalEx_DW.is_MoveForwardAndDrop =
            rover_fin_IN_MoveToNextWayPoint;
          rover_finalEx_DW.desDist = rover_finalEx_calcDist(2.0) - 10.0;

          /* Outputs for Function Call SubSystem: '<S4>/distCtrl' */
          rover_finalEx_distCtrl(rover_finalEx_DW.desDist,
            &rover_finalEx_B.distCtrl, &rover_finalEx_DW.distCtrl,
            &rover_finalEx_P.distCtrl);

          /* End of Outputs for SubSystem: '<S4>/distCtrl' */
          rover_finalEx_B.v = rover_finalEx_B.distCtrl.Sum;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      rover_finalEx_DW.desAng = rover_finalEx_calcAngle(rover_finalEx_DW.WPIndex);
      rover_finalEx_B.v = 0.0;

      /* Outputs for Function Call SubSystem: '<S4>/angCtrl' */
      rover_finalEx_angCtrl(rover_finalEx_DW.desAng, &rover_finalEx_B.angCtrl,
                            &rover_finalEx_DW.angCtrl, &rover_finalEx_P.angCtrl);

      /* End of Outputs for SubSystem: '<S4>/angCtrl' */
      rover_finalEx_B.w = rover_finalEx_B.angCtrl.Sum;
    }
  }

  /* End of Chart: '<Root>/StateLogic' */

  /* MATLABSystem: '<Root>/ForkliftMotor' */
  rover_finalEx_B.cmX = rt_roundd_snf(rover_finalEx_B.FLAng);
  if (rover_finalEx_B.cmX < 2.147483648E+9) {
    if (rover_finalEx_B.cmX >= -2.147483648E+9) {
      In = (int32_T)rover_finalEx_B.cmX;
    } else {
      In = MIN_int32_T;
    }
  } else {
    In = MAX_int32_T;
  }

  mkrmotorcarrier_ServoMotor_Serv(&rover_finalEx_DW.obj, In);

  /* End of MATLABSystem: '<Root>/ForkliftMotor' */

  /* Gain: '<S6>/ Gain' */
  rover_finalEx_B.cmX = 1.0 / rover_finalEx_P.r;

  /* SignalConversion generated from: '<S6>/Matrix multiplication' incorporates:
   *  Gain: '<S107>/Gain1'
   */
  rover_finalEx_B.cmY = rover_finalEx_P.Gain1_Gain * rover_finalEx_B.w;

  /* Gain: '<S6>/ Gain' incorporates:
   *  Gain: '<S6>/Matrix multiplication'
   *  SignalConversion generated from: '<S6>/Matrix multiplication'
   */
  rover_finalEx_B.heading = (rover_finalEx_P.Matrixmultiplication_Gain[1] *
    rover_finalEx_B.v + rover_finalEx_P.Matrixmultiplication_Gain[3] *
    rover_finalEx_B.cmY) * rover_finalEx_B.cmX;

  /* Gain: '<S2>/Gain' incorporates:
   *  Gain: '<S108>/Gain'
   *  Gain: '<S2>/deg//sec to rpm'
   *  Gain: '<S6>/ Gain'
   *  Gain: '<S6>/Matrix multiplication'
   *  Lookup_n-D: '<S2>/Lookup table'
   *  SignalConversion generated from: '<S6>/Matrix multiplication'
   */
  rover_finalEx_B.cmX = look1_binlxpw
    ((rover_finalEx_P.Matrixmultiplication_Gain[0] * rover_finalEx_B.v +
      rover_finalEx_P.Matrixmultiplication_Gain[2] * rover_finalEx_B.cmY) *
     rover_finalEx_B.cmX * rover_finalEx_P.Gain_Gain *
     rover_finalEx_P.degsectorpm_Gain, rover_finalEx_P.speedMono_L,
     rover_finalEx_P.PWMcmdMono_L, 29U) * rover_finalEx_P.Gain_Gain_g;

  /* MATLABSystem: '<S2>/M1 M2 DC Motors' */
  if (rover_finalEx_B.cmX > 100.0) {
    In = 100;
  } else if (rover_finalEx_B.cmX < -100.0) {
    In = -100;
  } else {
    rover_finalEx_B.cmX = rt_roundd_snf(rover_finalEx_B.cmX);
    if (rover_finalEx_B.cmX < 2.147483648E+9) {
      In = (int32_T)rover_finalEx_B.cmX;
    } else {
      In = MAX_int32_T;
    }
  }

  memcpy((void *)&data_uint8[0], (void *)&In, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 5U;
  final_data_to_write[1] = 1U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  obj = &rover_finalEx_DW.obj_f.i2cObj;
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes[0],
                     6U, false, false);

  /* End of MATLABSystem: '<S2>/M1 M2 DC Motors' */

  /* Gain: '<S3>/Gain' incorporates:
   *  Gain: '<S109>/Gain'
   *  Gain: '<S3>/deg//sec to rpm'
   *  Lookup_n-D: '<S3>/Lookup table'
   */
  rover_finalEx_B.cmX = look1_binlxpw(rover_finalEx_P.Gain_Gain_m *
    rover_finalEx_B.heading * rover_finalEx_P.degsectorpm_Gain_d,
    rover_finalEx_P.speedMono_R, rover_finalEx_P.PWMcmdMono_R, 26U) *
    rover_finalEx_P.Gain_Gain_i;

  /* MATLABSystem: '<S3>/M1 M2 DC Motors' */
  if (rover_finalEx_B.cmX > 100.0) {
    In = 100;
  } else if (rover_finalEx_B.cmX < -100.0) {
    In = -100;
  } else {
    rover_finalEx_B.cmX = rt_roundd_snf(rover_finalEx_B.cmX);
    if (rover_finalEx_B.cmX < 2.147483648E+9) {
      In = (int32_T)rover_finalEx_B.cmX;
    } else {
      In = MAX_int32_T;
    }
  }

  memcpy((void *)&data_uint8[0], (void *)&In, (size_t)4 * sizeof(uint8_T));
  final_data_to_write[0] = 5U;
  final_data_to_write[1] = 0U;
  final_data_to_write[2] = data_uint8[0];
  final_data_to_write[3] = data_uint8[1];
  final_data_to_write[4] = data_uint8[2];
  final_data_to_write[5] = data_uint8[3];
  obj = &rover_finalEx_DW.obj_n.i2cObj;
  memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0], (size_t)
         6 * sizeof(uint8_T));
  MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U, &SwappedDataBytes[0],
                     6U, false, false);

  /* End of MATLABSystem: '<S3>/M1 M2 DC Motors' */

  /* MATLABSystem: '<Root>/active1' */
  rover_finalEx_B.cmX = rover_finalEx_B.active;
  MW_WifiTCPFinalWrite(0, &rover_finalEx_B.cmX, rover_finalEx_DW.obj_o.isServer_,
                       8);
}

/* Model initialize function */
void rover_finalEx_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(rover_finalEx_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &rover_finalEx_B), 0,
                sizeof(B_rover_finalEx_T));

  /* states (dwork) */
  (void) memset((void *)&rover_finalEx_DW, 0,
                sizeof(DW_rover_finalEx_T));

  {
    f_codertarget_arduinobase_int_T *obj;
    int32_T i;

    /* Start for MATLABSystem: '<Root>/cmX' */
    rover_finalEx_DW.obj_lw.isInitialized = 0;
    rover_fina_SystemCore_setup_iac(&rover_finalEx_DW.obj_lw);

    /* Start for MATLABSystem: '<Root>/cmY' */
    rover_finalEx_DW.obj_b.isInitialized = 0;
    rover_fin_SystemCore_setup_iacf(&rover_finalEx_DW.obj_b);

    /* Start for MATLABSystem: '<Root>/heading' */
    rover_finalEx_DW.obj_l.isInitialized = 0;
    rover_fi_SystemCore_setup_iacfj(&rover_finalEx_DW.obj_l);

    /* Start for MATLABSystem: '<Root>/waypointData' */
    rover_finalEx_DW.obj_a.isInitialized = 0;
    rover_f_SystemCore_setup_iacfjg(&rover_finalEx_DW.obj_a);

    /* Start for MATLABSystem: '<Root>/ForkliftMotor' */
    rover_finalEx_DW.obj.isInitialized = 0;
    obj = &rover_finalEx_DW.obj.i2cObj;
    rover_finalEx_DW.obj.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    rover_finalEx_DW.obj.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    rover_finalEx_DW.obj.i2cObj.matlabCodegenIsDeleted = false;
    rover_finalEx_DW.obj.matlabCodegenIsDeleted = false;
    rover_finalEx_SystemCore_setup(&rover_finalEx_DW.obj);

    /* Start for MATLABSystem: '<S2>/M1 M2 DC Motors' */
    rover_finalEx_DW.obj_f.isInitialized = 0;
    obj = &rover_finalEx_DW.obj_f.i2cObj;
    rover_finalEx_DW.obj_f.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    rover_finalEx_DW.obj_f.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    rover_finalEx_DW.obj_f.i2cObj.matlabCodegenIsDeleted = false;
    rover_finalEx_DW.obj_f.matlabCodegenIsDeleted = false;
    rover_finalE_SystemCore_setup_i(&rover_finalEx_DW.obj_f);

    /* Start for MATLABSystem: '<S3>/M1 M2 DC Motors' */
    rover_finalEx_DW.obj_n.isInitialized = 0;
    obj = &rover_finalEx_DW.obj_n.i2cObj;
    rover_finalEx_DW.obj_n.i2cObj.DefaultMaximumBusSpeedInHz = 400000.0;
    rover_finalEx_DW.obj_n.i2cObj.isInitialized = 0;
    obj->I2CDriverObj.MW_I2C_HANDLE = NULL;
    rover_finalEx_DW.obj_n.i2cObj.matlabCodegenIsDeleted = false;
    rover_finalEx_DW.obj_n.matlabCodegenIsDeleted = false;
    rover_final_SystemCore_setup_ia(&rover_finalEx_DW.obj_n);

    /* Start for MATLABSystem: '<Root>/active1' */
    rover_finalEx_DW.obj_o.isInitialized = 1;
    rover_finalEx_DW.obj_o.isServer_ = 1.0;
    MW_WifiAndWifiTCPServerBegin(0, 25005.0, rover_finalEx_DW.obj_o.isServer_,
      192, 168, 1, 2);

    /* SystemInitialize for Chart: '<Root>/Chart' */
    rover_finalEx_DW.is_active_c2_rover_finalEx = 0U;
    rover_finalEx_DW.is_c2_rover_finalEx = rover_finalE_IN_NO_ACTIVE_CHILD;
    rover_finalEx_DW.cmXOldValue = 0.0;
    rover_finalEx_DW.cmYOldValue = 0.0;
    rover_finalEx_DW.headingOldValue = 0.0;
    rover_finalEx_B.cmXout = 0.0;
    rover_finalEx_B.cmYout = 0.0;
    rover_finalEx_B.headingOut = 0.0;

    /* SystemInitialize for Chart: '<Root>/calcWaypoints' */
    rover_finalEx_DW.is_active_c1_rover_finalEx = 0U;
    rover_finalEx_DW.is_c1_rover_finalEx = rover_finalE_IN_NO_ACTIVE_CHILD;
    rover_finalEx_DW.row = 1.0;
    rover_finalEx_DW.col = 0.0;
    for (i = 0; i < 6; i++) {
      rover_finalEx_DW.way[i] = 0.0;
      rover_finalEx_B.waypoints[i] = 0.0;
    }

    rover_finalEx_B.st = 0.0;

    /* End of SystemInitialize for Chart: '<Root>/calcWaypoints' */
    rover_finalEx_DW.is_MoveForwardAndDrop = rover_finalE_IN_NO_ACTIVE_CHILD;
    rover_finalEx_DW.is_MoveForwardAndPickUp = rover_finalE_IN_NO_ACTIVE_CHILD;
    rover_finalEx_DW.temporalCounter_i1 = 0U;
    rover_finalEx_DW.is_active_c3_rover_finalEx = 0U;
    rover_finalEx_DW.is_c3_rover_finalEx = rover_finalE_IN_NO_ACTIVE_CHILD;
    rover_finalEx_DW.desDist = 0.0;
    rover_finalEx_DW.desAng = 0.0;
    rover_finalEx_DW.WPIndex = 1.0;
    rover_finalEx_B.v = 0.0;
    rover_finalEx_B.w = 0.0;
    rover_finalEx_B.FLAng = 0.0;
    rover_finalEx_B.active = 0.0;

    /* SystemInitialize for Chart: '<Root>/StateLogic' incorporates:
     *  SubSystem: '<S4>/angCtrl'
     */
    rover_finalEx_angCtrl_Init(&rover_finalEx_DW.angCtrl,
      &rover_finalEx_P.angCtrl);

    /* SystemInitialize for Chart: '<Root>/StateLogic' incorporates:
     *  SubSystem: '<S4>/distCtrl'
     */
    rover_finalEx_distCtrl_Init(&rover_finalEx_DW.distCtrl,
      &rover_finalEx_P.distCtrl);
  }
}

/* Model terminate function */
void rover_finalEx_terminate(void)
{
  f_codertarget_arduinobase_int_T *obj;
  int32_T value;
  uint8_T SwappedDataBytes[6];
  uint8_T final_data_to_write[6];
  uint8_T data_uint8[4];

  /* Terminate for MATLABSystem: '<Root>/ForkliftMotor' */
  if (!rover_finalEx_DW.obj.matlabCodegenIsDeleted) {
    rover_finalEx_DW.obj.matlabCodegenIsDeleted = true;
    if ((rover_finalEx_DW.obj.isInitialized == 1) &&
        rover_finalEx_DW.obj.isSetupComplete) {
      mkrmotorcarrier_ServoMotor_Serv(&rover_finalEx_DW.obj, 0);
      obj = &rover_finalEx_DW.obj.i2cObj;
      MW_I2C_Close(obj->I2CDriverObj.MW_I2C_HANDLE);
    }
  }

  obj = &rover_finalEx_DW.obj.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/ForkliftMotor' */

  /* Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors' */
  if (!rover_finalEx_DW.obj_f.matlabCodegenIsDeleted) {
    rover_finalEx_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((rover_finalEx_DW.obj_f.isInitialized == 1) &&
        rover_finalEx_DW.obj_f.isSetupComplete) {
      value = 0;
      memcpy((void *)&data_uint8[0], (void *)&value, (size_t)4 * sizeof(uint8_T));
      final_data_to_write[0] = 5U;
      final_data_to_write[1] = 1U;
      final_data_to_write[2] = data_uint8[0];
      final_data_to_write[3] = data_uint8[1];
      final_data_to_write[4] = data_uint8[2];
      final_data_to_write[5] = data_uint8[3];
      obj = &rover_finalEx_DW.obj_f.i2cObj;
      memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
             (size_t)6 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                         &SwappedDataBytes[0], 6U, false, false);
    }
  }

  obj = &rover_finalEx_DW.obj_f.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/M1 M2 DC Motors' */

  /* Terminate for MATLABSystem: '<S3>/M1 M2 DC Motors' */
  if (!rover_finalEx_DW.obj_n.matlabCodegenIsDeleted) {
    rover_finalEx_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((rover_finalEx_DW.obj_n.isInitialized == 1) &&
        rover_finalEx_DW.obj_n.isSetupComplete) {
      value = 0;
      memcpy((void *)&data_uint8[0], (void *)&value, (size_t)4 * sizeof(uint8_T));
      final_data_to_write[0] = 5U;
      final_data_to_write[1] = 0U;
      final_data_to_write[2] = data_uint8[0];
      final_data_to_write[3] = data_uint8[1];
      final_data_to_write[4] = data_uint8[2];
      final_data_to_write[5] = data_uint8[3];
      obj = &rover_finalEx_DW.obj_n.i2cObj;
      memcpy((void *)&SwappedDataBytes[0], (void *)&final_data_to_write[0],
             (size_t)6 * sizeof(uint8_T));
      MW_I2C_MasterWrite(obj->I2CDriverObj.MW_I2C_HANDLE, 102U,
                         &SwappedDataBytes[0], 6U, false, false);
    }
  }

  obj = &rover_finalEx_DW.obj_n.i2cObj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/M1 M2 DC Motors' */
}
