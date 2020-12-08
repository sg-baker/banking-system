#ifndef RECORD_FUNCTIONS_H_INCLUDED
#define RECORD_FUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Adds a record to the database
void read_data(string fileName);

// First shows the number of records in the database,
// then searches the database by record number
void search_data(string fileName);

// First shows the number of records in the file,
// then edits the record given by record number
void edit_record(string fileName);

// First shows the number of records in the file,
// then asks for the number of a record to delete
void delete_record(string fileName);

// Prints the banking menu
void print_menu();

#endif // RECORD_FUNCTIONS_H_INCLUDED
