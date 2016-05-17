#pragma once

#include <vector>

#include "Node.h"

class PointSet
{
public:
	PointSet(int n);

	/*deleting allocated memory*/
	~PointSet();

	int getSize() const;
	/*get length between node i and j*/
	double getLength(const int i, const int j) const;
	/*get node with the index position*/
	Node getNode(const int index) const;

	/* read vertices positions from file*/
	void readVerticesFromFile(void);

	/*calculation of all distances between vertices
	setting up the nodeDistanceMatrix */
	void calculateDistances(void);

protected:
	const int size; /* number of nodes */
	std::vector<Node> nodes; /* vector of vertices with positions*/
	double ** nodeDistanceMatrix; /*matrix with lengths with between
							all vertices with each other*/
};