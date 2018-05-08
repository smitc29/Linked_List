//Author: Chris Smith
//Date: 3/2/2015
//Here to implement header functions

#include "list.h"
#include "iostream"
#include "Node.h"

Node::Node()
{
	data = NULL;
	next = NULL;
	last = NULL;
	return;
}

Node::Node(char *sam)
{
	data = _strdup(sam);
	next = NULL;
	return;
}

Node::~Node()
{
	return;
}

void Node::print()
{
	cout << data;
	return;
}