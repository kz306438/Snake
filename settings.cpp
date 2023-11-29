#include "settings.h"
#include "consoleGUI/window.h"
void settings()
{
	int activeButtonSettings = 0;
	StandartButton buttonGentral(30, 5, "General", 45, 2);
	StandartButton buttonCustom(30, 5, "Custom", 45, 9);
	StandartButton buttonControl(30, 5, "Control", 45, 16);
	StandartButton buttonBackToMenu(30, 5, "Back", 45, 23);

	buttonGentral.connect([&]() { activeButtonSettings = 1; });
	buttonCustom.connect([&]() { activeButtonSettings = 2; });
	buttonBackToMenu.connect([]() { stopSettings = true; });

	setupInputHandling();

	while (stopSettings != true)
	{
		mouseButtonInteraction(&buttonGentral, &buttonCustom, &buttonControl, &buttonBackToMenu);
		Sleep(10);
		if (activeButtonSettings == 1)
		{
			system("cls");
			general();
			activeButtonSettings = 0;
			setupInputHandling();
		}
		else if (activeButtonSettings == 2)
		{
			system("cls");
			custom();
			activeButtonSettings = 0;
			setupInputHandling();
		}
		else if (activeButtonSettings == 3)
		{

		}
	}
	stopSettings = false;
	system("cls");
}

void general()
{
	StandartButton buttonBackToSettings(20, 5, "Back", 12, 4);
	SliderButton sliderSnakeSpeed(1, 20, "snake speed", speed / 5, 50, 4, SliderButton::Orientation::HORIZONTAL);
	SliderButton sliderMapWidth(10, 40, "map width", width / 2, 45, 11, SliderButton::Orientation::HORIZONTAL);
	SliderButton sliderMapHeight(10, 25, "map height", height, 52, 17, SliderButton::Orientation::HORIZONTAL);
	SwitchButton switchThroughTheWall(12, 3, throughTheWalls, 55, 23);
	switchThroughTheWall.addName("through the wall", 51, 26);
	buttonBackToSettings.connect([]() { stopGeneral = true; });
	sliderSnakeSpeed.connect([&]() { speed -= 5; }, [&]() { speed += 5; });
	sliderMapWidth.connect([&]() { width -= 2; }, [&]() { width += 2; });
	sliderMapHeight.connect([&]() { height -= 1; }, [&]() { height += 1; });
	switchThroughTheWall.connect([&]() { throughTheWalls = false; }, [&]() { throughTheWalls = true; });

	setupInputHandling();

	while (stopGeneral != true)
	{
		mouseButtonInteraction(&buttonBackToSettings, &sliderSnakeSpeed, &sliderMapWidth, &sliderMapHeight, &switchThroughTheWall);
		Sleep(10);
	}
	stopGeneral = false;
	system("cls");
}

void custom()
{
	std::vector<std::vector<std::vector<char>>> content =
	{
		{
			{' ','b','l','u','e',' ',' '}
		},
		{
			{' ','g','r','e','e','n',' '}
		},
		{
			{' ','c','y','a','n',' ',' '}
		},
		{
			{' ',' ','r','e','d',' ',' '}
		},
		{
			{'m','a','g','e','n','t','a'}
		},
		{
			{'y','e','l','l','o','w',' '}
		},
		{
			{' ','w','h','i','t','e',' '}
		}
	};
	StandartButton backToSettingsFromCustom(20, 5, "Back", 12, 4);
	StandartButton addWalls(20, 5, "Add Walls", 40, 4);
	ScrollButton wallColor(content, 45, 12, ScrollButton::Orientation::HORIZONTAL);
	ScrollButton mapColor(content, 45, 15, ScrollButton::Orientation::HORIZONTAL);
	ScrollButton snakeSkin();
	ScrollButton snakeHeadColor();
	ScrollButton snakeTailColor();

	backToSettingsFromCustom.connect([]() { stopCustom = true; });
	addWalls.connect([]() {});

	setupInputHandling();
	bool stopCustomMap = true;
	addWalls.connect([&]() {stopCustomMap = false; });
	while (stopCustom != true)
	{
		mouseButtonInteraction(&backToSettingsFromCustom, &addWalls, &wallColor, &mapColor);
		if (!stopCustomMap)
		{
			customMap();
			stopCustomMap = true;
			setupInputHandling();
		}
		Sleep(10);
	}
	stopCustom = false;
	system("cls");
}

void customMap()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	system("cls");
	bool stopCustomMap = false;
	bool isChangesWallColors = false;
	bool isChangesBackgroundColors = false;

	vector<vector<char>> arr = { {char(219), char(219)} };
	Window wallsColors(27, 8, 86, 1), backgroundColors(27, 8, 86, 8), wallsTexture(27, 8, 86, 15);

	StandartButton backToCustomMenu(27, 5, "SAVE", 86, 23);
	backToCustomMenu.connect([&]() {stopCustomMap = true; });

	CustomButton whiteWall(arr, arr, 88, 4), brightWhiteWall(arr, arr, 91, 4), yellowWall(arr, arr, 94, 4), brightYellowWall(arr, arr, 97, 4),
		magentaWall(arr, arr, 100, 4), brightMagentaWall(arr, arr, 103, 4), redWall(arr, arr, 106, 4), brightRedWall(arr, arr, 109, 4),
		cyanWall(arr, arr, 88, 6), brightCyanWall(arr, arr, 91, 6), greenWall(arr, arr, 94, 6), brightGreenWall(arr, arr, 97, 6),
		blueWall(arr, arr, 100, 6), brightBlueWall(arr, arr, 103, 6), blackWall(arr, arr, 106, 6), brightBlackWall(arr, arr, 109, 6);
	whiteWall.setButtonForegroundColor(White); brightWhiteWall.setButtonForegroundColor(BrightWhite); yellowWall.setButtonForegroundColor(Yellow); brightYellowWall.setButtonForegroundColor(BrightYellow);
	magentaWall.setButtonForegroundColor(Magenta); brightMagentaWall.setButtonForegroundColor(BrightMagenta); redWall.setButtonForegroundColor(Red); brightRedWall.setButtonForegroundColor(BrightRed);
	cyanWall.setButtonForegroundColor(Cyan); brightCyanWall.setButtonForegroundColor(BrightCyan); greenWall.setButtonForegroundColor(Green); brightGreenWall.setButtonForegroundColor(BrightGreen);
	blueWall.setButtonForegroundColor(Blue); brightBlueWall.setButtonForegroundColor(BrightBlue); blackWall.setButtonForegroundColor(Black); brightBlackWall.setButtonForegroundColor(BrightBlack);

	whiteWall.connect([&]() {wallsColor = White; isChangesWallColors = true; });
	brightWhiteWall.connect([&]() {wallsColor = BrightWhite; isChangesWallColors = true; });
	yellowWall.connect([&]() {wallsColor = Yellow; isChangesWallColors = true; });
	brightYellowWall.connect([&]() {wallsColor = BrightYellow; isChangesWallColors = true; });
	magentaWall.connect([&]() {wallsColor = Magenta; isChangesWallColors = true;  });
	brightMagentaWall.connect([&]() {wallsColor = BrightMagenta; isChangesWallColors = true;  });
	redWall.connect([&]() {wallsColor = Red; isChangesWallColors = true;  });
	brightRedWall.connect([&]() {wallsColor = BrightRed; isChangesWallColors = true;  });
	cyanWall.connect([&]() {wallsColor = Cyan; isChangesWallColors = true;  });
	brightCyanWall.connect([&]() {wallsColor = BrightCyan; isChangesWallColors = true; });
	greenWall.connect([&]() {wallsColor = Green; isChangesWallColors = true; });
	brightGreenWall.connect([&]() {wallsColor = BrightGreen; isChangesWallColors = true; });
	blueWall.connect([&]() {wallsColor = Blue; isChangesWallColors = true;  });
	brightBlueWall.connect([&]() {wallsColor = BrightBlue; isChangesWallColors = true; });
	blackWall.connect([&]() {wallsColor = Black; isChangesWallColors = true; });
	brightBlackWall.connect([&]() {wallsColor = BrightBlack; isChangesWallColors = true; });

	CustomButton whiteBackground(arr, arr, 88, 11), brightWhiteBackground(arr, arr, 91, 11), yellowBackground(arr, arr, 94, 11), brightYellowBackground(arr, arr, 97, 11),
		magentaBackground(arr, arr, 100, 11), brightMagentaBackground(arr, arr, 103, 11), redBackground(arr, arr, 106, 11), brightRedBackground(arr, arr, 109, 11),
		cyanBackground(arr, arr, 88, 13), brightCyanBackground(arr, arr, 91, 13), greenBackground(arr, arr, 94, 13), brightGreenBackground(arr, arr, 97, 13),
		blueBackground(arr, arr, 100, 13), brightBlueBackground(arr, arr, 103, 13), blackBackground(arr, arr, 106, 13), brightBlackBackground(arr, arr, 109, 13);
	whiteBackground.setButtonForegroundColor(White); brightWhiteBackground.setButtonForegroundColor(BrightWhite); yellowBackground.setButtonForegroundColor(Yellow); brightYellowBackground.setButtonForegroundColor(BrightYellow);
	magentaBackground.setButtonForegroundColor(Magenta); brightMagentaBackground.setButtonForegroundColor(BrightMagenta); redBackground.setButtonForegroundColor(Red); brightRedBackground.setButtonForegroundColor(BrightRed);
	cyanBackground.setButtonForegroundColor(Cyan); brightCyanBackground.setButtonForegroundColor(BrightCyan); greenBackground.setButtonForegroundColor(Green); brightGreenBackground.setButtonForegroundColor(BrightGreen);
	blueBackground.setButtonForegroundColor(Blue); brightBlueBackground.setButtonForegroundColor(BrightBlue); blackBackground.setButtonForegroundColor(Black); brightBlackBackground.setButtonForegroundColor(BrightBlack);

	whiteBackground.connect([&]() {mapColor = White; isChangesBackgroundColors = true; });
	brightWhiteBackground.connect([&]() {mapColor = BrightWhite; isChangesBackgroundColors = true; });
	yellowBackground.connect([&]() {mapColor = Yellow; isChangesBackgroundColors = true; });
	brightYellowBackground.connect([&]() {mapColor = BrightYellow; isChangesBackgroundColors = true; });
	magentaBackground.connect([&]() {mapColor = Magenta; isChangesBackgroundColors = true;  });
	brightMagentaBackground.connect([&]() {mapColor = BrightMagenta; isChangesBackgroundColors = true;  });
	redBackground.connect([&]() {mapColor = Red; isChangesBackgroundColors = true;  });
	brightRedBackground.connect([&]() {mapColor = BrightRed; isChangesBackgroundColors = true;  });
	cyanBackground.connect([&]() {mapColor = Cyan; isChangesBackgroundColors = true;  });
	brightCyanBackground.connect([&]() {mapColor = BrightCyan; isChangesBackgroundColors = true; });
	greenBackground.connect([&]() {mapColor = Green; isChangesBackgroundColors = true; });
	brightGreenBackground.connect([&]() {mapColor = BrightGreen; isChangesBackgroundColors = true; });
	blueBackground.connect([&]() {mapColor = Blue; isChangesBackgroundColors = true;  });
	brightBlueBackground.connect([&]() {mapColor = BrightBlue; isChangesBackgroundColors = true; });
	blackBackground.connect([&]() {mapColor = Black; isChangesBackgroundColors = true; });
	brightBlackBackground.connect([&]() {mapColor = BrightBlack; isChangesBackgroundColors = true; });

	char tempWall = ' ';


	vector<vector<char>> arr176 = { {char(176),char(176)},{char(176),char(176)} }, arr177 = { {char(177),char(177)},{char(177),char(177)} }, arr178 = { {char(178),char(178)},{char(178),char(178)} }, arr219 = { {char(219),char(219)},{char(219),char(219)} };
	CustomButton wall176(arr176, arr176, 88, 19), wall177(arr177, arr177, 93, 19), wall178(arr178, arr178, 98, 19), wall219(arr219, arr219, 103, 19);

	wall176.connect([&]() { tempWall = char(176); });
	wall177.connect([&]() { tempWall = char(177); });
	wall178.connect([&]() { tempWall = char(178); });
	wall219.connect([&]() { tempWall = char(219); });
	vector<vector<char>> squar = { {char(220), char(220)}, {char(223), char(223)} };
	CustomButton eraser(squar, squar, 108, 19);
	eraser.connect([&]() {tempWall = ' '; });
	if (saveMAP.size() != height || saveMAP[0].size() != width)
	{
		saveMAP.resize(height);
		for (int i = 0; i < height; i++)saveMAP[i].resize(width);

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				saveMAP[i][j] = ' ';

		for (int i = 0; i < height; i++)
		{
			saveMAP[i][0] = 219;
			saveMAP[i][width - 1] = 219;

		}

		for (int j = 0; j < width; j++)
		{
			saveMAP[0][j] = 220;
			saveMAP[height - 1][j] = 223;
		}
	}
	saveMAP[height / 2][((width / 2) % 2 == 0) ? width / 2 : width / 2 - 1] = headSymbol;
	saveMAP[height / 2 + 1][((width / 2) % 2 == 0) ? width / 2 : width / 2 - 1] = tailSymbol;

	setColorForeground(wallsColor);
	setColorBackground(mapColor);
	for (int i = 0; i < saveMAP.size(); i++)
	{
		bool flag = false;
		if (i == 0 || i == saveMAP.size() - 1)
		{
			setColorBackground(Black);
			flag = true;
		}
		for (int j = 0; j < saveMAP[0].size(); j++)
		{
			setcur((80 - width) / 2 + j + 3, (30 - height) / 2 + i);
			if (saveMAP[i][j] == headSymbol)
			{
				setColorForeground(headColor);
				std::cout << saveMAP[i][j];
				setColorForeground(wallsColor);
			}
			else if (saveMAP[i][j] == tailSymbol)
			{
				setColorForeground(tailColor);
				std::cout << saveMAP[i][j];
				setColorForeground(wallsColor);
			}
			else cout << saveMAP[i][j];
		}
		if (flag == true)
		{
			flag = false;
			setColorBackground(mapColor);
		}
	}
	setColorForeground(White);
	setColorBackground(Black);


	wallsColors.show();
	backgroundColors.show();
	wallsTexture.show();
	setcur(93, 2); std::cout << "wall colors:";
	setcur(90, 9); std::cout << "background colors:";
	setcur(92, 16); std::cout << "walls textures:";
	setcur(86, 8); std::cout << char(219); setcur(86 + 26, 8); std::cout << char(219);
	setcur(86, 15); std::cout << char(219); setcur(86 + 26, 15); std::cout << char(219);
	setupInputHandling();
	while (stopCustomMap != true)
	{
		mouseButtonInteraction(&backToCustomMenu ,&whiteWall, &brightWhiteWall,&yellowWall, &brightYellowWall,
			                   &magentaWall, &brightMagentaWall, &redWall, &brightRedWall,
			                   &cyanWall, &brightCyanWall, &greenWall, &brightGreenWall,
			                   &blueWall, &brightBlueWall, &blackWall, &brightBlackWall,
			&whiteBackground, &brightWhiteBackground, &yellowBackground, &brightYellowBackground,
			&magentaBackground, &brightMagentaBackground, &redBackground, &brightRedBackground,
			&cyanBackground, &brightCyanBackground, &greenBackground, &brightGreenBackground,
			&blueBackground, &brightBlueBackground, &blackBackground, &brightBlackBackground,
			&wall176, &wall177, &wall178, &wall219, &eraser);
		if (isChangesWallColors == true || isChangesBackgroundColors == true)
		{
			saveConsoleAttributes();
			setColorForeground(wallsColor);
			setColorBackground(mapColor);
			for (int i = 0; i < saveMAP.size(); i++)
			{
				bool flag = false;
				if (i == 0 || i == saveMAP.size() - 1)
				{
					setColorBackground(Black);
					flag = true;
				}
				for (int j = 0; j < saveMAP[0].size(); j++)
				{
					setcur((80 - width) / 2 + j + 3, (30 - height) / 2 + i);
					if (saveMAP[i][j] == headSymbol)
					{
						setColorForeground(headColor);
						std::cout << saveMAP[i][j];
						setColorForeground(wallsColor);
					}
					else if (saveMAP[i][j] == tailSymbol)
					{
						setColorForeground(tailColor);
						std::cout << saveMAP[i][j];
						setColorForeground(wallsColor);
					}
					else cout << saveMAP[i][j];
				}
				if (flag == true)
				{
					flag = false;
					setColorBackground(mapColor);
				}
			}
			restoreConsoleAttributes();
			isChangesWallColors = false;
			isChangesBackgroundColors = false;
		}

		if (COORD mousePos = GetCursorPosition(); GetAsyncKeyState(VK_LBUTTON) & 0x8000
			&& mousePos.X >= (80 - width) / 2 + 4 && mousePos.X < (80 - width) / 2 + saveMAP[0].size() + 2
			&& mousePos.Y >= (30 - height) / 2 + 1 && mousePos.Y < (30 - height) / 2 + saveMAP.size() - 1)
		{	
			if(saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] != headSymbol &&
				saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] != tailSymbol &&
				saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 2] != headSymbol &&
				saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 2] != tailSymbol)
			{
				setColorForeground(wallsColor);
				if ((mousePos.X - (80 - width) / 2 - 3) % 2 == 0)
				{
					if (tempWall == ' ')
					{
						setColorBackground(mapColor);
						setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
						setcur(mousePos.X - 1, mousePos.Y); std::cout << tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] = tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3 - 1] = tempWall;
						setColorBackground(Black);
					}
					else
					{
						setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
						setcur(mousePos.X - 1, mousePos.Y); std::cout << tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] = tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3 - 1] = tempWall;
					}
				}
				else
				{
					if (tempWall == ' ')
					{
						setColorBackground(mapColor);
						setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
						setcur(mousePos.X + 1, mousePos.Y); std::cout << tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] = tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3 + 1] = tempWall;
						setColorBackground(Black);
					}
					else
					{
						setcur(mousePos.X, mousePos.Y); std::cout << tempWall;
						setcur(mousePos.X + 1, mousePos.Y); std::cout << tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3] = tempWall;
						saveMAP[mousePos.Y - (30 - height) / 2][mousePos.X - (80 - width) / 2 - 3 + 1] = tempWall;
					}
				}
				setColorForeground(White);
			}
		}

	}
	system("cls");
}
