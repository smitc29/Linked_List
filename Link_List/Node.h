#pragma once
//Author: Chris Smith
//Date: 3/2/2015

#ifndef __Node_h
#define __Node_h
class Node
{
public:
	Node();
	Node(char*);
	~Node();
	void print();
	friend class list;

private:
	char *data;
	Node *next,*last;
};

#endif // __Node_h