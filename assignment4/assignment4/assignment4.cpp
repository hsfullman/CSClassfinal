// assignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int dataElement) {
		data = dataElement;
		next = NULL;
	}
};

class Stack {
public:
	Node* top;
	Stack() {
		top = NULL;
	}
	void push(int data) {
		Node* temp = new Node(data);
		temp->data = data;
		if (top == NULL) {
			temp->next = NULL;
		}
		else {
			temp->next = top;
		}
		top = temp;
	}
	void pop() {
		class Node* temp;
		if (top == NULL) {
			cout << "Stack underflow\n";
		}
		else {
			temp = top;
			top = top->next;
			temp->next = NULL;
			free(temp);
		}
	}
	int getTop() {
		return top->data;
	}
	void displayStack()
	{
		Node* temp = top;
		while (temp->next != NULL)
		{
			std::cout << temp->data << "\n";
			temp = temp->next;
		}
		//get the last one at the top
		std::cout << temp->data << "\n";
	}
};

int main()
{
	Stack stack;
	Node* top = NULL;
	stack.push(5);
	stack.push(3);
	stack.push(9);
	stack.displayStack();
	stack.pop();
	stack.displayStack();
}


