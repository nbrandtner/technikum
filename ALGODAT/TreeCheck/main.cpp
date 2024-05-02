#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

// Node structure for the AVL tree
struct Node
{
    int key;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNewNode(int key)
{
    // Error handling for memory allocation
    Node *node = new (nothrow) Node;
    if (!node)
    {
        cerr << "Memory allocation failed" << endl;
        return nullptr;
    }
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

// Function to insert a new node into the AVL tree
Node *insertNodeIntoAVLTree(Node *node, int key)
{
    // If the node is null, create a new node
    if (node == nullptr)
        return createNewNode(key);
    // If the key is less than the node's key, insert into the left subtree
    if (key < node->key)
        node->left = insertNodeIntoAVLTree(node->left, key);
    // If the key is greater than the node's key, insert into the right subtree
    else if (key > node->key)
        node->right = insertNodeIntoAVLTree(node->right, key);
    return node;
}

// Function to calculate the height of a node
int calculateNodeHeight(Node *node)
{
    // If the node is null, its height is 0
    if (node == nullptr)
        return 0;
    // Otherwise, its height is the maximum height of its subtrees plus 1
    return max(calculateNodeHeight(node->left), calculateNodeHeight(node->right)) + 1;
}

// Function to calculate the balance factor of a node
int calculateBalanceFactor(Node *node)
{
    // If the node is null, its balance factor is 0
    if (node == nullptr)
        return 0;
    // Otherwise, its balance factor is the height of the right subtree minus the height of the left subtree
    return calculateNodeHeight(node->right) - calculateNodeHeight(node->left);
}

bool isAVL = true;

// Function to check if the tree is an AVL tree
void checkIfTreeIsAVLTree(Node *root)
{
    // If the root is not null
    if (root != nullptr)
    {
        // Check the left subtree
        checkIfTreeIsAVLTree(root->left);
        // Calculate the balance factor of the root
        int balance = calculateBalanceFactor(root);
        cout << "bal(" << root->key << ") = " << balance;
        // If the balance factor is not between -1 and 1, the AVL property is violated
        if (balance > 1 || balance < -1)
        {
            cout << " (AVL violation!)";
            isAVL = false;
        }
        cout << endl;
        // Check the right subtree
        checkIfTreeIsAVLTree(root->right);
    }
}

int minKey = INT_MAX;
int maxKey = INT_MIN;
double sumKeys = 0;
int countKeys = 0;

// Function to calculate the minimum, maximum and average keys
void calculateMinMaxAvgKeys(Node *root)
{
    // If the root is not null
    if (root != nullptr)
    {
        // Calculate for the left subtree
        calculateMinMaxAvgKeys(root->left);
        // Update the minimum, maximum, sum and count of keys
        minKey = min(minKey, root->key);
        maxKey = max(maxKey, root->key);
        sumKeys += root->key;
        countKeys++;
        // Calculate for the right subtree
        calculateMinMaxAvgKeys(root->right);
    }
}

// Function to read the keys from a file and build the AVL tree
Node *buildAVLTreeFromFile(string filename)
{
    ifstream file(filename);
    while (!file)
    {
        cerr << "Cannot open file: " << filename << endl;
        cout << "Enter a valid filename: ";
        cin >> filename;
        file.open(filename);
    }

    Node *root = nullptr;
    int key;
    while (file >> key)
    {
        if (file.fail())
        {
            cerr << "Error reading key from file" << endl;
            file.clear();
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        root = insertNodeIntoAVLTree(root, key);
    }

    if (root != nullptr)
    {
        checkIfTreeIsAVLTree(root);
        cout << "AVL: " << (isAVL ? "yes" : "no") << endl;

        calculateMinMaxAvgKeys(root);
        cout << "min: " << minKey << ", max: " << maxKey << ", avg: " << sumKeys / countKeys << endl;
    }

    return root;
}

// Function to search a key in the AVL tree
void searchKeyInAVLTree(Node *root, int key)
{
    // If the root is null, the key is not found
    if (root == nullptr)
    {
        cout << key << " not found!" << endl;
        return;
    }
    // If the key is less than the root's key, search the left subtree
    if (key < root->key)
        searchKeyInAVLTree(root->left, key);
    // If the key is greater than the root's key, search the right subtree
    else if (key > root->key)
        searchKeyInAVLTree(root->right, key);
    // If the key is equal to the root's key, the key is found
    else
        cout << key << " found" << endl;
}

// Function to check if a tree is a subtree of another tree
bool checkIfExactSubtree(Node *tree, Node *subtree)
{
    // If the subtree is null, it is a subtree of any tree
    if (subtree == nullptr)
        return true;
    // If the tree is null but the subtree is not, the subtree is not a subtree of the tree
    if (tree == nullptr)
        return false;
    // If the keys of the tree and subtree are equal, check their subtrees
    if (tree->key == subtree->key)
        return checkIfExactSubtree(tree->left, subtree->left) && checkIfExactSubtree(tree->right, subtree->right);
    // If the keys are not equal, check if the subtree is a subtree of the left or right subtree of the tree
    return checkIfExactSubtree(tree->left, subtree) || checkIfExactSubtree(tree->right, subtree);
}

// Function to search a key in the AVL tree and print the path
void searchKeyAndPrintPath(Node *root, int key, string path = "")
{
    // If the root is null, the key is not found
    if (root == nullptr)
    {
        cout << key << " not found!" << endl;
        return;
    }
    // If the key is less than the root's key, search the left subtree
    if (key < root->key)
        searchKeyAndPrintPath(root->left, key, path + to_string(root->key) + " -> ");
    // If the key is greater than the root's key, search the right subtree
    else if (key > root->key)
        searchKeyAndPrintPath(root->right, key, path + to_string(root->key) + " -> ");
    // If the key is equal to the root's key, the key is found
    else
        cout << key << " found at " << path << key << endl;
}

// Function to convert the AVL tree to a list
void convertAVLTreeToList(Node *root, vector<int> &list)
{ 
    // If the root is not null
    if (root != nullptr)
    {
        // Convert the left subtree to a list
        convertAVLTreeToList(root->left, list);
        // Add the root's key to the list
        list.push_back(root->key);
        // Convert the right subtree to a list
        convertAVLTreeToList(root->right, list);
    }
}

// Function to join the elements of a list into a string
string joinListElementsIntoString(const vector<int> &list, const string &delimiter)
{
    string result;
    // For each element in the list
    for (int i = 0; i < list.size(); i++)
    {
        // Add the element to the result
        result += to_string(list[i]);
        // If it is not the last element, add the delimiter
        if (i < list.size() - 1)
            result += delimiter;
    }
    // Return the result
    return result;
}

// Function to check if a tree is a subtree of another tree
bool checkIfSubtree(Node *tree, Node *subtree)
{
    // Convert the tree and subtree to lists
    vector<int> treeList, subtreeList;
    convertAVLTreeToList(tree, treeList);
    convertAVLTreeToList(subtree, subtreeList);

    // Convert the lists to strings
    string treeStr = "," + joinListElementsIntoString(treeList, ",") + ",";
    string subtreeStr = "," + joinListElementsIntoString(subtreeList, ",") + ",";

    // Check if the subtree string is a substring of the tree string
    return treeStr.find(subtreeStr) != string::npos;
}

// Main function
int main()
{
    // Ask the user for a filename
    string filename;
    do
    {
        cout << "Filename Example: `Testfiles\\test2.txt`\n";
        cout << "Enter filename: ";
        cin >> filename;
    } while (filename.empty());

    // Build the AVL tree from the file
    Node *root = buildAVLTreeFromFile(filename);
    // If the root is not null
    if (root != nullptr)
    {
        // Ask the user for a key to search
        int keyToSearch;
        cout << "Enter a key to search: ";
        while (!(cin >> keyToSearch))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Search the key and print the path
        searchKeyAndPrintPath(root, keyToSearch);

        // Ask the user for a subtree filename
        string subtreeFilename;
        do
        {
            cout << "Enter subtree filename: ";
            cin >> subtreeFilename;
        } while (subtreeFilename.empty());

        // Build the subtree from the file
        Node *subtree = buildAVLTreeFromFile(subtreeFilename);
        // If the subtree is not null
        if (subtree != nullptr)
        {
            // Check if the subtree is a subtree of the tree
            cout << (checkIfExactSubtree(root, subtree) ? "Subtree found" : "Subtree not found!") << endl;
        }
    }
    // Return 0 to indicate successful execution
    return 0;
}