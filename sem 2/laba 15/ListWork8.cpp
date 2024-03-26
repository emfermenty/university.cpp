/*Дан односвязный линейный список и указатель на голову списка P1. Необходимо
вывести указатель на девятый элемент этого списка P9. Известно, что в исходном списке не
менее 9 элементов.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};typedef Node *Pnode;

Node* findNinthElement(Node* head, int n) {
    Node* current = head;
    int count = 1;

    while (current != nullptr && count < 9) {
        current = current->next;
        count++;
    }

    return current;
}

int main() {
    Node* head = nullptr;
    Node* current = nullptr;
    int n;
    if (n < 9){
        cout << "Неверное значение ";
        return 0;
    }
    cout << "Введите количество элементов списка ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Введите " << i << " элемент ";
        int r;
        cin >> r;
        Node* newNode = new Node{r, nullptr};

        if (head == nullptr) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }


    Node* ninthElement = findNinthElement(head, n);

    cout << "Указатель на девятый элемент: " << ninthElement << endl;
    current = head;
    while (head -> next != nullptr){
        cout << current -> data << " ";
        current = current ->next;
        delete head;
        head = current;
    }
    cout << head ->data << " ";

    return 0;
}
