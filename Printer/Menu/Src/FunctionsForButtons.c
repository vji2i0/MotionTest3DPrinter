#include "FunctionsForButtons.h"

#include "Constructor_Menu.h"
#include "TextConverter_LCD.h"
#include "State_USBdrive.h"
#include "Driver_USBdrive.h"

#include "GcodeConverter_Gcode.h"
#include "Descritization_Gcode.h"
#include "Buffer_Gcode.h"
#include "VirtualPrinters_Gcode.h"
#include "Config_Gcode.h"

#include "fatfs.h"

#include "stdint.h"
#include <wchar.h>
#include "stdbool.h"

void simpleNavigationDown_Menu(void)
{
    if (!ThereIsNodeBelow_Menu())
        return;

    if (!ThereIsNodeAbove_Menu())
    {
        putLine_TextConverter_LCD(getName_Menu(), 2);   updateLine_TextConverter_LCD(2);
        moveDown_Menu();
        wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
        putLine_TextConverter_LCD(currName, 3);         updateLine_TextConverter_LCD(3);    currName[0] = *L" ";
        return;
    }

    moveDown_Menu();
    if (!ThereIsNodeBelow_Menu())
    {
        moveUp_Menu();
        putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
        moveDown_Menu();
        wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
        putLine_TextConverter_LCD(currName, 4);         updateLine_TextConverter_LCD(4);    currName[0] = *L" ";
        return;
    }

    moveUp_Menu();
    putLine_TextConverter_LCD(getName_Menu(), 2);   updateLine_TextConverter_LCD(2);
    moveDown_Menu();
    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 3);         updateLine_TextConverter_LCD(3);    currName[0] = *L" ";
    if (ThereIsNodeBelow_Menu())
    {
        moveDown_Menu();
        putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
        moveUp_Menu();
        return;
    }
}

void simpleNavigationUp_Menu(void)
{
    if (!ThereIsNodeAbove_Menu())
        return;

    moveUp_Menu();
    if (!ThereIsNodeAbove_Menu())
    {
        wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
        putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);    currName[0] = *L" ";
        moveDown_Menu();
        putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
        moveUp_Menu();
        return;
    }

    moveUp_Menu();
    putLine_TextConverter_LCD(getName_Menu(), 2);   updateLine_TextConverter_LCD(2);
    moveDown_Menu();
    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 3);         updateLine_TextConverter_LCD(3);    currName[0] = *L" ";
    moveDown_Menu();
    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
    moveUp_Menu();
}

void simpleNavigationOk_Menu(void)
{
    moveRight_Menu();
    putLine_TextConverter_LCD(getTitle_Menu(), 1);   updateLine_TextConverter_LCD(1);

    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);    currName[0] = *L" ";
    if (!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 3);   updateLine_TextConverter_LCD(3);
        putLine_TextConverter_LCD(EMPTY_STRING, 4);   updateLine_TextConverter_LCD(4);
        return;
    }
    moveDown_Menu();
    putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
    if (!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 4);   updateLine_TextConverter_LCD(4);
        moveUp_Menu();
        return;
    }
    moveDown_Menu();
    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
    moveUp_Menu();
    moveUp_Menu();
}

void simpleNavigationBack_Menu(void)
{
    moveLeft_Menu();    putLine_TextConverter_LCD(getTitle_Menu(), 1);   updateLine_TextConverter_LCD(1);
    if (!ThereIsNodeAbove_Menu())
    {
        wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
        putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);    currName[0] = *L" ";
        if (!ThereIsNodeBelow_Menu())
        {
            putLine_TextConverter_LCD(EMPTY_STRING, 3);   updateLine_TextConverter_LCD(3);
            putLine_TextConverter_LCD(EMPTY_STRING, 4);   updateLine_TextConverter_LCD(4);
            return;
        }
        moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
        if (!ThereIsNodeBelow_Menu())
        {
            putLine_TextConverter_LCD(EMPTY_STRING, 4);   updateLine_TextConverter_LCD(4);
            return;
        }
        moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
        moveUp_Menu();      moveUp_Menu();
        return;
    }
    if (!ThereIsNodeBelow_Menu())
    {
        moveUp_Menu();
        if (ThereIsNodeAbove_Menu())
        {
            moveDown_Menu();
            wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
            putLine_TextConverter_LCD(currName, 4);         updateLine_TextConverter_LCD(4);    currName[0] = *L" ";
            moveUp_Menu();
            putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
            moveUp_Menu();
            putLine_TextConverter_LCD(getName_Menu(), 2);   updateLine_TextConverter_LCD(2);
            moveDown_Menu();
            moveDown_Menu();
            return;
        }
    }
    moveUp_Menu();      putLine_TextConverter_LCD(getName_Menu(), 2);   updateLine_TextConverter_LCD(2);
    moveDown_Menu();    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 3);         updateLine_TextConverter_LCD(3);    currName[0] = *L" ";
    if (!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 4);   updateLine_TextConverter_LCD(4);
        return;
    }
    moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
    moveUp_Menu();
}

void printOk_Menu(void)
{
    if (getState_USBdrive() == NOT_READY_USBDRIVE)  return;
    if (getMountedStatus() == UNMOUNTED_USBDRIVE)   mount_USBdrive();
    openDirectory_USBdrive(USBHPath);
    destroyRightNode_Menu();

    readItem_USBdrive();
    createRightNode_Menu(L"USB drive", getWideLongName_USBdrive());
    moveRight_Menu();

    setFunctionUp(&simpleNavigationUp_Menu);
    setFunctionDown(&simpleNavigationDown_Menu);
    setFunctionBack(&simpleNavigationBack_Menu);
    setFunctionOk(&emptyFunction_Menu);
    if (getItemType_USBdrive() == ITEM_IS_DIRECTORY) setFunctionOk(&openDirectory_Menu);
    if (getItemType_USBdrive() == ITEM_IS_FILE)      setFunctionOk(&runGcode_Menu);
    putLine_TextConverter_LCD(getWideLongName_USBdrive(), 2);  updateLine_TextConverter_LCD(2);


    if(getItemType_USBdrive() == ITEM_IS_EMPTY)
    {
        putLine_TextConverter_LCD(getTitle_Menu(), 1);  updateLine_TextConverter_LCD(1);
        putLine_TextConverter_LCD(EMPTY_STRING, 2); updateLine_TextConverter_LCD(2);
        putLine_TextConverter_LCD(EMPTY_STRING, 3); updateLine_TextConverter_LCD(3);
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        return;
    }

    readItem_USBdrive();
    while(getItemType_USBdrive() != ITEM_IS_EMPTY)
    {
        createDownNode_Menu(getWideLongName_USBdrive());
        moveDown_Menu();
        setFunctionUp(&simpleNavigationUp_Menu);
        setFunctionDown(&simpleNavigationDown_Menu);
        setFunctionBack(&simpleNavigationBack_Menu);
        setFunctionOk(&emptyFunction_Menu);
        if (getItemType_USBdrive() == ITEM_IS_DIRECTORY) setFunctionOk(&openDirectory_Menu);
        if (getItemType_USBdrive() == ITEM_IS_FILE)      setFunctionOk(&runGcode_Menu);
        readItem_USBdrive();
    }

    while( ThereIsNodeAbove_Menu() )  moveUp_Menu();

    putLine_TextConverter_LCD(getTitle_Menu(), 1);  updateLine_TextConverter_LCD(1);
    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);    currName[0] = *L" ";
    if(!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 3); updateLine_TextConverter_LCD(3);
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        return;
    }
    moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
    if(!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        moveUp_Menu();
        return;
    }
    moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
    moveUp_Menu();      moveUp_Menu();
}


void changeFilamentOk_Menu(void) { moveRight_Menu(); }

void setTheTemperatureOk_Menu(void) {}
void setTheTemperatureBack_Menu(void) { moveLeft_Menu(); }
void setTheTemperatureUp_Menu(void) {}
void setTheTemperatureDown_Menu(void) {}

void englishOk_Menu(void) {}
void englishBack_Menu(void) { moveLeft_Menu(); }
void russianOk_Menu(void) {}
void russianBack_Menu(void) { moveLeft_Menu(); }

void helpOk_Menu(void) {}
void helpBack_Menu(void) {}





void emptyFunction_Menu(void) {}





static _Bool GcodeFormat()
{
    if(wcsstr(getName_Menu(), L".gcode\0") != NULL)
        return true;
    return false;
}

static void wait()
{
    HAL_Delay(500);
}

static void returnFirstLine()
{

    putLine_TextConverter_LCD(getTitle_Menu(), 1);
    updateLine_TextConverter_LCD(1);
}


static TCHAR wchar_t2TCHAR(wchar_t character)
{
    if(character == *L"а") return (TCHAR) 0xA0;
    if(character == *L"б") return (TCHAR) 0xA1;
    if(character == *L"в") return (TCHAR) 0xA2;
    if(character == *L"г") return (TCHAR) 0xA3;
    if(character == *L"д") return (TCHAR) 0xA4;
    if(character == *L"е") return (TCHAR) 0xA5;
    if(character == *L"ё") return (TCHAR) 0xF1;
    if(character == *L"ж") return (TCHAR) 0xA6;
    if(character == *L"з") return (TCHAR) 0xA7;
    if(character == *L"и") return (TCHAR) 0xA8;
    if(character == *L"й") return (TCHAR) 0xA9;
    if(character == *L"к") return (TCHAR) 0xAA;
    if(character == *L"л") return (TCHAR) 0xAB;
    if(character == *L"м") return (TCHAR) 0xAC;
    if(character == *L"н") return (TCHAR) 0xAD;
    if(character == *L"о") return (TCHAR) 0xAE;
    if(character == *L"п") return (TCHAR) 0xAF;
    if(character == *L"р") return (TCHAR) 0xE0;
    if(character == *L"с") return (TCHAR) 0xE1;
    if(character == *L"т") return (TCHAR) 0xE2;
    if(character == *L"у") return (TCHAR) 0xE3;
    if(character == *L"ф") return (TCHAR) 0xE4;
    if(character == *L"х") return (TCHAR) 0xE5;
    if(character == *L"ц") return (TCHAR) 0xE6;
    if(character == *L"ч") return (TCHAR) 0xE7;
    if(character == *L"ш") return (TCHAR) 0xE8;
    if(character == *L"щ") return (TCHAR) 0xE9;
    if(character == *L"ъ") return (TCHAR) 0xEA;
    if(character == *L"ы") return (TCHAR) 0xEB;
    if(character == *L"ь") return (TCHAR) 0xEC;
    if(character == *L"э") return (TCHAR) 0xED;
    if(character == *L"ю") return (TCHAR) 0xEE;
    if(character == *L"я") return (TCHAR) 0xEF;
    if(character == *L"А") return (TCHAR) 0x80;
    if(character == *L"Б") return (TCHAR) 0x81;
    if(character == *L"В") return (TCHAR) 0x82;
    if(character == *L"Г") return (TCHAR) 0x83;
    if(character == *L"Д") return (TCHAR) 0x84;
    if(character == *L"Е") return (TCHAR) 0x85;
    if(character == *L"Ё") return (TCHAR) 0xF0;
    if(character == *L"Ж") return (TCHAR) 0x86;
    if(character == *L"З") return (TCHAR) 0x87;
    if(character == *L"И") return (TCHAR) 0x88;
    if(character == *L"Й") return (TCHAR) 0x89;
    if(character == *L"К") return (TCHAR) 0x8A;
    if(character == *L"Л") return (TCHAR) 0x8B;
    if(character == *L"М") return (TCHAR) 0x8C;
    if(character == *L"Н") return (TCHAR) 0x8D;
    if(character == *L"О") return (TCHAR) 0x8E;
    if(character == *L"П") return (TCHAR) 0x8F;
    if(character == *L"Р") return (TCHAR) 0x90;
    if(character == *L"С") return (TCHAR) 0x91;
    if(character == *L"Т") return (TCHAR) 0x92;
    if(character == *L"У") return (TCHAR) 0x93;
    if(character == *L"Ф") return (TCHAR) 0x94;
    if(character == *L"Х") return (TCHAR) 0x95;
    if(character == *L"Ц") return (TCHAR) 0x96;
    if(character == *L"Ч") return (TCHAR) 0x97;
    if(character == *L"Ш") return (TCHAR) 0x98;
    if(character == *L"Щ") return (TCHAR) 0x99;
    if(character == *L"Ъ") return (TCHAR) 0x9A;
    if(character == *L"Ы") return (TCHAR) 0x9B;
    if(character == *L"Ь") return (TCHAR) 0x9C;
    if(character == *L"Э") return (TCHAR) 0x9D;
    if(character == *L"Ю") return (TCHAR) 0x9E;
    if(character == *L"Я") return (TCHAR) 0x9F;
    return (TCHAR) character;
}

static void getFileOrFolderNameTCHAR(TCHAR* nameTCHAR)
{
    int letterNember;
    for (letterNember = 0; letterNember < MAX_WIDE_NAME_LENGTH-1; letterNember++)
        nameTCHAR[letterNember] = wchar_t2TCHAR(getName_Menu()[letterNember+1]);
}

void runGcode_Menu(void)
{
    if(GcodeFormat())
    {
        putLine_TextConverter_LCD(L"Gcode file", 1);
        updateLine_TextConverter_LCD(1);


        TCHAR fileNameTCHAR[MAX_WIDE_NAME_LENGTH], pathToFile[PATH_LENGTH];

        getFileOrFolderNameTCHAR(fileNameTCHAR);    sprintf(pathToFile, "%s/%s", getPath_USBdrive(), fileNameTCHAR);    openFile_USBdrive(pathToFile);

        while(!endOfFile_USBdrive())
        {
            convertCommand_Gcode((const char*)getStringFromFile_USBdrive());
            setDescreteCommand_Gcode(getConvertedCommand_Gcode());
            while(!enoghSpaceIsReservedCommandBuffer_Gcode()) {}
            if(!descreteCommandIsRepeated(getDescreteCommand_Gcode()))
            {
                addElementToDescreteCommandBuffer_Gcode(getDescreteCommand_Gcode());
                descreteCommandAnalyser_Gcode();
            }


            /*
            convertCommand_Gcode((const char*)getStringFromFile_USBdrive());
            setDescreteCommand_Gcode(getConvertedCommand_Gcode());
            while(!enoghSpaceIsReservedCommandBuffer_Gcode()) {}
            addElementToDescreteCommandBuffer_Gcode(getDescreteCommand_Gcode());
            descreteCommandAnalyser_Gcode();
            */
        }
        addElementToDescreteCommandBuffer_Gcode(defaultDescreteCommand);
        descreteCommandAnalyser_Gcode();

        while( (checkFreeSpaceCommandBuffer_Gcode()!=COMMAND_BUFFER_LENGTH) || (!moveComleted()) ) {}

        wait(); returnFirstLine();
    }
    else
    {
        putLine_TextConverter_LCD(L"not a Gcode file", 1);
        updateLine_TextConverter_LCD(1);
        wait(); returnFirstLine();
    }
}



void openDirectory_Menu(void)
{
    destroyRightNode_Menu();

    TCHAR folderNameTCHAR[MAX_WIDE_NAME_LENGTH], pathToFolder[PATH_LENGTH];
    getFileOrFolderNameTCHAR(folderNameTCHAR);    sprintf(pathToFolder, "%s/%s", getPath_USBdrive(), folderNameTCHAR);
    openDirectory_USBdrive(pathToFolder);

    readItem_USBdrive();
    createRightNode_Menu(L"USB drive", getWideLongName_USBdrive());
    moveRight_Menu();

    setFunctionUp(&simpleNavigationUp_Menu);
    setFunctionDown(&simpleNavigationDown_Menu);
    setFunctionBack(&closeDirectory_Menu);
    setFunctionOk(&emptyFunction_Menu);
    if (getItemType_USBdrive() == ITEM_IS_DIRECTORY) setFunctionOk(&openDirectory_Menu);
    if (getItemType_USBdrive() == ITEM_IS_FILE)      setFunctionOk(&runGcode_Menu);
    putLine_TextConverter_LCD(getWideLongName_USBdrive(), 2);  updateLine_TextConverter_LCD(2);


    if(getItemType_USBdrive() == ITEM_IS_EMPTY)
    {
        putLine_TextConverter_LCD(getTitle_Menu(), 1);  updateLine_TextConverter_LCD(1);
        putLine_TextConverter_LCD(EMPTY_STRING, 2); updateLine_TextConverter_LCD(2);
        putLine_TextConverter_LCD(EMPTY_STRING, 3); updateLine_TextConverter_LCD(3);
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        return;
    }

    readItem_USBdrive();
    while(getItemType_USBdrive() != ITEM_IS_EMPTY)
    {
        createDownNode_Menu(getWideLongName_USBdrive());
        moveDown_Menu();
        setFunctionUp(&simpleNavigationUp_Menu);
        setFunctionDown(&simpleNavigationDown_Menu);
        setFunctionBack(&closeDirectory_Menu);
        setFunctionOk(&emptyFunction_Menu);
        if (getItemType_USBdrive() == ITEM_IS_DIRECTORY) setFunctionOk(&openDirectory_Menu);
        if (getItemType_USBdrive() == ITEM_IS_FILE)      setFunctionOk(&runGcode_Menu);
        readItem_USBdrive();
    }

    while( ThereIsNodeAbove_Menu() )  moveUp_Menu();

    putLine_TextConverter_LCD(getTitle_Menu(), 1);  updateLine_TextConverter_LCD(1);
    wchar_t* currName = (wchar_t*) getName_Menu();  currName[0] = *L">";
    putLine_TextConverter_LCD(currName, 2);         updateLine_TextConverter_LCD(2);    currName[0] = *L" ";
    if(!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 3); updateLine_TextConverter_LCD(3);
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        return;
    }
    moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 3);   updateLine_TextConverter_LCD(3);
    if(!ThereIsNodeBelow_Menu())
    {
        putLine_TextConverter_LCD(EMPTY_STRING, 4); updateLine_TextConverter_LCD(4);
        moveUp_Menu();
        return;
    }
    moveDown_Menu();    putLine_TextConverter_LCD(getName_Menu(), 4);   updateLine_TextConverter_LCD(4);
    moveUp_Menu();      moveUp_Menu();

}

static size_t findLastSlash(void)
{
    size_t j, lastSlashPosition=0;
    for (j=0; j<PATH_LENGTH; j++) if((int)(getPath_USBdrive()[j])==(int)'/') lastSlashPosition = j;
    return lastSlashPosition;
}

void closeDirectory_Menu(void)
{
    TCHAR path[PATH_LENGTH];

    sprintf(path, "%s", getPath_USBdrive());
    size_t j; for(j=findLastSlash(); j<PATH_LENGTH; j++) path[j]=0;
    openDirectory_USBdrive((const TCHAR*)path);
    destroyRightNode_Menu();

    simpleNavigationBack_Menu();
}
