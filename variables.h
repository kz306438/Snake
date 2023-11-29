#pragma once
#include <vector>
#include <memory>
#include "consoleGUI/buttons.h"
#include "consoleGUI/colors.h"

extern int width;
extern int height;
extern std::vector<std::vector<char>> MAP;
extern std::vector<std::vector<char>> saveMAP;

extern bool GameOver;
extern bool Victory;
extern bool pause;
extern bool stopMenu;
extern bool stopSettings;
extern bool stopGeneral;
extern bool stopCustom;
extern int fruitX;
extern int fruitY;
extern int Score;
extern int speed;
extern bool throughTheWalls;
extern bool collision;
extern char lastKeyPressed;

extern int snakelenght;
extern int maxlenght;
extern char tailSymbol;
extern char headSymbol;
extern char fruitSymbol;

extern ConsoleColor wallsColor;
extern ConsoleColor mapColor;
extern ConsoleColor headColor;
extern ConsoleColor tailColor;