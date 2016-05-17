#include "Node.h"

Node::Node(int position, int x, int y) :
	_number(position),
	_x(x),
	_y(y)
{}

int Node::getPosition(void) const
{
	return _number - 1; // return index
}

int Node::getX(void) const
{
	return _x;
}

int Node::getY(void) const
{
	return _y;
}

std::ostream& operator<<(std::ostream& o, const Node& n)
{
	o << n.getPosition();
	return o;
}
