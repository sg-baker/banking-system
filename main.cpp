// By Samuel Baker, Created 12/3/2020, Last Modified 12/3/2020

#include "record_functions.h"


#include <fstream>
#include <string>
#include <iostream>

const string fileName = "records.txt";

int main()
{
    int choice;
    bool quit = false;
    cout << "Welcome to the BBS (Baker Banking System) Menu!" << endl;
    print_menu();
    while (!quit) {
        cin >> choice;
        switch(choice) {
            case 1 :
                read_data(fileName);
                break;
            case 2 :
                search_data(fileName);
                break;
            case 3 :
                edit_record(fileName);
                break;
            case 4 :
                delete_record(fileName);
                break;
            case 5 :
                quit = true;
                break;
            default :
                cout << "Please enter a valid command." << endl;
        }

        if (!quit) {
            print_menu();
        }
    }


return 0;
}
