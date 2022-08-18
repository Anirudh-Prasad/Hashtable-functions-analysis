// --------------------------- HashTable.h ------------------------------------
// Anirudh Prasad, CSS 343 A
// Created: 3/8/2020
// Last Modified: 3/13/2020
// ----------------------------------------------------------------------------
// Purpose: This is the header file for a hash table that utilizes the 
// DJB2, SDBM, and Lose-Lose hashing functions.
// ----------------------------------------------------------------------------
// This header file describes the functions of this hash table, which
// implement two structs and three different hashing functions. These hashing
// functions allow data to be stored in tha location dependent on the contents
// of the data.
// ----------------------------------------------------------------------------

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class HashTable
{

private:

	//Node struct that hold string data and pointer to next Node in list
	struct Node {
		//data item
		string data;
		//pointer to next Node
		Node* next;
		//default constructor
		Node(string data) : data{ data }, next{ NULL }{}
	};

	//Linked list structure for HashTable
	struct HashList {
		//Head of the list
		Node* head;
		//length of the list
		int chainLength;
		//default constructor
		HashList() : head{ NULL }, chainLength{ 0 } {}
		//Linked list destructor
		~HashList() {
			Node* curr = head;
			while (curr != NULL) {
				Node* nxtNode = curr->next;
				delete curr;
				curr = nxtNode;
			}
		}
	};

	//stores the linked lists which store the data
	vector<HashList> table;
	//size of the table, set value
	const int tableSize = 4177;

public:
	//default constructor
	HashTable();
	//adds string to table
	void addToTable(string str);
	//Creates hash value to provide location to store data
	unsigned long hashFunction(string str);
	//Prints contents of the table at each index
	void outputTable();
};

#endif

