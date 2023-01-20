#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include "classes.cpp"
#include <vector>

vector<user> vectorUser;
string userMake, name, jmb;

void createUser()
{
    bool userExists = false;
    bool jmbExists = false;
    cout << "Please enter the username of your new user" << endl;

        cin >> userMake;

    for (int i = 0; i < vectorUser.size(); i++)
    {
        if (userMake == vectorUser[i].getUserUsername())
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
        getline(cin, name);
        cout << "Please enter the JMB of your new user(must contain only 13 numbers)" << endl;
        int counterForJMB = 0;
        bool JMBisDigit = false;
        do
        {
           do{
                cin >> jmb;
           jmbExists=false;
                    for(int i=0; i<vectorUser.size(); i++){
            if(jmb == vectorUser[i].getUserJMB()){

                jmbExists=true;
                cout << "JMB already exists please try again: ";

            }
        }}while(jmbExists == true);


            counterForJMB = 0;
            for (int j = 0; j < 13; j++)
            {
                if (isdigit(jmb[j]))
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
                JMBisDigit = false;
            }

        } while (JMBisDigit == false);
        user newUser = user(userMake, name, jmb);
        vectorUser.push_back(newUser);
    }
}

void readUser()
{
    for (int i = 0; i < vectorUser.size(); i++)
    {
        cout << "Username: " << vectorUser[i].getUserUsername() << endl;
        cout << "Name:     " << vectorUser[i].getUserName() << endl;
        cout << "JMB:      " << vectorUser[i].getUserJMB() << endl;
        cout << "------------------------------" << endl;
    }
}

void updateUser()
{
    string editUser;
    cout << "Please enter the username of the User you want to update, enter cancel to exit: " << endl;
    cin >> editUser;
    if (editUser != "cancel")
    {
        for (int i = 0; i < vectorUser.size(); i++)
        {
            if (vectorUser[i].getUserUsername() == editUser)
            {
                cout << "Please enter the new username of your User" << endl;
                cin >> userMake;
                cin.sync(); // discard unread characters
                cout << "Please enter the name of your new user" << endl;
                getline(cin, name);
                cout << "Please enter the new JMB of your User" << endl;
                int counterForJMB = 0;
                bool JMBisDigit = false;
                do
                {
                    cin >> jmb;

                    counterForJMB = 0;
                    for (int j = 0; j < 13; j++)
                    {
                        if (isdigit(jmb[j]) != 0)
                        {
                            counterForJMB++;
                        }
                    }
                    if (counterForJMB == 13)
                    {
                        vectorUser[i].setUserJMB(jmb);
                        JMBisDigit = true;
                    }
                    else
                    {
                        cout << "Invalid JMB (Must contain only 13 digits), please try JMB again: ";
                    }
                } while (JMBisDigit != true);

                vectorUser[i].setUserUsername(userMake);
                vectorUser[i].setUserName(name);
            }
        }
    }
}

void deleteUser()
{
    string delUser;
    bool deleteConfirm=false;
    cout << "Please enter the username of the User you want to delete: " << endl;
    cin >> delUser;
    for (int i = 0; i < vectorUser.size(); i++)
    {
        if (vectorUser[i].getUserUsername() == delUser)
        {
            vectorUser.erase(vectorUser.begin() + i);
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

void crudMenuUser()
{

    int choice = 0;

    do
    {
        cout << "Welcome to the User menu, please select a number and press Enter" << endl;
        cout << "1. Create worker." << endl
             << "2. Read worker info." << endl
             << "3. Update worker info." << endl
             << "4. Delete worker." << endl
             << "5. Back." << endl;

        cin >> choice;
        // input validation
        while (cin.fail())
        {
            cin.clear();         // clear input buffer to restore cin to a usable state
            cin.ignore(5, '\n'); // ignore last input
            cout << "That is not a valid option, please try again." << endl;
            Sleep(1000);
            system("CLS");
            crudMenuUser();
            cin >> choice;
        }

        switch (choice)
        {
        case 1: // Create
            system("CLS");
            createUser();
            system("CLS");

            break;

        case 2:
        { // Read
            system("CLS");
            readUser();
            break;
        }
        case 3: // Update
            system("CLS");
            readUser();
            updateUser();
            break;

        case 4: // Delete
            system("CLS");
            readUser();
            deleteUser();
            system("CLS");
            break;

        case 5: // Back
            choice = 5;
            system("CLS");
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
