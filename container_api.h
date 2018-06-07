//
// Created by Tsvetina on 12.1.2018 г..
//

#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H
#include "condition.h"
#include "iterator.h"
#include "item.h"
#include "queue.cpp"
#include "DLList.cpp"
#include "stack.cpp"
#include <iostream>
template <typename T>
class Container {
public:
    virtual bool isFoundX(T const& x) = 0;
    
    virtual void sortElements() = 0;
    
    virtual int size() const = 0;
    
    virtual void print(std::ostream& os = std::cout) const = 0;

    virtual bool isFoundUnderCondition(Condition<T> cond) = 0;

    virtual void removeElemUnderCondition(Condition<T> cond) = 0;

    virtual void push(T const& x)=0;

    virtual Iterator<T> itX(const T& x) = 0;

    virtual void pop() = 0;
    
    virtual item<T>* getStart() = 0;
};


#endif //PROJECT_CONTAINER_H
