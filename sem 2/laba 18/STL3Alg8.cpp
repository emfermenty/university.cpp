*/﻿Дано целое число K (> 0) и вектор V, содержащий только нули и единицы. Удалить
в векторе V последний набор из K подряд расположенных нулей (если в этом наборе имеется
больше K нулей, то требуется удалить только последние K из них). Если вектор не содержит
требуемого набора нулей, то не изменять его. Использовать алгоритм search_n и функцию-
член erase, а также обратные итераторы.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 k = 3 v = 29
// 0 0 1 0 1 1 1 0 0 1 1 1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 1 k = 4 v = 28
// 1 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 1 1 0 0 1  k = 5 v = 23
int main() {
    int K;
    cout << "Enter K: ";
    cin >> K;

    vector<int> V;

    cout << "Enter elements (0 or 1, separated by spaces): ";
    int num;
    int c;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> num;
        V.push_back(num);
    }
    int zxc = 0;
    int count = 0;
    auto it = V.rbegin();
    auto iter = it;
    for (; it != V.rend(); ++it) {
        if(*it == 1){
            zxc++;
        }
        if (*it == 0) {
            ++count;
            if (count == K) {
                iter = it;
                break;
                //cout << count;
            }
        } else {
            zxc += count;
            count = 0;
            
        }
    }

    if (count == K) {
        iter++;
        V.erase(iter.base(), iter.base() + K);
    }

    for (int num : V) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}
