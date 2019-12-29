#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include <random>
#include <iostream>
#include <ctime>
#include <vector>
//#include <windows.h>
#include <QKeyEvent>

#define ROW 4
#define COL 4

//游戏所处的状态
#define GAME_OVER 1
#define GAME_WIN 2
#define GAME_CONTINUE 3

//上下左右
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

class gamelogic
{
public:
    int pix[4][4];

    gamelogic();
    bool CreatNumber();
    int Process(int dir);
    int Judge();
    int Input();

};

#endif // GAMELOGIC_H
