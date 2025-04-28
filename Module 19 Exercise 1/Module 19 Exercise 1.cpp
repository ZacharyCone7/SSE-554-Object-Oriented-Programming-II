// Module 19 Exercise 1: Linked List with User Input-
// Coding linked list with user input that satifies:
// - Requests the user to enter data to populate a singly linked list;
// - Create the list from the user - provided data;
// - Displays the list to the user.

#include <iostream> // For cout, cin, endl, getline
#include <string>   // For string
using namespace std;

// Represents a single node in the linked list
class Node {
public:
    string data; // The data stored in the node
    Node* next;       // Pointer to the next node in the list

    // Constructor using an initializer list and const reference for efficiency
    //Node(string& d) : data(d), next(nullptr) {}
    Node(string d) {
        data = d;
        next = NULL;
    }
};

// Manages the linked list operations
class LinkedList {
public:
    Node* head; // Pointer to the first node in the list

    // Constructor: Initializes an empty list
    LinkedList() : head(nullptr) {}

    // Appends a new node with data 'd' to the end of the list
    void append_node(string d) {
        Node* new_node = new Node(d); // Create the new node

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = new_node;
        }
        // Otherwise, find the last node and append the new node
        else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Link the last node to the new node
            temp->next = new_node;
        }
    }

    // Displays the contents of the linked list
    void display() const { // Mark display as const as it doesn't modify the list
        if (head == nullptr) {
            cout << "List is empty!" << endl;
        }
        else {
            cout << "\nLinked List Contents:" << endl;
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->next != nullptr) {
                    cout << " -> "; // Add arrow for better visualization
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList my_list; // Create the list object (constructor called)
    int n = 0; // Use default initialization
    string input;

    cout << "How many elements do you want to add to the linked list? ";

    // Basic input validation loop
    while (!(cin >> n) || n < 0) { // Check if input is not an int OR if it's negative
        cout << "Invalid input. Please enter a non-negative integer: ";
        cin.clear(); // Clear the error flag on cin
        // Discard the invalid input from the buffer before trying again
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Consume the newline character left by cin >> n
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Loop to get data for each node
    for (int i = 0; i < n; ++i) {
        cout << "Enter data for node " << (i + 1) << ": ";
        getline(cin, input);
        my_list.append_node(input);
    }

    my_list.display(); // Display the list contents

    return 0; // Indicate successful execution
}