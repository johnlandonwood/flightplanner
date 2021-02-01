#include <iostream>
#include <cstring>
#include "DSString.h"
using namespace std;

// Default constructors, copy constructor, destructor
DSString::DSString() {
    this->data = nullptr;
    this->size = 0;
}
DSString::DSString(const char* param) {
    if (param == nullptr) {
        // Say no!!
    }
    data = new char[strlen(param) + 1];
    this->size = strlen(param);
    strcpy(data, param);
}
DSString::DSString(const DSString& source) {
    data = new char[strlen(source.data) + 1];
    strcpy(this->data, source.data);
    this->size = strlen(source.data) + 1;
}
DSString::~DSString() {
    if (data != nullptr) {
        delete []data;
    }
}

// Relational operators
DSString& DSString::operator= (const char* source)  {
    if (data != nullptr) {
        delete[] data;
    }
    data = new char[strlen(source + 1)];
    size = strlen(source) + 1;
    strcpy(this->data, source);
    return *this;
}
DSString& DSString::operator= (const DSString& source) {
    if (data != nullptr) {
        delete [] data;
    }
    data = new char[source.size + 1];
    strcpy(this->data, source.data);
    return *this;
}
DSString DSString::operator+ (const char* source) const {
    int len = this->size + strlen(source);
    char *newData = new char[len + 1];
    strcpy(newData, this->data);
    strcat(newData, source);
    return (DSString(newData));
}
DSString DSString::operator+ (const DSString& rhs) const {
    int len = this->size + rhs.size;
    char *newData = new char[len + 1];
    strcpy(newData, this->data);
    strcat(newData, rhs.data);
    return (DSString(newData));
}
bool DSString::operator== (const char* rhs) const {
    if (strcmp(this->data, rhs) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool DSString::operator== (const DSString& rhs) const {
    if(strcmp(this->data, rhs.data) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool DSString::operator> (const DSString& rhs) const {
    if(strcmp(this->data, rhs.data) > 0) {
        return true;
    }
    else {
        return false;
    }
}
bool DSString::operator< (const DSString& rhs) const {
    if (strcmp(this->data, rhs.data) < 0) {
        return true;
    }
    else {
        return false;
    }
}
bool DSString::operator!= (const DSString& rhs) const {
    if (strcmp(this->data, rhs.data) != 0) {
        return true;
    }
    else {
        return false;
    }
}
char& DSString::operator[] (const int i) {
    if (i > strlen(this->data)) {
        // throw exception
    }
    return data[i];
}

// Other functions
int DSString::getLength() {
    return strlen(data);
}
DSString DSString::substring(int start, int numChars) {
    DSString substr;
    char* tempSubstring = new char[numChars + 1];
    substr.size = numChars + 1;
    for(int i = 0; i < numChars; i++) {
        tempSubstring[i] = this->data[start + i];
    }
    tempSubstring[numChars] = '\0';
    substr.data = tempSubstring;
    return substr;
}
char* DSString::c_str() {
    char* cstring  = new char[this->getLength() + 1];
    strcpy(cstring, this->data);
    return cstring;
}
DSString DSString::removeAllPunct(DSString& source) { // Kind of a wonky implementation where I have to use source essentially as this, but I can't use this parameter with operator[]
    for (int i = 0; i < source.getLength(); i++) {
        if (ispunct(source[i])) {
            source[i] = ' ';
        }
    }
    return source;
}
DSString DSString::removeNewLines(DSString& source) {
    for (int i = 0; i < source.getLength(); i++) {
        if (source[i] == '\n') {
            source[i] = ' ';
        }
    }
    return source;
}
DSString DSString::toLower(DSString &source) { // Same wonky implementation in removeAllPunct
    for (int i = 0; i < source.getLength(); i++) {
        if (isalpha(source.data[i])) {
            source.data[i] = tolower(source.data[i]);
        }
    }
    return source;
}
std::ostream& operator<< (std::ostream& os, const DSString& obj) {
    os << obj.data;
    return os;
}