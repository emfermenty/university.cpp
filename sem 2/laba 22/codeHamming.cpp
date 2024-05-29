#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

vector<int> decomposeIntoMaxPowersOfTwo(int number) {
    vector<int> powersOfTwo;
    int power = 0;

    while (number > 0) {
        if (number % 2 == 1) {
            powersOfTwo.push_back(1 << power);
        }
        number /= 2;
        power++;
    }

    return powersOfTwo;
}

int main() {
    setlocale(LC_ALL, "RU");
    string alpha = "0010100001010";
    int m = alpha.length();
    int k;
    for (int i = 0;; i++) {
        if (m + 1 + i <= pow(2, i)) {
            k = i;
            break;
        }
    }
    int c = m + k;
    vector<int> razryad;
    for (int i = 0; i < k; i++) {
        razryad.push_back((pow(2, i)) - 1);
    }

    string betta = "";
    vector<int>::iterator iter = razryad.begin();
    auto it = alpha.begin();
    razryad.push_back(0);
    for (int i = 0; i < m + k; i++) {
        if (i == *iter) {
            betta += ',';
            iter++;
        }
        else {
            betta += *it;
            it++;
        }
    }
    betta += ' ';
    cout << "wait what: " << betta << endl;
    int qwe = 0;
        for(int i = 0; i < betta.length(); i++){
        string temp;
        char haha;
        int count = 0;
        if (betta[i] == ',') {
                switch (qwe)
                {
                case 0:
                    for (int j = i; j < betta.length(); j++) {
                        vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                        for (int c = 0; c < controls.size(); c++) {
                            if (controls[c] == 1) {
                                temp += betta[j - 1];
                            }
                        }
                    }
                    cout << "V-" << qwe << " " << temp;
                    cout << "\n";
                    temp = temp.substr(1);
                    for (int c = 0; c < temp.length(); c++) {
                        count += temp[c] - '0';
                    }
                    if (count % 2 == 0) {
                        betta[i] = '0';
                    }
                    else {
                        betta[i] = '1';
                    }
                    break;
                case 1:
                    for (int j = i; j < betta.length(); j++) {
                        vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                        for (int c = 0; c < controls.size(); c++) {
                            if (controls[c] == 2) {
                                temp += betta[j - 1];
                            }
                        }
                    }
                    cout << "V-" << qwe << " " << temp;
                    cout << "\n";
                    temp = temp.substr(1);
                    for (int c = 0; c < temp.length(); c++) {
                        count += temp[c] - '0';
                    }
                    if (count % 2 == 0) {
                        betta[i] = '0';
                    }
                    else {
                        betta[i] = '1';
                    }
                    break;
                case 2:
                    for (int j = i; j < betta.length(); j++) {
                        vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                        for (int c = 0; c < controls.size(); c++) {
                            if (controls[c] == 4) {
                                temp += betta[j - 1];
                            }
                        }
                    }
                    cout << "V-" << qwe << " " << temp;
                    cout << "\n";
                    temp = temp.substr(1);
                    for (int c = 0; c < temp.length(); c++) {
                        count += temp[c] - '0';
                    }
                    if (count % 2 == 0) {
                        betta[i] = '0';
                    }
                    else {
                        betta[i] = '1';
                    }
                    break;
                case 3:
                    for (int j = i; j < betta.length(); j++) {
                        vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                        for (int c = 0; c < controls.size(); c++) {
                            if (controls[c] == 8) {
                                temp += betta[j - 1];
                            }
                        }
                    }
                    cout << "V-" << qwe << " " << temp;
                    cout << "\n";
                    temp = temp.substr(1);
                    for (int c = 0; c < temp.length(); c++) {
                        count += temp[c] - '0';
                    }
                    if (count % 2 == 0) {
                        betta[i] = '0';
                    }
                    else {
                        betta[i] = '1';
                    }
                    break;
                case 4:
                    for (int j = i; j < betta.length(); j++) {
                        vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                        for (int c = 0; c < controls.size(); c++) {
                            if (controls[c] == 16) {
                                temp += betta[j - 1];
                            }
                        }
                    }
                    cout << "V-" << qwe << " " << temp;
                    cout << "\n";
                    temp = temp.substr(1);
                    for (int c = 0; c < temp.length(); c++) {
                        count += temp[c] - '0';
                    }
                    if (count % 2 == 0) {
                        betta[i] = '0';
                    }
                    else {
                        betta[i] = '1';
                    }
                    break;
                }
                qwe++;
            }
            
        }
        cout << "otvet: " << betta << endl;
    }
    