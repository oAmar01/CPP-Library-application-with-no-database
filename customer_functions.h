#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include "classes.cpp"
#include "book_functions.h"
#include <vector>

vector<customer> vectorCustomer;
string customerMake, customerName, customerJmb, customerAssignBook;


void createCustomer()
{
    bool userExists = false;
    bool jmbExists = false;
    cout << "Please enter the username of your new user" << endl;
    cin >> customerMake;

    for (int i = 0; i < vectorCustomer.size(); i++)
    {
        if (customerMake == vectorCustomer[i].getCustomerUsername())
        {
            cout << "Username is taken, please try again." << endl;
            userExists = true;
            Sleep(2000);
        }
    }

    if (userExists != true)
    {

        cin.sync(); // discard unread characters
        cout << "Please enter the name of your new user" << endl;
        getline(cin, customerName);
        cout << "Please enter the JMB of your new user(must contain only 13 numbers" << endl;
        int counterForJMB = 0;
        bool JMBisDigit = false;
        do
        {
            do{

                cin >> customerJmb;
           jmbExists=false;
                    for(int i=0; i<vectorCustomer.size(); i++){
            if(customerJmb == vectorCustomer[i].getCustomerJMB()){

                jmbExists=true;
                cout << "JMB already exists please try again: ";

            }
        }}while(jmbExists == true);


            for (int j = 0; j < 13; j++)
            {
                if (isdigit(customerJmb[j]))
                {
                    counterForJMB++;
                }
            }
            if (counterForJMB == 13)
            {
                JMBisDigit = true;
            }
            else
            {
                cout << "Invalid JMB (Must contain only 13 digits), please try JMB again: ";
                counterForJMB = 0;
            }
        } while (JMBisDigit != true || jmbExists == true);

        cout << "Please enter the category the customer belongs to (1 for Regular, 2 for Premium): ";
        string inputForCategory = "0";
        bool whileCategoryIncorrect;
        do
        {
            cin >> inputForCategory;
            if (inputForCategory == "1")
            {
                cout << "Category for customer set as Regular" << endl;
                inputForCategory = "Regular";
                whileCategoryIncorrect = true;
            }
            else if (inputForCategory == "2")
            {
                cout << "Category for customer set as Premium" << endl;
                inputForCategory = "Premium";
                whileCategoryIncorrect = true;
            }
            else
            {
                cout << "Incorrect pick, please try again" << endl;
                whileCategoryIncorrect = false;
            }
        } while (whileCategoryIncorrect == false);
        customer newCustomer = customer(customerMake, customerName, customerJmb, inputForCategory);
        vectorCustomer.push_back(newCustomer);
    }
}

void readCustomer()
{
    for (int i = 0; i < vectorCustomer.size(); i++)
    {
        cout << "Username:    " << vectorCustomer[i].getCustomerUsername() << endl;
        cout << "Name:        " << vectorCustomer[i].getCustomerName() << endl;
        cout << "JMB:         " << vectorCustomer[i].getCustomerJMB() << endl;
        cout << "Category:    " << vectorCustomer[i].getCustomerCategory() << endl;
        cout << "Rented Book: " << vectorCustomer[i].getCustomerRentedBook() << endl;
        cout << "------------------------------" << endl;
    }
}

void updateCustomer()
{
    string editUser;
    cout << "Please enter the username of the User you want to update, enter cancel to exit: " << endl;
    cin >> editUser;
    if (editUser != "cancel")
    {
        for (int i = 0; i < vectorCustomer.size(); i++)
        {
            if (vectorCustomer[i].getCustomerUsername() == editUser)
            {
                cout << "Please enter the new username of your User" << endl;
                cin >> customerMake;
                cin.sync(); // discard unread characters
                cout << "Please enter the name of your new user" << endl;
                getline(cin, customerName);
                cout << "Please enter the new JMB of your User" << endl;
                int counterForJMB = 0;
                bool JMBisDigit = false;
                do
                {

                    cin >> customerJmb;
                    counterForJMB = 0;
                    for (int j = 0; j < 13; j++)
                    {
                        if (isdigit(customerJmb[j]))
                        {
                            counterForJMB++;
                        }
                    }
                    if (counterForJMB == 13)
                    {
                        JMBisDigit = true;
                    }
                    else
                    {
                        cout << "Invalid JMB (Must contain only 13 digits), please try JMB again: ";
                    }
                } while (JMBisDigit != true);
                cout << "Please enter the category the customer belongs to (1 for Regular, 2 for Premium): ";
                string inputForCategory = "0";
                bool whileCategoryIncorrect;
                do
                {
                    cin >> inputForCategory;
                    if (inputForCategory == "1")
                    {
                        cout << "Category for customer set as Regular" << endl;
                        inputForCategory = "Regular";
                        whileCategoryIncorrect = true;
                    }
                    else if (inputForCategory == "2")
                    {
                        cout << "Category for customer set as Premium" << endl;
                        inputForCategory = "Premium";
                        whileCategoryIncorrect = true;
                    }
                    else
                    {
                        cout << "Incorrect pick, please try again" << endl;
                        whileCategoryIncorrect = false;
                    }
                } while (whileCategoryIncorrect == false);

                vectorCustomer[i].setCustomerUsername(customerMake);
                vectorCustomer[i].setCustomerName(customerName);
                vectorCustomer[i].setCustomerJMB(customerJmb);
                vectorCustomer[i].setCustomerCategory(inputForCategory);
            }
        }
    }
}

void deleteCustomer()
{
    string delUser;
    bool deleteConfirm;
    cout << "Please enter the username of the User you want to delete: " << endl;
    cin >> delUser;
    for (int i = 0; i < vectorCustomer.size(); i++)
    {
        if (vectorCustomer[i].getCustomerUsername() == delUser)
        {
            vectorCustomer.erase(vectorCustomer.begin() + i);
            deleteConfirm = true;
        }
    }
    if (deleteConfirm != true)
    {
        cout << "Unable to delete user, user does not exist." << endl;
        Sleep(2000);
    }
    else
    {
        cout << "User successfully deleted." << endl;
        Sleep(2000);
    }
}

void rentABook(){



    string rentToCustomer;
    cout << "Please enter the username of the customer you want to rent a book to: " << endl;
    cout << "----------------------------------------------------------------------" << endl;
    readCustomer();
    cin >> rentToCustomer;
    system("CLS");
    for (int i = 0; i < vectorCustomer.size(); i++)
        {
            if(rentToCustomer == vectorCustomer[i].getCustomerUsername()){
                cout << "Please enter BookID of book you want to rent for chosen customer: " << endl;
                for(int k=0; k<vectorBooks.size(); k++){
                    cout << "Book ID:    " << vectorBooks[k].getBookID() << endl;
                    cout << "Book Name:  " << vectorBooks[k].getBookName() << endl;
                    cout << "Book Genre: " << vectorBooks[k].getBookGenre() << endl;
                    cout << "Book Shelf: " << vectorBooks[k].getBookShelf() << endl;
                    cout << "-----------------------------------------------" << endl;
        }
            string bookIdForRent;
        cin >> bookIdForRent ;
        for (int j = 0; j < vectorBooks.size(); j++){
                if (bookIdForRent == vectorBooks[j].getBookID()){
                vectorCustomer[i].setCustomerRentedBook(vectorBooks[j].getBookName());
        }

            }
        }

}
}
void crudMenuCustomer()
{

    int choice = 0;

    do
    {
        cout << "Welcome to the User menu, please select a number and press Enter" << endl;
        cout << "1. Create a customer user." << endl
             << "2. Read customer info." << endl
             << "3. Update customer info." << endl
             << "4. Delete customer." << endl
             << "5. Rent a book for a user." << endl
             << "6. Back." << endl;

        cin >> choice;
        // input validation
        while (cin.fail())
        {
            cin.clear();         // clear input buffer to restore cin to a usable state
            cin.ignore(5, '\n'); // ignore last input
            cout << "That is not a valid option, please try again." << endl;
            Sleep(1000);
            system("CLS");
            crudMenuCustomer();
            cin >> choice;
        }

        switch (choice)
        {
        case 1: // Create
            system("CLS");
            createCustomer();
            system("CLS");

            break;

        case 2:
        { // Read
            system("CLS");
            readCustomer();
            break;
        }
        case 3: // Update
            system("CLS");
            readCustomer();
            updateCustomer();
            break;

        case 4: // Delete
            system("CLS");
            readCustomer();
            deleteCustomer();
            system("CLS");
            break;
        case 5://rent book
            system("CLS");
            rentABook();
            break;
        case 6: // Back
            choice = 6;
            system("CLS");
            break;

        default: // None of the above

            cout << "That is not a valid option, please try again." << endl;
            choice = 0;
            Sleep(1000);
            system("CLS");
            break;
        }
    } while (choice != 6);
}
