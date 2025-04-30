// Module 20 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Node class for each element in the queue
class Node {
public:
    int data;       // The value stored in the node
    Node* next;     // Pointer to the next node in the queue

    // Constructor to initialize node with data
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Custom Queue class using a singly linked list
class Queue {
private:
    Node* front;    // Pointer to the front of the queue
    Node* rear;     // Pointer to the rear of the queue

public:
    // Constructor initializes an empty queue
    Queue() {
        front = rear = NULL;
    }

    // Add a new element to the end of the queue
    void enqueue(int d) {
        Node* temp = new Node(d);

        // If the queue is empty, front and rear point to the new node
        if (rear == NULL) {
            front = rear = temp;
        }
        else {
            // Link the new node at the end and update rear
            rear->next = temp;
            rear = temp;
        }
    }

    // Remove the element from the front of the queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty after dequeue, update rear
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Return the value at the front of the queue
    int getFront() {
        if (front != NULL) {
            return front->data;
        }
        else {
            throw runtime_error("Queue is empty!");
        }
    }
};

int main() {
    Queue q;           // Create an instance of the custom queue
    int n, input;      // Variables for number of inputs and input value

    // Ask user for the number of people entering the line
    cout << "How many numbers would you like to enter? ";
    cin >> n;

    // Enqueue each number into the queue
    for (int i = 0; i < n; ++i) {
        cout << "Enter number #" << i + 1 << ": ";
        cin >> input;
        q.enqueue(input);

        if (i == 0)
            cout << input << " is first in line for the slide." << endl;
        else
            cout << input << " is now at the end of the line for the slide." << endl;
    }

    cout << "\nThe slide is now open!\n" << endl;

    // Process the queue: simulate people sliding down one by one
    while (!q.isEmpty()) {
        cout << q.getFront() << " is sliding down!" << endl;
        q.dequeue();
    }

    return 0;
}