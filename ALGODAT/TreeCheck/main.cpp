#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return max(height(node->left), height(node->right)) + 1;
}

int balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->right) - height(node->left);
}

void preOrder(Node* root) {
    if (root != nullptr) {
        int balance = balanceFactor(root);
        cout << "bal(" << root->key << ") = " << balance;
        if (balance > 1 || balance < -1) {
            cout << " (AVL violation!)";
        }
        cout << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int readFile(string filename) {

    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        return 1;
    }

    Node* root = nullptr;
    int key;
    while (file >> key)
        root = insert(root, key);

    preOrder(root);

    return 0;
}

int main() {
    //read filename from user
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    if(!filename.empty()){
        readFile(filename);
    }
    return 0;
}
