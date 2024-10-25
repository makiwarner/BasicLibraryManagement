#include "Magazine.h"
#include <iostream>

//Constructor
Magazine::Magazine(const std::string& title, int issueNumber)
    : LibraryItem(title), issueNumber(issueNumber) {}

//Override display function
void Magazine::display() const {
    std::cout << "Magazine: " << title << ", Issue #" << issueNumber << '\n';
}
