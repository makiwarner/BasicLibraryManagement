#include "Book.h"
#include <iostream>
#include <fstream>

// Constructor for the Book class - initializes title and author attributes
Book::Book(const std::string& title, const std::string& author)
    : LibraryItem(title), author(author) {}

// Override the abstract display function for the Book class
void Book::display() const {
    std::cout << "Book: " << title << " by " << author << '\n';
}

// Serialize (save) book information (title, author, is checked out) to a text file
//info comes from the data members of the Book object
//outFile is a reference to a std::ofstream object... the reference allows
//the function to access and modify the original object directly, without creating a copy
void Book::serializeToText(std::ofstream& outFile) const {
    outFile << title << "\n" << author << "\n" << isCheckedOut << "\n";
}

// Deserialize (load) book information from a text file
void Book::deserializeFromText(std::ifstream& inFile) {
    std::getline(inFile, title);
    std::getline(inFile, author);
    inFile >> isCheckedOut; //difference in syntax here: ">>" reads up to the first whitespace 
}

// Serialize book information to a binary file
void Book::serializeToBinary(std::ofstream& outFile) const {
    // 1. Serialize title
    size_t titleLength = title.size();
    outFile.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
    outFile.write(title.c_str(), titleLength);
    // 2. Serialize author
    size_t authorLength = author.size();
    outFile.write(reinterpret_cast<const char*>(&authorLength), sizeof(authorLength));
    outFile.write(author.c_str(), authorLength);
    // 3. Serialize isCheckedOut status
    outFile.write(reinterpret_cast<const char*>(&isCheckedOut), sizeof(isCheckedOut)); //reinterpret_cast changes isCheckedOut from 
    //a boolean to a char (to be written to the outFile)
}

// Deserialize (load) book information from a binary file
void Book::deserializeFromBinary(std::ifstream& inFile) {
    // 1. Deserialize title
    size_t titleLength;
    inFile.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength)); //inFile.read() reads the raw binary data from the file
    //reinterpret_cast converts the address of titleLength to char*
    title.resize(titleLength); //resizes the title string to match the length of the string data that will be read next. 
    inFile.read(&title[0], titleLength); //inFile.read(&title[0], titleLength);
    // 2. Deserialize author
    size_t authorLength;
    inFile.read(reinterpret_cast<char*>(&authorLength), sizeof(authorLength));
    author.resize(authorLength);
    inFile.read(&author[0], authorLength);
    // 3. Deserialize isCheckedOut status
    inFile.read(reinterpret_cast<char*>(&isCheckedOut), sizeof(isCheckedOut));
}
