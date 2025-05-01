// Module 24 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>   // Required for std::vector
#include <string>   // Required for std::string
#include <utility>  // Required for std::swap (alternative way to swap)

// Use the standard namespace for convenience
using namespace std;

// Bubble sort function modified to sort a vector of strings
void bubble_sort(vector<string>& items) // Takes a reference to a vector of strings
{
    int length = items.size(); // Get the number of items in the vector
    bool swapped; // Flag to check if any swap happened in a pass

    // Do n-1 passes (optimization: fewer passes might be needed)
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false; // Reset swap flag for the new pass
        // Look at each item up to the unsorted portion
        // The last 'i' items are already in place after 'i' passes
        for (int j = 0; j < length - 1 - i; j++)
        {
            // If two adjacent items are out of alphabetical order (string comparison)
            if (items[j] > items[j + 1])
            {
                // Swap them
                string temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
                // Or use std::swap: swap(items[j], items[j+1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        // If no swaps happened during a pass, the list is sorted
        if (!swapped)
        {
            break; // Exit the outer loop early
        }
    }
}

// Function to print the items in the vector
void print_words(const vector<string>& items) // Takes a const reference (doesn't modify)
{
    for (const string& word : items) // Use a range-based for loop for simplicity
    {
        cout << word << " ";
    }
    cout << endl;
}


int main()
{
    int num_words;

    // Get the number of words from the user
    cout << "How many words do you want to enter? ";
    cin >> num_words;

    // Create a vector of strings to hold the words
    vector<string> words(num_words); // Creates a vector with space for num_words strings

    // Prompt the user to enter the words
    cout << "Enter " << num_words << " words, separated by spaces or newlines:" << endl;
    for (int i = 0; i < num_words; ++i)
    {
        cin >> words[i]; // Read each word into the vector
    }

    // Print the original list (optional)
    cout << "\nOriginal list:" << endl;
    print_words(words);

    // Sort the vector of words alphabetically
    bubble_sort(words);

    // Print the sorted list
    cout << "\nAlphabetically sorted list:" << endl;
    print_words(words);

    cout << endl;
    return 0;
}
