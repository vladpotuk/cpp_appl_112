#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNode.h"

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;

public:
    LinkedList();
    ~LinkedList();

    void pushBack(T val);
    void display();

    LinkedList<T> clone();
    LinkedList<T> operator+(const LinkedList<T>& other);
    LinkedList<T> operator*(const LinkedList<T>& other);

    bool contains(T val) const; 
};

#endif 
