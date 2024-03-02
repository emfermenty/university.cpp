/*Дана строка S0, целое число N (≤ 4) и N файлов целых чисел с именами S1, …, SN. Объ-
единить их содержимое в новом файле-архиве с именем S0, последовательно записывая в него
следующие данные: размер (число элементов) первого исходного файла и все элементы этого
файла, размер второго исходного файла и все его элементы, …, размер N-го исходного файла и
все его элементы.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    string S0;
    int N;

    cout << "Введите количество файлов (N): ";
    cin >> N;
    if(N > 4 || N  <=0){
        return 0;
    }
    ofstream archiveFile("S0.dat", ios::binary);

    for (int i = 1; i <= N; ++i) {

        ofstream inputFile("S" + to_string(i) + ".dat", ios::binary);
        if (!inputFile.is_open()) {
            cout << "Error";
            return 1;
        }
        int n;
        cout << "Введите количество элементов в файле ";
        cin >> n;
        inputFile.write((char*)&n, sizeof(int));
        for (int j = 0; j < n; j++) {
        int r;
        cin >> r;
        inputFile.write((char*)&r, sizeof(int));
    }
        inputFile.close();
        // Считываем все числа из файла в вектор
        ifstream read("S" + to_string(i) + ".dat", ios::binary);
        vector<int> numbers;
        int num;
        while (read.read((char*)&num, sizeof(int))) {
            numbers.push_back(num);
        }

        // Записываем размер файла и все его элементы в архив
        int ss;
        for(int j = 0; j < numbers.size(); j++){
        ss = numbers[j];
        archiveFile.write((char*)&ss, sizeof(int));
        }
        inputFile.close();
    }

    archiveFile.close();
    int num3;
    cout << "Архив успешно создан." << std::endl;
    ifstream zxc("S0.dat", ios::binary);
        while (zxc.peek() != EOF) {
        zxc.read((char*)&num3, sizeof(num3));
        cout << num3 << " ";
    }

    return 0;
}
