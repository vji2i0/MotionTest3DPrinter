#include "GPIO_Motors.h"

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stm32f1xx_hal.h"

#include "coordinates.h"

void EnableX_Motors(void)   {HAL_GPIO_WritePin(EN_X_GPIO_Port, EN_X_Pin, GPIO_PIN_RESET);       }
void DisableX_Motors(void)  {HAL_GPIO_WritePin(EN_X_GPIO_Port, EN_X_Pin, GPIO_PIN_SET);         }
void ForwardX_Motors(void)  {HAL_GPIO_WritePin(DIR_X_GPIO_Port, DIR_X_Pin, GPIO_PIN_SET);       incX_coordinates(); }
void BackwardX_Motors(void) {HAL_GPIO_WritePin(DIR_X_GPIO_Port, DIR_X_Pin, GPIO_PIN_RESET);     decX_coordinates(); }
void StepOnX_Motors(void)   {HAL_GPIO_WritePin(STEP_X_GPIO_Port, STEP_X_Pin, GPIO_PIN_SET);     }
void StepOffX_Motors(void)  {HAL_GPIO_WritePin(STEP_X_GPIO_Port, STEP_X_Pin, GPIO_PIN_RESET);   }
void EnableY_Motors(void)   {HAL_GPIO_WritePin(EN_Y_GPIO_Port, EN_Y_Pin, GPIO_PIN_RESET);       }
void DisableY_Motors(void)  {HAL_GPIO_WritePin(EN_Y_GPIO_Port, EN_Y_Pin, GPIO_PIN_SET);         }
void ForwardY_Motors(void)  {HAL_GPIO_WritePin(DIR_Y_GPIO_Port, DIR_Y_Pin, GPIO_PIN_SET);       incY_coordinates(); }
void BackwardY_Motors(void) {HAL_GPIO_WritePin(DIR_Y_GPIO_Port, DIR_Y_Pin, GPIO_PIN_RESET);     decY_coordinates(); }
void StepOnY_Motors(void)   {HAL_GPIO_WritePin(STEP_Y_GPIO_Port, STEP_Y_Pin, GPIO_PIN_SET);     }
void StepOffY_Motors(void)  {HAL_GPIO_WritePin(STEP_Y_GPIO_Port, STEP_Y_Pin, GPIO_PIN_RESET);   }
void EnableZ_Motors(void)   {HAL_GPIO_WritePin(EN_Z1_GPIO_Port, EN_Z1_Pin, GPIO_PIN_RESET);     HAL_GPIO_WritePin(EN_Z2_GPIO_Port, EN_Z2_Pin, GPIO_PIN_RESET);      }
void DisableZ_Motors(void)  {HAL_GPIO_WritePin(EN_Z1_GPIO_Port, EN_Z1_Pin, GPIO_PIN_SET);       HAL_GPIO_WritePin(EN_Z2_GPIO_Port, EN_Z2_Pin, GPIO_PIN_SET);        }
void ForwardZ_Motors(void)  {HAL_GPIO_WritePin(DIR_Z1_GPIO_Port, DIR_Z1_Pin, GPIO_PIN_SET);     HAL_GPIO_WritePin(DIR_Z2_GPIO_Port, DIR_Z2_Pin, GPIO_PIN_SET);      incZ_coordinates(); }
void BackwardZ_Motors(void) {HAL_GPIO_WritePin(DIR_Z1_GPIO_Port, DIR_Z1_Pin, GPIO_PIN_RESET);   HAL_GPIO_WritePin(DIR_Z2_GPIO_Port, DIR_Z2_Pin, GPIO_PIN_RESET);    decZ_coordinates(); }
void StepOnZ_Motors(void)   {HAL_GPIO_WritePin(STEP_Z1_GPIO_Port, STEP_Z1_Pin, GPIO_PIN_SET);   HAL_GPIO_WritePin(STEP_Z2_GPIO_Port, STEP_Z2_Pin, GPIO_PIN_SET);    }
void StepOffZ_Motors(void)  {HAL_GPIO_WritePin(STEP_Z1_GPIO_Port, STEP_Z1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(STEP_Z2_GPIO_Port, STEP_Z2_Pin, GPIO_PIN_RESET);  }
void EnableE_Motors(void)   {HAL_GPIO_WritePin(EN_E1_GPIO_Port, EN_E1_Pin, GPIO_PIN_RESET);     HAL_GPIO_WritePin(EN_E2_GPIO_Port, EN_E2_Pin, GPIO_PIN_RESET);      }
void DisableE_Motors(void)  {HAL_GPIO_WritePin(EN_E1_GPIO_Port, EN_E1_Pin, GPIO_PIN_SET);       HAL_GPIO_WritePin(EN_E2_GPIO_Port, EN_E2_Pin, GPIO_PIN_SET);        }
void ForwardE_Motors(void)  {HAL_GPIO_WritePin(DIR_E1_GPIO_Port, DIR_E1_Pin, GPIO_PIN_SET);     HAL_GPIO_WritePin(DIR_E2_GPIO_Port, DIR_E2_Pin, GPIO_PIN_SET);      incE_coordinates(); }
void BackwardE_Motors(void) {HAL_GPIO_WritePin(DIR_E1_GPIO_Port, DIR_E1_Pin, GPIO_PIN_RESET);   HAL_GPIO_WritePin(DIR_E2_GPIO_Port, DIR_E2_Pin, GPIO_PIN_RESET);    decE_coordinates(); }
void StepOnE_Motors(void)   {HAL_GPIO_WritePin(STEP_E1_GPIO_Port, STEP_E1_Pin, GPIO_PIN_SET);   HAL_GPIO_WritePin(STEP_E2_GPIO_Port, STEP_E2_Pin, GPIO_PIN_SET);    }
void StepOffE_Motors(void)  {HAL_GPIO_WritePin(STEP_E1_GPIO_Port, STEP_E1_Pin, GPIO_PIN_RESET); HAL_GPIO_WritePin(STEP_E2_GPIO_Port, STEP_E2_Pin, GPIO_PIN_RESET);  }
