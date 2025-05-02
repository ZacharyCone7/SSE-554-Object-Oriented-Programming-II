// Module 28 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // For input/output streams (cin, cout)
#include <vector>   // To store the order items
#include <string>   // To work with strings (item names, user input)
#include <map>      // To store the menu (item name -> price)
#include <iomanip>  // For formatting output (setprecision, fixed)
#include <limits>   // For numeric_limits (used in input clearing)
#include <ios>      // For streamsize (used in input clearing)
#include <cctype>   // For tolower (to handle 'y'/'n' case-insensitively)

// --- Function Prototypes ---
void displayWelcomeMessage();
void displayMenu(const std::map<int, std::pair<std::string, double>>& menu);
void displayOrderSummary(const std::vector<std::string>& order, double totalCost);
void displayGoodbyeMessage();

int main() {
    // --- Data Structures ---
    // Using a map where the key is the menu number for easier selection
    // The value is a pair containing the item name (string) and its price (double)
    std::map<int, std::pair<std::string, double>> menu = {
        {1, {"Espresso", 2.50}},
        {2, {"Latte", 3.75}},
        {3, {"Cappuccino", 3.50}},
        {4, {"Americano", 3.00}},
        {5, {"Mocha", 4.25}},
        {6, {"Drip Coffee", 2.75}}
    };

    std::vector<std::string> currentOrder; // Stores the names of items ordered
    double totalCost = 0.0;              // Running total
    int userChoice = 0;                  // Stores the user's menu selection number
    char addAnother = 'y';               // Controls the ordering loop

    // --- Program Flow ---
    displayWelcomeMessage();

    // Main ordering loop
    do {
        displayMenu(menu);
        std::cout << "Please enter the number of the item you'd like to order: ";

        // Input validation loop: Keep asking until valid input is received
        while (!(std::cin >> userChoice) || menu.find(userChoice) == menu.end()) {
            std::cout << "That's not a valid menu number. Please try again: ";
            std::cin.clear(); // Clear the error flag on cin
            // Discard the invalid input remaining in the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // --- Process Valid Order ---
        std::string orderedItemName = menu[userChoice].first;
        double itemPrice = menu[userChoice].second;

        currentOrder.push_back(orderedItemName); // Add item name to the order list
        totalCost += itemPrice;                 // Add price to the total

        std::cout << "\n--> Added '" << orderedItemName << "' to your order.\n";
        std::cout << "--> Current total: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

        // --- Ask to Continue ---
        // Clear the newline character left by 'cin >> userChoice' before asking y/n
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\nWould you like to add another item? (y/n): ";
        std::cin >> addAnother;
        // Clear the buffer again after reading the single character 'y' or 'n'
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Convert response to lowercase to simplify the check
        addAnother = tolower(addAnother);

    } while (addAnother == 'y'); // Continue loop if user entered 'y' or 'Y'

    // --- Final Output ---
    displayOrderSummary(currentOrder, totalCost);
    displayGoodbyeMessage();

    return 0; // Indicate successful execution
}

// --- Function Definitions ---

void displayWelcomeMessage() {
    std::cout << "===================================\n";
    std::cout << " Welcome to the Cone Coffee Corner! \n";
    std::cout << "===================================\n";
}

void displayMenu(const std::map<int, std::pair<std::string, double>>& menu) {
    std::cout << "\n----- Here's Our Menu -----\n";
    // Set precision for currency formatting within the loop
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& pair : menu) {
        // pair.first is the menu number (int)
        // pair.second is the pair<string, double>
        // pair.second.first is the item name (string)
        // pair.second.second is the price (double)
        std::cout << pair.first << ". " << std::left << std::setw(15) << pair.second.first // Left align name in 15 spaces
            << " - $" << pair.second.second << std::endl;
    }
    // Reset output formatting flags if needed elsewhere (optional here)
   // std::cout.unsetf(std::ios_base::floatfield);
    std::cout << "----------------------------\n";
}

void displayOrderSummary(const std::vector<std::string>& order, double totalCost) {
    std::cout << "\n--- Your Final Order Summary ---\n";
    if (order.empty()) {
        std::cout << "Looks like you decided not to order anything today.\n";
    }
    else {
        std::cout << "Items Ordered:\n";
        for (const std::string& item : order) {
            std::cout << "- " << item << std::endl;
        }
        std::cout << "------------------------------\n";
        std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;
    }
    std::cout << "------------------------------\n";
}

void displayGoodbyeMessage() {
    std::cout << "\nThank you for stopping by the Cone Coffee Corner!\n";
    std::cout << "Have a great day!\n";
    std::cout << "===================================\n";
}
