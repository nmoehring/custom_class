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
	Farm(int);
	~Farm();
	void rollCall();
	void populate(int);
private:
	vector<Creature*> m_population;
};

int main() {
	srand(time(0));

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
		m_population.push_back(new Creature(names[rand() % names.size()]));
	}
}

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
	for (int x = 0; x < m_population.size(); x++) {
		cout << m_population[x]->getName() << ": 'Bye!'" << endl;
		delete m_population[x];
	}
}
