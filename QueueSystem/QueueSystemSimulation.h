#ifndef __QUEUE_SYSTEM_SIMULATION_H_
#define __QUEUE_SYSTEM_SIMULATION_H_

#include "Event.h"
#include "ServiceWindow.h"
#include "Queue.h"

// 排队系统的模拟
double QueueSystemSimulation(int total_service_time, int window_num);

void systemStrat(Event* &eventList, ServiceWindow* &windows, Queue &queue);
void systemEnd(ServiceWindow* &windows, Queue &queue);

void customerArrived(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event);
void customerDeparture(Event* &eventList, ServiceWindow* &windows, Queue &queue, Event &event);

#endif