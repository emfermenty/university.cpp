/*Дан указатель P1 на вершину непустого стека. Создать два новых стека, переместив
в первый из них все элементы исходного стека с четными значениями, а во второй — с
нечетными (элементы в новых стеках будут располагаться в порядке, обратном исходному;
один из этих стеков может оказаться пустым). Вывести адреса вершин полученных стеков (для
пустого стека вывести nullptr). Операции выделения и освобождения памяти не использовать.*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void show(Node* top) {
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;  
}

void splitStack(Node* P1, Node*& evenStack, Node*& oddStack) {
    Node* current = P1;
    evenStack = nullptr;
    oddStack = nullptr;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;

        if (temp->data % 2 == 0) {
            temp->next = evenStack;
            evenStack = temp;
        }
        else {
            temp->next = oddStack;
            oddStack = temp;
        }
    }

    cout << "Адрес вершины стека с четными значениями: " << evenStack << std::endl;
    cout << "Адрес вершины стека с нечетными значениями: " << oddStack << std::endl;
}

int main() {
    int n;
    cout << "press amounths ellements of stack ";
    cin >> n;
    Node* head = nullptr;
    Node* current = nullptr;
    for (int i = 1; i <= n; i++) {
        int r;
        cout << "press " << i <<" element of stack ";
        cin >> r;
        Node* P1 = new Node{r, nullptr};
        if (head == nullptr) {
            head = P1;
            current = head;
        }
        else {
            current->next = P1;
            current = P1;
        }
    }

    Node* evenStack;
    Node* oddStack;

    splitStack(head, evenStack, oddStack);
    show(evenStack);
    show(oddStack);

    return 0;
}
