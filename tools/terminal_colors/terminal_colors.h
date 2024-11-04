#pragma once
// ref. https://azrael.digipen.edu/~mmead/www/mg/ansicolors/index.html

// ANSI color codes
const char* GREEN = "\033[0;32m";
const char* LIGHT_GREEN = "\033[0;92m";
const char* ORANGE = "\033[0;33m";
const char* RED = "\033[0;31m";
const char* BLUE = "\033[0;34m";
const char* MAGENTA = "\033[0;35m";
const char* LIGHT_MAGENTA = "\033[0;95m";
const char* CYAN = "\033[0;36m";
const char* LIGHT_CYAN = "\033[0;96m";
const char* RESET = "\033[0m";
const char* DARK_WHITE = "\033[0;37m";
const char* GRAY = "\033[0;90m";
const char* YELLOW = "\033[0;93m";
const char* LIGHT_BLUE = "\033[0;94m";
const char* WHITE = "\033[0;97m";

// Emoji codes
const char* eEXIT_DOOR = "\xF0\x9F\x9A\xAA";
const char* ePAPPER = "\xF0\x9F\x93\x84";
const char* ePLUS = "\xE2\x9E\x95";
const char* eMINUS = "\xE2\x9E\x96";
const char* eINFO = "\xE2\x84\xB9";
const char* eTREE = "\xF0\x9F\x8C\xB3";
const char* eSEARCH = "\xF0\x9F\x94\x8D";
const char* eRIGHT = "\xE2\x96\xB6";
const char* eLINK = "\xF0\x9F\x94\x97";
const char* eLEFT = "\xE2\x97\x80";
const char* eUP = "\xE2\xAC\x86";
const char* eDOWN = "\xE2\xAC\x87";
const char* eCLOCK = "\xF0\x9F\x95\x9A";
const char* ePUSH = "\xE2\xA4\xB5";
const char* ePOP = "\xE2\xA4\xB4";
const char* eEYE = "\xf0\x9f\x91\x81";
const char* eCROSS = "\xE2\x9D\x8C";
const char* eAPPLE = "\xF0\x9F\x8D\x8E";


enum ForegroundColor
{
	fgNORMAL = 39,
	fgBLACK = 30,
	fgRED = 31,
	fgGREEN = 32,
	fgORANGE = 33,
	fgBLUE = 34,
	fgPURPLE = 35,
	fgCYAN = 36,
	fgGREY = 37,
	fgGRAY = 37,
	fgDARKGREY = 90,
	fgDARKGRAY = 90,
	fgLIGHTRED = 91,
	fgLIGHTGREEN = 92,
	fgYELLOW = 93,
	fgLIGHTBLUE = 94,
	fgLIGHTPURPLE = 95,
	fgTURQUOISE = 96
};

enum BackgroundColor
{
	bgBLACK = 40,
	bgRED = 41,
	bgGREEN = 42,
	bgORANGE = 43,
	bgBLUE = 44,
	bgPURPLE = 45,
	bgCYAN = 46,
	bgGREY = 47,
	bgGRAY = 47,
	bgDARKGREY = 100,
	bgDARKGRAY = 100,
	bgLIGHTRED = 101,
	bgLIGHTGREEN = 102,
	bgYELLOW = 103,
	bgLIGHTBLUE = 104,
	bgLIGHTPURPLE = 105,
	bgTURQUOISE = 106
};

enum ColorAttribute
{
	caNORMAL = 0,
	caBOLD = 1,
	caUNDERLINE = 4,
	caBLINKING = 5,
	caREVERSED = 7,
	caCONCEALED = 8
};

char* set_print(int foreground, int background, int attribute);
void setcolors(int foreground, int background, int attribute);
void resetcolors(void);
void showcolors(void);