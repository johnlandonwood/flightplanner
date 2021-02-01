#ifndef INC_20F_FLT_PLN_DSSTACK_H
#define INC_20F_FLT_PLN_DSSTACK_H
#include <iostream>
#include "DSList.h"

template <typename T> class DSStack {

private:
    DSList<T> stackList;
public:
    DSStack(){};

    void push(T data) {
        stackList.insert(data, 0);
    }

    void pop() {
        if (stackList.listSize == 0) {
            cout << "ERROR: Stack empty, cannot pop" << endl;
        }
        stackList.remove(0);
    }

    T peek() {
        if (stackList.listSize == 0) {
            cout << "ERROR: Stack empty, cannot peek" << endl;
        }
        return stackList[0];
    }

    int getSize() {
        return stackList.listSize;
    }

    bool isEmpty() const {
        return stackList.isEmpty();
    }

    void printStack() const {
        Node<T> *curr = stackList.head;
        while(curr != nullptr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }

    T& operator[] (const int location) {
        return stackList[location];
    }

    DSList<T>& getStackList() {
        return this->stackList;
    }

};

#endif //INC_20F_FLT_PLN_DSSTACK_H
