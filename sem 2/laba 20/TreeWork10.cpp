/* Дано дерево поиска и указатель корень дерева P1. Необходимо вставить в дерево
значение X*/

#include "pt4.h"
using namespace std;

void add(PNode &p1, int k) {
    if (!p1) {
        p1 = new Node;
        p1->Data = k;
        p1->Left = NULL;
        p1->Right = NULL;
        return;
    }
    if (k < p1->Data) {
        add(p1->Left, k);
    }else
    add(p1->Right, k);
}

void Solve()
{
    Task("TreeWork10");
    PNode p1;
    GetP(&p1);
    int k;
    GetN(&k);
    add(p1, k);
}