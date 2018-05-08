/*
//Program to test Linked Lists
//Author: Chris S.
//Date: March/4/2015

*/

#include "list.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
	list stomach;
	char name[120],food[120];
	bool eating = true;
	bool grass = false;

	cout << "\n Hi there! What is your dog's name?\n ";
	cin.getline(name,119);

	while (eating)
	{
		//eat
		while (!grass)
		{
			cout << "\n What does " << name << " eat?  ";
			cin.getline(food, 119);
			if (!strcmp(food, "grass"))
				break;
			else if (!strcmp(food, "dog food"))
			{
				eating = false;
				break;
			}

			stomach.insertBack(food);

		}


		//barf
		if (!strcmp(food, "grass"))
		{
			cout << "\n " << name << " isn't feeling well..." ;
			while (!stomach.empty())
				{
					cout << "\n " << name << " barfs up " << stomach.removeFront();
				}
			if (stomach.empty())
				cout << "\n " << name << " feels much better now.";
		}
		
	}

	cout << "\n Bah! You have offended " << name << ", and they storm off in anger.\n ";
	return 0;
}

//Output 
