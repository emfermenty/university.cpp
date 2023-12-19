//пока неверно, пытаюсь исправить

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int translate(int x) {
    int num = 0;
    int base = 1;
    int temp = x;
    while (temp) {
        int lastdigit = temp % 10;
        temp = temp / 10;
        num += lastdigit * base;
        base = base * 2;
    }
    return num;
}

int main() {
    ifstream infile("FN1.txt");
    ofstream outfile("FN2.txt");

    if (infile.is_open() && outfile.is_open()) {
        string problem;
        while (getline(infile, problem)) {
            int operand1, operand2, result;
            char operation, eq;
         
            infile >> operand1 >> operation >> operand2 >> eq >> result;

            if (operation == '+') {
                if (translate(operand1) + translate(operand2) == translate(result)) {
                    outfile << problem << " - Верно\n";
                }
                else {
                    outfile << problem << " - Неверно\n";
                }
            }
            else if (operation == '*') {
                if (translate(operand1) * translate(operand2) == translate(result)) {
                    outfile << problem << " - Верно\n";
                }
                else {
                    outfile << problem << " - Неверно\n";
                }
            }
            else {
                continue;
            }
            problem = "";
        }
        infile.close();
        outfile.close();
    }
    else {
        cout << "Unable to open file";
    }
}
