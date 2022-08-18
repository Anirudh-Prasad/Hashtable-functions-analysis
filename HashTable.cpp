// -------------------------- HashTable.cpp -----------------------------------
// Anirudh Prasad, CSS 343 A
// Created: 3/9/2020
// Last Modified: 3/13/2020
// ----------------------------------------------------------------------------
// Purpose: This is the implementation file for a hash table that utilizes the
// DJB2, SDBM, and Lose-Lose hashing functions.
// ----------------------------------------------------------------------------
// This implementation of a hash table stores a linked list of Nodes that each
// contain a data item. The data item is hashed the index based on one of the
// three hashing functions that can be commented and uncommented below. The
// report ultimately found that SDBM was the most effective function for this
// dataset, and so it remains uncommented.
// ----------------------------------------------------------------------------

#include "HashTable.h"

//Default constructor, sets the size of the table to TableSize
HashTable::HashTable()
{
	table.resize(tableSize);
}

//Adds string to the table based on a hashed index
//Also adds to a linked list at the index
void HashTable::addToTable(string str)
{
	int val = hashFunction(str) % tableSize;

	Node* curr = table[val].head;
	while (curr != NULL) 
	{
		curr = curr->next;
	}
	curr = new Node(str);
	table[val].chainLength++;
}

////DJB2 hashing function
////Utilizes bit manipulation and an initial prime number
////Returns hashing value as unsigned long
//unsigned long HashTable::hashFunction(string str)
//{
//	unsigned long hash = 5381;
//	int item;
//
//	for(int i = 0; i < str.length(); ++i)
//	{
//		item = (int)str[i];
//		hash = ((hash << 5) + hash) + item;
//	}
//
//	return hash;
//}

//SDBM hashing function
//Utilizes more intensive bit manipulation, good avalanching
//Returns hashing value as unsigned long
unsigned long HashTable::hashFunction(string str)
{
	unsigned long hash = 0;
	int item;

	for (int i = 0; i < str.length(); ++i) 
	{
		item = (int)str[i];
		hash = item + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}

////Lose-Lose Hashing function
////Simple, but not very effective
////Returns hashing value as unsigned long
//unsigned long HashTable::hashFunction(string str) 
//{
//	unsigned int hash = 0;
//	int item;
//
//	for (int i = 0; i < str.length(); i++) 
//	{
//		item = (int)str[i];
//		hash += item;
//	}
//
//	return hash;
//}

//Prints index and the length of the linked list at that index
void HashTable::outputTable()
{
	for (int i = 0; i < tableSize; i++) 
	{
		cout << "Index: " << i << ", Chain Length: " << table[i].chainLength << endl;
	}
}