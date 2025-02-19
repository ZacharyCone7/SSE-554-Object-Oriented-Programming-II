#include <iostream>
#include <string>

using namespace std;

class Substance {
public:
	virtual void grind() = 0;
	virtual void chunk() = 0;
	virtual ~Substance() {}

};

class Fruit:public Substance
{
	public:
		string name;
		Fruit(string name = "apple")
		{
			this->name = name;
		}
		void grind() override
		{
			cout << this->name << " juice was made!" << endl;
		}
		void chunk() override
		{
			cout << "lumpy " << this->name << " juice was made!" << endl;
		}
};

class Spice:public Substance
{
public:
	string name;
	Spice(string name = "coriander")
	{
		this->name = name;
	}
	void grind()
	{
		cout << this->name << "powder was made!" << endl;
	}
	// Code for Fruit, Spice, and Wood classes
	template <class T>
	void grind(T substance)
	{
		substance.grind();
	}
	int main()
	{
		// Create some substances to test
		Fruit apple = Fruit("apple");
		Fruit orange = Fruit("orange");
		Spice coriander = Spice("coriander");
		Wood oak = Wood("oak");
		// Test the templated function
		grind<Fruit>(apple);
		grind<Fruit>(orange);
		grind<Spice>(coriander);
		grind<Wood>(oak);
		return 0;
	}
	// Code for Fruit, Spice, and Wood classes
// A templated grinder class
	template <class T>
	class Grinder
	{
	public:
		T substance;
		int level;
		Grinder(T substance)
		{
			this->substance = substance;
			this->level = 0;
		}
		void setLevel(int level)
		{
			this->level = level;
		}
		void fill(T substance)
		{
			this->substance = substance;
		}
		void process()
		{
			if (this->level == 0)
			{
				this->substance.grind();
			}
			else if (this->level == 1)
			{
				this->substance.chunk();
			}
		}
	};
	int main()
	{
		// Create some substances to test
		Fruit apple = Fruit("apple");
		Spice coriander = Spice("coriander");
		Wood oak = Wood("oak");
		// Create some templated grinders
		Grinder<Fruit> juicer = Grinder<Fruit>(apple);
		Grinder<Spice> spiceGrinder = Grinder<Spice>(coriander);
		Grinder<Wood> woodChipper = Grinder<Wood>(oak);
		// Test the templated classes
		juicer.setLevel(1);
		juicer.process();
		spiceGrinder.process();
		woodChipper.process();
		return 0;
	}