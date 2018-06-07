//
// Created by Tsvetina on 12.1.2018 г..
//

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H


#include<iostream>
#include<cstdlib>
#include<cassert>
#include "item.h"
using namespace std;



template<typename T>

class Queue

{ private:

    item<T>* Front;

    item<T>* End;



    void Copy(const Queue<T>&);

    void Erase();


public:

    item<T>* getTop() const {
        return Front;
    }



    Queue();

    Queue(const Queue<T>&);

    ~Queue();

    Queue& operator=(const Queue<T>&);



    void push(const T&);

    void pop();

    T top() const;

    bool isEmpty() const;

    int length() const;

    void print(std::ostream& os = std::cout) const;
};



template<typename T>

void Queue<T>::Copy(const Queue<T> &other)

{ item<T>* otherFront = other.Front;



    while (otherFront)

    { push(otherFront->inf);

        otherFront = otherFront->link;

    }

}



template<typename T>

void Queue<T>::Erase()

{ while (!isEmpty())

        pop();

}



template<typename T>

Queue<T>::Queue()

{ Front = NULL;

    End = NULL;

}



template<typename T>

Queue<T>::Queue(const Queue<T> &other)

{ Front = NULL;

    End = NULL;

    Copy(other);

}



template<typename T>

Queue<T>::~Queue()

{ Erase();

}



template<typename T>

Queue<T>& Queue<T>::operator=(const Queue<T> &other)

{ if (this != &other)

    { Erase();

        Copy(other);

    }



    return *this;

}



template<typename T>

void Queue<T>::push(const T &element)

{ item<T>* save = End;

    End = new item<T>();

    End->inf = element;

    End->link = NULL;



    if (Front == NULL)

        Front = End;



    else save->link = End;

}



template<typename T>

void Queue<T>::pop()

{ if (Front == NULL)

    { cerr << "Error ! The queue is empty !" << endl;

        exit(1);

    }



    item<T>* save = Front;

    Front = Front->link;

    delete save;

}



template<typename T>

T Queue<T>::top() const

{ if (isEmpty())

    { cerr << "Error ! The queue is empty and there is no top element !" << endl;

        exit(1);

    }
    return Front->inf;

}



template<typename T>

bool Queue<T>::isEmpty() const

{ return Front == NULL;

}



template<typename T>

int Queue<T>::length() const
{
    item<T>* top = Front;
    int size = 0;
    while (top != nullptr) {
        ++size;
        top = top->link;
    }
    return size;
}

template<typename T>
void Queue<T>::print(ostream &os) const {
    item<T> *top = Front;
    os << "queue - ";
    while (top != nullptr) {
        os << top->inf << " ";
        top = top ->link;
    }
    os << endl;
}




#endif //PROJECT_QUEUE_H
