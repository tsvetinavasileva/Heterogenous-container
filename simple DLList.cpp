//
// Created by Tsvetina on 12.1.2018 г..
//

#include "container_api.h"
#include <vector>
#include <algorithm>

template <typename T>
class SimpleDLList : public DLList<T>, public Container<T>{
public:
    int size() const;
    void push (T const& x);
    void pop();
    bool isFoundX (T const& x);
    bool isFoundUnderCondition(Condition<T> cond);
    void removeElemUnderCondition(Condition<T> cond);
    void sortElements ();
    void print(std::ostream& os = std::cout) const;
    Iterator<T> itX(const T& x);
    item<T>* getStart() {
        DLList<T>::iterStart();
        item<T>* i = (item<T>*)(DLList<T>::iterSucc());
        return i;
    }

};

template<typename T>
Iterator<T> SimpleDLList<T>::itX(const T &x) {
    DLList<T>::iterStart();
    Iterator<T> it ((item<T>*) DLList<T>::iterSucc() );
    for (it; it.valid(); it++) {
        if (*it == x)
            return it;
    }
    return Iterator<T>();
}

template<typename T>
void SimpleDLList<T>::push(const T &x) {
   DLList<T>::toEnd(x);
}

template<typename T>
void SimpleDLList<T>::pop() {
    T x;
    DLList<T>::iterEnd();
    elem_link2<T>* end = DLList<T>::iterPred();
    DLList<T>::deleteElem(end,x);
}


template<typename T>
bool SimpleDLList<T>::isFoundX(const T &x) {
    DLList<T>::iterStart();
    Iterator<T> it ((item<T>*) DLList<T>::iterSucc() );
    for (it; it.valid(); it++)
        if (*it == x)
            return true;

    return false;

}

template<typename T>
bool SimpleDLList<T>::isFoundUnderCondition(Condition<T> cond) {
    DLList<T>::iterStart();
    Iterator<T> it ((item<T>*) DLList<T>::iterSucc() );
    for (it; it.valid(); it++)
        if (cond(*it))
            return true;

       return false;

}

template<typename T>
void SimpleDLList<T>::removeElemUnderCondition(Condition<T> cond) {
    int s = DLList<T>::length();
    std::vector<T> save;
    DLList<T>::iterStart();
    elem_link2<T>* it = DLList<T>::iterSucc() ;
    while (it != nullptr){
        if (!cond(it->inf))
            save.push_back(it->inf);
        T x;
        DLList<T>::deleteElem(it,x);
        it = DLList<T>::iterSucc() ;
    }
    for (T val : save)
        push(val);
}

template<typename T>
void SimpleDLList<T>::sortElements() {
    std::vector<T> save;
    DLList<T>::iterStart();
    elem_link2<T>* it = DLList<T>::iterSucc() ;
    while (it != nullptr){
        save.push_back(it->inf);
        T x;
        DLList<T>::deleteElem(it,x);
        it = DLList<T>::iterSucc() ;
    }
    std::sort(save.begin(), save.end());
    for (int i = 0 ; i <  save.size() ; i++)
     push(save[i]);
}

template<typename T>
void SimpleDLList<T>::print(ostream &os) const {
    DLList<T>::print(os);
}

template<typename T>
int SimpleDLList<T>::size() const {
   return DLList<T>::length();
}



