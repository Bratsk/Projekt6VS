#pragma once
#include <iostream>
class Node
{
	friend std::ostream & operator<<(std::ostream & o, const Node & n);
public:
	Node(int position, int x, int y);

	int getPosition(void) const;

	int getX(void) const;

	int getY(void) const;
protected:
	int _number;
	int _x;
	int _y;
};