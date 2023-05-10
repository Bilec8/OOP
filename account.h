#pragma once
#include <iostream>
#include "book.h"

/*
Trida account, klasicky zakaznik
*/

using namespace std;

class Account{
private:
    int id;
    string name;
public:
    Account(int id,string name);

    void changeName(string newName);

    int getId();
    string getName();
};