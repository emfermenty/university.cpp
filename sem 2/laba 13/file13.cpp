#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите количество эллементов: ";
    cin >> n;
    int r;
    ofstream inputt("input.dat", ios::binary);
    for(int i = 0; i < n; i++){
        cin >> r;
        inputt.write((char*)&r, sizeof(int));
    }
    inputt.close();

    ifstream input("input.dat", ios::binary);
    ofstream pozitive("pozitive.dat", ios::binary); //с положительными числами
    ofstream negative("negative.dat", ios::binary); //с отрицательными

    int num;
    vector<int> pozitivenums;
    vector<int> negativenums;
    while(input.read((char*)&num, sizeof(int))){
        if(num > 0){
            pozitivenums.push_back(num);
        } else if(num < 0){
            negativenums.push_back(num);
        }
    }
    for(int i = pozitivenums.size()-1; i >= 0; i--){
        pozitive.write((char*)& pozitivenums[i], sizeof(pozitivenums[i]));
    }
    for(int i = negativenums.size()-1; i >= 0; i--){
        negative.write((char*)& negativenums[i], sizeof(pozitivenums[i]));
    }

    input.close();
    pozitive.close();
    negative.close();

    ifstream poozitive("pozitive.dat", ios::binary); //положительные числа
    ifstream neegative("negative.dat", ios::binary); //отрицательные числа
    cout << "позитивные: ";
    int c;
    while(poozitive.peek()!=EOF){
        poozitive.read((char*)& c, sizeof(c));
        cout << c << " ";
    }
    cout << endl;
    cout << "негативные ";
    while(neegative.peek()!=EOF){
        neegative.read((char*)& c, sizeof(c));
        cout << c << " ";
    }
    poozitive.close();
    neegative.close();
}