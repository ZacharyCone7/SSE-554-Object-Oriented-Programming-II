// Module 20 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Node class for each element in the queue
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Custom Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int d) {
        Node* temp = new Node(d);
        if (rear == NULL) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty, update rear to NULL
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    bool isEmpty() {
        return front == NULL;
    }

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
    Queue q;
    int n, input;

    cout << "How many numbers would you like to enter? ";
    cin >> n;

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

    while (!q.isEmpty()) {
        cout << q.getFront() << " is sliding down!" << endl;
        q.dequeue();
    }

    return 0;
}

