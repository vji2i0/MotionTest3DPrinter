#include "temperature.h"
#include "PID.h"
#include "scalar_kalman.h"

static float current_extruder1_temperature, target_extruder1_temperature;

static PIDController extruder1_pid = {500.0f, 10.0f, 5.0f,
                                      1.0f,
                                      0.0f, 65535.0f,
                                      0.0, 60000.0,
                                      0.1f};
static scalar_kalman_t extruder1_kfilter, bed_kfilter;

static PIDController bed_pid = {500.0f, 10.0f, 5.0f,
                                1.0f,
                                0.0f, 255.0f,
                                0.0, 200.0,
                                0.1f};

static float current_bed_temperature, target_bed_temperature;

void init_Temperature(void)
{
    turnOffExtruder1_Temperature();
    turnOffBed_Temperature();
    PIDController_Init(&extruder1_pid);
    scalar_kalman_init(&extruder1_kfilter, 1, 1, 1, 25);
    PIDController_Init(&bed_pid);
    scalar_kalman_init(&bed_kfilter, 1, 1, 1, 25);
}

void regNewADCValue_Extruder1_Temperature(uint16_t adc_value)
{
    double T0 = 312.374;
    double a = 15707.2;
    double b = -0.0706367;
    double c = 0.0000107501;
    double d = 90269.8;
    uint16_t temp = (unsigned int)(T0 + (a / (double)adc_value) + b * ((double)adc_value) + c * ((double)adc_value) * ((double)adc_value) + d / ((double)adc_value - 4500.0));
    current_extruder1_temperature = scalar_kalman(&extruder1_kfilter, temp);
}

float getExtruder1_Temperature(void)
{
    return current_extruder1_temperature;
}

void setExtruder1_Temperature(float temp)
{
    target_extruder1_temperature = temp;
}

void turnOffExtruder1_Temperature(void)
{
    target_extruder1_temperature = 0;
}

void pidTimerCallBack_Temperature(void)
{
    setExtruder1_PWM((uint16_t)PIDController_Update(&extruder1_pid, target_extruder1_temperature, current_extruder1_temperature));
    setBed_PWM((uint16_t)PIDController_Update(&bed_pid, target_bed_temperature, current_bed_temperature));
}

void regNewADCValue_Bed_Temperature(uint16_t adc_value)
{
    double T0 = 173.534;
    double a = 6056.82;
    double b = -0.0797318;
    double c = 0.0000258104;
    double d = -0.00000000404498;

    current_bed_temperature = scalar_kalman(&bed_kfilter, (unsigned int)(0.85 * (T0 + (a / (double)adc_value) + b * ((double)adc_value) + c * ((double)adc_value) * ((double)adc_value) + d * ((double)adc_value) * ((double)adc_value) * ((double)adc_value))));
}

float getBed_Temperature(void)
{
    return current_bed_temperature;
}

void setBed_Temperature(float temp)
{
    target_bed_temperature = temp;
}

void turnOffBed_Temperature(void)
{
    target_bed_temperature = 0;
}