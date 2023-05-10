#include "library.h"

/*
Pracovnik knihovny, dedi z knohovny a muze hledat knihy, kontroluje ucty
*/

class LibraryWorker : public Library{
private:
    string name;
public:
    LibraryWorker(int b, int a, string name);

    void checkAccounts();
    void printAviableBooks();

    void searchBook(int id);                    // pretizene metody
    void searchBook(string name);               // pretizene metody

    void searchAccount(int id);
    void searchAccount(string name);
};