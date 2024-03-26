#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
}; typedef Node* Pnode;

Node* insert(Node* head, int M) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* P2 = new Node;
    P2->data = head->data;
    P2->next = nullptr;

    Node* current = head->next;
    Node* newCurrent = P2;

    int count = 1; 

    while (current != nullptr) {
        if (count % 2 != 0) { 
            Node* newNode = new Node;
            newNode->data = M;
            newNode->next = current;
            newCurrent->next = newNode;
            newCurrent = newNode;
        }

        Node* temp = new Node;
        temp->data = current->data;
        temp->next = nullptr;
        newCurrent->next = temp;
        newCurrent = temp;

        current = current->next;
        count++;
    }

    return P2;
}

Node* create() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int value;
    cout << "вводите элементы списка, -1 для остановки ";
    bool flag = true;
    while (flag) {
        cin >> value;
        if (value == -1) {
            flag = false;
        }

        Node* newNode = new Node{ value, nullptr };
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* getLastNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void main(){
    setlocale(LC_ALL, "ru");
    Node* P1 = create();
    printList(P1);

    int m;
    cout << "Введите M ";
    cin >> m;
    Node* P2 = insert(P1, m);
    cout << "Второй список " << endl;
    printList(P2);
    cout << "Узел: " << getLastNode(P2) << endl;

}
