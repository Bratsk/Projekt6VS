#pragma once

#include "Node.h"
//#include <utility>

//typedef std::pair<Node, Node> Vertice;
struct Vertice
{
	Vertice(Node one, Node two, double len) :
		first(one), second(two),
		length(len)
	{}

	Node first;
	Node second;

	double length;
};