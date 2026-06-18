#include "MyString.h"
#include <cstring>

// Constructor 1: no parameter, allocates size-1 space for empty string
MyString::MyString() {
    maxSize = 1;
    data = new char[maxSize];
    data[0] = '\0';
}

// Constructor 2: takes const char*, allocates exactly enough space and copies
MyString::MyString(const char* str) {
    int len = std::strlen(str);
    maxSize = len + 1;
    data = new char[maxSize];
    std::strcpy(data, str);
}

// Destructor: frees dynamically allocated space
MyString::~MyString() {
    delete[] data;
}

// Return current string length (excluding '\0')
int MyString::getLength() const {
    return std::strlen(data);
}

// Return current char array size
int MyString::getMaxSize() const {
    return maxSize;
}

// Check if string is empty
bool MyString::isEmpty() const {
    return (data[0] == '\0');
}

// Get and return pointer to current string
char* MyString::getString() const {
    return data;
}

// Modify current string to str (reallocate if space insufficient)
void MyString::setString(const char* str) {
    int newLen = std::strlen(str);
    int newMaxSize = newLen + 1;

    if (newMaxSize <= maxSize) {
        std::strcpy(data, str);
    } else {
        delete[] data;
        maxSize = newMaxSize;
        data = new char[maxSize];
        std::strcpy(data, str);
    }
}

// Output current string content
void MyString::printString() const {
    std::cout << data << std::endl;
}

// Operator + : concatenate str to the end of current string
void MyString::operator+(MyString& str) {
    int curLen = std::strlen(data);          // length of current string
    int strLen = std::strlen(str.data);       // length of str
    int newLen = curLen + strLen;
    int newMaxSize = newLen + 1;

    if (newMaxSize <= maxSize) {
        // existing space is sufficient, directly append
        std::strcat(data, str.data);
    } else {
        // need to reallocate
        char* temp = new char[newMaxSize];
        std::strcpy(temp, data);
        std::strcat(temp, str.data);
        delete[] data;
        data = temp;
        maxSize = newMaxSize;
    }
}

// Operator << : output string str to ostream
std::ostream& operator<<(std::ostream& out, const MyString& str) {
    out << str.data;
    return out;
}

// Operator >> : read keyboard input into str
std::istream& operator>>(std::istream& in, MyString& str) {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    in >> buffer;
    str.setString(buffer);
    return in;
}