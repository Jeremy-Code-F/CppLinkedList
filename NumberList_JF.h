/*
Student: Jeremy Farmer
Class: CSC 234-201
Assignment: Chapter 17 Homework
Purpose: This project makes a class for representing a singly linked list 
with some functions, and a driver program to test the classes' functionality 
*/

#pragma once

struct node {
	int data; 
	node *next;
};

class NumberList {
public:
	node * head, *tail;//Pointer to both head and tail nodes


	NumberList();//Constructor

	//Function to append a node based on a number
	void AppendNode(int num);

	//Function to display the list
	void DisplayList();

	//Function to insert a node at a position
	void InsertNode(int insertPosition, int nodeData);


	/*Deletes a node at the selected index
	IMPORTANT THIS IS ZERO BASED*/
	void DeleteNode(int positionIndex);

	//Function to sort the whole list
	void SortList();

	//Function to remove duplicates
	void RemoveDuplicates();


};