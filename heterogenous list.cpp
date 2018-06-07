//
// Created by Tsvetina on 12.1.2018 г..
//
#include <iostream>
#include "container_api.h"
#include <list>
#include <fstream>
#include <sstream>
#include "simple stack.cpp"
#include "simple queue.cpp"
#include "simple DLList.cpp"

template <typename T>
class HeterogenousList {
private:
    std::list<Container<T>*> containers;
public:
    void add(Container<T>* container);
    bool extractFromFileIntoContainer(std::string file);
    void addElem(T const& x);
    bool isFoundX (T const& x) const;
    bool isFoundUnderCondition(Condition<T> cond);
    void removeElemUnderCondition(Condition<T> cond);
    Iterator<T> getIterator(T const& x);
    void sortElements();
    void print() const;
    void printToFile(std::string file = "output.txt");
    void iterateAllElems();

};

template<typename T>
void HeterogenousList<T>::addElem(const T &x) {
    Container<T>* min = containers.front();
    for (Container<T>* container : containers) {
        if (container->size() < min->size()) {
            min = container;
        }
    }
    min->push(x);

}

template<typename T>
bool HeterogenousList<T>::isFoundX(const T &x) const {
    for (Container<T>* container : containers) {
        if (container->isFoundX(x)) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool HeterogenousList<T>::isFoundUnderCondition(Condition<T> cond) {
    for (Container<T>* cont : containers)
        if (cont->isFoundUnderCondition(cond))
            return true;
    return false;
}

template<typename T>
void HeterogenousList<T>::removeElemUnderCondition(Condition<T> cond) {
    for (Container<T>* cont : containers)
        cont->removeElemUnderCondition(cond);
}

template<typename T>
void HeterogenousList<T>::sortElements() {
    for (Container<T>* cont : containers)
        cont->sortElements();

}

template<typename T>
void HeterogenousList<T>::print() const {
    for (Container<T>* cont : containers)
        cont->print();
}

template<typename T>
void HeterogenousList<T>::printToFile(string file) {
    std::ofstream outputFile(file);
    for (Container<T>* cont : containers)
        cont->print(outputFile);
}

template<typename T>
Iterator<T> HeterogenousList<T>::getIterator(const T &x) {
   for(Container<T>* container : containers) {
       Iterator<T> iterator = container->itX(x);
       if (iterator.valid())
           return iterator ;
   }
       return Iterator<T>();
}

template<typename T>
bool HeterogenousList<T>::extractFromFileIntoContainer(std::string file) {
    std::ifstream input(file);
    std::string line;
    while (std::getline(input,line)){
        Container<T> *container = nullptr;
        std::istringstream br(line);
        std::string word;
        br >> word;
        if(word == "stack")
            container = new SimpleStack<T>();
        if(word == "queue")
            container = new SimpleQueue<T>();
        if(word == "dllist")
            container = new SimpleDLList<T>();
        if (container == nullptr)
            return false;
        br.ignore(3);
        int number;
        while (br >> number){
            container->push(number);
        }
        add(container);
    }

    return true;
}

template<typename T>
void HeterogenousList<T>::add(Container<T> *container) {
     containers.push_back(container);
}

template<typename T>
void HeterogenousList<T>::iterateAllElems() {
      for(Container<T>* container : containers)
      {
          Iterator<T> iterator (container->getStart());
          for(iterator; iterator.valid(); iterator++)
              std::cout << *iterator << ' ';
          cout<<endl;
      }
}
