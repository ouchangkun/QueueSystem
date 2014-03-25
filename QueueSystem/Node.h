#ifndef __NODE_H_
#define __NODE_H_

typedef struct Node
{
    int arrive_time;    // 到达时间
    int duration;       // 服务时间
    struct Node *next;
} Node, Customer;

#endif