#ifndef __SERVICE_WINDOW_H_
#define __SERVICE_WINDOW_H_

#include "Node.h"

typedef struct ServiceWindow
{
    Customer customer;
    int flag;           // 0表示当前窗口是空闲的，1表示当前窗口是被占用的
} ServiceWindow;

void initServiceWindows(ServiceWindow* &windows);
void destroyWindows(ServiceWindow* &windows);
int idleWindow(ServiceWindow* &windows);

#endif