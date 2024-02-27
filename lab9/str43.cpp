#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    const int size = 256;
    int charCount[size] = { 0 };

    for (char c : s) {
        charCount[c]++;
    }

    char maxChar = s[0];
    int maxCount = charCount[s[0]];

    for (char c : s) {
        if (charCount[c] > maxCount) {
            maxChar = c;
            maxCount = charCount[c];
        }
    }

    cout << "Больше всего встретилось: " << maxChar << endl;
    cout << "Количество вхождений: " << maxCount << endl;

    return 0;
}