#ifndef __EVENT_H_
#define __EVENT_H_

typedef struct Event
{
    int occur_time;      // 表示的是事件发生的时刻
    int evnet_type;      // 表示事件的类型
    struct Event *next;  // 下一个事件
} Event;
// 有头结点

void initEventList(Event* &eventList);
void orderInsert(Event* &eventList, Event &event);
void deleteFirstEvent(Event* &eventList);

#endif