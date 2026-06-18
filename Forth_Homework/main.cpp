#include "MyString.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== Test + (concatenation) =====" << endl;
    MyString s1("abc");
    MyString s2("123");
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    s1 + s2;                // s1 = s1 + s2
    cout << "After s1 + s2, s1 = " << s1 << endl;
    cout << "s1 length: " << s1.getLength() << endl;
    cout << "s1 maxSize: " << s1.getMaxSize() << endl;
    cout << endl;

    cout << "Test + with no resize needed: s3 = \"ab\", s4 = \"cd\"" << endl;
    MyString s3("ab");
    MyString s4("cd");
    cout << "s3 maxSize before +: " << s3.getMaxSize() << endl;
    s3 + s4;
    cout << "s3 maxSize after +: " << s3.getMaxSize() << " (should still be 5)" << endl;
    cout << "s3 = " << s3 << endl;
    cout << endl;

    cout << "===== Test << (output) =====" << endl;
    MyString s5("Hello, operator<<");
    cout << "s5 via operator<<: " << s5 << endl;
    cout << endl;

    cout << "===== Test >> (keyboard input) =====" << endl;
    MyString s6;
    cout << "Please enter a string (no spaces): ";
    cin >> s6;
    cout << "You entered: " << s6 << endl;
    cout << "s6 length: " << s6.getLength() << endl;
    cout << "s6 maxSize: " << s6.getMaxSize() << endl;
    cout << endl;

    cout << "===== Test >> with resize =====" << endl;
    MyString s7("short");
    cout << "s7 before input: " << s7 << ", maxSize: " << s7.getMaxSize() << endl;
    cout << "Please enter a longer string (no spaces): ";
    cin >> s7;
    cout << "s7 after input: " << s7 << endl;
    cout << "s7 length: " << s7.getLength() << endl;
    cout << "s7 maxSize: " << s7.getMaxSize() << endl;
    cout << endl;

    cout << "===== All tests completed =====" << endl;
    cout << "Press Enter to exit..." << endl;
    cin.get();
    cin.get();
    return 0;
}