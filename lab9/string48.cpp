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
    cout << "PRESS TEXT:\n";
    getline(cin, str);
    cout << "INFO:\n";
    str += " ";
    for (int i = 0; i < str.size(); i++) {
        s += str[i];
        if (str[i] == ' ') {
            s = f(s);
            cout << s << " ";
            s = "";
        }
    }
    system("pause");
    return 0;
}
