#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void closeThread();

protected:
    void run() Q_DECL_OVERRIDE;

private:
    volatile bool isStop;

signals:
    void g29_init_error();  //g29初始化错误
    void socket_init_error();
    void inet_error();


};

#endif // MYTHREAD_H
