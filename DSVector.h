#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H
#include <fstream>
#include <iostream>
#include "DSString.h"
#include "Flight.h"
#include "Request.h"
#include "DSList.h"

using namespace std;

template <typename T> class DSVector {
private:
    T* array;
    int size;
    int capacity;

public:
// Constructors and destructor
    DSVector(){
        capacity = 10;
        array = new T[10];
        size = 0;
    }
    DSVector(int capac) {
        if (capac <= 0 ) { // Set default size of container to 10 elements
            capac = 10;
        }
        capacity = capac;
        array = new T[capacity];
        size = 0;
    }
    DSVector (const DSVector &source) {
        array = new T[source.capacity];
        capacity = source.capacity;
        size = source.size;
        for (int i = 0; i < size; i++) {
            array[i] = source.array[i];
        }
    }
    ~DSVector() {
        delete []array;
    }

// Operators and functions
    DSVector& operator= (const DSVector& rhs)  {
        delete []array;
        array = new T[rhs.capacity];
        size = rhs.size;
        capacity = rhs.capacity;
        for (int i = 0; i < size; i++) {
            array[i] = rhs.array[i];
        }
        return *this;
    }

    void pushBack(const T data) { // Add data to back of vector
        if (size == capacity) { // Resize array if necessary
            T *temp = new T[capacity * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = array[i];
            }
            delete []array;
            capacity *= 2;
            array = temp;
        }
        array[size] = data;
        size++;
    }
    void pushAt(T data, int location) { // Overwrite data at location
        if(location == capacity) {
            pushBack(data);
        }
        else {
            array[location] = data;
        }
    }
    void popBack() { // Remove element at the back of the vector
        size--;
    }
    void popAt(const int location) { // Given a location, remove the data at that location, shift all elements to the left 1
        for(int i  = location; i < location + location; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    T& operator[] (int location) {
        if (location >= size || location < 0) {
            std::cout << "ERROR: Location out of bounds" << endl;
        }
        return array[location];
    }


    DSList<Flight>& operator[](Flight flight) {
        for (int i = 0; i < this->vectorSize(); i++) {
            if (array[i].head->data.getFlightPath() == flight.getFlightPath()) {
                return array[i];
            }
        }
        cout << "ERROR: key not found" << endl;
    }

    Request operator[](Request request) {               // Is there a better way to overload these operator[]'s? You can't just differ it by return type so idk.
        for (int i = 0; i < this->vectorSize(); i++) {  // This implementation and the one below it require making a temp object within loops to check equality, which I guess isn't a big deal
            if (array[i] == request) {
                return array[i];
            }
        }
        cout << "ERROR: key not found" << endl;
    }

    T& operator[](DSString key) {
        for (int i = 0; i < this->vectorSize(); i++) {
            if (array[i] == key) {
                return array[i];
            }
        }
        cout << "ERROR: key not found" << endl;
    }

    bool search (T data) { // Return true if the vector contains the given data
        for (int i = 0; i < size; i++ ) {
            if (array[i] == data) {
                return true;
            }
        }
        return false;
    }

    void swap (T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }

    void selectionSort() { // I found this selection sort function on stackoverflow.
        int minIndex;
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < size; j++)
                if (array[j] < array[minIndex])
                    minIndex = j;
            swap(array[i], array[minIndex]);
        }
    }

    void sortBy(char sortCriteria) { // Different version of above selection sort to sort paths by given criteria
        int minIndex;
        if (sortCriteria == 'C') {
            for (int i = 0; i < size - 1; i++) {
                minIndex = i;
                for (int j = i + 1; j < size; j++)
                    if (array[j].getTotalCost() < array[minIndex].getTotalCost())
                        minIndex = j;
                swap(array[i], array[minIndex]);
            }
        }
        else if (sortCriteria == 'T') {
            for (int i = 0; i < size - 1; i++) {
                minIndex = i;
                for (int j = i + 1; j < size; j++)
                    if (array[j].getTotalTime() < array[minIndex].getTotalTime())
                        minIndex = j;
                swap(array[i], array[minIndex]);
            }
        }
    }

    int vectorSize() const {
        return size;
    }
    int vectorCapacity() const {
        return capacity;
    }

    void print(ofstream &output) {
        if (this->size == 0) {
            output << "Vector is empty" << endl;
        }
        else if (this->size == 1) {
            output << array[0] << endl;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (i == size - 1) {
                    output << array[i];
                }
                else {
                    output << array[i] << ", ";
                }
            }
            output << endl;
        }
    }

    void printRequests() {
        for (int i = 0; i < size; i++) {
            array[i].printRequest();
        }
    }

    void getRequests(ifstream &input) {
        char* buffer = new char[80];
        while(input.getline(buffer, 80)) {
            int numLines = 0;
            int pipeCtr = 0;
            int start = 0;
            DSString line(buffer);
            Request newRequest;
            if (!isalpha(line[0])) {
                numLines = stoi(line.c_str());
            }
            else {
                for (int i = 0; i < line.getLength(); i++) {
                    // Populate requests vector
                    if (line[i] == '|') {
                        pipeCtr++;
                        if (pipeCtr == 1) {
                            newRequest.setSource(line.substring(start, i - start));
                        }
                        else if (pipeCtr == 2) {
                            newRequest.setDestination(line.substring(start, i - start));
                        }
                        start = i + 1;
                    }
                    else if (i == line.getLength() - 1) {
                        newRequest.setSortCriteria(line[i - 1]);
                    }
                }
                this->pushBack(newRequest);
            }
        }
    }

    void printPaths(ofstream& output) {
        for (int i = 0; i < size; i++) {
            if (i == 3) break; // If the paths vector has more than 3 possible flight paths, only print the top 3.
            output << "Path " << i + 1 << ": ";
            array[i].printPath(output);
        }
    }

    void reverse(int start, int end) {
        while (start < end) {
            T temp = this->array[start];
            this->array[start] = this->array[end];
            this->array[end] = temp;
            start++;
            end--;
        }
    }


};

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
