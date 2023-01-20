#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h> //For Sleep command
#include <cctype>    //For isdigit command
#include "worker_functions.h"
#include "customer_functions.h"
using namespace std;

void Menu()
{
    cout << "Welcome to the main menu, please select a number and press Enter" << endl;
    cout << "1. Create." << endl
         << "2. Read." << endl
         << "3. Update." << endl
         << "4. Delete." << endl
         << "5. Exit application." << endl;
}

int shutdownSequence()
{
    cout << "Thank you for using LibWizard by Amar Osmic v1.0..." << endl
         << "Shutting down..." << endl;
    Sleep(3000);
    system("CLS");
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    exit(0);
}

int main()
{
    int choice = 0;

    do
    {
        cout << "Welcome to the main menu, please select a section to begin." << endl;
        cout << "1. Workers." << endl
             << "2. Users." << endl
             << "3. Books." << endl
             << "4. Exit application." << endl;

        cin >> choice;
        // input validation
        while (cin.fail())
        {
            cin.clear();         // clear input buffer to restore cin to a usable state
            cin.ignore(5, '\n'); // ignore last input
            cout << "That is not a valid option, please try again." << endl;
            Sleep(1000);
            system("CLS");
            Menu();
            cin >> choice;
        }

        switch (choice)
        {
        case 1: // Workers
            system("CLS");
            crudMenuUser();
            break;

        case 2: // Users
            system("CLS");
            crudMenuCustomer();
            break;

        case 3: // Books

        system("CLS");
            crudMenuBook();
            break;

        case 4: // Exit

            shutdownSequence();

            break;
        default: // None of the above

            cout << "That is not a valid option, please try again." << endl;
            choice = 0;
            Sleep(1000);
            system("CLS");
            break;
        }
    } while (choice != 5);
}
