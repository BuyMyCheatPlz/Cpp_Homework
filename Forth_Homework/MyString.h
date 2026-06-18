#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* data;     // point to dynamically allocated char array
    int maxSize;    // size of the char array

public:
    // Constructor 1: no parameter, allocates size-1 space for empty string
    MyString();

    // Constructor 2: takes const char*, allocates exactly enough space and copies
    MyString(const char* str);

    // Destructor: frees the dynamically allocated space
    ~MyString();

    // Return current string length (excluding '\0')
    int getLength() const;

    // Return current char array size
    int getMaxSize() const;

    // Check if string is empty
    bool isEmpty() const;

    // Get and return pointer to current string
    char* getString() const;

    // Modify current string to str (reallocate if space insufficient)
    void setString(const char* str);

    // Output current string content
    void printString() const;

    // Operator + : concatenate str to the end of current string
    void operator+(MyString& str);

    // Operator << : output string str to ostream
    friend std::ostream& operator<<(std::ostream& out, const MyString& str);

    // Operator >> : read keyboard input into str
    friend std::istream& operator>>(std::istream& in, MyString& str);
};

#endif