//  
//  Event.h
//  QueueSystem
//
//  Create by Euryugasaki on 2014-03-24.
//  Copyright (c) 2014 Euryugasaki. All rights reserved.
// 

#ifndef __EVENT_H_
#define __EVENT_H_

typedef struct Event
{
    int occur_time;      // 表示的是事件发生的时刻
    int event_type;      // 表示事件的类型
    struct Event *next;  // 下一个事件
} Event;
// 事件链表也是有头结点的

void initEventList(Event* &eventList);
void orderInsert(Event* &eventList, Event &event);
void deleteFirstEvent(Event* &eventList);

#endif