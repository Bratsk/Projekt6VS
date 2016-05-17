#include "PointSet.h"

#include <iostream>
#include <fstream>

PointSet::PointSet(int n) :
	size(n),
	nodes(),
	nodeDistanceMatrix(new double*[size])
{
	for (int i = 0; i < size; i++)
		nodeDistanceMatrix[i] = new double[size];
}

PointSet::~PointSet(void)
{
	for (int i = 0; i < size; i++)
		delete[] nodeDistanceMatrix[i];
	delete[] nodeDistanceMatrix;
}

int PointSet::getSize() const
{
	return size;
}

double PointSet::getLength(const int i, const int j) const
{
	try //check bounds
	{
		if (0 > i || i > size - 1)
			throw i;
		if (0 > j || j > size - 1)
			throw j;
	}
	catch(const int i)
	{
		char b;
		std::cout << "index out of bound " << i <<  std::endl;
		std::cout << "Press ENTER to continue" << std::endl;
		std::cin.get();
		exit(4);
	}
	return nodeDistanceMatrix[i][j];
}

Node PointSet::getNode(const int index) const
{
	return nodes[index];
}

void PointSet::readVerticesFromFile(void)
{
	//open input stream
	std::fstream ifile;
	ifile.open("komiwojazer.dat", std::ios::in);
	//read next node from file
	for (int i = 0; i < size; i++)
	{
		int position;
		int x;
		int y;
		ifile >> position >> x >> y;
		Node v(position, x, y);
		nodes.push_back(v);
	}
	ifile.close();
	return;
}

void PointSet::calculateDistances(void)
{
	typedef std::vector<Node>::size_type size_type;
	for (size_type i = 0; i < nodes.size(); i++)
	{
		for (size_type j = i; j < nodes.size(); j++)
		{
			//calculate x and y distance between two nodes
			int deltaX = nodes[j].getX() - nodes[i].getX();
			int deltaY = nodes[j].getY() - nodes[i].getY();
			//calculate distance
			nodeDistanceMatrix[i][j] = nodeDistanceMatrix[j][i]
				= sqrt(deltaX * deltaX + deltaY * deltaY);
		}
	}
	return;
}

