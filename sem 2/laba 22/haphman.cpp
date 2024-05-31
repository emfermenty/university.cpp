#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node* left, * right;
    Node(char ch, int freq, Node* left, Node* right)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

Node* Create_Node(char ch, int freq, Node* left, Node* right)
{
    Node* root = new Node(ch, freq, left, right);
    return root;
}

class compare {
public:
    bool operator()(Node* left, Node* right)
    {
        return left->freq > right->freq;
    }
};

void encode(Node* root, unordered_map<char, string>& huffmanCode, string codes)
{
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL)
    {
        huffmanCode[root->ch] = codes;
    }
    encode(root->left, huffmanCode, codes + "0");
    encode(root->right, huffmanCode, codes + "1");
}

void decode(Node* root, string str, string& decoded_str)
{
    int index = 0;
    Node* head = root;
    while (index < str.length())
    {
        if (str[index] == '0')
        {
            head = head->left;
        }
        else {
            head = head->right;
        }

        if (head->left == NULL && head->right == NULL)
        {
            decoded_str.push_back(head->ch);
            head = root;
        }
        index++;
    }
}

Node* buildHuffmanTree(string text)
{

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair : freq) {
        pq.push(Create_Node(pair.first, pair.second, NULL, NULL));
    }


    while (pq.size() > 1)
    {

        Node* leftChild = pq.top(); pq.pop();
        Node* rightChild = pq.top();	pq.pop();

        int sum = leftChild->freq + rightChild->freq;
        pq.push(Create_Node('\0', sum, leftChild, rightChild));
    }
    Node* root = pq.top();
    return root;
}

int main()
{
    string text;

    getline(cin, text);
    cout << " оригинальный текст :\n ";
    cout << endl << text << endl;

    Node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    encode(root, huffmanCode, "");

    cout << "Huffman Codes are :\n" << endl;

    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }
    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n \n" << str << '\n';

    string decoded_str = "";
    decode(root, str, decoded_str);
    cout << endl << "decoded string is :" << endl << endl;
    cout << decoded_str << endl;
}
