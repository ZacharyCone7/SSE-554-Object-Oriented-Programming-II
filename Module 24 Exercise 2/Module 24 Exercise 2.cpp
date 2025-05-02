// Module 24 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Partition function with print statements
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose last element as pivot
    cout << "Pivot chosen: " << pivot << endl;

    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    printArray(arr); // Print after each partitioning
    return i + 1;
}

// Quicksort with iteration output
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = { 33, 10, 55, 71, 29, 3, 18 };

    cout << "Unsorted array: ";
    printArray(arr);

    quicksort(arr, 0, arr.size() - 1);

    cout << "Final sorted array: ";
    printArray(arr);

    return 0;
}
