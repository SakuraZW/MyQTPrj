#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget> //包含头文件 Qwidget
#include <QPushButton>
#include <QComboBox>

//定义了我的窗口类 此类继承了QWidget大类
class myWidget : public QWidget
{
    Q_OBJECT        //是一个宏 运行类中使用信号和槽的机制
public:
    QPushButton *btn_video;
    QPushButton *btn_ctrl;
    QComboBox *cbx_ratio;
public:
    myWidget(QWidget *parent = nullptr);    //类名字相同的默认就是类的构造函数 默认参数
    ~myWidget();

public:
    void start_video();
    void ctrl_G29();
};

#endif // MYWIDGET_H
