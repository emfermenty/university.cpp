#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    string numoftwelve; 
    cout << "Enter the string: ";
    cin >> numoftwelve;

    for (int i = 0; i < numoftwelve[i]; i++) {
        numoftwelve[i] = toupper(numoftwelve[i]);
    }

    int temp = 0;
    for (char c : numoftwelve) {
        if (isdigit(c)) {
            temp = temp * 12 + (c - '0');
        } else {
            temp = temp * 12 + (c - 'A' + 10);
        }
    }
    cout << "chislo v 10-oi " << temp << endl;
    string numoffour;
    while (temp > 0) {
        int rem = temp % 4;
        char digit;
        if (rem < 10) {
            digit = rem + '0';
        } else {
            digit = rem - 10 + 'A';
        }
        numoffour = digit + numoffour;
        temp /= 4;  
    }
    cout << "chislo v chetverichnoy: " << numoffour;
    return 0;
}