#include "ServiceWindow.h"

// 队列系统中的窗口数量
int window_num = 0;

void initServiceWindows(ServiceWindow* &windows)
{
    windows = new ServiceWindow[window_num];
    for (int i = 0; i != window_num; i++)
    {
        windows[i].customer.arrive_time = 0;
        windows[i].customer.duration = 0;
        windows[i].flag = 0;    // 0表示空闲
    }
}

void destroyWindows(ServiceWindow* &windows)
{
    delete windows;
}

int idleWindow(ServiceWindow* &windows)
{
    for (int i = 0; i != window_num; i++)
    {
        if (windows[i].flag == 0)   // 如果空闲
        {
            return i;
        }
    }
    return -1;  // -1表示当前没有窗口是空闲
}