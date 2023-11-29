#include "game.h"
#include "pause.h"
#include <algorithm>
#include <random>
void setUpGame()
{
	srand(time(0));
	GameOver = false;
	Victory = false;
	collision = false;

	Score = 0;
	lastKeyPressed = ' ';
	while (snake1.getSnakeLength())
	{
		snake1.deletePoint();
	}

	MAP.resize(height);
	for (int i = 0; i < height; i++)MAP[i].resize(width);

	snake1.addPoint(((width / 2) % 2 == 0) ? width / 2 : width / 2 - 1, height / 2, headSymbol);
	snake1.addPoint(((width / 2) % 2 == 0) ? width / 2 : width / 2 - 1, height / 2 + 1, tailSymbol);
	snakelenght = 2;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			MAP[i][j] = ' ';
		}
	}				                  //создание карты

	for (int i = 0; i < height; i++)
	{
		MAP[i][0] = 219;
		MAP[i][width - 1] = 219;
	}

	if (saveMAP.size() == MAP.size() && saveMAP[0].size() == MAP[0].size())MAP = saveMAP;

	for (int j = 0; j < width; j++)
	{
		MAP[0][j] = 220;
		MAP[height - 1][j] = 223;
	}

	vector<pair<int, int>> fruits;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j += 2)
		{
			if (MAP[i][j] == ' ')fruits.push_back({j,i});
		}
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(fruits.begin(), fruits.end(), gen);
	fruitX = fruits[0].first;
	fruitY = fruits[0].second;

	setcur(0, 1);
	saveConsoleAttributes();
	setColorBackground(mapColor);
	setColorForeground(wallsColor);
	for (int i = 1; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << MAP[i][j];
		}
		cout << endl;
	}
	restoreConsoleAttributes();

	saveConsoleAttributes();
	setColorForeground(wallsColor);
	setcur(0, 0);
	for (int i = 0; i < width; i++)
		cout << MAP[0][i];
	
	setcur(0, height - 1);
	for (int i = 0; i < width; i++)
		cout << MAP[height - 1][i];
	restoreConsoleAttributes();

	setcur(0, height + 1);
	cout << "Score: " << Score;
	saveConsoleAttributes();
	setColorBackground(mapColor);
	setColorForeground(headColor);
	setcur(snake1.getXAtIndex(0), snake1.getYAtIndex(0));
	cout << snake1.getValueAtIndex(0);
	setcur(snake1.getXAtIndex(1), snake1.getYAtIndex(1));
	cout << snake1.getValueAtIndex(1);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j+=2)
		{
			if (MAP[i][j] == ' ')maxlenght++;
		}
	}
}

void game()
{
	setUpGame();

	while (GameOver != true)
	{
		snakeFill(snake1);
		Control(snake1);
		isDead(snake1);
		invisibleCursor();
		Sleep(120 - speed);
		if (snakelenght == maxlenght)
		{
			GameOver = true;
			Victory = true;
		}
		if (pause == true)
		{
			pauseMenu();
		}
	}
	setColorBackground(Black);
	setColorForeground(White);
	system("cls");
	if (Victory == true)
	{
		titleVictory(43, 11);
	}
	else
	{
		titleGameOver();
	}
	maxlenght = 2;
}

void Pause()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 27:
			pause = false;
			break;
		}
	}
}