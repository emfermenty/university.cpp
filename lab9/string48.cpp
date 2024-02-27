#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string f(string s) {
    for (int i = 1; i < s.size(); i++)
        if (s[i] == s[0]) s[i] = '.';
    return s;
}

int main() {
    string s, str;
    cout << "press text:\n";
    getline(cin, str);
    cout << "itog:\n";
    str += " ";
    for (int i = 0; i < str.size(); i++) {
        s += str[i];
        if (str[i] == ' ') {
            s = f(s);
            cout << s << " ";
            s = "";
        }
    }

    return 0;
}