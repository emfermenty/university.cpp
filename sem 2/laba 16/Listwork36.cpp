#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
}; typedef Node* Pnode;

void print(Node* current) {
    if (current == nullptr) {
        return;
    }
    print(current->next);
    cout << current->data << " ";
}

int main() {
    Node* prev = nullptr;
    Node* head = nullptr;
    bool flag = true;
    while (flag) {

        int n;
        cin >> n;
        if (n == -1) {
            flag = false;
        }
        Node* newNode = new Node{ n, prev, nullptr };
        if (prev != nullptr) {
            prev->next = newNode;
        }
        else {
            head = newNode;
        }
        prev = newNode;
    }
    print(head);
    cout << endl;
}