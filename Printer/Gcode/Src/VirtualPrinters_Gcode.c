#include "VirtualPrinters_Gcode.h"

#include "Config_Gcode.h"
#include "temperature.h"

#include "Driver_Motors.h"

#include "math.h"

const float evaluationPeriod_Gcode = TIMER_PERIOD_S;


static struct
{
    command_Gcode command;
    _Bool xDone;    long xDirection;
    _Bool yDone;    long yDirection;
    _Bool zDone;    long zDirection;
    _Bool eDone;    long eDirection;
    _Bool extDone;
    _Bool bedDone;
} currentCommand;

static struct
{
    long X;
    long Y;
    long Z;
    long E;
} discretePrinter;

static struct
{
    float X;    float vX;
    float Y;    float vY;
    float Z;    float vZ;
    float E;    float vE;
} continiuosPrinter;

void virtualPrintersCreate_Gcode(void)
{
    discretePrinter.X = 0;          discretePrinter.Y = 0;          discretePrinter.Z = 0;          discretePrinter.E = 0;
    continiuosPrinter.X = 0;        continiuosPrinter.Y = 0;        continiuosPrinter.Z = 0;        continiuosPrinter.E = 0;
    continiuosPrinter.vX = 0;       continiuosPrinter.vY = 0;       continiuosPrinter.vZ = 0;       continiuosPrinter.vE = 0;
    currentCommand.xDone = true;    currentCommand.yDone = true;    currentCommand.zDone = true;    currentCommand.eDone = true;
    currentCommand.extDone = true;
    currentCommand.bedDone = true;
}

long getCurrentX_Gcode(void) {return discretePrinter.X;}
long getCurrentY_Gcode(void) {return discretePrinter.Y;}
long getCurrentZ_Gcode(void) {return discretePrinter.Z;}
long getCurrentE_Gcode(void) {return discretePrinter.E;}

float getCurrentSpeedX_Gcode(void) {return continiuosPrinter.vX;}
float getCurrentSpeedY_Gcode(void) {return continiuosPrinter.vY;}
float getCurrentSpeedZ_Gcode(void) {return continiuosPrinter.vZ;}
float getCurrentSpeedE_Gcode(void) {return continiuosPrinter.vE;}

long getCurrentCommandX_Gcode(void) {return currentCommand.command.dXn;}
long getCurrentCommandY_Gcode(void) {return currentCommand.command.dYn;}
long getCurrentCommandZ_Gcode(void) {return currentCommand.command.dZn;}
long getCurrentCommandE_Gcode(void) {return currentCommand.command.dEn;}


static long sign(long dLn)
{
    if (dLn > 0) return 1;
    if (dLn < 0) return -1;
    return 0;
}

void sendCommandToPrinter_Gcode(command_Gcode command)
{
    virtualPrintersCreate_Gcode();
    currentCommand.command = command;
    continiuosPrinter.vX = command.FnX; currentCommand.xDirection = sign(command.dXn);  if (command.dXn != 0) currentCommand.xDone = false;
    continiuosPrinter.vY = command.FnY; currentCommand.yDirection = sign(command.dYn);  if (command.dYn != 0) currentCommand.yDone = false;
    continiuosPrinter.vZ = command.FnZ; currentCommand.zDirection = sign(command.dZn);  if (command.dZn != 0) currentCommand.zDone = false;
    continiuosPrinter.vE = command.FnE; currentCommand.eDirection = sign(command.dEn);  if (command.dEn != 0) currentCommand.eDone = false;
    if (command.type == WAIT_HEAT_EXTRUDER_COMMAND) currentCommand.extDone = false;
    if (command.type == WAIT_HEAT_BED_COMMAND)      currentCommand.bedDone = false;
}

_Bool moveComleted(void)
{
    return currentCommand.xDone && currentCommand.yDone && currentCommand.zDone && currentCommand.eDone && currentCommand.extDone && currentCommand.bedDone;
}
static void makeStepX_Gcode(void)
{
    discretePrinter.X += currentCommand.xDirection;
    doStepX_Motors(currentCommand.xDirection);
}
static void makeStepY_Gcode(void)
{
    discretePrinter.Y += currentCommand.yDirection;
    doStepY_Motors(currentCommand.yDirection);
}
static void makeStepZ_Gcode(void)
{
    discretePrinter.Z += currentCommand.zDirection;
    doStepZ_Motors(currentCommand.zDirection);
}
static void makeStepE_Gcode(void)
{
    discretePrinter.E += currentCommand.eDirection;
    doStepE_Motors(currentCommand.eDirection);
}

static void checkExt1Temperature_Gcode(void) { if(getTargetExtruder1_Temperature() < getExtruder1_Temperature()) currentCommand.extDone = true; }
static void checkBedTemperature_Gcode(void)  { if(getTargetBed_Temperature()       < getBed_Temperature())       currentCommand.bedDone = true; }

_Bool evaluatePrinter_Gcode(void)
{
    if (currentCommand.command.type == EMPTY_COMMAND) return true;
    if (currentCommand.command.type == MOVE_COMMAND)
    {
        if (moveComleted())
            return true;
        if (!currentCommand.xDone)
        {
            continiuosPrinter.vX += currentCommand.command.AnX*evaluationPeriod_Gcode;
            continiuosPrinter.X  += continiuosPrinter.vX*evaluationPeriod_Gcode;
            if (lroundf(continiuosPrinter.X - (float)discretePrinter.X) != 0) makeStepX_Gcode();
            if (discretePrinter.X == currentCommand.command.dXn) currentCommand.xDone = true;
        }
        if (!currentCommand.yDone)
        {
            continiuosPrinter.vY += currentCommand.command.AnY*evaluationPeriod_Gcode;
            continiuosPrinter.Y  += continiuosPrinter.vY*evaluationPeriod_Gcode;
            if (lroundf(continiuosPrinter.Y - (float)discretePrinter.Y) != 0) makeStepY_Gcode();
            if (discretePrinter.Y == currentCommand.command.dYn) currentCommand.yDone = true;
        }
        if (!currentCommand.zDone)
        {
            continiuosPrinter.vZ += currentCommand.command.AnZ*evaluationPeriod_Gcode;
            continiuosPrinter.Z  += continiuosPrinter.vZ*evaluationPeriod_Gcode;
            if (lroundf(continiuosPrinter.Z - (float)discretePrinter.Z) != 0) makeStepZ_Gcode();
            if (discretePrinter.Z == currentCommand.command.dZn) currentCommand.zDone = true;
        }
        if (!currentCommand.eDone)
        {
            continiuosPrinter.vE += currentCommand.command.AnE*evaluationPeriod_Gcode;
            continiuosPrinter.E  += continiuosPrinter.vE*evaluationPeriod_Gcode;
            if (lroundf(continiuosPrinter.E - (float)discretePrinter.E) != 0) makeStepE_Gcode();
            if (discretePrinter.E == currentCommand.command.dEn) currentCommand.eDone = true;
        }
    }
    if (currentCommand.command.type == HEAT_EXTRUDER_COMMAND) {setExtruder1_Temperature(currentCommand.command.extrT); return true;}
    if (currentCommand.command.type == HEAT_BED_COMMAND)      {setBed_Temperature(currentCommand.command.bedT);        return true;}
    if (currentCommand.command.type == WAIT_HEAT_EXTRUDER_COMMAND)
    {
        setExtruder1_Temperature(currentCommand.command.extrT);
        checkExt1Temperature_Gcode();
        if(moveComleted())   return true;
    }
    if (currentCommand.command.type == WAIT_HEAT_BED_COMMAND)
    {
        setBed_Temperature(currentCommand.command.bedT);
        checkBedTemperature_Gcode();
        if(moveComleted())   return true;
    }

    return false;
}
