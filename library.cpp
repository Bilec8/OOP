#include "library.h"

Library::Library(int b, int a){
    this->accounts = new RegisteredAccount*[a];
    this->numOfAccounts = 0;

    this->books = new Book*[b];
    this->numOfBooks = 0;
}

Library::~Library(){
    for(int i=0;i<this->numOfAccounts;i++){
        delete this->accounts[i];
    }
    delete[] this->accounts;

    for(int i=0;i<this->numOfBooks;i++){
        delete this->books[i];
    }
    delete[] this->books;
}

Book *Library::createBook(int id, int pages, int year, string author,string name){
    Book *newBook = new Book(id,pages,year,author,name);

    this->books[this->numOfBooks] = newBook;
    this->numOfBooks++;

    return newBook;
}

RegisteredAccount *Library::createRegAcc(int id, string name, int credits, string password){
    RegisteredAccount *newAccount = new RegisteredAccount(id,name,credits,password);

    this->accounts[this->numOfAccounts] = newAccount;
    this->numOfAccounts++;

    return newAccount;
}

RegisteredAccount *Library::getAccount(int id){
    for(int i=0;i<this->numOfAccounts;i++){
        if(this->accounts[i]->getId() == id){
            return this->accounts[i];
        }
    }
    return nullptr;
}

int Library::getNumAccount(){
    return this->numOfAccounts;
}

int Library::getNumBooks(){
    return this->numOfBooks;
}

Book* Library::getBook(int id) {
    for (int i=0; i < this->numOfAccounts; i++) {
        if (this->books[i]->getId() == id) {
            return this->books[i];
        }
    }
    return nullptr;
}