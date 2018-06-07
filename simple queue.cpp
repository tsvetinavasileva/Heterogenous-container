
#include <vector>
#include <algorithm>
#include "container_api.h"



template <typename T>
class SimpleQueue : public Queue<T>, public Container<T> {

public:
    void push(T const &x);
    void pop();
    bool isFoundX(T const &x);
    bool isFoundUnderCondition(Condition<T> cond);
    void removeElemUnderCondition(Condition<T> cond);
    int size() const;
    void sortElements();
    void print(std::ostream &os = std::cout) const;
    Iterator<T> itX(const T& x);
    item<T>* getStart() {
        return Queue<T>::getTop();
    }

};



template<typename T>
void SimpleQueue<T>::push(const T &x) {
    Queue<T>::push(x);
}

template<typename T>
void SimpleQueue<T>::pop() {
    Queue<T>::pop();
}

template<typename T>
bool SimpleQueue<T>::isFoundX(const T &x) {
    Iterator<T> it(Queue<T>::getTop());
    for(it;it.valid();it++) {
        if (*it == x)
            return true;
    }
    return false;
}

template<typename T>
bool SimpleQueue<T>::isFoundUnderCondition(Condition<T> cond) {
    Iterator<T> it(Queue<T>::getTop());
    for(it;it.valid();it++) {
        if (cond (*it))
            return true;
    }
    return false;
}

template<typename T>
void SimpleQueue<T>::removeElemUnderCondition(Condition<T> cond) {
    int s = size();
    std::vector<T> save;
    while (!Queue<T>::isEmpty()) {
        T fr = Queue<T>::top();
        if (!cond(fr)) {
            save.push_back(fr);
        }
        Queue<T>::pop();
    }
    for(T val : save) {
        push(val);
    }

}

    template<typename T>
    void SimpleQueue<T>::sortElements() {
        std::vector<T> save;
        while (!Queue<T>::isEmpty()) {
            T fr = Queue<T>::top();
            save.push_back(fr);
            Queue<T>::pop();
        }
        std::sort(save.begin(), save.end());
        for(T val : save) {
            push(val);
        }
}


    template<typename T>
    void SimpleQueue<T>::print(ostream &os) const {
        Queue<T>::print(os);
    }

template<typename T>
int SimpleQueue<T>::size() const {
    return Queue<T>::length();
}

template<typename T>
Iterator<T> SimpleQueue<T>::itX(const T &x) {
    Iterator<T> it(Queue<T>::getTop());
    for(it;it.valid();it++) {
        if (*it == x)
            return it;
    }
    return Iterator<T>();
}

