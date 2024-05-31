#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iterator>


using namespace std;

vector<int> decomposeIntoMaxPowersOfTwo(int number) {
    vector<int> powersOfTwo;
    int power = 0;

    while (number > 0) {
        if (number % 2 == 1) {
            powersOfTwo.push_back(pow(2, power) - 1); 
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
            k = i - 1;
            break;
        }
    }
    //int c = m + k;
    vector<int> razryad;
    cout << "Контрольные разряды: ";
    for (int i = 0; i < k; i++) {
        razryad.push_back((pow(2, i)) - 1);
        cout << (pow(2, i)) << " ";
    }
    cout << endl;
    vector<int>::iterator iter = razryad.begin();
    vector<int> махинация;
    //razryad.push_back(0);
    int qwe = 0;
    for (int i = 0; i <= alpha.length(); i++) {
        string temp;
        char haha;
        int count = 0;
        if (i == *iter) {
            for (int j = i; j <= alpha.length(); j++) {
                vector<int> controls = decomposeIntoMaxPowersOfTwo(j);
                for (int c = 0; c < controls.size(); c++) {
                    if (controls[c] == *iter) {
                        temp += alpha[j - 1];
                    }
                }
            }
            cout << "V-" << qwe << " " << temp;
            cout << "\n";
            //temp = temp.substr(1);
            for (int c = 0; c < temp.length(); c++) {
                count += temp[c] - '0';
            }
            if (count % 2 == 0) {
                махинация.push_back(0);
            }
            else {
                махинация.push_back(*iter+1);
            }
            iter++;
            qwe++;
        }
    }
    cout << "Необходимо сложить разряды, чтобы получить ошибку: ";
    int again = 0;
    for (int s = 0; s < махинация.size(); s++) {
        cout << махинация[s] << " ";
        again += махинация[s];
    }

    if(again == 0){
        cout << "\n" << "Слово без ошибок ";
    } else {
        if(alpha[again-1] == '0')
            alpha[again-1] = '1';
            else
            alpha[again-1] = '0';
            cout << "\n" << "Слово после исправления выглядит так: " << alpha;
    }
}
