/*Даны списки L1 и L2, у каждого из которых количество элементов делится на 4. В
первом списке инвертировать (расположить в обратном порядке) первую половину элементов,
во втором списке — вторую половину. Для первого списка использовать алгоритм
swap_ranges и обратные итераторы, для второго — алгоритм reverse. Использовать также
функцию advance.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

//32
//81 -56 88 -35 26 50 -72 -25 -63 50 56 -24 84 -15 58 81 48 60 -59 -9 -25 64 5 95 12 -28 -73 9 -12 -32 -38 -55
//12
//-58 -39 -78 -12 94 -50 -6 -57 36 59 -4 -50
using namespace std;

int main(){
    int n;
    cout << "Введите размерность первого списка ";
    cin >> n;
    list<int> L1;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        L1.push_back(num);
    }
    int m;
    cout << "Введите размерность второго списка ";
    cin >> m;
    list<int> L2;
    for(int i = 0; i < m; i++){
        int num2;
        cin >> num2;
        L2.push_back(num2);
    }

    int half1 = L1.size() /2;
    auto it_mid1 = next(L1.begin(), half1);
    auto rit1 = L1.rbegin();
    advance(rit1, L1.size() - half1);
    swap_ranges(L1.begin(), it_mid1, rit1);

    int half2 = L2.size() / 2;
    auto it_mid2 = next(L2.begin(), half2);
    reverse(it_mid2, L2.end());

    cout << "Первый список: ";
    for(int i : L1){
        cout << i << " ";
    }
    cout << endl << "Второй список ";
    for(int i : L2){
        cout << i << " ";
    }
}