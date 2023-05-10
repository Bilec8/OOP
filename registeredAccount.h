#pragma once
#include "account.h"
#include "book.h"

/*
Registrovany zakaznik, muze si pujcovat knihy
*/

class RegisteredAccount : public Account{
    private:
        int numberOfBooks;
        bool wantLend;
        int credits;
    
    protected:
        int bookId;
        string bookName;

        string password;
    public:
        Book **books;

        RegisteredAccount(int id, string name, int credits, string password);


        void borrowBook(int id);                           // Pretizene metody
        void borrowBook(string name);                      // Pretizene metody
        void returnBook(string name);
        void changePassword(string password);
        void changeWantLend();
        void removeCredit();
        void addBook();

        void resetBookId();
        void resetBookName();
        
        void printBooks();

        int getCredits();
        string getPassword();
        int getNumberOfBooks();
        int getBookId();
        string getBookName();
        bool getWantLend();
};