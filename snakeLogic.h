#pragma once
#include "variables.h"
#include <ctime>
#include <Windows.h>
#include <iostream>
#include "consoleGUI/cursor.h"
#include <conio.h>

using namespace std;

class Snake {
public:
    class Point {
    public:
        Point(int x, int y, char value) : x(x), y(y), value(value) {}

        int getX() const { return x; }
        int getY() const { return y; }
        char getValue() const { return value; }

        void setX(int newX) { x = newX; }
        void setY(int newY) { y = newY; }
        void setValue(char newValue) { value = newValue; }

    private:
        int x;
        int y;
        char value;
    };

    int getXAtIndex(int index) const;
    int getYAtIndex(int index) const;
    char getValueAtIndex(int index) const;

    void setXAtIndex(int index, int newX);
    void setYAtIndex(int index, int newY);
    void setValueAtIndex(int index, char newValue);

    void addPoint(int x, int y, char value);
    void deletePoint();

    int getSnakeLength();

private:
    std::vector<Point> snake;
};

extern Snake snake1;

void snakeFill(Snake& snake);

void Control(Snake& snake);

void isDead(Snake& snake);