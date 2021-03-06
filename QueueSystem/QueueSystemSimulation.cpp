//  
//  QueueSystemSimulation.cpp
//  QueueSystem
//
//  Create by Euryugasaki on 2014-03-24.
//  Copyright (c) 2014 Euryugasaki. All rights reserved.
// 

#include "QueueSystemSimulation.h"
#include "Random.h"
#include <iostream>

// 服务台的窗口数
extern int window_num;
// 总的营业时间
int total_service_time = 0;
// 顾客的逗留总时间
int customer_stay_total_time = 0;
// 总的顾客数
int total_customer_num = 0;

double QueueSystemSimulation(int a1, int a2)
{
    total_service_time = a1;
    window_num = a2;

    // 顾客的逗留总时间
    customer_stay_total_time = 0;
    // 总的顾客数
    total_customer_num = 0;

    // 整个模拟依赖于一个事件表（时间线）
    Event *eventList;
    Event event;
    event.event_type = -1;  // -1表示到达事件，>=0的数字表示离开事件，同时还表示第几个窗口的顾客离开
    event.occur_time = 0;
    event.next = NULL;

    ServiceWindow *windows = NULL;
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;

    // 系统开始（初始化）
    systemStart(eventList, windows, queue);

    // 处理完全部事件，则表示营业已经结束了
    while (eventList->next)
    {
        event.event_type = eventList->next->event_type; // 获取下一个事件的事件类型
        event.occur_time = eventList->next->occur_time; // 获取下一个事件的发生时间
        deleteFirstEvent(eventList);                    // 删除事件链表的第一个事件
        if (event.event_type == -1) // 如果当前要发生的时间是0，则表明有顾客到达，处理顾客到达，否则，顾客离开
            customerArrived(eventList, windows, queue, event);
        else
            customerDeparture(eventList, windows, queue, event);
        //printQueue(queue);
    }

    systemEnd(windows, queue);
    double t = (float)customer_stay_total_time / total_customer_num;
    return t;
}

void systemStart(Event* &eventList, ServiceWindow* &windows, Queue &queue)
{
    initEventList(eventList);
    initServiceWindows(windows);
    initQueue(queue);
}

void systemEnd(ServiceWindow* &windows, Queue &queue)
{
    destroyQueue(queue);
    destroyWindows(windows);
    //std::cout << "办理业务总人数为：" << total_customer_num << "人." << std::endl;
    //std::cout << "每个顾客平均在系统内逗留的时间为：" << (float)customer_stay_total_time / total_customer_num << "分钟." << std::endl;
}

void customerArrived(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event)
{
    //std::cout << "-------顾客到达-------" << std::endl;
    total_customer_num++;
    int durtime = getExponentail(0.1);      // 办理业务所需要的时间
    int intertime = getPoisson(30);    // 随机生成下一个顾客的到达时间间隔

    // 生成下一个顾客的到达事件
    int time = event.occur_time + intertime; // 下一个顾客的到达时间 = 当前事件的发生时间 + 下一个顾客到达的时间间隔
    Event temp_event;
    temp_event.occur_time = time;
    temp_event.event_type = -1;
    temp_event.next = NULL;

    //std::cout << "顾客的到达时间为：" << event.occur_time << std::endl;

    if (time < total_service_time)
    {
        orderInsert(eventList, temp_event);
        //std::cout << "下一个顾客的到达时间为：" << time << std::endl;
    }

    // 把当前事件到达的顾客插入到队列当中
    Customer customer;
    customer.arrive_time = event.occur_time;
    customer.duration = durtime;
    customer.next = NULL;
    enQueue(queue, customer);

    // 如果当前窗口是有空闲窗口的，那么我们直接就不需要排队就可以直接进服务台服务了
    int i = idleWindow(windows);
    // -1表示没有窗口是空闲，如果没有窗口是空闲的话呢，我们就什么也不做
    if (i == -1)
    {
        ;
    }
    else
    {
        deQueue(queue, customer);
        windows[i].customer = customer;
        windows[i].flag = 1;    // 标记窗口被占用

        // 顾客到窗口开始服务了，我们就需要插入这个顾客的一个离开时间到时间线（事件表）当中
        temp_event.occur_time = event.occur_time + durtime; // 离开事件的发生时间 = 当前时间的发生时间 + 服务时间
        temp_event.event_type = i;
        temp_event.next = NULL;
        orderInsert(eventList, temp_event);
    }
}
void customerDeparture(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event)
{
    //std::cout << "-------顾客离开-------" << std::endl;
    //std::cout << "顾客的离开事件为：" << event.occur_time << std::endl;

    if (event.occur_time > total_service_time)
    {
        ; // 如果这个离开事件的发生时间比总服务时间大，则什么也不做
    }
    else
    {
        // 顾客的逗留时间 = 当前顾顾客的离开时间 - 顾客的到达时间
        customer_stay_total_time += event.occur_time - windows[event.event_type].customer.arrive_time;
        // 如果队列还有人，则直接将队首的人叫到服务台来进行服务
        if (queue.front->next)
        {
            Customer customer;
            deQueue(queue, customer);
            windows[event.event_type].customer = customer;

            // 离开事件
            Event temp_event;
            temp_event.occur_time = event.occur_time + customer.duration;
            temp_event.event_type = event.event_type;
            orderInsert(eventList, temp_event);
        }
        else
        {
            // 如果队列没有人，且当前窗口的顾客又离开了，那么这个窗口就处于空闲状态。
            windows[event.event_type].flag = 0;
        }
    }
}