#include "registeredAccount.h"

int maxNumberOfBooks = 10;

RegisteredAccount::RegisteredAccount(int id, string name, int credits, string password) : Account(id,name){
    this->credits = credits;
    this->password = password;
    this->books = new Book * [maxNumberOfBooks];
    this->numberOfBooks = 0;
    this->bookId = -1;
    this->bookName = "";
    this->wantLend = false;
}

void RegisteredAccount::borrowBook(int id){
    this->bookId = id;
    this->wantLend = true;
}

void RegisteredAccount::borrowBook(string name){
    this->bookName = name;
    this->wantLend = true;
}

void RegisteredAccount::changePassword(string password){
    this->password = password;
    cout << this->getName() <<  ", your password was successfully changed." << endl << endl;
}

void RegisteredAccount::returnBook(string name){
    Book* pom = nullptr;

    cout << this->getName() << " has returned book with name " << name << endl;

    for(int i=0;i<this->numberOfBooks;i++){
        
        if (this->books[i]->getName() == name) {
            this->books[i]->changeAviability();
            for (int j = i; j < this->numberOfBooks - i; j++) {
                this->books[j] = this->books[j + 1];
                this->books[j + 1] = pom;
                pom = this->books[j];
            }
            
            
            this->numberOfBooks--;
        }
    }
}

int RegisteredAccount::getCredits(){
    return this->credits;
}

string RegisteredAccount::getPassword(){
    return this->password;
}

int RegisteredAccount::getNumberOfBooks(){
    return this->numberOfBooks;
}

int RegisteredAccount::getBookId(){
    return this->bookId;
}

string RegisteredAccount::getBookName(){
    return this->bookName;
}

bool RegisteredAccount::getWantLend(){
    return this->wantLend;
}

void RegisteredAccount::removeCredit(){
    this->credits--;
}

void RegisteredAccount::addBook(){
    this->numberOfBooks++;
}

void RegisteredAccount::changeWantLend(){
    this->wantLend = !this->wantLend;
}

void RegisteredAccount::printBooks(){
    cout << "Customer " << this->getName() << " with id " << this->getId() << " has landed theese books: " << endl;
    for (int i = 0; i < this->numberOfBooks; i++) {
        cout << "\tBook id " << this->books[i]->getId() << " with name " << this->books[i]->getName() << " and author " << this->books[i]->getAuthor() << endl;
    }
    if (this->numberOfBooks == 0) cout << "\tNo landed books." << endl;
}

void RegisteredAccount::resetBookId() {
    this->bookId = -1;
}

void RegisteredAccount::resetBookName() {
    this->bookName = "";
}