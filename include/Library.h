#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "LibraryItem.h" //since we will use members such as getTitle() from the base class in the .cpp file

class Library {
private:
    //RAII principle: std::unique_ptr automatically manages the deletion of LibraryItem objects
    std::vector<std::unique_ptr<LibraryItem>> items;

public:
    void addItem(std::unique_ptr<LibraryItem> item);

    void displayAllItems() const;

    void checkOutItem(const std::string& title);

    void returnItem(const std::string& title);
};

#endif  // LIBRARY_H
