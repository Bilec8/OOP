#pragma once

#include "book.h"
#include "registeredAccount.h"

/*
Trida knihovna, muze vytovrit knihy a ucty
*/

class Library{
protected:                                // Prekryte chovani 
    int numOfBooks;     
    Book **books;                         //  pole ukazatelù na objekty jine tridy
    int numOfAccounts;
    RegisteredAccount **accounts;
public:
    Library(int b, int a);
    ~Library();

    Book *createBook(int id, int pages, int year, string author,string name);
    RegisteredAccount *createRegAcc(int id, string name, int credits, string password);

    RegisteredAccount *getAccount(int id);
    Book*  getBook(int id);

    int getNumBooks();
    int getNumAccount();
};  