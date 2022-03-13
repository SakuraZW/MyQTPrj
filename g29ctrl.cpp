#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/timeb.h>
#include <winsock.h>
#include <QDebug>
#include "LogitechSteeringWheelLib.h"
#include "g29ctrl.h"

#pragma comment(lib, "Ws2_32.lib")      //必须要有这个库，winsock需要使用这个库。详见笔记，注意看编译器的报错显示，同时学会使用MSDN
#pragma comment  (lib, "Advapi32.lib")
#pragma comment(lib, "LogitechSteeringWheelLib.lib")
#pragma comment( linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")

using namespace std;

int driver[5];
int driverdata = 0;
int changeddata = 0;
int symb = 0;

int WheelInit()
{
/*
    if (LogiSteeringInitialize(true))
    {
        cout << "————————————————————————————————————————" << endl;
        printf("init secusssssss\n");
        int gearShifter = 0;
        //sendthere(1);

        while (LogiUpdate() && LogiIsConnected(0))
        {
            printf("update seccessed\n");
            LogiPlaySpringForce(0, 0, 90, 1);//产生弹簧力
            LogiPlayDamperForce(0, 5);//产生阻尼力
            LogiPlaySurfaceEffect(0, 0, 5, 1000);//路面响应效果
            //printf("connect secuss\n");
            //Sleep(20);
            DIJOYSTATE2* wheel = LogiGetState(0);

            //输出角度，油门，刹车信息

            //printf("Angle = %d  Accelerator = %d  Brake = %d\n", wheel->lX, wheel->lY,wheel->lRz);

            //printf(wheel->rgdwPOV)
            //std::cout << wheel->rglSlider[0] << endl;

                            //挡位
            if (LogiButtonIsPressed(0, 13) || LogiButtonIsPressed(0, 14) || LogiButtonIsPressed(0, 15) || LogiButtonReleased(0, 15) || LogiButtonReleased(0, 14) || LogiButtonReleased(0, 13))
            {


                //挡位 2（P) 挡
                if (LogiButtonTriggered(0, 13))
                {
                    gearShifter = 2;
                }
                else if (LogiButtonIsPressed(0, 13))
                {
                    // if (gearShifter.OnPressed != null) gearShifter.OnPressed(2);
                }
                else if (LogiButtonReleased(0, 13))
                {
                    // if (gearShifter.OnReleased != null) gearShifter.OnReleased(2);
                }

                //挡位 3（D） 挡
                if (LogiButtonTriggered(0, 14))
                {
                    gearShifter = 1;
                }
                else if (LogiButtonIsPressed(0, 14))
                {
                    //if (gearShifter.OnPressed != null) gearShifter.OnPressed(3);
                }
                else if (LogiButtonReleased(0, 14))
                {
                    //if (gearShifter.OnReleased != null) gearShifter.OnReleased(3);
                }

                //挡位 4（R） 挡
                if (LogiButtonTriggered(0, 15))
                {
                    gearShifter = -1;
                }
                else if (LogiButtonIsPressed(0, 15))
                {
                    // if (gearShifter.OnPressed != null) gearShifter.OnPressed(4);
                }
                else if (LogiButtonReleased(0, 15))
                {
                    //if (gearShifter.OnReleased != null) gearShifter.OnReleased(4);
                }


                //N档
                {
                    if (LogiButtonReleased(0, 13)
                        || LogiButtonReleased(0, 14)
                        || LogiButtonReleased(0, 15)
                        )
                    {
                        gearShifter = 0;
                    }
                }
            }

            //SendMessage(wheel->lX, wheel->lY, wheel->lRz,wheel->rglSlider[0], gearShifter);
            cout << wheel->lX<< wheel->lY<< wheel->lRz<< wheel->rglSlider[0]<< gearShifter << endl;

            driver[0] = wheel->lX;
            driver[1] = wheel->lY;
            driver[2] = wheel->lRz;
            driver[3] = wheel->rglSlider[0];
            driver[4] = gearShifter;
            changeddata = 0;
            switch (gearShifter)
            {
            case -1://  changeddata = 30，000，000
                changeddata = changeddata + 30000000;
                break;
            case 1://  changeddata = 10，000，000
                changeddata = changeddata + 10000000;
                break;
            case 2://前进挡位  changeddata = 20，000，000
                changeddata = changeddata + 20000000;
                break;
            default:
                break;
            }
            changeddata = changeddata - ((driver[1] - 32767) * 22 / 65535) * 10000;
            if (driver[0] > 0) {//角度方向为右
                changeddata = changeddata + 1000;
            }
            changeddata = changeddata + abs(driver[0]) * 450 / 32767;
            driverdata = changeddata;
            //printf("Angle = %d  Accelerator = %d  Brake = %d  离合 = %d  档位 = %d\n", driver[0], driver[1], driver[2], driver[3], driver[4]);
            SendMessage(driver[0], driver[1], driver[2], driver[4]);
            printf("Angle = %d  Accelerator = %d  Brake = %d  离合 = %d  档位 = %d\n", driver[0], driver[1], driver[2], driver[3], driver[4]);
            printf("changeddata = %d\n", changeddata);
//            sendthere(111);
            printf("update finished\n");
            cout << "timestamp:" << TimeMilliSecond() << endl;
            cout << "————————————————————————————————————————" << endl;
            //Sleep(500);
        }

    }
*/

//    else
//    {

            qDebug()<<"init faild";         //QT中尽量使用qdebug输出调试信息。如果使用功printf和cout在多线程情况下无法输出
            symb = 1;

//    }
    return symb;
}

uint64_t TimeMilliSecond()
{
    timeb now;
    ftime(&now);
    return now.time * 1000 + now.millitm;
}

void initialization() {
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2);//版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        cout << "初始化套接字库失败！" << endl;
    }
    else {
        cout << "初始化套接字库成功！" << endl;
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "套接字库版本号不符！" << endl;
        WSACleanup();
    }
    else {
        //cout << "套接字库版本正确！" << endl;
    }
    //填充服务端地址信息

}

void SendMessage(int x, int y, int z, int bb)//创建并关闭套接字，接受发送数据；
{
    //定义长度变量
    int send_len = 0;
    int recv_len = 0;
    //定义发送缓冲区和接受缓冲区
    char send_buf[100];
    char recv_buf[100];
    //定义服务端套接字，接受请求套接字
    SOCKET s_server;
    //服务端地址客户端地址
    SOCKADDR_IN server_addr;

    initialization();       //网络连接的初始化

    //填充服务端信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.S_un.S_addr = inet_addr(INET_ADDR);
    server_addr.sin_port = htons(8888);
    //创建套接字
    s_server = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        cout << "服务器连接失败！" << endl;
        WSACleanup();
    }

    else {
        cout << "服务器连接成功！" << endl;
    }


    //发送,接收数据

    //cout << "请输入发送信息:";
    //cin >> send_buf;

    sprintf_s(send_buf, "%X%X%X%X", x + 1081344, y + 1081344, z + 1081344, bb + 1);
    send_len = send(s_server, send_buf, sizeof(send_buf), 0);
    if (send_len < 0) {

        cout << "发送失败！" << endl;

    }
    printf("send success x = %d,y = %d,z = %d,dangwei =%d\n", x + 42768, y + 42768, z + 42768, bb + 1);
    Sleep(20);


    //接受数据
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = recv(s_server, recv_buf, 100, 0);
    if (recv_len < 0) {
        cout << "接受失败！" << endl;
    }
    else {
        cout << "———————————————" << endl;
        //cout << "服务端信息:" << recv_buf << endl;
    }


    //关闭套接字
    closesocket(s_server);
    //释放DLL资源
    WSACleanup();

}
