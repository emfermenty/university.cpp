#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


size_t file1() {
    ifstream F1("input.dat", ios::binary);
    size_t sizeF1 = 0; //size_t возвращает значние в байтах
    while (!F1.eof()) { //до конца файла
        F1.get(); //считаем по 1 символу
        sizeF1++;
    }
    F1.close();
    sizeF1--;
    return sizeF1;
}

int main() {
    int n;
    cout << "Write amount value in file: ";
    cin >> n;
    int r;
    vector<int> a;
    ofstream inputt("input.dat", ios::binary);
    cout << "Write values: ";
    for (int i = 0; i < n; i++) {
        cin >> r;
        a.push_back(r);
        inputt.write((char*)&r, sizeof(int));
    }
    inputt.close();
    
    int num;
    cout << "before adds: ";
    ifstream read("input.dat", ios::binary);
    while (read.peek() != EOF) {
        read.read((char*)&num, sizeof(num));
        cout << num << " ";
    }
    cout << endl;
    cout << "file size before extension: " <<  file1() << endl;

    read.close();

    vector<int> b;
    for (int i = 0; i < a.size(); i++) {
        b.push_back(a[i]);
    }
    for (int i = 0; i < a.size(); i++) {
        b.push_back(a[i]);
    }

    ofstream inputt2("input.dat", ios::binary);
    int num2;
    for (int i = 0; i < b.size(); i++) {
        num2 = b[i];
        inputt2.write((char*)&num2, sizeof(int));
    }
    cout << "after adds: ";
    inputt2.close();
    int num3;
    ifstream read2("input.dat", ios::binary);
    while (read2.peek() != EOF) {
        read2.read((char*)&num3, sizeof(num3));
        cout << num3 << " ";
    }
    cout << endl;
    cout << "file size after extension: " << file1() << endl;
}