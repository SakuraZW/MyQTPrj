#include "mythread.h"
#include "g29ctrl.h"
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QLabel>

#include "mythread.h"
#include "g29ctrl.h"


////这个文件用于定义自己的线程类的成员函数
MyThread::MyThread()
{
//    isStop = false;
}

void MyThread::closeThread()
{
    isStop = true;
}

void MyThread::run()
{
    if (g29_error == WheelInit())
    {
        emit show_error_msg("g29_error");
    }
}

//下面的代码用于辅助测试子线程是否工作
//    while (1)
//    {
//        if(isStop)
//            return;
//        qDebug()<<tr("mythread QThread::currentThreadId()==")<<QThread::currentThreadId();
//        sleep(1);
//    }
