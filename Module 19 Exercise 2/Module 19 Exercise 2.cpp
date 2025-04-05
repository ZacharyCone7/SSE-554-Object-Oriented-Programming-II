// Module 19 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Page {
public:
    string content;
    Page* next;
    Page* prev;

    Page(string text) {
        content = text;
        next = nullptr;
        prev = nullptr;
    }
};

class Book {
private:
    Page* head;
    Page* tail;
    Page* current;

public:
    Book() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void add_page(string text) {
        Page* new_page = new Page(text);
        if (head == nullptr) {
            head = tail = current = new_page;
        }
        else {
            tail->next = new_page;
            new_page->prev = tail;
            tail = new_page;
        }
    }

    void show_current_page() {
        if (current != nullptr) {
            cout << "\n--- Page Content ---" << endl;
            cout << current->content << endl;
            cout << "---------------------" << endl;
        }
        else {
            cout << "No pages in the book." << endl;
        }
    }

    void next_page() {
        if (current && current->next) {
            current = current->next;
            show_current_page();
        }
        else {
            cout << "You are at the last page." << endl;
        }
    }

    void prev_page() {
        if (current && current->prev) {
            current = current->prev;
            show_current_page();
        }
        else {
            cout << "You are at the first page." << endl;
        }
    }
};

int main() {
    Book myBook;

    // Add sample pages to the book
    myBook.add_page("Page 1: Once upon a time in a land far, far away...");
    myBook.add_page("Page 2: The knight rode bravely into the sunset.");
    myBook.add_page("Page 3: A mysterious cave appeared before him.");
    myBook.add_page("Page 4: Inside the cave, he found an ancient treasure.");
    myBook.add_page("Page 5: He returned a hero, with tales to tell.");

    cout << "Welcome to the Book Reader!\n";
    myBook.show_current_page();

    char choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "[n] Next Page\n";
        cout << "[p] Previous Page\n";
        cout << "[q] Quit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 'n':
            myBook.next_page();
            break;
        case 'p':
            myBook.prev_page();
            break;
        case 'q':
            cout << "Exiting the book reader. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'q');

    return 0;
}
