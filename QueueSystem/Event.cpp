#include "Event.h"
#include "Random.h"
#include <iostream>

void initEventList(Event* &eventList)
{
    eventList = new Event;
    eventList->next = NULL;

    Event event;
    event.occur_time = getPoisson(30); // 生成一个1~30的随机值，是第一个顾客隔了多长才会到银行
    event.evnet_type = -1;
    event.next = NULL;
    orderInsert(eventList, event);
}
void orderInsert(Event* &eventList, Event &event)
{
    Event* temp_event;
    temp_event = new Event;
    temp_event->occur_time = event.occur_time;
    temp_event->evnet_type = event.evnet_type;
    temp_event->next = NULL;

    // 如果eventList里面是没有事件的话，那么我们需要把temp_event直接插入
    if (!eventList->next)
    {
        eventList->next = temp_event;
        return;
    }

    // 按照时间顺序来进行插入
    Event *temp_event_list = eventList;
    while (temp_event_list->next && temp_event_list->next->occur_time < event.occur_time)
    {
        temp_event_list = temp_event_list->next;
    }
    // 将其插入
    temp_event->next = temp_event_list->next;
    temp_event_list->next = temp_event;

}
void deleteFirstEvent(Event* &eventList)
{
    Event *temp;
    temp = eventList->next;
    eventList->next = temp->next;
    delete temp;
}