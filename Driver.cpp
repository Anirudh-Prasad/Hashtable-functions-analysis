// --------------------------- Driver.cpp -------------------------------------
// Anirudh Prasad, CSS 343 A
// Created: 3/9/2020
// Last Modified: 3/13/2020
// ----------------------------------------------------------------------------
// Purpose: This is a driver for the HashTable files.
// ----------------------------------------------------------------------------
// This driver opens the text file containing the data and sends the data to 
// the Hash Table to be stored, line by line. The contents of the table are 
// then outputted.
// ----------------------------------------------------------------------------

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	HashTable hash1;
	ifstream myFile;
	myFile.open("phonebook.txt");
	string str;
	while (getline(myFile, str)) {
		hash1.addToTable(str);
	}
	hash1.outputTable();
	myFile.close();
}