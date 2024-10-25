#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "LibraryItem.h"

//inherited from LibraryItem class
class Book : public LibraryItem {
private:
    std::string author;

public:
    //Constructor
    Book(const std::string& title, const std::string& author);

    //Override the display function
    void display() const override;
};

#endif  // BOOK_H
