// Module 19 Exercise 1: Linked List with User Input-
// Coding linked list with user input that satifies:
// - Requests the user to enter data to populate a singly linked list;
// - Create the list from the user - provided data;
// - Displays the list to the user.
//

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void append_node(string d) {
        Node* new_node = new Node(d);
        if (head == NULL) {
            head = new_node;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
    }

    void display() {
        if (head == NULL)
            cout << "List is empty!" << endl;
        else {
            cout << "Linked List Contents:" << endl;
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList my_list;
    int n;
    string input;

    cout << "How many elements do you want to add to the linked list? ";
    cin >> n;
    cin.ignore(); // To consume the newline after entering the number

    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        getline(cin, input);
        my_list.append_node(input);
    }

    cout << endl;
    my_list.display();

    return 0;
}