#include "Queue.h"

#include <iostream>

using namespace std;

int Queue::activeStacksCount = 0;

int Queue::getactiveStacksCount() { return activeStacksCount; }

Queue::Queue(int sizeArray)
    : sizeArray(sizeArray), rear(0), front(0), count(0) {
  items = new int[sizeArray];

  activeStacksCount++;
}

void Queue::push(int data) {
  if (count == sizeArray) {
    cout << "Queue is full!" << endl;
    return;
  }

  items[rear] = data;

  rear = (rear + 1) % sizeArray;

  count++;
}

int Queue::pop() {
  if (count == 0) {
    cout << "Queue is empty!" << endl;
    return -1;
  }

  int data = items[front];

  front = (front + 1) % sizeArray;

  count--;
  
  return data;
}

void Queue::display() {
  if (count == 0) {
    cout << "Queue is empty!" << endl;
    return;
  }

  cout << endl;

  for (int i = 0; i < count; i++) {
    cout << items[(front + i) % sizeArray] << " ";
  }

  cout << endl;
}

Queue::~Queue() {
  delete[] items;
  activeStacksCount--;
}