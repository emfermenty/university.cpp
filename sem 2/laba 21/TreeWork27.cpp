#include "pt4.h"
#include <iostream>
#include <string>
using namespace std;
string птаск = "";

Node* deleteRoot(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->Left == nullptr) {
        return root->Right;
    }
    if (root->Right == nullptr) {
        return root->Left;
    }
    Node* temp = root->Right;
    while (temp->Left) {
        temp = temp->Left;
    }
    temp->Left = root->Left;
    return root->Right;
}

void PrintTree(Node* tree, string& stroka) {
    if (tree != NULL) {
        stroka += "(";
        PrintTree(tree->Left, stroka);
        stroka += to_string(tree->Data);
        PrintTree(tree->Right, stroka);
        stroka += ")";
    }
}


void Solve()
{
    Task("TreeWork27");
    PNode P1;
    GetP(&P1);
    Node* root = deleteRoot(P1);
    //pt << to_string(root->Data);
    string строка;
    PrintTree(root, строка);
    строка.erase(строка.begin());
    строка.erase(строка.end() - 1);
    pt << строка;
}