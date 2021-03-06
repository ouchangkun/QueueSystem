//  
//  Queue.cpp
//  QueueSystem
//
//  Create by Euryugasaki on 2014-03-24.
//  Copyright (c) 2014 Euryugasaki. All rights reserved.
// 

#include "Queue.h"
#include <iostream>

// 有头结点
void initQueue(Queue &queue)
{
    queue.front = new Node;
    // 如果申请失败，则不应该继续运行程序了
    if (!queue.front)
        exit(-1);
    queue.front->next = NULL;
    queue.rear = queue.front;
}

void enQueue(Queue &queue, Node &node)
{
    // 插入新节点
    Node *newNode = new Node;
    if (!newNode)
        exit(-1);
    *newNode = node;
    queue.rear->next = newNode;
    // 队尾指针后移
    queue.rear = newNode;
}

void deQueue(Queue &queue, Node &node)
{
    Node *temp_node;
    temp_node = queue.front->next;
    node.arrive_time = temp_node->arrive_time;
    node.duration = temp_node->duration;
    node.next = NULL;
    queue.front->next = temp_node->next;
    if (queue.rear == temp_node)
        queue.rear = queue.front;   // 如果队列中只有一个节点，那么删除后要记得将队尾指针置为头结点
    delete temp_node;
}

void destroyQueue(Queue &queue)
{
    Node *temp_node;
    while (queue.front->next)
    {
        temp_node = queue.front->next;
        queue.front->next = temp_node->next;
        delete temp_node;
    }
    queue.front->next = NULL;
    queue.rear = queue.front;
}

void printQueue(Queue  &queue)
{
    std::cout << "Lenth of queue:" << lenthQueue(queue) << std::endl;
}

int lenthQueue(Queue &queue)
{
    Node *temp_node;
    temp_node = queue.front->next;
    int lenth = 0;
    while (temp_node)
    {
        temp_node = temp_node->next;
        ++lenth;
    }
    return lenth;
}