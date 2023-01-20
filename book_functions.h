#include <stdlib.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include "classes.cpp"
#include <vector>

using namespace std;

vector<book> vectorBooks;
string addBookID, addBookName, addBookGenre;
int addBookShelf;



void createBook()
{

    bool bookIDFound=false;
    int counterForBookID=0;
    cout << "Please enter the book ID, please make sure the first character is a letter and the others are numbers, book ID must contain 5 characters" << endl;
   do{
    cin >> addBookID ;
    for (int k = 0; k<vectorBooks.size(); k++){
        if (addBookID == vectorBooks[k].getBookID()){
            cout << "Book ID already exists, please try again: " << endl;
            bookIDFound = true;

        }else{
        bookIDFound= false;
        }
    }

}while(bookIDFound==true);
    for (int i = 1; i<9; i++){

            if(isdigit(addBookID[i]) == true){

                counterForBookID++;
            }

        }

    if(isalpha(addBookID[0]) == false || counterForBookID != 4){
        cout << "Wrong input please try again: "<< endl;
        while (isalpha(addBookID[0]) == 0 || counterForBookID != 4){
                counterForBookID=0;
            cout << "Try again, please make sure that the first character is a letter and the other 4 are numbers: ";
            cin >> addBookID;
            for (int i = 1; i<9; i++){
            if(isdigit(addBookID[i]) == true){
                counterForBookID++;
            }

                                    }
        }}
        cin.ignore(1,'\n');
        cout << "Please enter the book name next: " <<endl;

        getline(cin, addBookName);
        cout << "Please enter the book genre next: "<<endl;
        cin >> addBookGenre;
        cout << "Please enter book shelf number next (1-9): "<<endl;
        do{cin >> addBookShelf;
            if(addBookShelf >10 || addBookShelf<0){
                cout << "Wrong input, please use shelfs 1-9: "<<endl;
                cin >> addBookShelf;
            }
        }while(addBookShelf>10 || addBookShelf<0);
        book newBook = book(addBookID,addBookName,addBookGenre,addBookShelf);
        vectorBooks.push_back(newBook);
};

void readBook()
{
 for (int i = 0; i < vectorBooks.size(); i++)
    {
        cout << "    BookID: " << vectorBooks[i].getBookID() << endl;
        cout << " Book Name: " << vectorBooks[i].getBookName() << endl;
        cout << "Book Genre: " << vectorBooks[i].getBookGenre() << endl;
        cout << "Book Shelf: " << vectorBooks[i].getBookShelf() << endl;
        cout << "-------------------------------------------" << endl;
    }
};

void updateBook()
{
    string editBook, newID, newBookName, newGenre;
    int newShelf, counterForBookID = 0;
    bool bookIDFound;

    cout << "Please enter the book ID you want to update, enter cancel to exit: " << endl;
    cin >> editBook;
    if (editBook != "cancel")
    {
        for (int position = 0; position < vectorBooks.size(); position++)
        {
            if (editBook == vectorBooks[position].getBookID())
            {

                do
                {
                    cout << "Please enter the new book ID: " << endl;
                    cin >> newID;
                    for (int k = 0; k < vectorBooks.size(); k++)
                    {
                        if (newID == vectorBooks[k].getBookID())
                        {
                            cout << "Book ID already exists, please try again." << endl;
                            bookIDFound = true;
                        }
                        else
                        {
                            bookIDFound = false;
                        }
                    }

                } while (bookIDFound == true);
                counterForBookID=0;
                for (int i = 1; i < 10; i++)
                {

                    if (isdigit(newID[i]) == true)
                    {
                        counterForBookID++;
                        cout << counterForBookID << endl;
                    }
                }

                if (isalpha(newID[0]) == false || counterForBookID != 4)
                {
                    cout << "Wrong input please try again: " << endl;
                    while (isalpha(newID[0]) == 0 || counterForBookID != 5)
                    {
                        counterForBookID = 0;
                        cout << "Try again, please make sure that the first character is a letter and the other 4 are numbers: ";
                        cout << isalpha(newID[0]) << endl;
                        cin >> newID;
                        for (int i = 1; i < 10; i++)
                        {

                            if (isdigit(newID[i]) == true)
                            {
                                counterForBookID++;
                                cout << counterForBookID << endl;
                            }
                        }
                    }
                }
                cin.ignore(1, '\n');
                cout << "Please enter the book name next: " << endl;

                getline(cin, newBookName);
                cout << "Please enter the book genre next: " << endl;
                cin >> newGenre;
                cout << "Please enter book shelf number next (1-9): " << endl;
                do
                {
                    cin >> newShelf;
                    if (newShelf > 10 || newShelf < 0)
                    {
                        cout << "Wrong input, please use shelfs 1-9: " << endl;
                        cin >> newShelf;
                    }
                } while (newShelf > 10 || newShelf < 0);

                vectorBooks[position].setBookID(newID);
                vectorBooks[position].setBookName(newBookName);
                vectorBooks[position].setBookGenre(newGenre);
                vectorBooks[position].setBookShelf(newShelf);
            }
        }
    }
};

void deleteBook()
{
  string delBook;
    bool deleteConfirm;
    cout << "Please enter the username of the User you want to delete: " << endl;
    cin >> delBook;
    for (int i = 0; i < vectorBooks.size(); i++)
    {
        if (vectorBooks[i].getBookID() == delBook)
        {
            vectorBooks.erase(vectorBooks.begin() + i);
            deleteConfirm = true;
        }
    }
    if (deleteConfirm != true)
    {
        cout << "Unable to delete book, book does not exist." << endl;
        Sleep(2000);
    }
    else
    {
        cout << "Book successfully deleted." << endl;
        Sleep(2000);
    }
};

void crudMenuBook()
{
    book preDefBook1 = book ("N0001", "The Great Gatsby", "Novel", 1);
    vectorBooks.push_back(preDefBook1);
    book preDefBook2 = book ("F0001", "The Fellowship of the Ring", "Fantasy", 2);
    vectorBooks.push_back(preDefBook2);
    book preDefBook3 = book ("S0001", "2001: A Space Odyssey", "Sci-Fi", 3);
    vectorBooks.push_back(preDefBook3);
    book preDefBook4 = book ("H0001", "Pet Semetery", "Horror", 4);
    vectorBooks.push_back(preDefBook4);
    int choice = 0;

    do
    {
        cout << "Welcome to the book menu, please select a number and press Enter" << endl;
        cout << "1. Create a book." << endl
             << "2. Read book info." << endl
             << "3. Update book info." << endl
             << "4. Delete a book." << endl
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
                createBook();
            break;

        case 2:
        { // Read
        system("CLS");
        readBook();
            break;
        }
        case 3: // Update
        system("CLS");
        readBook();
        updateBook();
            break;

        case 4: // Delete
        system("CLS");
        readBook();
        deleteBook();

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
