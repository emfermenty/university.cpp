/*Дано число D и указатели P1 и P2 на начало и конец очереди (если очередь является
пустой, то P1 = P2 = nullptr). Добавить элемент со значением D в конец очереди и вывести новые
адреса начала и конца очереди */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Queue {
    Node* front;
    Node* rear;
};

void enqueue(Queue& queue, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (queue.front == nullptr) {
        queue.front = queue.rear = newNode;
    }
    else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

void print(Queue& queue) {
    Node* temp = queue.front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Адрес начала: " << queue.front << endl;
    cout << "Адрес конца: " << queue.rear << endl;
}

void main(){
    setlocale(LC_ALL, "ru");
    int d;
    cout << "Введите кол-во элементов ";
    cin >> d;

    Queue queue;
    queue.front = nullptr;
    queue.rear = nullptr;

    for (int i = 0; i < d; i++) {
        cout << "Введите " << i << " элемент " << endl;
        int k;
        cin >> k;
        enqueue(queue, k);
    }

    cout << "Initial " << endl;
    print(queue);

    int D;
    cout << "Введите D ";
    cin >> D;
    enqueue(queue, D);
    cout << "after " << endl;
    print(queue);
    return;
}
