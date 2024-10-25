#include <iostream>
#include <string>
#include <vector> //for library <LibraryItem> vector in Library class
#include <memory> //for library class
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "Library.h"

//main adds items to the library based on their type, checks them out, and displays all items
int main() {
    Library library;

    library.addItem(std::make_unique<Book>("To Kill a Mockingbird", "Harper Lee"));
    library.addItem(std::make_unique<Magazine>("National Geographic", 101));

    std::cout << "Library Items:\n";
    library.displayAllItems();

    std::cout << "\nChecking out 'To Kill a Mockingbird':\n";
    library.checkOutItem("To Kill a Mockingbird");

    std::cout << "\nDisplaying Library Items After Checkout:\n";
    library.displayAllItems();

    std::cout << "\nReturning 'To Kill a Mockingbird':\n";
    library.returnItem("To Kill a Mockingbird");

    return 0;
}

// to run, use
// mkdir build (if you havent already)
// cd build (if you havent already)
// cmake .. (run CMake to configure the project... if you havent already)
// build the project (cmake --build .   ... if you havent already)
// ./bin/library_management_system (run the executable)
