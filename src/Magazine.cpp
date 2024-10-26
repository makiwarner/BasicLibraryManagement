#include "Magazine.h"
#include <iostream>
#include <fstream>

//Constructor
Magazine::Magazine(const std::string& title, int issueNumber)
    : LibraryItem(title), issueNumber(issueNumber) {}

//Override display function
void Magazine::display() const {
    std::cout << "Magazine: " << title << ", Issue #" << issueNumber << '\n';
}

// Serialize (save) magazine information (title, isue number, is checked out) to a text file
//info comes from the data members of the Magazine object
//outFile is a reference to a std::ofstream object... the reference allows
//the function to access and modify the original object directly, without creating a copy
void Magazine::serializeToText(std::ofstream& outFile) const {
    outFile << title << "\n" << issueNumber << "\n" << isCheckedOut << "\n";
}

// Deserialize (load) magazine information from a text file
void Magazine::deserializeFromText(std::ifstream& inFile) {
    std::getline(inFile, title);
    inFile >> issueNumber;
    inFile >> isCheckedOut; //difference in syntax here: ">>" reads up to the first whitespace 
}

// Serialize magazine information to a binary file
void Magazine::serializeToBinary(std::ofstream& outFile) const {
    // 1. Serialize title
    size_t titleLength = title.size();
    outFile.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
    outFile.write(title.c_str(), titleLength);
    // 2. Serialize issueNumber
    outFile.write(reinterpret_cast<const char*>(&issueNumber), sizeof(issueNumber));
    // 3. Serialize isCheckedOut status
    outFile.write(reinterpret_cast<const char*>(&isCheckedOut), sizeof(isCheckedOut)); //reinterpret_cast changes isCheckedOut from 
    //a boolean to a char (to be written to the outFile)
}

// Deserialize (load) magazine information from a binary file
void Magazine::deserializeFromBinary(std::ifstream& inFile) {
    // 1. Deserialize title
    size_t titleLength;
    inFile.read(reinterpret_cast<char*>(&titleLength), sizeof(titleLength)); //inFile.read() reads the raw binary data from the file
    //reinterpret_cast converts the address of titleLength to char*
    title.resize(titleLength); //resizes the title string to match the length of the string data that will be read next. 
    inFile.read(&title[0], titleLength); //inFile.read(&title[0], titleLength);
    // 2. Deserialize issueNumber
    inFile.read(reinterpret_cast<char*>(&issueNumber), sizeof(issueNumber));
    // 3. Deserialize isCheckedOut status
    inFile.read(reinterpret_cast<char*>(&isCheckedOut), sizeof(isCheckedOut));
}
