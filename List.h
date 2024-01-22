//
// Created by voiz94 on 19.01.2024.
//

#ifndef MATRIX_LIST_H
#define MATRIX_LIST_H


template <typename T>
class List {
protected:
    unsigned length;
public:
    explicit List(unsigned _length) : length(_length) {};
    virtual ~List() { };
    virtual void push_back(T obj) = 0;
    virtual void insert(int n, T obj) = 0;
    virtual void erase(int n) = 0;
    unsigned size() {
        return length;
    };
};


#endif //MATRIX_LIST_H
