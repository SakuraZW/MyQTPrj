#ifndef G29CTRL_H
#define G29CTRL_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sys/timeb.h>
#include <winsock.h>
#include <sys/types.h>

#define BUF_SIZE 4096
#define INET_ADDR ("119.45.138.172")

enum error_type{
    none_error,
    g29_error,
    socket_error,
    inet_error,
    unknown_error,
};

enum error_type WheelInit();
uint64_t TimeMilliSecond();
void initialization();
void SendMessage(int x, int y, int z, int bb);

#endif // G29CTRL_H
