//
// Created by Tsvetina on 22.1.2018 г..
//
#ifndef ITERATOR_H
#define ITERATOR_H
#include "item.h"
template <typename T>
class Iterator {
private:
    item<T>* it;
public:
    Iterator () : it (nullptr){}

    explicit Iterator (item<T>* item) : it (item){}

    void operator++(int) {
        it = it->link;
    }

    bool operator ==(const Iterator<T>* iterator) {
        return it == iterator;
    }

    bool operator !=(const Iterator<T>* iterator) {
        return it != iterator;
    }

    bool valid () {
        return it != nullptr;
    }

    T operator *() {
        return it->inf;
    }
};
#endif