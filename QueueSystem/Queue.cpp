#include "Queue.h"
#include <iostream>

// 有头结点
void initQueue(Queue &queue)
{
    queue.front = new Node;
    if (!queue.front)
    {
        exit(-1);
    }
    queue.front->next = NULL;
    queue.rear = queue.front;
}

void enQueue(Queue &queue, Node &node)
{
    Node *newNode = new Node;
    *newNode = node;
    queue.rear->next = newNode;
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
        queue.rear = queue.front;
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
    std::cout << "队列的长度:" << lenthQueue(queue) << std::endl;
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