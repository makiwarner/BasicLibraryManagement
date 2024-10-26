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

    // New functions for text and bin file I/O (L14 Challenge)
    void serializeToText(std::ofstream& outFile) const;
    void deserializeFromText(std::ifstream& inFile);

    void serializeToBinary(std::ofstream& outFile) const;
    void deserializeFromBinary(std::ifstream& inFile);
};

#endif  // BOOK_H
