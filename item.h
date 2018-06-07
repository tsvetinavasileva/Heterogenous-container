//
// Created by Tsvetina on 22.1.2018 г..
//
#ifndef ELEM_H
#define ELEM_H
template <typename T>
struct item {
    T inf;
    item<T>* link;

    item(T x) {
        inf = x;
    }
    item(){
        inf = -1;
        link = nullptr;
    }
};
#endif