#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cout << "===== Test Constructor 1 (no args): empty string s1 =====" << endl;
    MyString s1;
    cout << "s1 content: ";
    s1.printString();
    cout << "s1 length: " << s1.getLength() << endl;
    cout << "s1 maxSize: " << s1.getMaxSize() << endl;
    cout << "s1 isEmpty: " << (s1.isEmpty() ? "true" : "false") << endl;
    cout << "s1 getString: " << s1.getString() << endl;
    cout << endl;

    cout << "===== Test Constructor 2 (char*): s2 = \"Hello\" =====" << endl;
    MyString s2("Hello");
    cout << "s2 content: ";
    s2.printString();
    cout << "s2 length: " << s2.getLength() << endl;
    cout << "s2 maxSize: " << s2.getMaxSize() << endl;
    cout << "s2 isEmpty: " << (s2.isEmpty() ? "true" : "false") << endl;
    cout << endl;

    cout << "===== Test Constructor 2 (char*): s3 = \"\" =====" << endl;
    MyString s3("");
    cout << "s3 content: ";
    s3.printString();
    cout << "s3 length: " << s3.getLength() << endl;
    cout << "s3 maxSize: " << s3.getMaxSize() << endl;
    cout << "s3 isEmpty: " << (s3.isEmpty() ? "true" : "false") << endl;
    cout << endl;

    cout << "===== Test setString: s1 empty -> \"World\" (need resize) =====" << endl;
    cout << "before setString, s1 maxSize: " << s1.getMaxSize() << endl;
    s1.setString("World");
    cout << "after setString, s1 content: ";
    s1.printString();
    cout << "s1 length: " << s1.getLength() << endl;
    cout << "s1 maxSize: " << s1.getMaxSize() << endl;
    cout << "s1 isEmpty: " << (s1.isEmpty() ? "true" : "false") << endl;
    cout << endl;

    cout << "===== Test setString: \"World\" -> \"Hi\" (no resize needed) =====" << endl;
    cout << "s1 current maxSize: " << s1.getMaxSize() << ", current content: ";
    s1.printString();
    s1.setString("Hi");
    cout << "after setString(\"Hi\"), s1 content: ";
    s1.printString();
    cout << "s1 length: " << s1.getLength() << endl;
    cout << "s1 maxSize: " << s1.getMaxSize() << " (should still be 6)" << endl;
    cout << endl;

    cout << "===== Test setString: \"Hi\" -> \"C++ Programming\" (need resize) =====" << endl;
    cout << "s1 current maxSize: " << s1.getMaxSize() << endl;
    s1.setString("C++ Programming");
    cout << "after setString, s1 content: ";
    s1.printString();
    cout << "s1 length: " << s1.getLength() << endl;
    cout << "s1 maxSize: " << s1.getMaxSize() << endl;
    cout << endl;

    cout << "===== Test getString: modify via returned pointer =====" << endl;
    char* p = s2.getString();
    cout << "s2 content via getString: " << p << endl;
    p[0] = 'M';
    cout << "after p[0]='M', s2 content: ";
    s2.printString();
    cout << endl;

    cout << "===== All tests completed =====" << endl;
    cout << "Press Enter to exit..." << endl;
    cin.get();
    return 0;
}