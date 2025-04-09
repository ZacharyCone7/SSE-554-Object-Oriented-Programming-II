// Module 20 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>g
using namespace std;

int main() {
    stack<int> num_stack;
    vector<int> original_numbers;
    int n, input;

    cout << "How many numbers do you want to enter? ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> input;
        original_numbers.push_back(input);  // Store for original order
        num_stack.push(input);              // Push to stack for reverse
    }

    // Display original order
    cout << "\nNumbers in original order:\n";
    for (int i = 0; i < original_numbers.size(); ++i) {
        cout << original_numbers[i] << " ";
    }

    // Display reverse order using the stack
    cout << "\n\nNumbers in reverse order:\n";
    while (!num_stack.empty()) {
        cout << num_stack.top() << " ";
        num_stack.pop();
    }

    cout << endl;
    return 0;
}

