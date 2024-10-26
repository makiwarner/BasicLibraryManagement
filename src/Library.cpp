#include "Library.h" 
#include "Book.h"
#include "Magazine.h"
#include <fstream> 
#include <iostream>

//load items from binary based on L14
void Library::loadItemsFromBinary(std::ifstream& inFile) {
    while (inFile) {
        char itemType;
        inFile.read(&itemType, sizeof(itemType));
        
        if (itemType == 'B') { // book... originally saved in the saveItemsToBinary() method
            auto book = std::make_unique<Book>("", "");
            book->deserializeFromBinary(inFile);
            addItem(std::move(book));
        } else if (itemType == 'M') { //magazine
            auto magazine = std::make_unique<Magazine>("", 0);
            magazine->deserializeFromBinary(inFile);
            addItem(std::move(magazine));
        }
    }
}

// unique_ptr: holds exclusive ownership of a dynamically allocated object
void Library::addItem(std::unique_ptr<LibraryItem> item) {
    items.push_back(std::move(item));
}

void Library::displayAllItems() const {
    for (const auto& item : items) {
        item->display();
    }
}

void Library::checkOutItem(const std::string& title) {
    for (auto& item : items) {
        if (item->getTitle() == title) {
            item->checkOut();
            return;
        }
    }
    std::cout << title << " not found in library.\n";
}

void Library::returnItem(const std::string& title) {
    for (auto& item : items) {
        if (item->getTitle() == title) {
            item->returnItem();
            return;
        }
    }
    std::cout << title << " not found in library.\n";
}

//saveItemsToBinary based on L14
void Library::saveItemsToBinary(std::ofstream& outFile) const {
    for (const auto& item : items) {
        if (dynamic_cast<Book*>(item.get())) {
            char itemType = 'B'; //saves with a specific letter identifier to later by accessed by category
            outFile.write(&itemType, sizeof(itemType));
            dynamic_cast<Book*>(item.get())->serializeToBinary(outFile);
        } else if (dynamic_cast<Magazine*>(item.get())) {
            char itemType = 'M';
            outFile.write(&itemType, sizeof(itemType));
            dynamic_cast<Magazine*>(item.get())->serializeToBinary(outFile);
        }
    }
}
