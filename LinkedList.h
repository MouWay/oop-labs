//
// Created by voiz94 on 20.01.2024.
//

#ifndef MATRIX_LINKEDLIST_H
#define MATRIX_LINKEDLIST_H


#include "List.h"
#include <stdexcept>

template <typename T>
class LinkedList : public List<T> {

    struct Node{
        T data;
        struct Node *next;
    };

protected:
    struct Node *head = nullptr;
public:
    LinkedList() : List<T>(0){};
    ~LinkedList() = default;

    void push_back(T obj) override{
        struct Node* node = new Node;
        node->data = obj;
        node->next = nullptr;

        if (head == nullptr) head = node;
        else {
            struct Node *last = *head;
            while (last->next != nullptr) last = last->next;
            last->next = node;
        }
    }

    void insert(int n, T obj) override{
        if (n == List<T>::length) push_back(obj);
        else if (n > List<T>::length) throw std::out_of_range("N is more than list length");
        else if (n == 0) {
            struct Node* node = new Node;
            node->data = obj;
            node->next = head;

            head = node;
        }
        else {
            struct Node *last = *head;
            for (int i = 1; i < n; i++){
                last = last->next;
            }

            struct Node* node = new Node;
            node->data = obj;
            node->next = last->next;
            last->next = node;
        }
    }

    void erase(int n) override{
        if (n > List<T>::length) throw std::out_of_range("N is more than list length");
        else if (n == 0) head = head->next;
        else{
            struct Node *last = *head;
            for (int i = 1; i < n; i++){
                last = last->next;
            }
            if (n == List<T>::length) last->next= nullptr;
            else last->next=last->next->next;
        }
    }

    T& operator[](int index) {
        if (index > List<T>::length) throw std::out_of_range("Index is out of range");
        else {
            struct Node *node = *head;
            for (int i = 0; i < index; i++){
                node = node->next;
            }
            return node->data;
        }
    };
};


#endif //MATRIX_LINKEDLIST_H
