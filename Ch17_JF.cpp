/*
Student: Jeremy Farmer
Class: CSC 234-201
Assignment: Chapter 17 Homework
Purpose: This project makes a class for representing a singly linked list
with some functions, and a driver program to test the classes' functionality
*/

#include<iostream>
#include<string>
#include "NumberList_JF.h"

using namespace std;

int main() {
	NumberList myList; // a linked list of integers

					   // these integers will be used to test the linked list
	static const int SIZE = 5;
	static const int sourceList[] = { 200, 42, 87, 301, 22 };

	//
	// test NumberList::appendNode
	//
	cout << "Appending sourceList to the linked list\n" << endl;

	for (int i = 0; i < SIZE; i++)
		myList.AppendNode(sourceList[i]);

	myList.DisplayList();  // show the list

	cout << "Appending sourceList (again) to the linked list\n" << endl;
	for (int i = 0; i < SIZE; i++)
		myList.AppendNode(sourceList[i]);

	myList.DisplayList();   // show the list

						  //
						  // test NumberList::inserNode
						  //
	cout << "Inserting sourceList into linked list\n" << endl;
	for (int i = 0; i < SIZE; i++)
		myList.InsertNode(i, sourceList[i]);

	myList.DisplayList();   // show the list

						  //
						  // test NumberList::deleteNode
						  //
	cout << "deleting at index 2" << endl;
	myList.DeleteNode(2);

	myList.DisplayList();   // show the list

						  //
						  // test NumberList::sort
						  //
	cout << "Sorting in ascending order\n" << endl;
	myList.SortList();
	myList.SortList();

	myList.DisplayList();   // show the list

						  //
						  // test NumberList::deleteDuplicates
						  //
	cout << "Deleting duplicates\n" << endl;
	myList.RemoveDuplicates();
	myList.SortList();	//Sort again in case of any issues from Removing Duplicates
	myList.DisplayList();  // show the list

						  // finished
	system("pause");

	return 0;
}