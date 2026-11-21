#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class LinkedList {
 private:
  Node* head;
  Node* tail;
  int count;

 public:
  LinkedList();
  ~LinkedList();
  void push_back(int value);
  void InsertAfter(int data, int afterData);
  void InsertBefore(int data, int beforeData);
  int GetCount();
  int GetDataByIndex(int index);

  Node* get_head() const;
};

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  count = 0;
}

LinkedList::~LinkedList() {
  Node* temp = head;

  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }

  head = nullptr;
  tail = nullptr;
  count = 0;
}

void LinkedList::push_back(int value) {
  Node* newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }

  count++;
}

void LinkedList::InsertAfter(int data, int afterData) {
  Node* temp = head;

  while (temp != nullptr && temp->data != afterData) temp = temp->next;

  if (temp == nullptr) return;

  Node* newNode = new Node(data);

  newNode->next = temp->next;
  temp->next = newNode;

  if (temp == tail) tail = newNode;

  count++;
}

void LinkedList::InsertBefore(int data, int beforeData) {
  if (head == nullptr) return;

  Node* temp = head;

  while (temp->next != nullptr && temp->next->data != beforeData)
    temp = temp->next;

  if (temp->next == nullptr) return;

  Node* newNode = new Node(data);

  newNode->next = temp->next;
  temp->next = newNode;

  count++;
}

int LinkedList::GetCount() { return count; }

int LinkedList::GetDataByIndex(int index) {
  if (index < 0 || index >= count) return -1;

  Node* temp = head;

  for (int i = 0; i < index; i++) temp = temp->next;

  return temp->data;
}

Node* LinkedList::get_head() const { return head; }

int main() {
  LinkedList list;

  list.push_back(10);

  list.push_back(20);
  list.push_back(30);

  list.InsertAfter(15, 10);
  list.InsertBefore(25, 30);
  Node* temp = list.get_head();

  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << "\nCount: " << list.GetCount() << endl;
  if (list.GetDataByIndex(1010) == -1)
    cout << "incorrect index: \n";
  else
    cout << "Data of index " << list.GetDataByIndex(1010) << "\n";
  cout << "Data of index 2: " << list.GetDataByIndex(2) << "\n";
  return 0;
}