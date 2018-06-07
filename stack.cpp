//
// Created by Tsvetina on 12.1.2018 г..
//

#ifndef PROJECT_Stack_H
#define PROJECT_Stack_H


#include <cassert>
#include <iostream>
#include "item.h"
using namespace std;


template <class T>

class Stack {

public:

    Stack(T x);

    Stack();

    ~Stack();

    Stack(Stack const&);



    Stack<T>& operator=(Stack const&);



    void push(T const&);

    item<T>* getTop() const {
        return start;
    }

    void pop();

    T top() const;

    int size() const;

    bool empty() const;

    void print(std::ostream& os = std::cout) const;




private:

    item<T>* start;

    void delStack();

    void copy(Stack const&);

};



template <class T>

Stack<T>::Stack(T x)

{

    start = new item<T>(x);
    assert(start != NULL);

}



template <class T>

Stack<T>::Stack()

{

    start = NULL;

}



template <class T>

Stack<T>::Stack(Stack const& r)

{

    copy(r);

}



template <class T>

Stack<T>::~Stack()

{

    delStack();

}



template <class T>

Stack<T>& Stack<T>::operator=(Stack<T> const& r)

{

    if (this != &r) {

        delStack();

        copy(r);

    }

    return *this;

}



// Stack API

template <class T>

void Stack<T>::push(T const& x)

{

    item<T>* i = new item<T>(x);

    assert(i != NULL);

    i->link = start;

    start = i;

}



template <class T>

void Stack<T>::pop()

{

    if (!start) {

        throw 1;

    }



    item<T>* temp = start;

    start = start->link;

    delete temp;

}



template <class T>

T Stack<T>::top() const

{

    return start->inf;

}



template <class T>

bool Stack<T>::empty() const

{

    return start == NULL;

}



template <class T>

void Stack<T>::print(std::ostream& os) const{
    item<T> *top = start;
    os << "stack - ";
    while (top != nullptr) {
        os << top->inf << " ";
        top = top ->link;
    }
    os << endl;
}



// Private helpers

template <class T>

void Stack<T>::delStack()

{

    item<T>* p;

    while (start) {

        p = start;

        start = start->link;

        delete p;

    }

}



template <class T>

void Stack<T>::copy(Stack const& r)

{

    if (r.start) {

        item<T>* p = r.start;

        item<T>* q = NULL;



        start = new item<T>;

        assert(start != NULL);

        start->inf = p->inf;

        start->link = q;



        q = start;

        p = p->link;

        while (p) {

            q->link = new item<T>;

            assert(q->link != NULL);

            q->link->inf = p->inf;

            q->link->link = NULL;



            q = q->link;

            p = p->link;

        }

    } else {

        start = NULL;

    }

}

template<class T>
int Stack<T>::size() const {
    item<T>* top = start;
    int size = 0;
    while (top != nullptr) {
        ++size;
        top = top->link;
    }

    return size;
}


#endif //PROJECT_Stack_H
