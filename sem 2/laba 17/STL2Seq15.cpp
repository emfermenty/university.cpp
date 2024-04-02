/*Дан дек D с четным количеством элементов. Вставить перед каждым элементом
из первой половины исходного дека число −1. Использовать функцию-член insert в цикле с
числовым параметром.
Указание. Используйте цикл с числовым параметром, повторяющийся N/2 раз (где N —
исходный размер дека). Свяжите вспомогательный итератор i с началом второй половины
элементов дека. В цикле выполняйте функцию-член insert для первого параметра, равного --i,
обязательно присваивая возвращаемое значение итератору i.*/

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    deque<int> L;
    int n;
    cin >> n;
    if (n % 2 != 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        L.push_back(m);
    }
    for (int i = 0; i < L.size() / 2; i++) {
        deque<int>::iterator it = L.begin() + 2 * i;
        it = L.insert(it, -1);
    }
    for (int num : L) {
        cout << num << " ";
    }
    cout << endl;
}
