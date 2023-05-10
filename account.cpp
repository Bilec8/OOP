#include "account.h"

Account::Account(int id, string name){
    this->id = id;
    this->name = name;
}

void Account::changeName(string name){
    this->name = name;
    cout << "Your nickname : " << this->name << " was successfully changed." << endl;
}

int Account::getId(){
    return this->id;
}

string Account::getName(){
    return this->name;
}