#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    for (char& c : s) {
        if (c >= 'a' && c <= 'z'){
            c= c - 'a'+ 'A';
        }
    }
    cout << s;
}
