#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//list of names for the creatures
vector<string> names = {"Bob", "Alice", "William", "Mary", "Mark", "James", "Susan"};

class Creature {
public:
	Creature(string);
	void introduce();
	string getName();
private:
	string m_name;
};

class Farm {
public:
	Farm(int numCreatures = 0); //Farm empty by default
	~Farm();
	void rollCall();
	void populate(int);
private:
	vector<Creature*> m_population; //unnecessary but shows what I learned from the chapter
};

int main() {
	srand(time(0));

	//Create 5 randomly named creatures in the farm
	Farm creatureFarm(5);
	creatureFarm.rollCall();

	return 0;
}

Creature::Creature(string name) : m_name(name){
	introduce();
}

void Creature::introduce() {
	cout << "Hi! My name is " << m_name << "." << endl;
}

string Creature::getName() {
	return m_name;
}

void Farm::populate(int numCreatures) {
	for (int x = 0; x < numCreatures; x++) {
		//push a pointer of a new creature on the heap and pass a randomly
		//selected name to the constructor
		m_population.push_back(new Creature(names[rand() % names.size()]));
	}
}

//iterate through all creatures in the farm, have them give their name and
// address on the heap
void Farm::rollCall() {
	for (int x = 0; x < m_population.size(); x++) {
		cout << m_population[x]->getName() << " at pen " << m_population[x];
		cout << " here!" << endl;
	}
}

Farm::Farm(int numCreatures) {
	populate(numCreatures);
}

Farm::~Farm() {
	//iterate through creatures on farm and have them say bye before freeing
	// up their heap memory
	for (int x = 0; x < m_population.size(); x++) {
		cout << m_population[x]->getName() << ": 'Bye!'" << endl;
		delete m_population[x];
	}
}
