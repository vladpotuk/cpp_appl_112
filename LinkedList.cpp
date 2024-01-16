#include "LinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::pushBack(T val) {
    ListNode<T>* newNode = new ListNode<T>(val);

    if (!head) {
        head = newNode;
        return;
    }

    ListNode<T>* current = head;
    while (current->next) {
        current = current->next;
    }

    current->next = newNode;
}

template <typename T>
void LinkedList<T>::display() {
    ListNode<T>* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
LinkedList<T> LinkedList<T>::clone() {
    LinkedList<T> clonedList;

    ListNode<T>* current = head;
    while (current) {
        clonedList.pushBack(current->data);
        current = current->next;
    }

    return clonedList;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& other) {
    LinkedList<T> result = clone();

    ListNode<T>* current = other.head;
    while (current) {
        if (!result.contains(current->data)) {
            result.pushBack(current->data);
        }
        current = current->next;
    }

    return result;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator*(const LinkedList<T>& other) {
    LinkedList<T> result;

    ListNode<T>* current = head;
    while (current) {
        if (other.contains(current->data)) {
            result.pushBack(current->data);
        }
        current = current->next;
    }

    return result;
}

template <typename T>
bool LinkedList<T>::contains(T val) const {
    ListNode<T>* current = head;
    while (current) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template class LinkedList<int>;
