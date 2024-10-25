#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& title) : title(title), isCheckedOut(false) {} //mem address of title is passed as a reference
//(prevents creating a copy of the title argument, which saves memory and processing time)
//the title parameter allows library items to be initialized with a unique title.

void LibraryItem::checkOut() {
    if (!isCheckedOut) {
        isCheckedOut = true;
        std::cout << title << " has been checked out.\n";
    } else {
        std::cout << title << " is already checked out.\n";
    }
}

void LibraryItem::returnItem() {
    if (isCheckedOut) {
        isCheckedOut = false;
        std::cout << title << " has been returned.\n";
    } else {
        std::cout << title << " was not checked out.\n";
    }
}

// Getter for title
std::string LibraryItem::getTitle() {
    return title;
}
