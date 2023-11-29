#include "pause.h"
#include "consoleGUI/buttons.h"
#include "variables.h"
#include "titleImage.h"
void pauseMenu()
{
	restoreConsoleAttributes();
	int status = -1;
	system("cls");
	puseImage(2, 1);
	StandartButton continuePlay(30, 5, "continue", 45, 17);
	StandartButton backToMenuFromPause(30, 5, "back to menu", 45, 10);
	continuePlay.connect([&]() { pause = false; status = 1;});
	backToMenuFromPause.connect([&]() { pause = false; GameOver = true; status = 2; });
	setupInputHandling();
	while (pause != false)
	{
		mouseButtonInteraction(&continuePlay, &backToMenuFromPause);
	}
	if (status == 1)
	{
		system("cls");
		saveConsoleAttributes();
		setColorForeground(wallsColor);
		setColorBackground(mapColor);
		for (int i = 0; i < MAP.size(); i++)
		{
			bool flag = false;
			if (i == 0 || i == MAP.size() - 1)
			{
				setColorBackground(Black);
				flag = true;
			}
			for (int j = 0; j < MAP[0].size(); j++)
			{
				if (MAP[i][j] == headSymbol)
				{
					setColorForeground(headColor);
					std::cout << MAP[i][j];
					setColorForeground(wallsColor);
				}
				else if (MAP[i][j] == tailSymbol)
				{
					setColorForeground(tailColor);
					std::cout << MAP[i][j];
					setColorForeground(wallsColor);
				}
				else cout << MAP[i][j];
			}
			std::cout << endl;
			if (flag == true)
			{
				flag = false;
				setColorBackground(mapColor);
			}
		}
		/*restoreConsoleAttributes();*/
		Sleep(1500);
	}
}
