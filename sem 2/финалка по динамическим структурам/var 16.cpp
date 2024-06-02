/*«Хитрый купец» Два купца отправились торговать за море. Каждый из них
повез по N одинаковых тюков с товаром. В пути корабль попал в шторм и дал
течь. Чтобы корабль не затонул, капитан приказал поднять весь груз на палубу
корабля, расставить его вдоль бортов по периметру и выбросить за борт
половину груза. Груз выбрасывается по следующему правилу:
• каждый тюк получает порядковый номер, начиная с тюка, стоящего на
носу корабля;
• их нумерация осуществляется по часовой стрелке;
• номер первого выброшенного тюка соответствует текущему числу
месяца M;
• через K тюков следующий тюк с товаром выбрасывается. Один из
купцов прознал про это правило. Как необходимо расставить ему груз,
чтобы ни один из его тюков не был выброшен?
Использовать циклический однонаправленный список.*/
#include <iostream>

using namespace std;

// Структура для элементов односвязного списка
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* searchElement(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return current; // возвращаем узел, если найден элемент
        }
        current = current->next;
    }
    return nullptr; // если элемент не был найден
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    do {
        if (current->data == value) {
            if (current == head) {
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                }
                else {
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    temp->next = head->next;
                    head = head->next;
                    delete current;
                }
            }
            else {
                previous->next = current->next;
                delete current;
            }
            return;
        }
        previous = current;
        current = current->next;
    } while (current != head);

    std::cout << "Element not found" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    Node* head = new Node(1);
    Node* current = head;
    for (int i = 2; i <= n; i++) {
        current->next = new Node(i);
        current = current->next;
    }
    current->next = head;

    current = head;
    while (current->next != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;

    Node* result = searchElement(head, m);

    if (result != nullptr) {
        cout << "Найден элемент с данными: " << result->data << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }
    Node* tea = result->next;
    deleteNode(head, m);

    current = head;
    while (current->next != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;

    Node* temp = tea;
    for (int i = 0; i < (n - 1) / 2; i++) {
        temp = tea;
        int count = 1;
        while (count != k) {
            //        cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        //cout << "\n";
        tea = temp->next;
        deleteNode(head, temp->data);
    }
    cout << "позиции, чтобы груз не выкинули " << endl;
    current = head;
    while (current->next != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << current->data << endl;
    return 0;
}
