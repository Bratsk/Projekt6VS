#include "Cycle.h"
#include <random>
#include <iostream>

Cycle::Cycle() :
	length(0),
	cycle()
{
}

Cycle::Cycle(PointSet const *  set) :
	length(0)
{
	int numberNodes = set->getSize();
	//add all nodes to cycle_prim
	for(int i = 0; i < numberNodes; i++)
	{
		Node nextNode = Node(set->getNode(i));
		cycle.push_back(nextNode);
	}
	Node lastNode(set->getNode(0));
	cycle.push_back(lastNode);

	calculateLength(set);
}

Cycle::Cycle(const Cycle& cycle) :
	length(cycle.length),
	cycle(cycle.cycle)
{
}

Cycle & Cycle::operator=(const Cycle& cycle)
{
	this->length = cycle.length;
	this->cycle = cycle.cycle;
	return *this;
}

Node Cycle::operator[](const int i) const
{
	return cycle[i];
}

double Cycle::getLength(void) const
{
	return length;
}

int Cycle::getSize() const
{
	return cycle.size();
}

double Cycle::calculateLength(PointSet const* set)
{
	for (unsigned i = 0; i < cycle.size() - 1; i++) {
		length += set->getLength(cycle[i].getPosition(),
								 cycle[i + 1].getPosition());
	}
	return length;
}

void Cycle::chooseAB(int& a, int& b) const
{
	//choose beginning and end of range
	int begin = 2;
	int end = cycle.size() - 1;
	//initialise uniform random number generator
	std::random_device rand_dev;
	std::default_random_engine generator(rand_dev());
	std::uniform_int_distribution<int> distribution(begin, end);
	//generate numbers until they fit the given condition
	do
	{
		a = distribution(generator);
		b = distribution(generator);
	} while (abs(a - b) < 2 || b < a);
}

Cycle* Cycle::swapEdges(PointSet const *  set)
{
	int begin = 0;
	int end = cycle.size();
	
	//generating two random numbers
	int a, b;
	chooseAB(a, b);
	Cycle * newCycle = new Cycle();

	//shift all nodes till a
	for(int i = begin; i < a - 1; i++)
		newCycle->cycle.push_back(this->cycle[i]);

	//enter values between a and b in reverse order
	for(int i = a, r = 0; i < b + 1; i++, r++)
		newCycle->cycle.push_back(this->cycle[b - r - 1]);

	//move the rest of elements
	for(int i = b; i < end; i++)
		newCycle->cycle.push_back(this->cycle[i]);
	newCycle->calculateLength(set);
	return newCycle;
}

std::ostream& operator<<(std::ostream& o, const Cycle & c)
{
	o << "length:" << c.getLength() << std::endl;
	for(int i = 0; i < c.getSize(); i++)
	{
		o << " - " << c[i];
	}
	o << std::endl;
	return o;
}
