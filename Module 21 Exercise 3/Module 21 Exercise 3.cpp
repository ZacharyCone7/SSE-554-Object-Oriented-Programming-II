// Module 21 Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Definition of a node in the binary search tree
class Node {
public:
    int value;      // Value held by the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize the node with a value
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) class
class BST {
public:
    Node* root; // Root of the BST

    // Constructor initializes the root to nullptr
    BST() : root(nullptr) {}

    // Public method to insert a value into the BST
    void insert(int val) {
        root = insert_recursive(root, val);
    }

    // Public method to search for a value in the BST
    bool search(int val) {
        return search_recursive(root, val);
    }

private:
    // Helper function to insert a value recursively
    Node* insert_recursive(Node* node, int val) {
        if (!node) return new Node(val); // If node is null, insert here
        if (val < node->value)           // If value is less, go left
            node->left = insert_recursive(node->left, val);
        else if (val > node->value)      // If value is greater, go right
            node->right = insert_recursive(node->right, val);
        return node; // Return the unchanged node pointer
    }

    // Helper function to search for a value recursively
    bool search_recursive(Node* node, int val) {
        if (!node) return false;              // Reached a leaf, not found
        if (val == node->value) return true;  // Value found
        if (val < node->value)                // Search left subtree
            return search_recursive(node->left, val);
        else                                  // Search right subtree
            return search_recursive(node->right, val);
    }
};

int main() {
    BST tree;

    // Insert 15 unique integers into the BST
    vector<int> bst_values = { 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85 };
    for (int val : bst_values)
        tree.insert(val);

    // Numbers to search in the BST
    // 25 and 60 are present; 99 and 13 are not; 44 may or may not be (in this case, it is not)
    vector<int> search_numbers = { 25, 60, 99, 13, 44 };

    cout << "=== BST Search Results ===\n";
    for (int num : search_numbers) {
        bool found = tree.search(num);
        cout << "Number " << num << (found ? " was FOUND in the BST.\n" : " was NOT found in the BST.\n");
    }

    return 0;
}