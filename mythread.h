#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread:public QThread
{

public:
    MyThread();
    void closeThread();
protected:
    virtual void run();

private:
    volatile bool isStop;

};

#endif // MYTHREAD_H
