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
    void show_error_msg(const QString);  //g29初始化错误
};

#endif // MYTHREAD_H
