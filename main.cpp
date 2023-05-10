#include "account.h"
#include "book.h"
#include "libraryWorker.h"
#include "safeAccount.h"

int main(){

    LibraryWorker *lw = new LibraryWorker(20,30,"Tomas");

    SafeAccount* sa = new SafeAccount(8, "Jakub Novy", 12, "rastik123");
        
    Library *lib = lw;                                                      // Polymorfismus                             

    lib->createBook(0,300,2002,"Karel Capek","R.U.R.");
    lib->createBook(1,345,2015,"Karel Capek","Bila nemoc");
    lib->createBook(2,210,1850,"Marcus Aureliues","Hovory k sobe");
    lib->createBook(3,456,2018,"James Black","The modern man");
    lib->createBook(4,300,1999,"Jonhatan King","Brown crow");
    lib->createBook(5,300,2012,"Jan Novak","Myslete velkoryse");
    lib->createBook(6,324,2012,"Alena Morsnajova","Les v dome");
    lib->createBook(7, 313, 2022,"Rober Brynza", "Dablova cesta");
    lib->createBook(8, 340, 2013,"Jo nesbo","Random");
    lib->createBook(9, 530, 2014, "Michaela Klevisova","Vrani oko");
    lib->createBook(10, 102, 2022, "Roland Malfi", "Pojd semnou");

    RegisteredAccount* c1 = lw->createRegAcc(0, "Martin Lysek", 15, "rastik123");
    RegisteredAccount *c2 = lw->createRegAcc(1,"Honza Szotkowski",2,"lol123");
    RegisteredAccount* c3 = lw->createRegAcc(2, "Lukas Sikora", 3, "hvezda54");
    RegisteredAccount* c4 = lw->createRegAcc(3, "Ondra Byrtus", 4, "budna23");
    RegisteredAccount* c5 = lw->createRegAcc(4, "Dominik Wojnar", 0, "dsafds123");
    RegisteredAccount* c6 = lw->createRegAcc(5, "Simon Sikora", 2, "becool");
    RegisteredAccount* c7 = lw->createRegAcc(6, "Jirka Bilko", 4, "random");
    RegisteredAccount* c8 = lw->createRegAcc(7, "Nikol Novakova", 5, "ahoj123");

    lw->printAviableBooks();

    c2 = sa;                                                            // Polymorfismus

    c2->changePassword("ok");

    sa->changePassword("ok");

    sa->changePassword("ok I undersand");

    c1->borrowBook(5);
    c5->borrowBook(2);
    c6->borrowBook("Pojd semnou");

    lw->checkAccounts();
    c5->printBooks();
    c1->borrowBook(4);
    c2->borrowBook("Hovory k sobe");

    lw->checkAccounts();


    c1->borrowBook(3);
    c5->borrowBook(3);

    lw->checkAccounts();

    c2->printBooks();


    c3->borrowBook(5);

    lw->checkAccounts();
    c1->borrowBook("R.U.R.");
    lw->checkAccounts();
    lw->printAviableBooks();

    c1->printBooks();

    c1->returnBook("R.U.R.");

    c1->printBooks();
    c6->printBooks();

    lw->printAviableBooks();

    delete lw;

}