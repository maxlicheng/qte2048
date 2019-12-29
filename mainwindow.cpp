#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
//#include <windows.h>
#include <QLabel>
#include <QPalette>
#include <QColor>
#include <QMessageBox>
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    totscore = 0;
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

//显示并更新所有方块
void MainWindow::showbroad()
{
    //第一行
    if(game.pix[0][0])  ui->label1->setText(QString::number(game.pix[0][0]));
    else ui->label1->setText(" ");
    changeColor(ui->label1, game.pix[0][0]);

    if(game.pix[0][1])  ui->label2->setText(QString::number(game.pix[0][1]));
    else ui->label2->setText(" ");
    changeColor(ui->label2, game.pix[0][1]);

    if(game.pix[0][2])  ui->label3->setText(QString::number(game.pix[0][2]));
    else ui->label3->setText(" ");
    changeColor(ui->label3, game.pix[0][2]);

    if(game.pix[0][3])  ui->label4->setText(QString::number(game.pix[0][3]));
    else ui->label4->setText(" ");
    changeColor(ui->label4, game.pix[0][3]);

    //第二行
    if(game.pix[1][0])  ui->label5->setText(QString::number(game.pix[1][0]));
    else ui->label5->setText(" ");
    changeColor(ui->label5, game.pix[1][0]);

    if(game.pix[1][1])  ui->label6->setText(QString::number(game.pix[1][1]));
    else ui->label6->setText(" ");
    changeColor(ui->label6, game.pix[1][1]);

    if(game.pix[1][2])  ui->label7->setText(QString::number(game.pix[1][2]));
    else ui->label7->setText(" ");
    changeColor(ui->label7, game.pix[1][2]);

    if(game.pix[1][3])  ui->label8->setText(QString::number(game.pix[1][3]));
    else ui->label8->setText(" ");
    changeColor(ui->label8, game.pix[1][3]);

    //第三行
    if(game.pix[2][0])  ui->label9->setText(QString::number(game.pix[2][0]));
    else ui->label9->setText(" ");
    changeColor(ui->label9, game.pix[2][0]);

    if(game.pix[2][1])  ui->label10->setText(QString::number(game.pix[2][1]));
    else ui->label10->setText(" ");
    changeColor(ui->label10, game.pix[2][1]);

    if(game.pix[2][2])  ui->label11->setText(QString::number(game.pix[2][2]));
    else ui->label11->setText(" ");
    changeColor(ui->label11, game.pix[2][2]);

    if(game.pix[2][3])  ui->label12->setText(QString::number(game.pix[2][3]));
    else ui->label12->setText(" ");
    changeColor(ui->label12, game.pix[2][3]);

    //第四行
    if(game.pix[3][0])  ui->label13->setText(QString::number(game.pix[3][0]));
    else ui->label13->setText(" ");
    changeColor(ui->label13, game.pix[3][0]);

    if(game.pix[3][1])  ui->label14->setText(QString::number(game.pix[3][1]));
    else ui->label14->setText(" ");
    changeColor(ui->label14, game.pix[3][1]);

    if(game.pix[3][2])  ui->label15->setText(QString::number(game.pix[3][2]));
    else ui->label15->setText(" ");
    changeColor(ui->label15, game.pix[3][2]);

    if(game.pix[3][3])  ui->label16->setText(QString::number(game.pix[3][3]));
    else ui->label16->setText(" ");
    changeColor(ui->label16, game.pix[3][3]);

}

//改变方块的底色
void MainWindow::changeColor(QLabel* label, int num)
{
    QPalette palette;
    switch (num)
    {
    case 2:
        palette.setColor(QPalette::Background,QColor(238,228,218));
        break;

    case 4:
        palette.setColor(QPalette::Background,QColor(237,224,200));
        break;

    case 8:
        palette.setColor(QPalette::Background,QColor(242,177,121));
        break;

    case 16:
        palette.setColor(QPalette::Background,QColor(245,150,100));
        break;

    case 32:
        palette.setColor(QPalette::Background,QColor(245,125,95));
        break;

    case 64:
        palette.setColor(QPalette::Background,QColor(245,95,60));
        break;

    case 128:
        palette.setColor(QPalette::Background,QColor(237,207,114));
        break;

    case 256:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    case 512:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    case 1024:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    case 2048:
        palette.setColor(QPalette::Background,QColor(237,204,97));
        break;

    default:
        palette.setColor(QPalette::Background,QColor(238,228,218));
        break;
    }

    label->setAutoFillBackground(true);
    label->setPalette(palette);
}

void MainWindow::GameDisplay(MouseState msta)
{
    int score = 0;
    showbroad();
    switch (msta)
    {
    case mLEFT:
        score = game.Process(LEFT);
        cout << "left" << endl;
        break;

    case mUP:
        score = game.Process(UP);
        cout << "up" << endl;
        break;

    case mRIGHT:
        score = game.Process(RIGHT);
        cout << "right" << endl;
        break;

    case mDOWN:
        score = game.Process(DOWN);
        cout << "down" << endl;
        break;

    default:
        return;
        break;
    }
    totscore += score;
    ui->score2->setText(QString::number(totscore));
    showbroad();

    int Gamstate = game.Judge();
    srand((unsigned int)time(0));
    if (Gamstate == GAME_CONTINUE)
    {
        if(game.CreatNumber()==0)
        {
            cout << "Sorry  " << "You lose the chance!" << endl;
            QMessageBox::information(NULL, "2048", "游戏结束！", QMessageBox::Yes , QMessageBox::Yes);
            //return GAME_OVER;
        }
        else showbroad();
    }
    else if(Gamstate == GAME_WIN)
    {
        cout << "Congratulation  " << "You Win！" << endl;
        //return GAME_WIN;
    }
    else
    {
        cout << "Sorry  " << "You lose the game!" << endl;
        QMessageBox::information(NULL, "2048", "游戏结束", QMessageBox::Yes , QMessageBox::Yes);
       // return GAME_OVER;
    }
}

//Key输入
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    static MouseState keystats;
    switch(event->key()){
    case Qt::Key_Left:
        keystats = mLEFT;
        break;
    case Qt::Key_Up:
        keystats = mUP;
        break;
    case Qt::Key_Right:
        keystats = mRIGHT;
        break;
    case Qt::Key_Down:
        keystats = mDOWN;
        break;
    default:
        return;
        break;
    }

    GameDisplay(keystats);
    qDebug() << "key press:" << keystats;
}

/*
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{//移动

//    QPoint p_ab = event->globalPos();
//    QPoint p_re = event->pos();

//    QString str;
//    str = QString("%1 , %2").arg(p_ab.x()).arg(p_ab.y());
//    qDebug() << "p_ab:" << p_ab.x() << ":" << p_ab.y() << ";" << "p_re:" << p_re.x() << ":" << p_re.y();

//    str = QString("%1 , %2").arg(p_re.x()).arg(p_re.y());
        qDebug() << "Mouse type:" << event->type();
}
*/

void MainWindow::mousePressEvent(QMouseEvent *event)
{//单击
    // 如果是鼠标左键按下
    if (event->button() == Qt::LeftButton){
        press_x = event->globalX();
        press_y = event->globalY();
        qDebug() << "left press:" << press_x << ":" << press_y;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{//释放
    static int X=0;
    static int Y=0;
    static MouseState dirsta;
    if (event->button() == Qt::LeftButton){
        relea_x = event->globalX();
        relea_y = event->globalY();
        qDebug() << "left release:" << relea_x << ":" << relea_y;
        X = relea_x - press_x;
        Y = relea_y - press_y;
        qDebug() << "X:" << X << ", Y:" << Y;
        //对鼠标（手指）滑动的方向进行判断(右滑)
        if((qAbs(X) > qAbs(Y)) && X>0)
        {
            qDebug() << "LEFT 2 RIGHT" ;
            dirsta = mRIGHT;
        }
        //对鼠标（手指）滑动的方向进行判断(左滑)
        else if((qAbs(X) > qAbs(Y)) && X<0)
        {
            qDebug() << "RIGHT 2 LEFT" ;
            dirsta = mLEFT;
        }
        //对鼠标（手指）滑动的方向进行判断(down)
        else if((qAbs(X) < qAbs(Y)) && Y>0)
        {
            qDebug() << "TOP 2 BOTTOM" ;
            dirsta = mDOWN;
        }
        //对鼠标（手指）滑动的方向进行判断(up)
        else if((qAbs(X) < qAbs(Y)) && Y<0)
        {
            qDebug() << "BOTTOM 2 TOP" ;
            dirsta = mUP;
        }
        else
        {
            qDebug() << "JUST TOUCH";
            press_x = 0;
            press_y = 0;
            relea_x = 0;
            relea_y = 0;
            return;
        }
        press_x = 0;
        press_y = 0;
        relea_x = 0;
        relea_y = 0;
        GameDisplay(dirsta);
    }
}


/*
bool MainWindow::eventFilter(QObject *watch, QEvent *qevent)
{
    static int press_x;     //点击鼠标时获取的横坐标x
    static int press_y;     //点击鼠标时获取的纵坐标y
    static int relea_x;     //松开鼠标时获取的横坐标x
    static int relea_y;     //松开鼠标时获取的纵坐标y

    cout << "QMouseEvent" << endl;

    QMouseEvent *event = static_cast<QMouseEvent *>(qevent);

    //获取点击鼠标（手指）时的坐标
    if (event->type() == QEvent::MouseButtonPress)
    {
        press_x = event->globalX();
        press_y = event->globalY();
        cout << "Mouse Press" << endl;
    }
    //获取松开鼠标（手指）时的坐标
    if(event->type() == QEvent::MouseButtonRelease)
    {
        relea_x = event->globalX();
        relea_y = event->globalY();
        cout << "Mouse Release" << endl;
    }

    //对鼠标（手指）滑动的方向进行判断(右滑)
    if((relea_x - press_x) > 5 && event->type() == QEvent::MouseButtonRelease && qAbs(relea_y - press_y) < 50)
    {
        cout << "right" << endl;
    }
    //对鼠标（手指）滑动的方向进行判断(左滑)
    if((press_x - relea_x) > 5 && event->type() == QMouseEvent::MouseButtonRelease && qAbs(relea_y - press_y) < 50)
    {
        cout << "left" << endl;
    }

    return QWidget::eventFilter(watch, qevent);
}
*/

MainWindow::~MainWindow()
{
    delete ui;
}

//重新开始
void MainWindow::on_restartButton_clicked()
{
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            game.pix[i][j] = 0;

    game.CreatNumber();
    game.CreatNumber();
    showbroad();
    totscore = 0;
    ui->score2->setText(QString::number(totscore));
}
