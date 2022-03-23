#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget> //包含头文件 Qwidget
#include <QPushButton>
#include <QComboBox>
#include <QMainWindow>
#include <QErrorMessage>

#include <mythread.h>

//enum error_type{
//    g29_error,
//    socket_error,
//    inet_error,
//    unknown_error,
//};

//定义了我的窗口类 此类继承了QWidget大类
class myWidget : public QWidget
{
    Q_OBJECT        //是一个宏 运行类中使用信号和槽的机制
public:
    QPushButton *btn_video;
    QPushButton *btn_ctrl;
    QComboBox *cbx_ratio;
//    QMainWindow *windo_err;
    QErrorMessage *err_msg;
public:
    myWidget(QWidget *parent = nullptr);    //类名字相同的默认就是类的构造函数 默认参数enum error_typeenum error_type
    ~myWidget();

public slots:
    void start_video_slot();
    void ctrl_G29_slot();

public:
    MyThread * thrd_data_send;
};

#endif // MYWIDGET_H
