#include "GPIOandTIM_LCD.h"
#include "Driver_LCD.h"

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "stdbool.h"
#include "stm32f1xx_hal.h"

void RS_high_LCD(void)  {HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);}
void RS_low_LCD(void)   {HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);}
void RW_high_LCD(void)  {HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_SET);}
void RW_low_LCD(void)   {HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);}
void E_high_LCD(void)   {HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);}
void E_low_LCD(void)    {HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);}
void DB0_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB0_GPIO_Port, LCD_DB0_Pin, GPIO_PIN_SET);}
void DB0_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB0_GPIO_Port, LCD_DB0_Pin, GPIO_PIN_RESET);}
void DB1_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB1_GPIO_Port, LCD_DB1_Pin, GPIO_PIN_SET);}
void DB1_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB1_GPIO_Port, LCD_DB1_Pin, GPIO_PIN_RESET);}
void DB2_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB2_GPIO_Port, LCD_DB2_Pin, GPIO_PIN_SET);}
void DB2_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB2_GPIO_Port, LCD_DB2_Pin, GPIO_PIN_RESET);}
void DB3_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB3_GPIO_Port, LCD_DB3_Pin, GPIO_PIN_SET);}
void DB3_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB3_GPIO_Port, LCD_DB3_Pin, GPIO_PIN_RESET);}
void DB4_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB4_GPIO_Port, LCD_DB4_Pin, GPIO_PIN_SET);}
void DB4_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB4_GPIO_Port, LCD_DB4_Pin, GPIO_PIN_RESET);}
void DB5_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB5_GPIO_Port, LCD_DB5_Pin, GPIO_PIN_SET);}
void DB5_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB5_GPIO_Port, LCD_DB5_Pin, GPIO_PIN_RESET);}
void DB6_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB6_GPIO_Port, LCD_DB6_Pin, GPIO_PIN_SET);}
void DB6_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB6_GPIO_Port, LCD_DB6_Pin, GPIO_PIN_RESET);}
void DB7_high_LCD(void) {HAL_GPIO_WritePin(LCD_DB7_GPIO_Port, LCD_DB7_Pin, GPIO_PIN_SET);}
void DB7_low_LCD(void)  {HAL_GPIO_WritePin(LCD_DB7_GPIO_Port, LCD_DB7_Pin, GPIO_PIN_RESET);}

int Ready_LCD(void)
{
    HAL_Delay(1);
    return READY_LCD;

    /*
    static _Bool wait = true;

    if (wait)
    {
        HAL_TIM_Base_Start_IT(&htim2);
        wait = false;
        return NOT_READY_LCD;
    }


    if (!wait && (__HAL_TIM_GET_COUNTER(&htim2) == 0))
    {
        wait = true;
        return READY_LCD;
    }

    return NOT_READY_LCD;
    */
}
