#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};

Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Бинарные коды для каждого символа:\n";
    for (auto pair : huffmanCode) {
        cout << "Символ: " << pair.first << " Код: " << pair.second << '\n';
    }

    
    cout << "Закодированная строка: ";
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    cout << encodedString << endl;
    cout << "Размер закодированной строки: " << encodedString.size() << "" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string text;
    cout << "Введите строку символов: ";
    getline(cin, text);

    buildHuffmanTree(text);
    cout << "Исходная строка: " << text << endl;
    return 0;
}
