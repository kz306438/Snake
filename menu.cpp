#include "menu.h"

void menu()
{
	StandartButton buttonPlay(20, 5, "PLAY", 6, 3);
	StandartButton buttonSettings(20, 5, "settings", 6, 10);
	StandartButton buttonExit(20, 5, "EXIT", 6, 17);
	int activeButtonMenu{};
	buttonPlay.connect([&]() {  activeButtonMenu = 1; });
	buttonSettings.connect([&]() { activeButtonMenu = 2; });
	buttonExit.connect([&]() { stopMenu = true; activeButtonMenu = 3; });

	setupInputHandling();
	while (stopMenu != true)
	{
		mouseButtonInteraction(&buttonPlay, &buttonSettings, &buttonExit);
		titleSnake(60, 5);
		snakeImage(51, 22);
		Sleep(10);
		if (activeButtonMenu == 1)
		{
			if(_kbhit())int temp = _getch();
			system("cls");
			game();
			activeButtonMenu = 0;
			setupInputHandling();
		}
		else if (activeButtonMenu == 2)
		{
			system("cls");
			settings();
			activeButtonMenu = 0;
			setupInputHandling();
		}
		else if (activeButtonMenu == 3)
		{
			exit(0);
		}
	}
	system("cls");
	stopMenu = false;
}