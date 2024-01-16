#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(T val) : data(val), next(nullptr) {}
};

#endif 

