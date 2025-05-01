#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert_recursive(root, val);
    }

    bool search(int val) {
        return search_recursive(root, val);
    }

private:
    Node* insert_recursive(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->value)
            node->left = insert_recursive(node->left, val);
        else if (val > node->value)
            node->right = insert_recursive(node->right, val);
        return node;
    }

    bool search_recursive(Node* node, int val) {
        if (!node) return false;
        if (val == node->value) return true;
        if (val < node->value)
            return search_recursive(node->left, val);
        else
            return search_recursive(node->right, val);
    }
};

int main() {
    BST tree;

    // 15 unique integers from 1 to 100
    vector<int> bst_values = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85 };
    for (int val : bst_values)
        tree.insert(val);

    // 5 search numbers (2 in the BST, 2 not in the BST, 1 either way)
    vector<int> search_numbers = { 25, 60, 99, 13, 44 }; // 25 and 60 are in the BST; 99 and 13 are not

    cout << "=== BST Search Results ===\n";
    for (int num : search_numbers) {
        bool found = tree.search(num);
        cout << "Number " << num << (found ? " was FOUND in the BST.\n" : " was NOT found in the BST.\n");
    }

    return 0;
}
