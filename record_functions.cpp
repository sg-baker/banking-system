// By Samuel Baker, Created 12/3/2020, Last Modified 12/3/2020

#include "record_functions.h"

// Works
void read_data(string fileName) {
	ofstream outputFile;
	// ios::app opens the file for appending
	outputFile.open(fileName.c_str(), ios::app);
	int accNum;
	string firstName, lastName;
	double balance;

	cout << "Enter Account Number: ";
	cin >> accNum;
	cout << endl;

	cout << "Enter First Name: ";
	cin >> firstName;
	cout << endl;

	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << endl;

	cout << "Enter Balance: ";
	cin >> balance;
	cout << endl;

	outputFile << accNum << " " << firstName << " "
		<< lastName << " " << balance << endl;

	outputFile.close();

	return;
}

// Works
void search_data(string fileName) {
    ifstream inputFile;
    inputFile.open(fileName.c_str());
    // Account Number given by user
    int numKey;
    cout << "Enter Account Number: ";
	cin >> numKey;
	cout << endl;
	// Dummy Variables
	int accNum;
	string firstName, lastName;
	double balance;
	// Linear search loop
	bool found = false;
	while (inputFile >> accNum >> firstName >> lastName >> balance
            && !found) {
        if (numKey == accNum) {
            found = true;
            cout << "Account Holder Name: " << firstName << " " << lastName << endl;
            cout << "Balance: " << balance << endl;
        }
    }

    if (!found) {
        cout << "Account of that number has no record." << endl;
    }
    inputFile.close();
    return;

}
// Works
void edit_record(string fileName) {
    ifstream inputFile;
    ofstream outputFile;
    string n = "n.dat";
    inputFile.open(fileName.c_str());
    outputFile.open(n.c_str());
    // Account Number given by user
    int numKey;
    cout << "Enter Account Number: ";
	cin >> numKey;
	cout << endl;
	// Dummy Variables
	int accNum;
	string firstName, lastName;
	double balance;
	// Linear search loop
	while (inputFile >> accNum >> firstName >> lastName >> balance){
        if (numKey == accNum) {
            cout << "Enter new Balance: " << endl;
            cin >> balance;
        }
        // Outputting edited records
        outputFile << accNum << " " << firstName << " "
		<< lastName << " " << balance << endl;
    }
    inputFile.close();
    outputFile.close();
    // Opening of edited file
    ifstream newFile;
    newFile.open(n.c_str());
    ofstream OGfile;
    OGfile.open(fileName.c_str());
    // Remaking original file
    while (newFile >> accNum >> firstName >> lastName >> balance) {
        OGfile << accNum << " " << firstName << " "
		<< lastName << " " << balance << endl;
    }
    // Closing of both files
    newFile.close();
    OGfile.close();
    return;
}

// Works
void delete_record(string fileName) {
    ifstream inputFile;
    ofstream outputFile;
    string n = "n.dat";
    inputFile.open(fileName.c_str());
    outputFile.open(n.c_str());
    // Account Number given by user
    int numKey;
    cout << "Enter Account Number: ";
	cin >> numKey;
	cout << endl;
	// Dummy Variables
	int accNum;
	string firstName, lastName;
	double balance;
	// Linear search loop
	while (inputFile >> accNum >> firstName >> lastName >> balance){
        // Ignores given account
        if (numKey != accNum) {
            outputFile << accNum << " " << firstName << " "
            << lastName << " " << balance << endl;
        }
    }
    inputFile.close();
    outputFile.close();
    // Opening of edited file
    ifstream newFile;
    newFile.open(n.c_str());
    ofstream OGfile;
    OGfile.open(fileName.c_str());
    // Remaking original file
    while (newFile >> accNum >> firstName >> lastName >> balance) {
        OGfile << accNum << " " << firstName << " "
		<< lastName << " " << balance << endl;
    }
    // Closing of both files
    newFile.close();
    OGfile.close();
    return;
}
// Works
void print_menu() {
    cout << "1 - Add a new Account!" << endl;
    cout << "2 - Search for an Account's balance!" << endl;
    cout << "3 - Edit an existing Account's balance!" << endl;
    cout << "4 - Delete an existing Account!" << endl;
    cout << "5 - Exit this menu." << endl;
    return;
}
