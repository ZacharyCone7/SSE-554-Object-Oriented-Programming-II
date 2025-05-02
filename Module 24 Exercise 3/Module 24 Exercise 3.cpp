// Module 24 Exercise 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

// Merge two sorted subarrays into one
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    // Merge the two subarrays
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copy any remaining elements
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];

    // Print array after merging
    printArray(arr);
}

// Recursive merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(arr, left, mid);
        // Sort right half
        mergeSort(arr, mid + 1, right);
        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = { 33, 10, 55, 71, 29, 3, 18 };

    cout << "Unsorted array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Final sorted array: ";
    printArray(arr);

    return 0;
}

