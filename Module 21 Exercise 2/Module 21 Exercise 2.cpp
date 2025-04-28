// Module 21 Exercise 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string questionOrDecision;
    Node* yes;
    Node* no;

    Node(string text) : questionOrDecision(text), yes(nullptr), no(nullptr) {}
};

class JobApplication {
public:
    Node* root;

    JobApplication() {
        // Building the tree
        root = new Node("Do you have a college degree?");

        root->yes = new Node("Do you have relevant work experience?");
        root->no = new Node("Are you willing to go through training?");

        // Left side (has degree)
        root->yes->yes = new Node("Do you have more than 2 years of experience?");
        root->yes->no = new Node("Have you completed an internship?");

        root->yes->yes->yes = new Node("? Application accepted!");
        root->yes->yes->no = new Node("?? Application under consideration.");

        root->yes->no->yes = new Node("?? Application under consideration.");
        root->yes->no->no = new Node("? Application rejected.");

        // Right side (no degree)
        root->no->yes = new Node("Are you willing to relocate?");
        root->no->no = new Node("Are you a team player?");

        root->no->yes->yes = new Node("?? Application under consideration.");
        root->no->yes->no = new Node("? Application rejected.");

        root->no->no->yes = new Node("? Application accepted!");
        root->no->no->no = new Node("? Application rejected.");
    }

    void start_application(Node* current) {
        if (!current->yes && !current->no) {
            cout << "\nResult: " << current->questionOrDecision << endl;
            return;
        }

        string answer;
        while (true) {
            cout << current->questionOrDecision << " (yes/no): ";
            getline(cin, answer);
            for (auto& c : answer) c = tolower(c);

            if (answer == "yes") {
                start_application(current->yes);
                break;
            }
            else if (answer == "no") {
                start_application(current->no);
                break;
            }
            else {
                cout << "Please answer with 'yes' or 'no'.\n";
            }
        }
    }
};

int main() {
    JobApplication app;
    cout << "=== Job Application Questionnaire ===\n";
    app.start_application(app.root);
    return 0;
}

