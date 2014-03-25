#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "Node.h"

// 带头结点
typedef struct Queue
{
    Node *front;    // 头结点, 不是队首
    Node *rear;     // 队尾
} Queue;

void initQueue(Queue &queue);
void enQueue(Queue &queue, Node &node);
void deQueue(Queue &queue, Node &node);
void destroyQueue(Queue &queue);
void printQueue(Queue  &queue);
int lenthQueue(Queue &queue);

#endif