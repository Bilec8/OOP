#pragma once
#include "registeredAccount.h"

/*
	Vicenasobna dedicnost
*/

class SafeAccount  : public RegisteredAccount{
	public:
		SafeAccount(int id, string name, int credits, string password);

		virtual void changePassword(string password);	// Pozdni vazba

		void borrowBook(string name);					// Prekryti chovani
		void borrowBook(int id);						// Prekryti chovani

};