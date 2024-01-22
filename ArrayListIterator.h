//
// Created by voiz94 on 19.01.2024.
//

#ifndef MATRIX_ARRAYLISTITERATOR_H
#define MATRIX_ARRAYLISTITERATOR_H


template <typename T>
class ArrayListIterator {
    T* obj;
public:
    ArrayListIterator(T* obj) {
        this->obj = obj;
    };
    ~ArrayListIterator() {
        obj = nullptr;
    };
    T operator *() {
        return *obj;
    };
    ArrayListIterator<T>& operator +(int n) {
        obj += n;
        return *this;
    };
    ArrayListIterator<T>& operator -(int n) {
        obj -= n;
        return *this;
    };
    bool operator ==(const T* it) {
        if (obj == it) return true;
        else return false;
    };
    bool operator !=(const T* it) {
        return !(obj == it);
    };
    bool operator ==(const ArrayListIterator<T>& it) {
        if (obj == it.obj) return true;
        else return false;
    };
    bool operator !=(const ArrayListIterator<T>& it) {
        return !(obj == it.obj);
    };
    bool operator <(const ArrayListIterator<T>& it) {
        if (obj < it.obj) return true;
        else return false;
    };
    bool operator >(const ArrayListIterator<T>& it) {
        return it.obj < obj;
    };
    ArrayListIterator<T>& operator ++() {
        ++obj;
        return *this;
    };
    ArrayListIterator<T> operator ++(int) {
        ArrayListIterator<T> copy = *this;
        ++(*this);
        return copy;
    };
    ArrayListIterator<T>& operator --() {
        --obj;
        return *this;
    };
    ArrayListIterator<T> operator --(int) {
        ArrayListIterator<T> copy = *this;
        --(*this);
        return copy;
    };
};


#endif //MATRIX_ARRAYLISTITERATOR_H
