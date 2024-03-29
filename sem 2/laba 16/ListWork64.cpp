//Дан двусвязный линейный список и указатель на первый элемент этого списка.
//Создать текстовый файл, в который вывести содержимое списка в следующем порядке :
//сначала первый элемент списка, потом последний, далее второй и предпоследний и т.д., в
//конце - элементы, находящиеся в середине списка.Подсказка : после вывода очередного числа
//удалять его в списке.Числа выводить в одну строку, разделяя ровно одним пробелом, в конце
//строки пробел на ставить.

#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void print(Node* head) {
    if (!head) {
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    ofstream file("output.txt");
    while (head != nullptr) {
        file << head->data << " ";
        file << current->data << " ";
        head = head->next;
        if (head == current) {
            break;
        }
        current = current->prev;
    }

    file.close();
}


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    bool flag = true;
    while (flag) {
        int n;
        cin >> n;
        if (n == -1) {
            flag = false;
        }
        Node* newNode = new Node{ n, tail , nullptr };
        if (tail != nullptr) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
    }

       // while (head != nullptr || tail != nullptr) {
            print(head);
       // }

        return 0;
    }
