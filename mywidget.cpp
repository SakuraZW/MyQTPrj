#include <QFontComboBox>
#include <QComboBox>
#include <QStringList>
#include <QDebug>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <qprocess.h>
#include <QMessageBox>
#include <thread>
#include <Windows.h>
#include <QThread>
#include <QWindow>

#include "g29ctrl.h"
#include "mywidget.h"

//replace your own path
#define FFMPEG_PATH "D:\\MyProject\\RemoteDrive\\FFmpeg\\ffmpeg_4.4_full_build\\bin\\ffplay.exe"
#define VIDEO_URL "D:\\IDM_DownLoad\\Video\\f.flv"



myWidget::myWidget(QWidget *parent)
    : QWidget(parent) //初始化列表
{
    //设置父窗口的大小及标题
    this->setWindowTitle("Remote Drive v1.0 ");
    this->setFixedSize(300, 200);

    //设置第一个按键
    btn_video = new QPushButton;           //new一个新的按键的对象出来，同时将这个指针幅值给类中的成员变量 类中的成员变量可以在类中的不同成员函数之间调用
//    QPushButton *btn = new QPushButton; //此处相当于新建了一个按键的指针，这个按键只是这个函数的局部变量 无法被外部变量所调用
//    btn->show();        //创建了一个button但是并未是在之前的窗口里面
                        //show是以顶层的方式弹出窗口空间
                        //让btn对象依赖在myWidget对象中
    btn_video->setParent(this);
    //显示文本
    btn_video->setText("Start Video");
    btn_video->move(90,20);
    btn_video->resize(120, 40);

    //创建第二个按钮
    btn_ctrl = new QPushButton("Start G29 Control", this);
    btn_ctrl->move(90,80);
    btn_ctrl->resize(120, 40);



    //创建下拉选项
    cbx_ratio = new QComboBox(this);
    const QStringList my_text = {"1920*1080","1080*720","640*480"};     //设置视频拉流的分辨率
//    resolution_ratio =  cbx_ratio->currentText();                     //由于我在自己的类中定义了三个控件，即两个按键一个下拉列表 所以此处我就不需要这个全局变量来传递列表中的分辨率
    cbx_ratio->addItems(my_text);
    cbx_ratio->resize(120, 40);
    cbx_ratio->move(90,140);


    thrd_data_send = new MyThread;    //创建一个新的线程,用来发送数据g29_error

//    windo_err = new QMainWindow;
//    windo_err->setParent(this);
    //关联信号与槽函数
    connect(btn_ctrl, &QPushButton::clicked, this, &myWidget::ctrl_G29_slot);

    connect(thrd_data_send, &MyThread::g29_init_error, this, &myWidget::create_error_info);        //当你想用QT

    connect(btn_video, &QPushButton::clicked, this, &myWidget::start_video_slot);
    connect(btn_ctrl, &QPushButton::clicked, this, &myWidget::ctrl_G29_slot);
}

void myWidget:: start_video_slot()   //定义一个在myWidget类下的函数方法
{
    QString resolution_ratio = {};       //存放分辨率
    qDebug()<< "start video";
    QStringList arg_ratio;
    QProcess *myProcess = new QProcess();       //使用下面这种声明方式却无法播放视频
//    QProcess myProcess(this);       //详见onenote的笔记中说明 相当于使用类中的创建函数
    QString program =  FFMPEG_PATH;
    QStringList arguments;


    resolution_ratio = cbx_ratio->currentText();            //调用成员变量中的控件 下拉列表

    if( "1920*1080" == resolution_ratio)                    //判断下拉列表中的分辨率 注意start函数的参数得是QStringList类型的变量
        arg_ratio = {"-x", "1920", "-y", "1080"};
    else if ( "1080*720" == resolution_ratio )
        arg_ratio = {"-x", "1080", "-y", "720"};
    else
        arg_ratio = {"-x", "640", "-y", "480"};

    arguments << arg_ratio;
    arguments << VIDEO_URL;//传递到可执行文件的参数
    qDebug() << arguments;//调试
    myProcess->start(program, arguments);


}

void myWidget::ctrl_G29_slot()
{
    thrd_data_send->start();
//    qDebug()<<"主线程"<<QThread::currentThreadId();enum error_type err
}

void myWidget::create_error_info()
{

//    switch (err)
//    {
//        case g29_error:
        qDebug()<<"hello";
//    }


}

//我的窗口类的析构 创建出来的对象必须要释放
myWidget::~myWidget()
{
}



