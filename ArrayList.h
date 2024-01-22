//
// Created by voiz94 on 19.01.2024.
//

#ifndef MATRIX_ARRAYLIST_H
#define MATRIX_ARRAYLIST_H


#include "List.h"
#include "ArrayListIterator.h"

template <typename T>
class ArrayList : public List<T> {
    T* arr;
    int capacity;
public:
    ArrayList() : List<T>(0) { capacity = 0; };

    ArrayList(unsigned _length) : List<T>(_length) {
        arr = new T[List<T>::length];
        capacity = List<T>::length;
    };

    ArrayList(unsigned _length, T n) : List<T>(_length) {
        arr = new T[List<T>::length];
        capacity = List<T>::length;
        for (int i = 0; i < List<T>::length; i++) arr[i] = n;
    };

    ~ArrayList() override = default;

    void push_back(T obj) override{
        if (capacity > List<T>::length) {
            arr[List<T>::length] = obj;
            List<T>::length++;
        }
        else {
            T* new_arr = new T[List<T>::length + 1];
            if (List<T>::length != 0) {
                copy(arr, new_arr, List<T>::length);
                delete[] arr;
            }
            new_arr[List<T>::length] = obj;
            List<T>::length++;
            capacity++;
            arr = new_arr;
        }
    };

    void pop_back() {
        if (List<T>::length > 0) {
            List<T>::length--;
            //arr[List<T>::length] = 0;
        }
    };

    void insert(int n, T obj) override {
        if (n == List<T>::length) push_back(obj);
        else {
            if (capacity > List<T>::length) {
                for (int i = List<T>::length; i > n; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[n] = obj;
                List<T>::length++;
            }
            else {
                if ((n >= 0) && (n < List<T>::length)) {
                    T* new_arr = new T[List<T>::length + 1];
                    if (n == 0) {
                        new_arr[0] = obj;
                        copy(arr, new_arr + 1, List<T>::length);
                    }
                    else {
                        copy(arr, new_arr, n);
                        new_arr[n] = obj;
                        copy(arr + n, new_arr + n + 1, List<T>::length - n);
                    }
                    delete[] arr;
                    arr = new_arr;
                    List<T>::length++;
                    capacity++;
                }
            }
        }
    };

    void erase(int n) override {
        if (n >= 0 && n < List<T>::length) {
            if (n == List<T>::length - 1) pop_back();
            else {
                for (int i = n; i < List<T>::length - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                List<T>::length--;
            }
        }
    };

    ArrayListIterator<T> erase(ArrayListIterator<T> it) {
        bool ind = false;
        ArrayListIterator<T> result(nullptr);
        for (int i = 0; i < List<T>::length; i++) {
            if (it == arr + i) {
                ind = true;
                ArrayListIterator<T> new_it(arr + 1);
                result = new_it;
            }
            if (ind && (i != List<T>::length - 1)) arr[i] = arr[i + 1];
        }
        if (ind) List<T>::length--;
        return result;
    };

    void copy(T* arr, T* new_arr, int size) {
        if ((size > 0) && (size <= List<T>::length)) {
            for (int i = 0; i < size; i++) new_arr[i] = arr[i];
        }
    };

    void reserve(unsigned size) {
        if (size > List<T>::length) {
            T* new_arr = new T[size];
            copy(arr, new_arr, List<T>::length);
            for (int i = List<T>::length; i < size; i++) new_arr[i] = 0;
            delete[] arr;
            arr = new_arr;
            capacity = size;
        }
    };

    void clear() {
        for (int i = 0; i < List<T>::length; i++) {
            arr[i] = 0;
        }
        List<T>::length = 0;
    };

    ArrayListIterator<T> begin() {
        ArrayListIterator<T> it(arr);
        return it;
    };

    ArrayListIterator<T> end() {
        return arr + List<T>::length;
    };

    T& operator[](int index) {
        return *(arr + index);
    };
};


#endif //MATRIX_ARRAYLIST_H
