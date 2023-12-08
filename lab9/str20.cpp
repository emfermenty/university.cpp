#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int i = 0;
    string s;
    cout << "string: \n";
    getline(cin, s);
    while (s[i]) {
        s[i] = toupper(s[i]);
        i++;
    }
    cout << s << endl;
}