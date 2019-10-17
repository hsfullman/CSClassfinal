// Program2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h> 
#include<string>

using namespace std;
// implementation of linked list
class Node {
public:
	int element;
	// NEW :  You have to assign null value, by default the pointer has no NULL ,  check what is null pointer
	Node* next = NULL;
	Node(int dataElement) {
		element = dataElement;
		next = NULL;
	}
};
// class that contains functions to handle the nodes
class LinkedList
{
public:
	// NEW   same thing for null pointer initalisation
	Node* head = NULL;
	Node* tail = NULL;
	void insert(int dataElement) {
		if (!tail)
		{
			//if list is empty, make a new node
			Node* newNode = new Node(dataElement);
			tail = newNode;
			// NEW You forgot to update head pointer to refer to the first element
			head = newNode;
		}
		else
		{
			//list has items already
			Node* newNode = new Node(dataElement);
			tail->next = newNode;
			tail = newNode;  // NEW  you forgot to update the tail pointer to refer to the last node.
		}
	}
	int getElement(Node* head, int index) {
		int count = 0;
		while (head != NULL)
		{
			if (count == index)
			{
				return ((*head).element);
			}
			count++;
			(*head).next = head;
		}
		//assert(0);
	}

	void Print() { //Print all elements in the list
		while (head) {
			int y = head->element;
			cout << std::to_string(y);
			head = head->next;  // NEW YOU assing the the next pointer to the head instead of the other way around
			if (head)  cout << "==>";
		}
		cout << endl;
	}
};

int main()
{
	
	Node* head = NULL; //Empty list
	int num;
	cout << "Enter list: ";
	LinkedList myList;
	while (cin >> num)
	{
		myList.insert(num);
	};
	myList.Print();
	int index;
	cout << "Enter a position to get element: ";
	cin >> index;
	int result;
	result = myList.getElement(head, index);
};
