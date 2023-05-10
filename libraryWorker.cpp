#include "libraryWorker.h"

LibraryWorker::LibraryWorker(int b, int a, string name) : Library(b,a){
    this->name = name;
}

void LibraryWorker::checkAccounts(){

    for(int i=0;i<this->numOfAccounts;i++){
        if(this->accounts[i]->getWantLend()){
            if(this->accounts[i]->getBookId() != -1){
                for(int j=0;j<this->numOfBooks;j++){
                    if(this->books[j]->getId() == this->accounts[i]->getBookId()){
                        if(this->books[j]->getAviable()){
                            if (this->accounts[i]->getNumberOfBooks() < 10) {
                                this->accounts[i]->books[this->accounts[i]->getNumberOfBooks()] = this->books[j];
                                this->books[j]->changeAviability();
                                this->accounts[i]->removeCredit();
                                this->accounts[i]->addBook();
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookId();
                                cout << "Customer " << this->accounts[i]->getName() << " has landed book " << this->books[j]->getName() << " from " << this->books[j]->getAuthor() << endl;
                                break;
                            }
                            else {
                                cout << "You already have lended 10 book, you need to return some." << endl;
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookId();
                            }

                            if (this->accounts[i]->getCredits() >= 1) {
                                this->accounts[i]->books[this->accounts[i]->getNumberOfBooks()] = this->books[j];
                                this->books[j]->changeAviability();
                                this->accounts[i]->removeCredit();
                                this->accounts[i]->addBook();
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookId();
                                cout << "Customer " << this->accounts[i]->getName() << " has landed book " << this->books[j]->getName() << " from " << this->books[j]->getAuthor() << endl;
                                break;
                            }
                            else {
                                cout << "You dont have enough credits to lend a book. " << endl;
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookId();
                            }

                        }else{
                            cout << "We are sorry " << this->accounts[i]->getName() << ", but book " << this->books[j]->getName() << " is not currently aviable." << endl << endl;
                            this->accounts[i]->changeWantLend();
                            this->accounts[i]->resetBookId();
                        }
                    }
                }
            }
            if(this->accounts[i]->getBookName().size() > 1){
                for (int j = 0; j < this->numOfBooks; j++) {
                    if (this->books[j]->getName().compare(this->accounts[i]->getBookName()) == 0) {
                        if (this->books[j]->getAviable()) {
                            if (this->accounts[i]->getNumberOfBooks() < 10) {
                                this->accounts[i]->books[this->accounts[i]->getNumberOfBooks()] = this->books[j];
                                this->books[j]->changeAviability();
                                this->accounts[i]->removeCredit();
                                this->accounts[i]->addBook();
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookName();
                                cout << "Customer " << this->accounts[i]->getName() << " has landed book " << this->books[j]->getName() << " from " << this->books[j]->getAuthor() << endl;
                                break;
                            }
                            else {
                                cout << "You already have lended 10 book, you need to return some." << endl;
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookName();
                            }

                            if (this->accounts[i]->getCredits() >= 1) {
                                this->accounts[i]->books[this->accounts[i]->getNumberOfBooks()] = this->books[j];
                                this->books[j]->changeAviability();
                                this->accounts[i]->removeCredit();
                                this->accounts[i]->addBook();
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookName();
                                cout << "Customer " << this->accounts[i]->getName() << " has landed book " << this->books[j]->getName() << " from " << this->books[j]->getAuthor() << endl;
                                break;
                            }
                            else {
                                cout << "You dont have enough credits to lend a book. " << endl;
                                this->accounts[i]->changeWantLend();
                                this->accounts[i]->resetBookName();
                            }
                        }
                        else cout << "We are sorry, but book" << this->accounts[i]->getBookName() << " is not currently aviable." << endl << endl;
                        this->accounts[i]->changeWantLend();
                        this->accounts[i]->resetBookName();
                    }
                }
            }
        }
    }
    
}

void LibraryWorker::printAviableBooks(){
    cout << "Aviable books: " << endl;
    for(int i=0;i<this->numOfBooks;i++){
        if(this->books[i]->getAviable() == true){
            cout << "Book with id: " << this->books[i]->getId() << " and name: " << this->books[i]->getName() << endl;
        }
    }
    cout << endl;
}

void LibraryWorker::searchAccount(int id){
    cout << "Searched account: " << endl;
    for (int i = 0; i < this->getNumAccount(); i++) {
        if (this->accounts[i]->getId() == id) {
            cout << "Name: " << this->accounts[i]->getName() << " has landed books: " << endl;
            for (int j = 0; j < this->accounts[i]->getNumberOfBooks(); j++) {
                cout << j + 1 << ": " << this->accounts[i]->books[j]->getName() << " from " << this->accounts[i]->getBookName() << endl;
            }
        }
     }
}

void LibraryWorker::searchAccount(string name) {
    cout << "Searched account:" << endl;
    for (int i = 0; i < this->getNumAccount(); i++) {
        if (this->accounts[i]->getName() == name) {
            cout << "Name: " << this->accounts[i]->getName() << " has landed books: " << endl;
            for (int j = 0; j < this->accounts[i]->getNumberOfBooks(); j++) {
                cout << j + 1 << ": " << this->accounts[i]->books[j]->getName() << " from " << this->accounts[i]->getBookName() << endl;
            }
        }
    }
}

void LibraryWorker::searchBook(int id) {
    cout << "Searched book: " << endl;
    for (int i = 0; i < this->getNumBooks(); i++) {
        if (this->books[i]->getId() == id) {
            cout << i + 1 << ": " << this->books[i]->getName() << " from " << this->books[i]->getName() << endl;
        }
    }
}

void LibraryWorker::searchBook(string name) {
    cout << "Searched book: " << endl;
    for (int i = 0; i < this->getNumBooks(); i++) {
        if (this->books[i]->getName() == name) {
            cout << i + 1 << ": " << this->books[i]->getName() << " from " << this->books[i]->getName() << endl;
        }
    }
}



