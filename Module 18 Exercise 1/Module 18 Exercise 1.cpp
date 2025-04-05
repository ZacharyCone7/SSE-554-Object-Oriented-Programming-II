// Module 18 Exercise 1.cpp: Template vs. Polymorphism-
// Modifies the code in Figures 18-7, 18-8, and 18-9 to achieve 
// the functionality using polymorphism instead of templates

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class for Polymorphism
class Substance {
public:
    virtual void grind() = 0;
    virtual void chunk() = 0;
    virtual ~Substance() {}
};

// Fruit class inheriting from Substance
class Fruit : public Substance {
public:
    string name;

    Fruit(string name = "apple") : name(name) {}

    void grind() override {
        cout << name << " juice was made!" << endl;
    }

    void chunk() override {
        cout << "lumpy " << name << " juice was made!" << endl;
    }
};

// Spice class inheriting from Substance
class Spice : public Substance {
public:
    string name;

    Spice(string name = "coriander") : name(name) {}

    void grind() override {
        cout << name << " powder was made!" << endl;
    }

    void chunk() override {
        cout << "coarse ground " << name << " was made!" << endl;
    }
};

// Wood class inheriting from Substance
class Wood : public Substance {
public:
    string name;

    Wood(string name = "oak") : name(name) {}

    void grind() override {
        cout << name << " sawdust was made!" << endl;
    }

    void chunk() override {
        cout << name << " chips were made!" << endl;
    }
};

// Grinder class using polymorphism
class Grinder {
public:
    Substance* substance;
    int level;

    Grinder(Substance* substance) : substance(substance), level(0) {}

    void setLevel(int level) {
        this->level = level;
    }

    void fill(Substance* substance) {
        this->substance = substance;
    }

    void process() {
        if (level == 0) {
            substance->grind();
        }
        else if (level == 1) {
            substance->chunk();
        }
    }
};

// Generalized grind function
void grind(Substance& substance) {
    substance.grind();
}

int main() {
    Fruit apple("apple");
    Fruit orange("orange");
    Spice coriander("coriander");
    Wood oak("oak");

    // Test the generalized grind function
    grind(apple);
    grind(orange);
    grind(coriander);
    grind(oak);

    // Test the Grinder class
    Grinder juicer(&apple);
    Grinder spiceGrinder(&coriander);
    Grinder woodChipper(&oak);

    juicer.setLevel(1);
    juicer.process();
    spiceGrinder.process();
    woodChipper.process();

    return 0;
}
