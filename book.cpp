#include "book.h"

int Book::objectsCount = 0;       // Trida v roli objektu

Book::Book(int id, int pages, int year, string author,string name){
    this->id = id;
    this->pages = pages;
    this->year = year;
    this->author = author;
    this->name = name;
    this->isAviable = true;
    Book::objectsCount++;      // Trida v roli objektu
}

void Book::printBookId(){
    cout << this->name << " is from year" << this->year << " and was written by" << this->author << endl;
}

string Book::getAuthor(){
    return this->author;
}

string Book::getName(){
    return this->name;
}

int Book::getId(){
    return this->id;
}

int Book::getPages(){
    return this->pages;
}

int Book::getYear(){
    return this->year;
}

bool Book::getAviable(){
    return this->isAviable;
}

void Book::changeAviability(){
    this->isAviable = (!this->isAviable);
}

int Book::getObjctCount() {
    return Book::objectsCount;
}

Book::~Book() {
    Book::objectsCount--;          // Trida v roli objektu
}