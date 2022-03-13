#include "mythread.h"
#include <QDebug>
#include <QMutex>


//这个文件用于定义自己的线程类的成员函数
MyThread::MyThread()
{
    isStop = false;
}

void MyThread::closeThread()
{
    isStop = true;
}

void MyThread::run()
{
//    while (1)
//    {
        if(isStop)
            return;
        qDebug()<<tr("mythread QThread::currentThreadId()==")<<QThread::currentThreadId();
        sleep(1);
//    }
}
