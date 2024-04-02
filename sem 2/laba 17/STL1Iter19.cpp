/*Даны вещественные числа A, D и целое число N. Вывести N первых членов
арифметической прогрессии с первым элементом A и разностью D. Использовать алгоритм
generate_n. */

#include <iostream>
#include <fstream>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    double A;  // Первый элемент
    double D;  // Разность
    int N;       // Количество членов арифметической прогрессии
    cin >> A >> D >> N;
   vector<double> progression(N);

    double currentValue = A;
    generate_n(progression.begin(), N, [&currentValue, D]() {
        double value = currentValue;
        currentValue += D;
        return value;
        });

    // Вывод первых N членов арифметической прогрессии
    cout << "Первые " << N << " членов арифметической прогрессии с A=" << A << " и D=" << D << ":\n";
    for (const double& elem : progression) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
