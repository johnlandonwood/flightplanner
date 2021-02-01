#ifndef STRING
#define STRING
#include <iostream>
#include <cstring>

class DSString {
private:
    char *data;
    int size;
public:
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();
    DSString& operator= (const char* source);
    DSString& operator= (const DSString& source);
    DSString operator+ (const char* source) const;
    DSString operator+ (const DSString& rhs) const;
    bool operator== (const char* rhs) const;
    bool operator== (const DSString& rhs) const;
    bool operator> (const DSString& rhs) const;
    bool operator< (const DSString& rhs) const;
    bool operator!= (const DSString& rhs) const;
    char& operator[] (const int i);
    int getLength();
    DSString substring(int start, int numChars);
    char* c_str();
    DSString removeAllPunct(DSString& source);
    DSString toLower(DSString& source);
    DSString removeNewLines(DSString& source);
    friend std::ostream& operator<< (std::ostream& , const DSString&);
};

#endif