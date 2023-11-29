#include "snakeLogic.h"
#include "menu.h"
#include "settings.h"

#define endl "\n"
using namespace std;

int width = 80;
int height = 25;
vector<vector<char>> MAP(height, vector<char>(width));
vector<vector<char>> saveMAP(0);
bool GameOver = true;
bool Victory = false;
bool pause = false;
bool stopMenu = false;
bool stopSettings = false;
bool stopGeneral = false;
bool stopCustom = false;
int fruitX;
int fruitY;
int Score = 0;
int speed = 60;
bool throughTheWalls = false;
bool collision = false;
char lastKeyPressed = ' ';

Snake snake1;
int snakelenght = 2;
int maxlenght = 2;
char tailSymbol = '*';
char headSymbol = 'O';
char fruitSymbol = '$';

ConsoleColor wallsColor = White;
ConsoleColor mapColor = Black;
ConsoleColor headColor = White;
ConsoleColor tailColor = White;

int main()
{
	HWND console = GetConsoleWindow();
	SetConsoleTitleA("    Snake    ");
	invisibleCursor();
	menu();
	return 0;
}