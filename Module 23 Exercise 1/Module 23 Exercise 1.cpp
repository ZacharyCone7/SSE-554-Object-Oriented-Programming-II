// Module 23 Exercise 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CompanionAnimal {
public:
    CompanionAnimal() {}

    CompanionAnimal(string _name, string _color, int _age, double _weight) {
        name = _name;
        color = _color;
        age = _age;
        weight = _weight;
    }

    string get_name() { return name; }
    string get_color() { return color; }
    int get_age() { return age; }
    double get_weight() { return weight; }

    void display_info() {
        cout << "Name: " << name
            << ", Color: " << color
            << ", Age: " << age
            << ", Weight: " << weight << " lbs" << endl;
    }

private:
    string name;
    string color;
    int age;
    double weight;
};

// Linear search by color
vector<CompanionAnimal> search_by_color(vector<CompanionAnimal> animals, string search_color) {
    vector<CompanionAnimal> matches;
    for (CompanionAnimal animal : animals) {
        if (animal.get_color() == search_color) {
            matches.push_back(animal);
        }
    }
    return matches;
}

int main() {
    vector<CompanionAnimal> shelter_animals = {
        CompanionAnimal("Buddy", "Brown", 3, 45.2),
        CompanionAnimal("Whiskers", "Gray", 2, 10.5),
        CompanionAnimal("Luna", "Black", 4, 55.0),
        CompanionAnimal("Max", "White", 1, 35.0),
        CompanionAnimal("Daisy", "Brown", 5, 25.7),
        CompanionAnimal("Charlie", "Black", 6, 60.3),
        CompanionAnimal("Bella", "Gray", 2, 9.8),
        CompanionAnimal("Rocky", "White", 7, 42.1)
    };

    string user_color;
    cout << "Enter the color of the pet you are looking for: ";
    cin >> user_color;

    vector<CompanionAnimal> results = search_by_color(shelter_animals, user_color);

    if (!results.empty()) {
        cout << "\nAnimals matching color '" << user_color << "':\n";
        for (CompanionAnimal pet : results) {
            pet.display_info();
        }
    }
    else {
        cout << "No animals found with color '" << user_color << "'.\n";
    }

    return 0;
}

