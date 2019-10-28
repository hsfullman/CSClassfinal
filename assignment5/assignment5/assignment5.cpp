// assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <assert.h> 
#include<string>

using namespace std;
// implementation of linked list
class Node {
public:
	int data;
	Node* next = NULL;
	Node() {
	}
};

class arrayList {
public:
	Node* head = NULL;
};

class Graph
{
public:

	int num;
	arrayList* array;

	Graph(int num) {
		this->num = num;
		array = new arrayList[num]; // total vertices
		for (int i = 0; i < num; i++) {
			array[i].head = NULL; //linking head of all vertices to NULL
		}
	}

	void insertEdge(int src, int dest) {
		// add edge from src to dest; new node added to array list of src
		Node* newNode = new Node();
		newNode->data = dest;
		newNode->next = NULL;
	
		newNode->next = array[src].head;
		array[src].head = newNode;
	
		// also add edge from dest to src since undirected
		newNode = new Node();
		newNode->data = src;
		newNode->next = NULL;

		newNode->next = array[dest].head;
		array[dest].head = newNode;
	}

	void Print() { //Print all elements in the list
		int i;
		for (i = 0; i < num; i++) {
			Node* temp = array[i].head;
			cout << "Connections from city " << i << endl;
			while (temp) {
				cout << "==>" << temp->data;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};


int main()
{

	Node* head = NULL; //Empty list
	Graph myGraph(8);
	myGraph.insertEdge(0, 1);
	myGraph.insertEdge(0, 2);
	myGraph.insertEdge(1, 2);
	myGraph.insertEdge(1, 5);
	myGraph.insertEdge(2, 3);
	myGraph.insertEdge(2, 4);
	myGraph.insertEdge(3, 6);
	myGraph.insertEdge(4, 5);
	myGraph.insertEdge(5, 6);
	myGraph.insertEdge(5, 7);
	myGraph.insertEdge(6, 7);
	myGraph.Print();
};
