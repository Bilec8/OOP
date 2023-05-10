#include "safeAccount.h"

SafeAccount::SafeAccount(int id, string name, int credits, string password) : RegisteredAccount(id, name, credits, password){}

void SafeAccount::changePassword(string password) {
	if (password.length() > 8) {
		this->password = password;
		cout << this->getName() << ", your password were succesfully changed" << endl;
	}
	else {
		cout << this->getName() << " ,your password is too short" << endl;
	}
	cout << endl;
}

void SafeAccount::borrowBook(string name) {
	this->bookName = name;
	this->changeWantLend();
	if (this->getCredits() < 3) {
		cout << "Be carefull you only have " << this->getCredits() << "credits." << endl;
	}
}

void SafeAccount::borrowBook(int id) {
	this->bookId = id;
	this->changeWantLend();
	if (this->getCredits() < 3) {
		cout << "Be carefull you only have " << this->getCredits() << "credits." << endl;
	}
}