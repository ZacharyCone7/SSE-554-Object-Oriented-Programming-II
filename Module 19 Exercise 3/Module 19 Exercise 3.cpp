// Module 19 Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the node structure for the circular linked list
struct Node {
    string value;  // The value on the wheel (could be a color, category, etc.)
    Node* next;    // Pointer to the next node
};

// Class to represent the Circularly Linked List
class CircularList {
private:
    Node* head;    // Head of the list

public:
    CircularList() : head(nullptr) {}

    // Function to add a node to the list
    void addNode(const string& value) {
        Node* newNode = new Node();
        newNode->value = value;

        if (!head) {
            head = newNode;
            newNode->next = head;  // Circular link to itself
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Link back to the head
        }
    }

    // Function to spin the wheel a random number of times
    string spinWheel(int spinCount) {
        if (!head) return "";  // Empty list

        Node* temp = head;
        // Spin the wheel by moving through the nodes
        for (int i = 0; i < spinCount; i++) {
            temp = temp->next;
        }

        return temp->value;  // Return the value where the wheel stops
    }
};

// Function to generate a random speed (spin count)
int getRandomSpeed(int maxSpeed) {
    return rand() % maxSpeed + 1;  // Random speed between 1 and maxSpeed
}

int main() {
    srand(time(0));  // Seed the random number generator

    CircularList wheel;

    // Adding five values (e.g., categories/colors)
    wheel.addNode("History");
    wheel.addNode("Math");
    wheel.addNode("Science");
    wheel.addNode("Art");
    wheel.addNode("Music");

    // Simulate spinning the wheel 5 times
    for (int i = 0; i < 5; i++) {
        int speed = getRandomSpeed(20);  // Random speed between 1 and 20
        cout << "Spin #" << (i + 1) << ": Spinning with a speed of " << speed << "...\n";
        string result = wheel.spinWheel(speed);  // Spin the wheel
        cout << "The wheel stopped at: " << result << endl << endl;

        // Slow down the spin after each round (reduce max speed)
        if (speed > 1) {
            speed--;
        }
    }

    return 0;
}

