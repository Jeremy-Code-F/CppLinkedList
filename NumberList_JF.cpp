/*
Student: Jeremy Farmer
Class: CSC 234-201
Assignment: Chapter 17 Homework
Purpose: This project makes a class for representing a singly linked list
with some functions, and a driver program to test the classes' functionality
*/

#include "NumberList_JF.h"
#include <iostream>
#include<string>

using namespace std;

//Default Constructor
NumberList::NumberList() {
	head = NULL;
	tail = NULL;
};


/*Append a new node with the value passed to the method (num) to the end of the linked list*/
void NumberList::AppendNode(int num) {
	node *newNode = new node;
	newNode->data = num;
	newNode->next = NULL;

	//If list isn't made yet set the 'newnode' as the head and tail
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		newNode = NULL;
	}
	else { //Otherwise add it to the end of the linked list
		tail->next = newNode;
		tail = newNode;
	}

	return;
}

/*Member function to loop and display the linked list*/
void NumberList::DisplayList() {
	node *tempNode = new node;
	tempNode = head;
	
	while (tempNode != NULL) {
		cout << tempNode->data << ", ";
		tempNode = tempNode->next;
	}
}

/*Deletes a node at the selected index
IMPORTANT THIS IS ZERO BASED*/
void NumberList::DeleteNode(int positionIndex) {

	//Get two node pointers one for the current Node we are on
	//and one for the node before the current node
	node *currentNode = new node;
	node *previousNode = new node;

	

	//Get the first node
	currentNode = head;
	
	//If head is needing to be deleted
	if (positionIndex == 0) {
		head = currentNode->next;//Set head equal to the second node in the linked list
	}
	else {//Otherwise loop until we get to the position to delete
		for (int i = 0; i < positionIndex; i++) {

			previousNode = currentNode;
			currentNode = currentNode->next;

		}
		previousNode->next = currentNode->next;// Skip over an element so it is no longer included
	}

}


/*Method to insert a node at x position in the linked list*/
void NumberList::InsertNode(int insertPosition, int nodeData) {
	node *previousNode = new node;
	node *currentNode = new node;
	node *newNode = new node;

	currentNode = head;

	//Loop until we get to the insert position
	for (int i = 0; i < insertPosition; i++) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	newNode->data = nodeData;//Set the new nodes data to what was passed into the function
	previousNode->next = newNode; //Add the new node after the previous node
	newNode->next = currentNode;//Setup the newNode's 'nextNode' value

}



/*Method to remove the duplicates in the list*/
void NumberList::RemoveDuplicates() {
	node *currentNode = new node;
	currentNode = head;

	//Nodes setup to 
	node *currentHead = new node;
	node *currentTail = new node;

	//While node is valid value
	while (currentNode) {
		currentHead = currentNode->next;
		currentTail = currentNode;
		while (currentHead) {

			//If the next node's data matches this nodes data
			if (currentHead->data == currentNode->data) {
				currentTail->next = currentHead->next;//Remove from linked list
			}
			else {
				currentTail = currentTail->next;//Move to the next node
				
			}
			currentHead = currentHead->next;//Move to the next node

		}
		currentNode = currentNode->next;//Move to the next node
	}
}


/*Function that sorts the linked list  
KNOWN BUG: This function leaves the first number out of order
call the function again to resolve until further notice*/
void NumberList::SortList() {
	node *currentNode = new node;
	bool sortedOnce = false;

	//Setting up variables
	currentNode = head; int temp;
	
	//Keep getting the next node until null
	while (currentNode != NULL) {

		//If the next is going to be null break out of the function
		if (currentNode->next == NULL) {
			return;
		}

		//If the current node is larger than the next swap the current and next node's values
		if (currentNode->data > currentNode->next->data) {
		
			temp = currentNode->next->data;
			currentNode->next->data = currentNode->data;
			currentNode->data = temp;
			currentNode = head;
		}
		currentNode = currentNode->next;//Move to the next node in the list
	}

	
}