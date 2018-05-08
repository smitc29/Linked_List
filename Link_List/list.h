//Author: Chris Smith
//Date: 3/2/2015
//Linked list class, uses node class
#pragma once
#ifndef __list_h
#define __list_h

#include "Node.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class list
{
public:
	list();
	~list();
	bool empty();
	bool full();
	bool insertFront(char*);
	bool insertBack(char*);
	bool find(char*);
	char *removeFront();
	char *removeBack();
	bool removeElement(char*);
	bool insertAfter(char *data, char *after);
	void print();

private:
	Node *head; //null if list is empty
};

#endif __list_h