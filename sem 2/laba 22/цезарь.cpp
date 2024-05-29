#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>
using namespace std;

void caesarCipher(std::string& str, int shift) {
    for (char& c : str) {
        if (isalpha(c)) {
            char start = (islower(c)) ? 'a' : 'A';
            c = start + (c - start + shift) % 26;
        }
    }
}

void ruscaesarCipher(std::string& str, int shift) {
    for (char& c : str) {
        if (isalpha(c)) {
            char start = (islower(c)) ? 224 : 192;
            c = start + (c - start + shift) % 33;
        }
    }
}

int main() {
    //locale::global(locale(""));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "RUS");
    int shift;
    string text;

    cout << "Enter the text to encrypt: ";
    getline(std::cin, text);

    cout << "Enter the shift value: ";
    cin >> shift;
    char temp = text[0];
    if (iswalpha(temp)) {
        if (temp >= 192 && temp <= 255) {
            ruscaesarCipher(text, shift);
        }
        else {
            caesarCipher(text, shift);
        }
    }
    //caesarCipher(text, shift);
    cout << "Encrypted text: " << text << endl;
    caesarCipher(text, 26 - shift);
    cout << text << endl;
    char aha = '卐';
    cout << "\u534d";
    return 0;
}
