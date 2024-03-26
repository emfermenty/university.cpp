//Даны указатели P1, P2 и P3 на первый, последний и текущий элементы
//двусвязного списка(если список является пустым, то P1 = P2 = P3 = NULL).Также дано число
//N(> 0) и набор из N чисел.Описать тип TList — запись с полями First, Last и Current типа
//PNode(поля указывают соответственно на первый, последний и текущий элементы списка) —
//и процедуру InsertLast(L, D), которая добавляет новый элемент со значением D в конец списка
//L(L — входной и выходной параметр типа TList, D — входной параметр целого типа).
//Добавленный элемент становится текущим.С помощью этой процедуры добавить в конец
//исходного списка данный набор чисел(в том же порядке) и вывести новые адреса его первого,
//последнего и текущего элементов.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

struct TList {
    Node* First;
    Node* Last;
    Node* Current;
};

void insert(TList& L, int i) {
    Node* NewNode = new Node;
    NewNode->data = i;
    NewNode->next = nullptr;

    if (L.First == nullptr) {
        L.First = NewNode;
        L.Last = NewNode;
        L.Current = NewNode;
    }
    else {
        L.Last->next = NewNode;
        NewNode->prev = L.Last;
        L.Last = NewNode;
    }
    L.Current = NewNode;
    cout << L.Current->data<< "наш слон ";
}

int main() {
    setlocale(LC_ALL, "ru");
    TList L = { nullptr, nullptr, nullptr };
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i : num) {
        insert(L, i);
        cout << i << " " << L.Current << endl;
        
    }
    cout << L.First << endl;
    cout << L.Last << endl;
    cout << L.Current << endl;
}
