#pragma once

#include <deque>

#include "Node.h"
#include "PointSet.h"


class Cycle
{
	friend std::ostream & operator<<(std::ostream & o, const Cycle & c);
public:
	/*empty cycle_prim*/
	Cycle();

	/*creating a Cycle out of the given set*/
	explicit Cycle(PointSet const * set);

	/*copy constructor*/
	Cycle(const Cycle & cycle);

	/*assignment operator*/
	Cycle & operator=(const Cycle & cycle);

	Node operator[](const int i) const;

	/*length of cycle_prim*/
	double getLength(void) const;

	int getSize(void) const;

	/*calculate length of cycle_prim*/
	double calculateLength(PointSet const * set);

	void chooseAB(int & a, int & b) const;

	/*creation of new cycle_prim with swapped edges with 2-opt algorithm*/
	Cycle * swapEdges(PointSet const *  set);
protected:
	double length; /* length of cycle_prim */
	std::deque<Node> cycle; /*double ended queue represents
								sequence of nodes*/
};