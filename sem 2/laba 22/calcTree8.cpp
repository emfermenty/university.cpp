#include "pt4.h"
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int pow(const int& num, const int& toPow) {
	int result = 1;
	for (unsigned short i = 0; i < toPow; ++i)
		result *= num;
	return result;
}

int getSym(const char& sym) {
	switch (sym) {
	case '+': return -1;
	case '-': return -2;
	case '*': return -3;
	case '/': return -4;
	case '%': return -5;
	case '^': return -6;
	default: return sym - '0';
	}
}

int calc(const PNode& tree) {
	if (!tree) return 0;
	//Show("TEST:");
	//Show(tree->Data);
	switch (tree->Data) {
	case -1: return calc(tree->Left) + calc(tree->Right);
	case -2: return calc(tree->Left) - calc(tree->Right);
	case -3: return calc(tree->Left) * calc(tree->Right);
	case -4: return calc(tree->Left) / calc(tree->Right);
	case -5: return calc(tree->Left) % calc(tree->Right);
	case -6: return pow(calc(tree->Left), calc(tree->Right));
	default: return tree->Data;
	}
}

void construct(PNode& tree, const std::string& input) {
	stack<PNode> stack;
	for (short i = input.size() - 1; i >= 0; i = i - 2) {
		//Show(input[i]);
		PNode temp = new Node;
		temp->Left = nullptr;
		temp->Right = nullptr;
		temp->Data = getSym(input[i]);
		if (getSym(input[i]) < 0) {
			temp->Left = stack.top(); stack.pop();
			temp->Right = stack.top(); stack.pop();
		}
		stack.push(temp);
	}
	tree = stack.top();
}

void LKR(PNode& tree) {
	if (!tree) return;

	LKR(tree->Left);
	if (calc(tree->Left) == 0 || calc(tree->Right) == 0) {
		tree->Data = calc(tree);
		tree->Left = nullptr;
		tree->Right = nullptr;
	}
	LKR(tree->Right);

}

void Solve()
{
	Task("CalcTree8");
	string in;
	PNode tree = nullptr;

	GetS(in);
	std::ifstream input(in);
	getline(input, in);
	//Show(in);

	construct(tree, in);
	LKR(tree);

	pt << tree;
}
