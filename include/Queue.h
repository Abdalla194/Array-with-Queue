#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    static int activeStacksCount;

    int* items;
    int sizeArray;

    int rear;
    int front;
    int count;

public:
    Queue(int sizeArray);

    Queue(const Queue& q);
    Queue& operator=(const Queue& q);

    ~Queue();

    void push(int data);
    int pop();
    void display();

    static int getactiveStacksCount();
};

#endif