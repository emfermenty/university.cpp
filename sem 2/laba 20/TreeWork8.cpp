/*Дан указатель P1 на корень непустого дерева. Вывести значения всех вершин
дерева в инфиксном порядке (вначале выводится содержимое левого поддерева в инфиксном
порядке, затем выводится значение корня, затем — содержимое правого поддерева в инфиксном
порядке)*/

#include "pt4.h"
#include <iostream>

using namespace std;

//struct Node{
//    int data;
//    Node* left; Node* right;
//};
//typedef Node* Pnode;

void printlkp(PNode p1){
    if (!p1) {
        return;
    }
    printlkp(p1->Left); 
    pt << p1->Data; 
    printlkp(p1->Right); 
}

void Solve()
{
    Task("TreeWork8");
    PNode p1;
    GetP(&p1);

    printlkp(p1);
}
