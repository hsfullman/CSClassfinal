// BTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class BTree
{
public:
	int data;
	BTree* leftNode;
	BTree* rightNode;
	BTree* rootNode;
	BTree(int dataElement) {
		data = dataElement;
	}
};

int counter = 1;
void insert(int dataElement, BTree* rootNode) {
	//first assume it's empty list
	//assign sides to data
	//do counter to show levels
		if (rootNode->data < dataElement && !rootNode->rightNode) { //right side of tree is empty
			BTree* newNode = new BTree(dataElement); // creat local pointer
			rootNode->rightNode = newNode; // copy pointer to global variable "rootNode->rightNode" so it stays in memory
			cout << "\nLevel " << counter << " Right Side:" << newNode->data;
		}
		else if (rootNode->data < dataElement && rootNode->rightNode) {
			counter = counter + 1;
			insert(dataElement, rootNode->rightNode);//"->" like *(rootNode.rightNode)

		}
		if (rootNode->data > dataElement && !rootNode->leftNode) {
			BTree *newNode = new BTree(dataElement);
			rootNode->leftNode = newNode;
			cout << "\nLevel " << counter << " Left Side:" << newNode->data;
		}
		else if (rootNode->data > dataElement && rootNode->leftNode) {
			counter = counter + 1;
			insert(dataElement, rootNode->leftNode);
		}
};

bool Search(struct BTree* rootNode, int dataElement)
{ 
	if (rootNode == NULL) {
		cout << "\nNot found";
		return false;
	}
	if (rootNode != NULL && dataElement > rootNode->data) {
		Search(rootNode->rightNode, dataElement);
	}
	else if (rootNode != NULL && dataElement < rootNode->data) {
		Search(rootNode->leftNode, dataElement);
	}
	else if (dataElement == rootNode->data) {
		cout << "\nFound";
		return true; // if the key is found return 1 
	}
}
int findSmallestNode(BTree* rootNode) {
	if (rootNode == NULL) {
		cout << "The tree is empty";
		return -1000;
	}
	else {
		if (rootNode->leftNode != NULL) {
			return findSmallestNode(rootNode->leftNode);
		}
		else {
			return rootNode->data;
		}
	}
}
void deleteNode(int dataElement, BTree* rootNode) {

	if (rootNode != NULL) {
		if (rootNode->data == dataElement) {
			BTree* Pdelete = rootNode;
			int rootData = rootNode->data;
			int smallestRightSubTree;
			//no children
			if (rootNode->leftNode == NULL && rootNode->rightNode == NULL) {
				rootNode = NULL;
				delete Pdelete;
				cout << "\nThe node with data element " << rootData << " was deleted.\n";
			}
			//1 child
			else if (rootNode->leftNode == NULL && rootNode->rightNode != NULL) {
				rootNode = rootNode->rightNode;
				Pdelete->rightNode = NULL;
				delete Pdelete;
				cout << "The root node with data element " << rootData << " was deleted. The new root data element contains " << rootNode->data << "\n";
			}
			else if (rootNode->rightNode == NULL && rootNode->leftNode != NULL) {
				rootNode = rootNode->leftNode;
				Pdelete->leftNode = NULL;
				delete Pdelete;
				cout << "\nThe root node with data element " << rootData << " was deleted. The new root data element contains " << rootNode->data << "\n";
			}
			//2 children
			else {
				smallestRightSubTree = findSmallestNode(rootNode->rightNode);
				deleteNode(smallestRightSubTree, rootNode);
				rootNode->data = smallestRightSubTree;
				cout << "\nThe root node with data element " << rootData << " was overwritten with data element " << rootNode->data << "\n";
			}
		}
		else if (rootNode->data != dataElement) {
			if (dataElement < rootNode->data && rootNode->leftNode != NULL) {
				deleteNode(dataElement, rootNode->leftNode);
			}
			if (dataElement > rootNode->data && rootNode->rightNode != NULL) {
					deleteNode(dataElement, rootNode->rightNode);
			}
		}
		else {
			cout << "Data element " << dataElement << " not found in tree\n";
		}
	}
}

int main()
{
	BTree root(8);
	BTree* rootNode = &root;
	cout << root.data;
	insert(5, rootNode);
	counter = 1;
	insert(10, rootNode);
	counter = 1;
	insert(7, rootNode);
	counter = 1;
	insert(2, rootNode);
	counter = 1;
	insert(1, rootNode);
	counter = 1;
	insert(9, rootNode);
	counter = 1;
	insert(11, rootNode);
	Search(rootNode, 7);
	deleteNode(5, rootNode);
	
	
	/*
	//create root
	BTree rootNode(8);
	BTree node2(5); // the static way -- ideally should make a function
	rootNode.leftNode = &node2;
	BTree node3(2);
	node2.leftNode = &node3;
	BTree node4(2);
	node3.leftNode = &node4;
	BTree node5(7);
	node2.rightNode = &node5;
	BTree node6(10);
	rootNode.rightNode = &node6;
	BTree node7(9);
	node6.leftNode = &node7;
	BTree node8(11);
	node6.rightNode = &node8;
	*/

};


	// print the tree
	/*
	cout << "            " << rootNode.data;
	BTree newnode2 = *(rootNode.leftNode);
	cout << "\n\n      " << newnode2.data;
	BTree newnode5 = *(rootNode.rightNode);
	cout << "          " << newnode5.data;
	BTree newnode3 = *(newnode2.leftNode);
	cout << "\n\n  " << newnode3.data;
	BTree newnode4 = *(newnode2.rightNode);
	cout << "     " << newnode4.data;
	BTree newnode6 = *(newnode5.leftNode);
	cout << "     " << newnode6.data;
	BTree newnode7 = *(newnode5.rightNode);
	cout << "      " << newnode7.data;
	BTree newnode8 = *(newnode3.leftNode);
	cout << "\n\n" << newnode8.data;
	*/

	//insert function

