#ifndef INC_20F_AUTO_IDX_DSLIST_H
#define INC_20F_AUTO_IDX_DSLIST_H
#include <iostream>
#include <fstream>
#include "DSString.h"
#include "Flight.h"
using namespace std;

template <typename T> class Node {
public:
    T data;
    Node *prev;
    Node *next;

    // Constructors and destructor
    Node() {
        prev = nullptr;
        next = nullptr;
    }
    Node(T data) {
        this->data = data;
    }
    ~Node() {}

    friend std::ostream& operator<< (std::ostream& os, const Node<T> &node) {
        os << node.data;
        return os;
    }
};

template <typename T> class DSList {
public:
    Node<T> *head;
    Node<T> *tail;
    int listSize;
    Node<T> *iter; // Node<T> to be used for iterator mechanism

    // Constructors and destructor
    DSList() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
        iter = nullptr;
    }
    DSList(const DSList &source) {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
        Node<T> *curr = source.head;
        for (int i = 0; i < source.listSize; i++) {
            insert(curr->data, i);
            curr = curr->next;
        }
        iter = head;
    }

    ~DSList() {
        destroy();
    }

    void destroy() {
        Node<T> *curr;
        while (head != nullptr && head != tail) {
            curr = head;
            head = head->next;
            delete curr;
        }
        head = tail = nullptr;
    }

    // Operators
    DSList &operator=(const DSList &rhs) {
        clearList();
        Node<T> *curr = rhs.head;
        for (int i = 0; i < rhs.listSize; i++) {
            insert(curr->data, i);
            curr = curr->next;
        }
        iter = head;
        return *this;
    }
    T& operator[] (const int location) { // Return data at given location
        if (location >= listSize || location < 0) {
            cout << "ERROR: Trying to access out of bounds location" << endl;
        }
        Node<T> *curr;
        int i = 0;
        for (curr = head; curr != nullptr; curr = curr->next) {
            if (i == location)  {
                return curr->data;
            }
            i++;
        }
    }

    void insert(T data, int location) { // Insert a node at the given location/index in list
        if (location > listSize || location < 0 ) {
            cout << "ERROR: Trying to insert node at out of bounds location" << endl;
        }
        if (head == nullptr) { // If list is empty, insert at location 0
            Node<T> *newNode = new Node<T>;
            newNode->data = data;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
            listSize++;
        }
        else if (location == 0) { // Insert node at head
            Node<T> *newNode = new Node<T>;
            head->prev = newNode;
            newNode->next = head;
            newNode->data = data;
            newNode->prev = nullptr;
            head = newNode;
            listSize++;
        }
        else if (location == listSize) { // Insert node at tail
            Node<T> *newNode = new Node<T>;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->data = data;
            newNode->next = nullptr;
            listSize++;
        }
        else { //Insert at location in list
            Node<T> *newNode = new Node<T>;
            Node<T> *temp = head;
            for (int i = 0; i < location; i++) {
                temp = temp->next;
            }
            temp->prev->next = newNode;
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev = newNode;
            newNode->data = data;
            listSize++;
        }
    }
    void remove(int location) { // Remove node at given location from the list
        if (location >= listSize || location < 0 ) {
            cout << "ERROR: Trying to remove node at out of bounds location" << endl;
        }
        if (location == 0 && listSize > 1) { // Delete head node
            head->next->prev = nullptr;
            head = head->next;
            listSize--;
        }
        else if (location == listSize - 1 && listSize > 1) { // Delete tail node
            tail->prev->next = nullptr;
            tail = tail->prev;
            listSize--;
        }
        else if (listSize > 1) { // Delete node at location
            Node<T> *curr = head;
            for (int i = 0; i < location; i++) {
                curr = curr->next;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            listSize--;
        }
        else { // List has only one node - delete it
            head = nullptr;
            tail = nullptr;
            listSize--;
        }
    }

    bool search(T key) { // If an element exists in the list that has a Node->data with the given key, return true.
        Node<T>* temp;
        bool found = false;
        temp = head;
        while ((!found) && (temp != nullptr)) {
            if (temp->data == key) {
                found = true;
            }
            else {
                temp = temp->next;
            }
        }
        return found;
    }

    bool search2(T key) {
        Node<T> *temp;
        bool found = false;
        temp = head;
        while ((!found) && (temp != nullptr)) {
            if (temp->data.getFlightPath() == key.getFlightPath()) {
                found = true;
            }
            else {
                temp = temp->next;
            }
        }
        return found;
    }

    void clearList() { // remove all nodes in the list
        Node<T> *curr = head;
        for (int i = 0; i < listSize; i++) {
            remove(0);
        }
    }
    bool isEmpty() const {
        if (listSize == 0)
            return true;
        else return false;
    }

    void bubbleSort() {
        int swapped;
        Node<T> *curr1;
        Node<T> *curr2 = nullptr;
        if (listSize == 0 || listSize == 1) { // List is empty or list is only one element
            return;
        }
        do {
            swapped = 0;
            curr1 = head;
            while (curr1->next != curr2) {
                if (curr1->data > curr1->next->data) {
                    swap(curr1->data, curr1->next->data);
                    swapped = 1;
                }
                curr1 = curr1->next;
            }
            curr2 = curr1;
        }
        while (swapped);
    }

    void printList() {
        Node<T> *curr = head;
        while(curr != nullptr) {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }

    void printFlightList() { // Specific print function for list of Flight objects
        Node<Flight> *curr = head;
        if (curr->data.getFlightPath() != "" && curr->data.getTime() == 0 && curr->data.getCost() == 0 && curr->data.getAirline() == "") {
            cout << "Head City: " << curr->data.getFlightPath() << endl;
            cout << "------------------------------" << endl;
            curr = curr->next;
        }
        while (curr != nullptr) {
            curr->data.printFlight();
            curr = curr->next;
        }
        cout << "------------------------------" << endl;
    }

    void resetIter() {
        iter = this->head->next;
    }
    void moveIter() {
        if (iter == nullptr) {
            cout << "ERROR: tried to move iter past null" << endl;
        }
        iter = iter->next;
    }
    T getIterData() {
        return iter->data;
    }

};

#endif //INC_20F_AUTO_IDX_DSLIST_H