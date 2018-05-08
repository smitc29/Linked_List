#include "list.h"
#include "Node.h"
#include "iostream"
#include "iostream"
using namespace std;

//Puts NULL ptr in head
//Author: Christopher Smith, Date: March 4 2015
list::list()
{
	head = new Node;
	head->next = head->last = head;
	return;
}

//Needs to traverse list deallocating all the nodes
list::~list()
{
	while (!empty())
	{
		removeFront();
	}
	return;
}

bool list::empty()
{
	if (head->next == head)
		return true;
	else
		return false;
	

}

bool list::full()
{
	return false;
}

//Inserts a cstring at the front of the Linked List
//Returns true if successful, false in failure
//Author: Christopher Smith, Date: March 4 2015
bool list::insertFront(char *s)
{
	Node *ptr;
	if (full())
	{
		cerr << "\n Tried to insert " << s << " into a full list...Force Exit.";
		exit(-1);//-1 means list full
	}
	//make new node
	ptr = new Node;
	//put data into it
	ptr->data = _strdup(s);

	//Set next ptr to point to where head directed
	ptr->next = head->next;
	ptr->last = head;
	head->next->last = ptr;
	head = ptr;
	return true;
}

bool list::insertBack(char *s)
{
	Node *ptr;
	if (full())
	{
		cerr << "\n Tried to insert " << s << " into a full list...Force Exit.";
		exit(-1);//-1 means list full
	}
	//make new node
	ptr = new Node;
	
	ptr->data = _strdup(s);

	//Set next ptr to point to where head directed
	ptr->next = head;
	ptr->last = head->last;
	head->last->next = ptr;
	head->last = ptr;
	
	return true;
}

//returns whether a string is in the list or not
bool list::find(char* s)
{
	Node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		if (strcmp(ptr->data, s))
		{
			ptr = ptr->next;
		}
		else
		{
			break;
		}
	}

	if (ptr == NULL)
		return false;
	else
		return true;
}

//removes node in front of list
char *list::removeFront()
{
	Node *ptr;
	char *result;

	if (empty())
	{
		cout << "Removing from an empty list... exiting. \n ";
		exit(13);
	}

	ptr = head->next;
	head->next = head->next->next;
	head->next->last = head;
	result = ptr->data;

	delete ptr;
	return result;
}

//removes node in back of list
char *list::removeBack()
{
	Node *ptr;
	char *retval;
	ptr = head->last;
	if (empty())//0 elements
	{
		cout << "\n Removing from an empty list...exiting.";
		exit(13);
	}
	else 
	{
		ptr = head->last;
		head->last = head->last->last;
		head->last->next = head;

		delete ptr;
	}
	return retval;
}

//removes specific element user has selected
bool list::removeElement(char*)
{
	return false;
}

//inerts after a specific element given by user; if fail, adds to end
bool list::insertAfter(char *data, char *after)
{
	return false;
}

void list::print()
{
	int n = 1;
	Node *ptr;
	ptr = head;
	if (ptr == NULL)
	{
		cout << "\n List is empty.";
	}
	else
	{
		while (ptr != NULL)
		{
			cout << "\n " << n++ << ".  ";
			ptr->print();
			ptr = ptr->next;
		}

	}
	return;
}
