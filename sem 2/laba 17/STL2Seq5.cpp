//Дан двусвязный линейный список и указатель на первый элемент этого списка.
//Создать текстовый файл, в который вывести содержимое списка в следующем порядке :
//сначала первый элемент списка, потом последний, далее второй и предпоследний и т.д., в
//конце - элементы, находящиеся в середине списка.Подсказка : после вывода очередного числа
//удалять его в списке.Числа выводить в одну строку, разделяя ровно одним пробелом, в конце
//строки пробел на ставить.

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    list<int> L;
    int n;
    cout << "Введите кол-во элементов списка (кол-во делится на 3) ";
    cin >> n;
    if (n % 3 != 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        L.push_back(m);
    }
    int size = L.size();
    int third = size / 3;
    list<int>::iterator it = L.begin();
    for (int i = 0; i < third; i++) {
        cout << *it << " ";
        ++it;
    } cout << endl;
    for (int i = 0; i < third-1; i++) {
        ++it;
    }
    for (int i = 0; i < third; i++) {
        cout << *it << " ";
        --it;
    }
    for (int i = 0; i < third*2; i++) {
        ++it;
    }
    cout << endl;
    for (int i = 0; i < third; i++) {
        cout << *it << " ";
        --it;
    }
    cout << endl;
}