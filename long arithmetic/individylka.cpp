#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>

using namespace std;

vector<int> multiply(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    vector<int> result(m + n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j] += a[i] * b[j]; // Умножение цифр чисел и сохранение в промежуточном результате
            result[i + j + 1] += result[i + j] / 10; // Перенос разряда при необходимости
            result[i + j] %= 10; // Оставляем только одну цифру в текущем разряде
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back(); // Удаляем незначащие нули в конце числа
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    string a_str;
    int n;
    int num = 0;
    cout << "Программа для вычисления степени a^n, если a > MaxInt, n > 10\n" << endl;
    cout << "maxint = 2147483647, число a должно быть больше данного числа" << endl;
    cout << "Введите число a: ";
    cin >> a_str;

    // проверка на коректность данных
    num = atoi(a_str.c_str());
    if (a_str[0] == '-') {
        cout << "НЕВЕРНО, число не должно быть отрицательным" << endl;
        return 0;
    }
    if (num < 2147483647) {
        cout << "НЕВЕРНО, маленькое число, необходимо количество разрядов > 10 или большее число" << endl;
        return 0;
     }
 
    cout << "Введите степень n (n>10): "; // проверка на коректность введенных данных для переменной n
    cin >> n;
    if (n <= 10) {
        cout << "Степень должна быть больше 10" << endl;
        return 0;
    }

    vector<int> a;
    for (int i = a_str.length() - 1; i >= 0; i--) {
        a.push_back(a_str[i] - '0'); // Преобразование строки в вектор цифр
    }

    vector<int> result = a;
    for (int i = 1; i < n; i++) {
        result = multiply(result, a); // Последовательное умножение числа на само себя n раз
    }

    cout << "Результат: ";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i]; // Вывод результата
    }
    cout << endl;

    return 0;
}