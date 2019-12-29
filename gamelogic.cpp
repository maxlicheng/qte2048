#include "gamelogic.h"
#include <random>
#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h>
//#include <windows.h>
#include <QKeyEvent>
using namespace std;

gamelogic::gamelogic()
{
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            pix[i][j] = 0;
}


//在空白处产生一个数字
//若没有空白，则返回false
bool gamelogic::CreatNumber()
{
    int RandNum = rand() % 3;
    int r = 0;
    vector<int> index;  //记录空白格

    for (int i = 0; i < ROW; i++)
       for (int j = 0; j < COL; j++)
       {
           if (!pix[i][j])
           {
               index.push_back(i * 4 + j);  //记录空白格的索引
           }
        }
    if (index.empty())
    {
        return false;
    }
    else {                    //找到空白点
       r = rand() % index.size();
       int CreatNum = 0;
       if (RandNum == 0)
       {
           CreatNum = 4;  //1/3概率是4
       }
       else {
          CreatNum = 2;   //2/3概率是2
       }
       pix[index[r] / 4][index[r] % 4] = CreatNum; //给空白处一个数据
    }
    return true;
}

int gamelogic::Process(int dir)
{
    int score = 0;    //记录分数
    switch (dir)      //根据按键指示进行处理
    {
    case UP:
        for(int j=0; j<COL; j++)
        {
            //取出所有非零元素
            int t[10];
            int cnt = 0;
            for(int i=0; i<ROW; i++)
                if(pix[i][j])	t[cnt++] = pix[i][j];

            int n = 0;
            for(int k=0; k<cnt-1; k++)
            {//合并
                if(t[k]==t[k+1])
                {
                    t[k] *= 2;
                    score += t[k];
                    t[k+1] = 0;
                }
            }
            //将合并后的非零元素填入pix中
            for(int k=0; k<cnt; k++)
            {
                if(t[k])	pix[n++][j] = t[k];
            }

            //尾部补零
            for(; n<ROW; n++)
            {
                pix[n][j] = 0;
            }

        }
        break;
    case DOWN:
        for(int j=0; j<COL; j++)
        {
            int t[10];
            int cnt = 0;

            for(int i=ROW-1; i>=0; i--)
                if(pix[i][j])	t[cnt++] = pix[i][j];

            int n = ROW-1;
            for(int k=0; k<cnt-1; k++)
            {
                if(t[k]==t[k+1])
                {
                    t[k] *= 2;
                    score += t[k];
                    t[k+1] = 0;
                }
            }

            for(int k=0; k<cnt; k++)
            {
                if(t[k])	pix[n--][j] = t[k];
            }

            for(; n>=0; n--)
            {
                pix[n][j] = 0;
            }
        }
        break;
    case LEFT:
        for(int i=0; i<ROW; i++)
        {
            int t[10];
            int cnt = 0;
            for(int j=0; j<COL; j++)
                if(pix[i][j])	t[cnt++] = pix[i][j];

            int n = 0;
            for(int k=0; k<cnt-1; k++)
            {
                if(t[k]==t[k+1])
                {
                    t[k] *= 2;
                    score += t[k];
                    t[k+1] = 0;
                }
            }

            for(int k=0; k<cnt; k++)
            {
                if(t[k])	pix[i][n++] = t[k];
            }

            for(; n<COL; n++)
            {
                pix[i][n] = 0;
            }

        }
        break;
    case RIGHT:
        for(int i=0; i<ROW; i++)
        {
            int t[10];
            int cnt = 0;
            for(int j=COL-1; j>=0; j--)
                if(pix[i][j])	t[cnt++] = pix[i][j];

            int n = COL-1;
            for(int k=0; k<cnt-1; k++)
            {
                if(t[k]==t[k+1])
                {
                    t[k] *= 2;
                    score += t[k];
                    t[k+1] = 0;
                }
            }

            for(int k=0; k<cnt; k++)
            {
                if(t[k])	pix[i][n--] = t[k];
            }

            for(; n>=0; n--)
            {
                pix[i][n] = 0;
            }

        }
        break;
    default:break;
    }
    return score;
}

//判断游戏转态
int gamelogic::Judge()
{
    //赢得游戏
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (pix[i][j] == 2048)
            {
                return GAME_WIN;
                break;
            }
        }
    }

    //横向检查
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL - 1; ++j)
        {
            if (!pix[i][j] || (pix[i][j] == pix[i][j + 1]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }

    //纵向检查
    for (int j = 0; j< COL; ++j)
    {
        for (int i = 0; i < ROW - 1; ++i)
        {
            if (!pix[i][j] || (pix[i][j] == pix[i + 1][j]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }

    //不符合上述两种状况，游戏结束
    return GAME_OVER;

}



