/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "fatfs.h"
#include "tim.h"
#include "usart.h"
#include "usb_host.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <wchar.h>

#include "TextConverter_LCD.h"
#include "MainMenu_Menu.h"
#include "Constructor_Menu.h"
#include "State_USBdrive.h"
#include "Driver_USBdrive.h"

#include "GcodeConverter_Gcode.h"
#include "Descritization_Gcode.h"
#include "Buffer_Gcode.h"
#include "VirtualPrinters_Gcode.h"
#include "temperature.h"
#include "coordinates.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static uint8_t bed_pwm = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_USB_HOST_Process(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#if defined(__GNUC__)
int _write(int fd, char * ptr, int len)
{
  HAL_UART_Transmit(&huart2, (uint8_t *) ptr, len, HAL_MAX_DELAY);
  return len;
}
#elif defined (__ICCARM__)
#include "LowLevelIOInterface.h"
size_t __write(int handle, const unsigned char * buffer, size_t size)
{
  HAL_UART_Transmit(&huart2, (uint8_t *) buffer, size, HAL_MAX_DELAY);
  return size;
}
#elif defined (__CC_ARM)
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}
#endif
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_FATFS_Init();
  MX_USB_HOST_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM6_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim3);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
  HAL_TIM_Base_Start_IT(&htim4);
  HAL_NVIC_EnableIRQ(TIM4_IRQn);
  create_coordinates();
  HAL_TIM_Base_Start_IT(&htim5);
  HAL_NVIC_EnableIRQ(TIM5_IRQn);

  HAL_TIM_Base_Start(&htim1);
  HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);

  HAL_TIM_Base_Start_IT(&htim6);
  HAL_TIM_Base_Start_IT(&htim7);

  createGcodeConverter_Gcode();
  createDescretization_Gcode();
  createDescreteCommandBuffer_Gcode();
  createCommandBuffer_Gcode();
  virtualPrintersCreate_Gcode();

  HAL_Delay(500);
  create_TextConverter_LCD();
  setMainMenu_Menu();
  createState_USBdrive();
  createDriver_USBdrive();
  init_Temperature();


  putLine_TextConverter_LCD(getTitle_Menu(), 1);  updateLine_TextConverter_LCD(1);
  wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
  putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);  currName[0] = *L" ";
  moveDown_Menu();
  putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
  moveDown_Menu();
  putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
  moveToTheFirstNode_Menu();


//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 50000);
  /*
  for (uint16_t i=0; i<65535; i++){
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, i);
    HAL_Delay(1);
  }
  */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setExtruder1_Temperature(220);
  setBed_Temperature(60);
  
  while (1)
  {
    /* USER CODE END WHILE */
    MX_USB_HOST_Process();

    /* USER CODE BEGIN 3 */
    if (HAL_GPIO_ReadPin(Button_Down_GPIO_Port, Button_Down_Pin) & GPIO_PIN_SET)  getCurrentNode_Menu()->pfnDown();
    if (HAL_GPIO_ReadPin(Button_Up_GPIO_Port, Button_Up_Pin) & GPIO_PIN_SET)      getCurrentNode_Menu()->pfnUp();
    if (HAL_GPIO_ReadPin(Button_Ok_GPIO_Port, Button_Ok_Pin) & GPIO_PIN_SET)      getCurrentNode_Menu()->pfnOk();
    if (HAL_GPIO_ReadPin(Button_Back_GPIO_Port, Button_Back_Pin) & GPIO_PIN_SET)  getCurrentNode_Menu()->pfnBack();

    if (getState_USBdrive() == READY_USBDRIVE)  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    else                                        HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    printf("%d %d\n", (uint8_t)getExtruder1_Temperature(), (uint8_t)getBed_Temperature());
    HAL_Delay(100);
    
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC|RCC_PERIPHCLK_USB;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV4;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the Systick interrupt time
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM6)
  {

    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = ADC_CHANNEL_8;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);

    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 10000) == HAL_OK)
    {
      regNewADCValue_Extruder1_Temperature(HAL_ADC_GetValue(&hadc1));
    }
    sConfig.Channel = ADC_CHANNEL_10;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
    HAL_ADC_ConfigChannel(&hadc1, &sConfig);
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 10000) == HAL_OK)
    {
      regNewADCValue_Bed_Temperature(HAL_ADC_GetValue(&hadc1));
    }
    pidTimerCallBack_Temperature();
  }
  if (htim->Instance == TIM7)
  {
    static uint8_t i;
    if (++i <= bed_pwm)
    {
      HAL_GPIO_WritePin(Bed_Heater_GPIO_Port, Bed_Heater_Pin, GPIO_PIN_SET);
    }
    else
    {
      HAL_GPIO_WritePin(Bed_Heater_GPIO_Port, Bed_Heater_Pin, GPIO_PIN_RESET);
    }
  }
}

void setExtruder1_PWM(uint16_t val)
{
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, val);
}
void setBed_PWM(uint16_t val)
{
  bed_pwm = val;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
