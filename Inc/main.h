/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Bed_Temperature_Pin GPIO_PIN_0
#define Bed_Temperature_GPIO_Port GPIOC
#define EN_E2_Pin GPIO_PIN_7
#define EN_E2_GPIO_Port GPIOA
#define STEP_E2_Pin GPIO_PIN_4
#define STEP_E2_GPIO_Port GPIOC
#define DIR_E2_Pin GPIO_PIN_5
#define DIR_E2_GPIO_Port GPIOC
#define Extr1_Temperature_Pin GPIO_PIN_0
#define Extr1_Temperature_GPIO_Port GPIOB
#define EN_E1_Pin GPIO_PIN_7
#define EN_E1_GPIO_Port GPIOE
#define STEP_E1_Pin GPIO_PIN_8
#define STEP_E1_GPIO_Port GPIOE
#define DIR_E1_Pin GPIO_PIN_9
#define DIR_E1_GPIO_Port GPIOE
#define EN_Z2_Pin GPIO_PIN_10
#define EN_Z2_GPIO_Port GPIOE
#define STEP_Z2_Pin GPIO_PIN_11
#define STEP_Z2_GPIO_Port GPIOE
#define DIR_Z2_Pin GPIO_PIN_12
#define DIR_Z2_GPIO_Port GPIOE
#define EN_Z1_Pin GPIO_PIN_13
#define EN_Z1_GPIO_Port GPIOE
#define STEP_Z1_Pin GPIO_PIN_14
#define STEP_Z1_GPIO_Port GPIOE
#define DIR_Z1_Pin GPIO_PIN_15
#define DIR_Z1_GPIO_Port GPIOE
#define EN_Y_Pin GPIO_PIN_10
#define EN_Y_GPIO_Port GPIOB
#define STEP_Y_Pin GPIO_PIN_11
#define STEP_Y_GPIO_Port GPIOB
#define DIR_Y_Pin GPIO_PIN_12
#define DIR_Y_GPIO_Port GPIOB
#define DIR_X_Pin GPIO_PIN_13
#define DIR_X_GPIO_Port GPIOB
#define STEP_X_Pin GPIO_PIN_14
#define STEP_X_GPIO_Port GPIOB
#define EN_X_Pin GPIO_PIN_15
#define EN_X_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_9
#define LCD_RS_GPIO_Port GPIOD
#define LCD_RW_Pin GPIO_PIN_10
#define LCD_RW_GPIO_Port GPIOD
#define LCD_EN_Pin GPIO_PIN_11
#define LCD_EN_GPIO_Port GPIOD
#define LCD_DB0_Pin GPIO_PIN_12
#define LCD_DB0_GPIO_Port GPIOD
#define LCD_DB1_Pin GPIO_PIN_13
#define LCD_DB1_GPIO_Port GPIOD
#define LCD_DB2_Pin GPIO_PIN_14
#define LCD_DB2_GPIO_Port GPIOD
#define LCD_DB3_Pin GPIO_PIN_15
#define LCD_DB3_GPIO_Port GPIOD
#define LCD_DB4_Pin GPIO_PIN_6
#define LCD_DB4_GPIO_Port GPIOC
#define LCD_DB5_Pin GPIO_PIN_7
#define LCD_DB5_GPIO_Port GPIOC
#define LCD_DB6_Pin GPIO_PIN_8
#define LCD_DB6_GPIO_Port GPIOC
#define LCD_DB7_Pin GPIO_PIN_9
#define LCD_DB7_GPIO_Port GPIOC
#define USB_Fault_Pin GPIO_PIN_8
#define USB_Fault_GPIO_Port GPIOA
#define USB_Enable_Pin GPIO_PIN_10
#define USB_Enable_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_4
#define LED_GPIO_Port GPIOD
#define Button_Down_Pin GPIO_PIN_7
#define Button_Down_GPIO_Port GPIOD
#define Button_Up_Pin GPIO_PIN_3
#define Button_Up_GPIO_Port GPIOB
#define Button_Ok_Pin GPIO_PIN_4
#define Button_Ok_GPIO_Port GPIOB
#define Button_Back_Pin GPIO_PIN_5
#define Button_Back_GPIO_Port GPIOB
#define Bed_Heater_Pin GPIO_PIN_1
#define Bed_Heater_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
