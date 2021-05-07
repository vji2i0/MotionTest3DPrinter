#!/bin/bash

#Gcode/Inc
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/Buffer_Gcode.h ./Printer/Gcode/Inc/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/Config_Gcode.h ./Printer/Gcode/Inc/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/Descritization_Gcode.h ./Printer/Gcode/Inc/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/GcodeConverter_Gcode.h ./Printer/Gcode/Inc/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/VirtualPrinters_Gcode.h ./Printer/Gcode/Inc/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/inc/Boundary_Gcode.h ./Printer/Gcode/Inc
#Gcode/Src
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/src/Buffer_Gcode.c ./Printer/Gcode/Src/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/src/Descritization_Gcode.c ./Printer/Gcode/Src/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/src/GcodeConverter_Gcode.c ./Printer/Gcode/Src/
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/src/VirtualPrinters_Gcode.c ./Printer/Gcode/Src/
sed -i -e 's/^#include "Fake_Motors.h"/#include "Driver_Motors.h"/' ./Printer/Gcode/Src/VirtualPrinters_Gcode.c
cp ./../Tests4Printer/3DPrinterV3/G-code/Gcode_GcodeConverter/firmware/src/Boundary_Gcode.c ./Printer/Gcode/Src/
#LCD/Inc
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Interface/firmware/inc/CharacterConverter_LCD.h ./Printer/LCD/Inc/
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Driver/firmware/inc/Driver_LCD.h ./Printer/LCD/Inc/
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Interface/firmware/inc/Interface_LCD.h ./Printer/LCD/Inc/
cp ./../Tests4Printer/3DPrinterV3/LCD/TextConverter/firmware/inc/TextConverter_LCD.h ./Printer/LCD/Inc/
#LCD/Src
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Interface/firmware/src/CharacterConverter_LCD.c ./Printer/LCD/Src/
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Driver/firmware/src/Driver_LCD.c ./Printer/LCD/Src/
cp ./../Tests4Printer/3DPrinterV3/LCD/LCD_Interface/firmware/src/Interface_LCD.c ./Printer/LCD/Src/
sed -i -e 's/^#include "Mock_Driver_LCD.h"/#include "Driver_LCD.h"/' ./Printer/LCD/Src/Interface_LCD.c
#Menu/Inc
cp ./../Tests4Printer/3DPrinterV3/Menu/Menu_Constructor/firmware/inc/Constructor_Menu.h ./Printer/Menu/Inc/
cp ./../Tests4Printer/3DPrinterV3/Menu/Menu_Constructor/firmware/inc/MainMenu_Menu.h ./Printer/Menu/Inc/
#Menu/Src
cp ./../Tests4Printer/3DPrinterV3/Menu/Menu_Constructor/firmware/src/Constructor_Menu.c ./Printer/Menu/Src/
cp ./../Tests4Printer/3DPrinterV3/Menu/Menu_Constructor/firmware/src/MainMenu_Menu.c ./Printer/Menu/Src/
sed -i -e 's/^#include "Fake_FunctionsForButtons.h"/#include "FunctionsForButtons.h"/' ./Printer/Menu/Src/MainMenu_Menu.c
#Motors/Inc
cp ./../Tests4Printer/3DPrinterV3/Motors/Motors_Driver/firmware/inc/Driver_Motors.h ./Printer/Motors/Inc/
#Motors/Src
cp ./../Tests4Printer/3DPrinterV3/Motors/Motors_Driver/firmware/src/Driver_Motors.c ./Printer/Motors/Src/
#USB/Inc
cp ./../Tests4Printer/3DPrinterV3/USB/USB_Host/firmware/inc/Driver_USBdrive.h ./Printer/USB/Inc/
sed -i -e 's/^#include "Mock_ff.h"/#include "ff.h"/' ./Printer/USB/Inc/Driver_USBdrive.h
cp ./../Tests4Printer/3DPrinterV3/USB/USB_Host/firmware/inc/State_USBdrive.h ./Printer/USB/Inc/
#USB/Src
cp ./../Tests4Printer/3DPrinterV3/USB/USB_Host/firmware/src/Driver_USBdrive.c ./Printer/USB/Src/
sed -i -e 's/^#include "Fake_fatfs.h"/#include "fatfs.h"/' ./Printer/USB/Src/Driver_USBdrive.c
sed -i -e 's/^#include "Mock_ff.h"/#include "ff.h"/' ./Printer/USB/Src/Driver_USBdrive.c
cp ./../Tests4Printer/3DPrinterV3/USB/USB_Host/firmware/src/State_USBdrive.c ./Printer/USB/Src/
