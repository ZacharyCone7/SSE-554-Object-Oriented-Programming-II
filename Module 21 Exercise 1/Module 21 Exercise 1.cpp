// Module 21 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    string name;
    vector<Node*> children;

    Node(const string& name) : name(name) {}

    void add_child(Node* child) {
        children.push_back(child);
    }

    // Print path to "Exit" node
    bool print_tree(vector<string>& path) {
        path.push_back(name);

        if (name == "Exit") {
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) cout << " -> ";
            }
            cout << endl;
            return true;
        }

        for (Node* child : children) {
            if (child->print_tree(path)) {
                return true;
            }
        }

        // Backtrack if Exit not found in this path
        path.pop_back();
        return false;
    }
};

int main() {
    // Construct the tree from Figure 21-7
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");
    Node* Exit = new Node("Exit");

    // Assume structure:
    // A -> B, C
    // B -> D, E
    // E -> F, Exit
    A->add_child(B);
    A->add_child(C);
    B->add_child(D);
    B->add_child(E);
    E->add_child(F);
    E->add_child(Exit);

    vector<string> path;
    cout << "Path to Exit:\n";
    if (!A->print_tree(path)) {
        cout << "No path to Exit found." << endl;
    }

    return 0;
}