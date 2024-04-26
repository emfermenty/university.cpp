 /*Дано дерево поиска и указатель корень дерева P1. Необходимо вывести второе
максимальное значение в дереве. Решение должно иметь сложность по времени исполнения
T(n) = O(log n), где n - число вершин в дереве.*/

#include "pt4.h"
#include <iostream>
using namespace std;

void search(){}

Node* findMax(Node* root) {
    while (root->Right != nullptr) {
        root = root->Right;
    }
    return root;
}

int findSecondMax(Node* root, Node* maxNode) {
    if (maxNode->Left) {
        return findMax(maxNode->Left)->Data;
    }
    else {
        Node* current = root;
        Node* parent = nullptr;

        while (current != maxNode) {
            if (current->Data < maxNode->Data) {
                parent = current;
                current = current->Right;
            }
            else {
                current = current->Left;
            }
        }

        return parent->Data;
    }
}

void Solve()
{
    Task("TreeWork18");
    PNode p1;
    GetP(&p1);
    Node* maxNode = findMax(p1);
   
    pt << findSecondMax(p1, maxNode);
}
