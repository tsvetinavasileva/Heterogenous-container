#include <vector>
#include <algorithm>
#include "container_api.h"

template <typename T>
class SimpleStack : public Container<T>, public Stack<T>{
private:
    void backToStack(std::vector<T> v);
public:
    void push (T const& x);
    void pop();
    bool isFoundX (T const& x);
    bool isFoundUnderCondition(Condition<T> cond);
    void removeElemUnderCondition(Condition<T> cond);
    void sortElements ();
    int size() const;
    void print(std::ostream& os = std::cout) const;
    Iterator<T> itX(const T& x);
    item<T>* getStart() {
        return Stack<T>::getTop();
    };

};

template<typename T>
void SimpleStack<T>::push(const T &x) {
    Stack<T>::push(x);
}

template<typename T>
void SimpleStack<T>::pop() {
    Stack<T>::pop();
}

template<typename T>
void SimpleStack<T>::backToStack (std::vector<T> v) {
    for(int i = v.size() - 1; i >= 0; i--) {
        Stack<T>::push(v[i]);
    }
}

template<typename T>
bool SimpleStack<T>::isFoundX(const T &x) {
    // pop to vector and then push baackwords before returining (create function that pushes back to stack)
    Iterator<T> it(Stack<T>::getTop());
    for(it;it.valid();it++) {
        if (*it == x)
            return true;
    }
    return false;
}

template<typename T>
bool SimpleStack<T>::isFoundUnderCondition(Condition<T> cond) {
    Iterator<T> it(Stack<T>::getTop());
    for(it;it.valid();it++) {
        if (cond (*it))
            return true;
    }
    return false;
}

template<typename T>
void SimpleStack<T>::removeElemUnderCondition(Condition<T> cond) {
    std::vector<T> save;
    while (!Stack<T>::empty()) {
        if (!cond (Stack<T>::top())) {
            save.push_back(Stack<T>::top());
        }
        pop();
    }

    for (int i = save.size() - 1; i >= 0; i--) {
        push(save[i]);
    }

}

template<typename T>
void SimpleStack<T>::sortElements() {
    std::vector<T> save;
    while (!Stack<T>::empty()){
        save.push_back(Stack<T>::top());
        pop();
    }
    std::sort(save.begin(), save.end());
    for (int i = save.size() - 1 ; i >= 0  ; i--)
        push(save[i]);
}

template<typename T>
int SimpleStack<T>::size() const {
    return Stack<T>::size();
}

template<typename T>
void SimpleStack<T>::print(ostream &os) const {

    Stack<T>::print(os);
}

template<typename T>
Iterator<T> SimpleStack<T>::itX(const T &x) {
    Iterator<T> it(Stack<T>::getTop());
    for(it;it.valid();it++) {
        if (*it == x) {
            return it;

        }
    }
    return Iterator<T>();
}
