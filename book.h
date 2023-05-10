#pragma once
#include "objectInLibrary.h"

class Book : public objectInLibrary{
    private:
        int id;
        int pages;
        int year;
        string author;
        string name;
        bool isAviable;

        static int objectsCount;      // Trida v roli objektu
    public:

        Book(int id, int pages, int year, string author,string name);
        ~Book();
        virtual void printBookId();         // Polymorfismus
        void changeAviability();

        int getId();
        int getPages();
        int getYear();
        bool getAviable();
        string getAuthor();
        string getName();

        static int getObjctCount();         // Trida v roli objektu
};  