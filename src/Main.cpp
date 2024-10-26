#include <iostream>
#include <string>
#include <vector> //for library <LibraryItem> vector in Library class
#include <memory> //for library class
#include <fstream>
#include "LibraryItem.h"
#include "Book.h"
#include "Magazine.h"
#include "Library.h"

//main adds items to the library based on their type, checks them out, and displays all items
int main() {
    Library library;

    // change based on L14 (loads existing items from a binary file)
    std::ifstream inFile("library_items.bin", std::ios::binary);
    if (inFile) { //if we already have a file to begin with.
        library.loadItemsFromBinary(inFile);
        inFile.close();
    } else { 
        std::cout << "No existing library file found. Starting with an empty library.\n";
    }

    library.addItem(std::make_unique<Book>("Glucose Goddess", "Jessie Inchauspé"));
    library.addItem(std::make_unique<Magazine>("National Geographic", 101));

    std::cout << "Library Items:\n";
    library.displayAllItems();

    std::cout << "\nChecking out 'Glucose Goddess':\n";
    library.checkOutItem("Glucose Goddess");

    std::cout << "\nDisplaying Library Items After Checkout:\n";
    library.displayAllItems();

    std::cout << "\nReturning 'Glucode Goddess':\n";
    library.returnItem("Glucose Goddess");

    // change based on L14: saves updates of items to the binary file
    std::ofstream outFile("library_items.bin", std::ios::binary);
    if (outFile) {
        library.saveItemsToBinary(outFile);
        outFile.close();
        std::cout << "\nLibrary items saved to file :) \n";
    } else {
        std::cerr << "Failed to open file for saving :( \n";
    }

    return 0;
}

// to run, use
// mkdir build (if you havent already)
// cd build (if you havent already)
// cmake .. (run CMake to configure the project... if you havent already)
// build the project (cmake --build .   ... if you havent already)
// ./bin/library_management_system (run the executable)
