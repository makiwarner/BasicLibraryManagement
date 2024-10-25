#ifndef MAGAZINE_H //checks if the macro MAGAZINE_H has not been defined yet
#define MAGAZINE_H //If it hasn’t, this line is included, which defines the macro

#include <string>
#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    //Constructor
    Magazine(const std::string& title, int issueNumber);

    //Override the display function
    void display() const override;
};

#endif  //MAGAZINE_H
