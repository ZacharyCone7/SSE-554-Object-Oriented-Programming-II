// Module 19 Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <thread>
#include <sstream>
#include <cstdlib> // For srand and rand
#include <ctime>   // For seeding the random number generator

using namespace std;

// Function to clear the screen
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Definition for a Node in the circular linked list
class Node {
public:
    string data;
    Node* next;

    Node(const string& d) : data(d), next(nullptr) {}
};

// Circular linked list class
class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    Node* curr;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr), curr(nullptr) {}

    void appendNode(const string& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
            tail->next = head; // Complete circular link
            curr = head;       // Set current to the first node
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Complete circular link
        }
    }

    void nextPlayerTurn() {
        if (!curr) {
            cout << "No players!" << endl;
        }
        else {
            cout << "\n" << curr->data << "'s turn:\n" << endl;
            curr = curr->next;
        }
    }

    string spinWheel(int spins) {
        Node* temp = head;
        while (spins > 0) {
            cout << "Spinning... Current subject: " << temp->data << endl;
            temp = temp->next;
            spins--;
            this_thread::sleep_for(chrono::milliseconds(200)); // Simulates spinning
        }
        return temp->data;
    }
};

int main() {
    CircularLinkedList wheel;
    wheel.appendNode("Math");
    wheel.appendNode("Science");
    wheel.appendNode("History");
    wheel.appendNode("Geography");
    wheel.appendNode("Pop Culture");

    CircularLinkedList players;
    int numPlayers;

    cout << "Enter number of players: ";
    cin >> numPlayers;

    // Add players to the list
    for (int i = 1; i <= numPlayers; i++) {
        players.appendNode("Player " + to_string(i));
    }

    // Initialize random seed
    srand(time(0));
    cout << "The categories are: Math, Science, History, Geography, and Pop Culture.\n";

    bool isPlaying = true;
    while (isPlaying) {
        players.nextPlayerTurn();
        cout << "Type \"1\" to spin the wheel to select a category: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int initialSpeed = rand() % 30;
            cout << "Spinning with initial speed of: " << initialSpeed << endl;
            string result = wheel.spinWheel(initialSpeed);
            cout << "Final Category is: " << result << endl;
        }
        else {
            cout << "Thanks for playing!" << endl;
            isPlaying = false;
        }
    }

    return 0;
}