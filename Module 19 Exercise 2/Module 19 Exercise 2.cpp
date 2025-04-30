// Module 19 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

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
    myBook.add_page("Title Page: AN AWESOME DISCOVERY!!!");
    myBook.add_page("Page 1: Amelia had always dreamed of finding something extraordinary. Growing up in a sleepy village, she spent her\n"
                    "afternoons wandering through the nearby woods, imagining hidden treasures beneath the ancient oaks. One misty morning,\n"
                    "as the sunlight filtered through the trees, she stumbled upon a peculiar artifact partially buried in the soil. It was\n"
                    "a golden compass, its needle spinning erratically.Engraved on its surface was a cryptic phrase:\nFollow where others dare not.");
    myBook.add_page("Page 2: The compass seemed alive, pulling her forward as though it had a will of its own. Trusting her instincts, Amelia\n"
                    "packed a bag and set off. She followed the compass through rugged trails, across rushing rivers, and up steep mountains.\n"
                    "Along the way, she encountered symbols carved into rocks and trees, as if someone—or something—had been guiding her path\n"
                    "for centuries.Each mark seemed to promise answers, but the journey grew more perilous with every step.");
    myBook.add_page("Page 3: After days of travel, the compass led her to a cave concealed by thick vines. Inside, the air was damp and cold,\n"
                    "and the walls glowed faintly with bioluminescent moss. As she ventured deeper, Amelia discovered a massive underground \n"
                    "city, long abandoned but marvelously preserved. Towering spires and intricate carvings suggested a civilization far \n"
                    "ahead of its time. In the heart of the city stood a pedestal, and on it rested a glowing orb.");
    myBook.add_page("Page 4: Just as Amelia reached out to touch the orb, a low growl echoed through the cavern. A spectral figure emerged \n"
                    "from the shadows—it was the city’s ancient guardian, a being made of shimmering light and shadow. It spoke in a voice \n"
                    "that resonated within her: To claim the knowledge of this place, you must prove yourself worthy. The guardian presented\n"
                    "her with a riddle, a test of her courage, wit, and compassion. With a trembling voice, Amelia answered, her heart \n"
                    "pounding as the guardian scrutinized her response.");
    myBook.add_page("Page 5: The guardian nodded solemnly and vanished, leaving the orb glowing brighter than ever. When Amelia touched it, a"
                    "flood of memories and knowledge surged into her mind, revealing the secrets of the lost city and its people. She \n"
                    "realized she had been chosen not merely to uncover the city, but to safeguard its legacy. As she emerged from the cave, \n"
                    "the compass stopped spinning, its purpose fulfilled. Amelia returned to her village, forever changed, her eyes alight \n"
                    "with the wisdom of the ancients.");

    cout << "Welcome to the Book Reader!\n";
    myBook.show_current_page();

    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "[->] Next Page\n";
        cout << "[<-] Previous Page\n";
        cout << "[esc] Quit\n";
        cout << "Your choice: ";
        choice = _getch();

        if (choice == 224) { // Extended code
            choice = _getch();
            system("cls");
            switch (choice) {
            case KEY_RIGHT:
                myBook.next_page();
                break;
            case KEY_LEFT:
                myBook.prev_page();
                break;
            case KEY_ESC:
                cout << "Exiting the book reader. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        }

    } while (choice != KEY_ESC);

    return 0;
}
