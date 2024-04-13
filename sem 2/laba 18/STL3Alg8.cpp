/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вывести все элементы списка кратные 7 в порядке, обратном исходному. Известно, что в списке
есть хотя бы два элемента кратные 7.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 k = 3 v = 29
// 0 0 1 0 1 1 1 0 0 1 1 1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 1 k = 4 v = 28
// 1 1 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 1 1 0 0 1  k = 5 v = 23
int main() {
    int K;
    std::cout << "Enter K: ";
    std::cin >> K;

    std::vector<int> V;

    std::cout << "Enter elements (0 or 1, separated by spaces): ";
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