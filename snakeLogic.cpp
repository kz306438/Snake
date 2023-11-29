#include "snakeLogic.h"


int Snake::getXAtIndex(int index) const {
    return snake[index].getX();
}

int Snake::getYAtIndex(int index) const {
    return snake[index].getY();
}

char Snake::getValueAtIndex(int index) const {
    return snake[index].getValue();
}

void Snake::setXAtIndex(int index, int newX) {
    snake[index].setX(newX);
}

void Snake::setYAtIndex(int index, int newY) {
    snake[index].setY(newY);
}

void Snake::setValueAtIndex(int index, char newValue) {
    snake[index].setValue(newValue);
}

void Snake::addPoint(int x, int y, char value) {
    snake.emplace_back(x, y, value);
}

void Snake::deletePoint() {
    snake.pop_back();
}

int Snake::getSnakeLength() {
    return snake.size();
}

void snakeFill(Snake& snake)
{
	srand(time(NULL));
	/*записываем координаты змейки в массив MAP*/
	for (int i = 0; i < snakelenght; i++)
	{
		MAP[snake.getYAtIndex(i)][snake.getXAtIndex(i)] = snake.getValueAtIndex(i);
	}
	if (fruitX % 2 == 1) {
		if (fruitX == 1) fruitX += 1;
		else fruitX -= 1;
	}
	setcur(fruitX, fruitY);
	cout << fruitSymbol;

	/*съедание фрукта*/
	if (snake.getYAtIndex(0) == fruitY && snake.getXAtIndex(0) == fruitX)
	{
		Snake::Point a(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1), tailSymbol);
		snake.addPoint(a.getX(), a.getY(), a.getValue());
		setcur(fruitX, fruitY);
		cout << ' ';

		/*ищем новые координаты фрукта, удовлетвор€ющие услови€м*/
		bool isSpawn = false;
		int k = 0;
		while (k != (height - 2) * (width - 2))
		{
			if (fruitX % 2 == 0) isSpawn = true;
			if (MAP[fruitY][fruitX] != ' ') isSpawn = false;
			if (isSpawn) break;
			fruitX = (rand() % (width - 2)) + 1;
			fruitY = rand() % (height - 2) + 1;
			k++;
		}
		/*если поиск зат€нулс€, то берЄм первую попавшуюс€ координату пустой €чейки карты*/
		if (isSpawn == false)
		{
			for (int i = 1; i < height - 1; i++)
			{
				for (int j = 2; j < width - 1; j += 2)
				{
					if (MAP[i][j] == ' ')
					{
						fruitX = j;
						fruitY = i;
						isSpawn = true;
						break;
					}
				}
				if (isSpawn) break;
			}
		}
		/*рисуем новый фрукт*/
		setcur(fruitX, fruitY);
		cout << fruitSymbol;
		Score++;
		setcur(0, height + 1);
		setColorForeground(White);
		setColorBackground(Black);
		cout << "Score: " << Score;
		setColorBackground(mapColor);
		setColorForeground(headColor);
		snakelenght++;
	}
}

void Control(Snake& snake)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 0x48:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			if (lastKeyPressed == 0x50)
			{
				lastKeyPressed = 0x50;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setYAtIndex(0, snake.getYAtIndex(0) + 1);
				if (snake.getYAtIndex(0) == height - 1) {
					snake.setYAtIndex(0, 1);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			else
			{
				lastKeyPressed = 0x48;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setYAtIndex(0, snake.getYAtIndex(0) - 1);
				if (snake.getYAtIndex(0) == 0) {
					snake.setYAtIndex(0, height - 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			break;
		}
		case 0x50:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			if (lastKeyPressed == 0x48)
			{
				lastKeyPressed = 0x48;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setYAtIndex(0, snake.getYAtIndex(0) - 1);
				if (snake.getYAtIndex(0) == 0) {
					snake.setYAtIndex(0, height - 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			else
			{
				lastKeyPressed = 0x50;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setYAtIndex(0, snake.getYAtIndex(0) + 1);
				if (snake.getYAtIndex(0) == height - 1) {
					snake.setYAtIndex(0, 1);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			break;
		}
		case 0x4D:
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			if (lastKeyPressed == 0x4B)
			{
				lastKeyPressed = 0x4B;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setXAtIndex(0, snake.getXAtIndex(0) - 2);
				if (snake.getXAtIndex(0) <= 0) {
					snake.setXAtIndex(0, width - 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			else
			{
				lastKeyPressed = 0x4D;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setXAtIndex(0, snake.getXAtIndex(0) + 2);
				if (snake.getXAtIndex(0) >= width - 1) {
					snake.setXAtIndex(0, 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			break;
		case 0x4B:
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			if (lastKeyPressed == 0x4D)
			{
				lastKeyPressed = 0x4D;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setXAtIndex(0, snake.getXAtIndex(0) + 2);
				if (snake.getXAtIndex(0) >= width - 1)
				{
					snake.setXAtIndex(0, 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			else
			{
				lastKeyPressed = 0x4B;
				setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
				cout << ' ';
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << tailSymbol;
				if (snakelenght > 1)
				{
					for (int i = snakelenght - 1; i >= 1; i--)
					{
						snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
						snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
					}
				}
				snake.setXAtIndex(0, snake.getXAtIndex(0) - 2);
				if (snake.getXAtIndex(0) <= 0) {
					snake.setXAtIndex(0, width - 2);
					collision = true;
				}
				if (throughTheWalls == true || collision == false) {
					setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
					cout << headSymbol;
				}
			}
			break;
		case 27:
			pause = true;
		}
	}
	else
	{
		switch (lastKeyPressed)
		{
		case 0x48:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
			cout << ' ';
			setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
			cout << tailSymbol;
			if (snakelenght > 1)
			{
				for (int i = snakelenght - 1; i >= 1; i--)
				{
					snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
					snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
				}
			}
			snake.setYAtIndex(0, snake.getYAtIndex(0) - 1);
			if (snake.getYAtIndex(0) == 0) {
				snake.setYAtIndex(0, height - 2);
				collision = true;
			}
			if (throughTheWalls == true || collision == false) {
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << headSymbol;
			}
			break;
		}
		case 0x50:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
			cout << ' ';
			setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
			cout << tailSymbol;
			if (snakelenght > 1)
			{
				for (int i = snakelenght - 1; i >= 1; i--)
				{
					snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
					snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
				}
			}
			snake.setYAtIndex(0, snake.getYAtIndex(0) + 1);
			if (snake.getYAtIndex(0) == height - 1) {
				snake.setYAtIndex(0, 1);
				collision = true;
			}
			if (throughTheWalls == true || collision == false) {
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << headSymbol;
			}
			break;
		}
		case 0x4D:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
			cout << ' ';
			setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
			cout << tailSymbol;
			if (snakelenght > 1)
			{
				for (int i = snakelenght - 1; i >= 1; i--)
				{
					snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
					snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
				}
			}
			snake.setXAtIndex(0, snake.getXAtIndex(0) + 2);
			if (snake.getXAtIndex(0) >= width - 1) {
				snake.setXAtIndex(0, 2);
				collision = true;
			}
			if (throughTheWalls == true || collision == false) {
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << headSymbol;
			}
			break;
		}
		case 0x4B:
		{
			MAP[snake.getYAtIndex(snakelenght - 1)][snake.getXAtIndex(snakelenght - 1)] = ' ';
			setcur(snake.getXAtIndex(snakelenght - 1), snake.getYAtIndex(snakelenght - 1));
			cout << ' ';
			setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
			cout << tailSymbol;
			if (snakelenght > 1)
			{
				for (int i = snakelenght - 1; i >= 1; i--)
				{
					snake.setXAtIndex(i, snake.getXAtIndex(i - 1));
					snake.setYAtIndex(i, snake.getYAtIndex(i - 1));
				}
			}
			snake.setXAtIndex(0, snake.getXAtIndex(0) - 2);
			if (snake.getXAtIndex(0) <= 0) {
				snake.setXAtIndex(0, width - 2);
				collision = true;
			}
			if (throughTheWalls == true || collision == false) {
				setcur(snake.getXAtIndex(0), snake.getYAtIndex(0));
				cout << headSymbol;
			}
			break;
		}
		}

	}
}

void isDead(Snake& snake)
{
	if (throughTheWalls == false && collision == true) {
		GameOver = true;
	}
	if (MAP[snake.getYAtIndex(0)][snake.getXAtIndex(0)] == tailSymbol)GameOver = true;
	if (MAP[snake.getYAtIndex(0)][snake.getXAtIndex(0)] != ' ' && MAP[snake.getYAtIndex(0)][snake.getXAtIndex(0)] != headSymbol)
	{
		GameOver = true;
		setcur(snake.getXAtIndex(0), snake.getYAtIndex(0)); 
		setColorForeground(wallsColor); 
		std::cout << MAP[snake.getYAtIndex(0)][snake.getXAtIndex(0)];
		setColorForeground(headColor);
	}
}