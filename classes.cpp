#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#ifndef CLASSES_CPP
#define CLASSES_CPP

using namespace std;
class user
{
private:
    string username;
    string name;
    string JMB;

public:
    // constructor

    user(string US, string NM, string JM)
    {

        username = US;
        name = NM;
        JMB = JM;
    }

    // get

    string getUserUsername()
    {
        return username;
    }
    string getUserName()
    {
        return name;
    }
    string getUserJMB()
    {
        return JMB;
    }

    // set
    void setUserUsername(string US)
    {
        username = US;
    }
    void setUserName(string NM)
    {
        name = NM;
    }

    void setUserJMB(string JMBi)
    {

        if (JMBi.size() == 13)
        {
            JMB = JMBi;
        }
        else
        {
            cout << "Wrong input JMB, please try again" << endl;
            while (JMBi.size() != 13)
            {
                cout << "Try JMB again: ";
                cin >> JMBi;
            }
        }
    }
};
class customer
{
private:
    string username;
    string name;
    string JMB;
    string category;
    string rentedBook;

public:
    // constructor

    customer(string US, string NM, string JM, string categoryInput)
    {

        username = US;
        name = NM;
        JMB = JM;
        category = categoryInput;
    }

    // get

    string getCustomerUsername()
    {
        return username;
    }
    string getCustomerName()
    {
        return name;
    }
    string getCustomerJMB()
    {
        return JMB;
    }
    string getCustomerCategory()
    {
        return category;
    }
    string getCustomerRentedBook(){
        return rentedBook;

    }

    // set
    void setCustomerUsername(string US)
    {
        username = US;
    }
    void setCustomerName(string NM)
    {
        name = NM;
    }

    void setCustomerJMB(string JMBi)
    {

        if (JMBi.size() == 13)
        {
            JMB = JMBi;
        }
        else
        {
            cout << "Wrong input JMB, please try again" << endl;
            while (JMBi.size() != 13)
            {
                cout << "Try JMB again: ";
                cin >> JMBi;
            }
        }
    }
    void setCustomerCategory(string value)
    {
        category = value;
    }
    void setCustomerRentedBook (string rentedBookInput){
    rentedBook = rentedBookInput;
    }
};

class book
{
private:
    string bookID;
    string bookName;
    string bookGenre;
    int bookShelf;

public:
    // constructor

    book(string bID, string bN, string bG, int bS)
    {
        bookID = bID;
        bookName = bN;
        bookGenre = bG;
        bookShelf = bS;
    }

    // get

    string getBookID()
    {
        return bookID;
    }
    string getBookName()
    {
        return bookName;
    }
    string getBookGenre()
    {
        return bookGenre;
    }
    int getBookShelf()
    {
        return bookShelf;
    }
    // set

    void setBookID(string setBID)
    {
        bookID = setBID;
    }
    void setBookName(string setBN)
    {
        bookName = setBN;
    }
    void setBookGenre(string setBG)
    {
        bookGenre = setBG;
    }
    void setBookShelf(int setBS)
    {
        bookShelf = setBS;
    }
};
#endif // CLASSES_CPP
