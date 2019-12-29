#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "gamelogic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum MouseState{
        mUP,
        mDOWN,
        mLEFT,
        mRIGHT,
    };

public:
    gamelogic game;
    int totscore;
    explicit MainWindow(QWidget *parent = 0);
    void showbroad();
    void GameDisplay(MouseState msta);
    void keyPressEvent(QKeyEvent *event);
    void changeColor(QLabel* label, int num);
    ~MainWindow();

protected:	//mouse
//    void mouseMoveEvent(QMouseEvent *event);         //移动
    void mousePressEvent(QMouseEvent *event);        //单击
    void mouseReleaseEvent(QMouseEvent *event);      //释放
//    void mouseDoubleClickEvent(QMouseEvent *event);  //双击
//    void wheelEvent(QWheelEvent *event);             //滑轮
//    bool eventFilter(QObject *watched, QEvent *qevent);  //点击事件

private slots:

    void on_restartButton_clicked();

private:
    Ui::MainWindow *ui;
    int press_x;     //点击鼠标时获取的横坐标x
    int press_y;     //点击鼠标时获取的纵坐标y
    int relea_x;     //松开鼠标时获取的横坐标x
    int relea_y;     //松开鼠标时获取的纵坐标y
    bool pressflag=0;
};

#endif // MAINWINDOW_H
