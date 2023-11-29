#include "titleImage.h"

void titleSnake(int x, int y)
{
	char a = char(219);
	char b = char(32);
	char titlesnake[5][23] =
	{
		{a,a,a,b,a,b,b,a,b,a,a,a,a,b,a,b,b,a,b,a,a,a},
		{a,b,b,b,a,a,b,a,b,a,b,b,a,b,a,b,a,b,b,a},
		{a,a,a,b,a,b,a,a,b,a,a,a,a,b,a,a,b,b,b,a,a,a},
		{b,b,a,b,a,b,b,a,b,a,b,b,a,b,a,b,a,b,b,a},
		{a,a,a,b,a,b,b,a,b,a,b,b,a,b,a,b,b,a,b,a,a,a}
	};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			setcur(x + j, y + i);
			cout << titlesnake[i][j];
		}
	}
}

void puseImage(int x, int y)
{
	std::vector<std::vector<char>> pauseImage =
	{
		{char(220),char(220),char(220),char(220),char(220),char(220),char(220), char(220), char(220)},
		{char(219), char(32), char(32), char(32), char(32), char(32),char(32),char(32), char(219)},
		{char(219),char(32), char(32), char(219), char(32), char(219), char(32),char(32), char(219)},
		{char(219), char(32), char(32), char(32), char(32), char(32),char(32),char(32), char(219)},
		{char(223),char(223),char(223),char(223),char(223),char(223), char(223), char(223), char(223)}
	};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			setcur(x + j, y + i);
			cout << pauseImage[i][j];
		}
	}
}

void titleVictory(int x, int y)
{
	char a = char(219);
	char b = ' ';
	char titlevictory[7][34] =
	{
		{a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a},
		{a,b,a,b,a,b,b,b,a,b,b,b,b,a,b,b,b,a,b,b,b,b,a,b,b,b,b,a,b,b,a,b,b,a},
		{a,b,a,b,a,a,b,a,a,b,a,a,b,a,a,b,a,a,b,a,a,b,a,b,a,a,b,a,a,b,b,b,a,a},
		{a,b,a,b,a,a,b,a,a,b,a,a,a,a,a,b,a,a,b,a,a,b,a,b,b,b,b,a,a,a,b,a,a,a},
		{a,b,b,b,a,a,b,a,a,b,a,a,b,a,a,b,a,a,b,a,a,b,a,b,a,b,a,a,a,a,b,a,a,a},
		{a,a,b,a,a,b,b,b,a,b,b,b,b,a,a,b,a,a,b,b,b,b,a,b,a,b,a,a,a,a,b,a,a,a},
		{a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a}
	};
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 34; j++)
		{
			setcur(x + j, y + i);
			cout << titlevictory[i][j];
		}
	}
	Sleep(3000);
	system("cls");
}

void titleGameOver()
{
	char w = char(219);
	char arr[7][39] =
	{

		{w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
		{w,' ',' ',' ',' ',w,' ',' ',' ',' ',w,' ',w,w,w,' ',w,' ',' ',' ',w,' ',' ',' ',' ',w,' ',w,' ',w,' ',' ',' ',w,' ',' ',' ',' ',w},
		{w,' ',w,w,w,w,' ',w,w,' ',w,' ',' ',w,' ',' ',w,' ',w,w,w,' ',w,w,' ',w,' ',w,' ',w,' ',w,w,w,' ',w,w,' ',w},
		{w,' ',w,' ',' ',w,' ',' ',' ',' ',w,' ',w,' ',w,' ',w,' ',' ',' ',w,' ',w,w,' ',w,' ',w,' ',w,' ',' ',' ',w,' ',' ',' ',' ',w},
		{w,' ',w,w,' ',w,' ',w,w,' ',w,' ',w,w,w,' ',w,' ',w,w,w,' ',w,w,' ',w,' ',' ',' ',w,' ',w,w,w,' ',w,' ',w,w},
		{w,' ',' ',' ',' ',w,' ',w,w,' ',w,' ',w,w,w,' ',w,' ',' ',' ',w,' ',' ',' ',' ',w,w,' ',w,w,' ',' ',' ',w,' ',w,' ',w,w},
		{w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w}
	};

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "                                        ";
		for (int j = 0; j < 39; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	string s = "press any key...";
	setcur(52, 27);
	cout << s;
	while (!_kbhit())
	{

	}
	char a = _getch();
	system("cls");
}

void snakeImage(int x, int y)
{
	char a = char(32), b = char(220), c = char(223), d = char(179), e = char(191);

	char snakeImage[4][68] =
	{
		{32,32,32,32,32,32,32,32,32,32,32,32,'_','_',32,32,32,32,'_','_',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
		{32,'_','_','_','_','_','_','_','_','_','_','/',32,b,32,'\\','_','/',32,b,32,'\\','_','_',32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32},
		{d,32,'_','_','_','_','_','_',e,32,32,32,32,'-',32,32,32,32,32,'-',32,32,32,32,'\\','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_' },
		{32,'\\','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','/','-','-','-','-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32,'-',32,c,32}
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 68; j++)
		{
			setcur(x + j, y + i);
			cout << snakeImage[i][j];
		}
	}
}