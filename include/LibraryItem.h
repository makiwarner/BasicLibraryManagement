#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>

class LibraryItem {
protected:
    std::string title;
    bool isCheckedOut;

public:
    // Constructor
    LibraryItem(const std::string& title);

    // Note that virtual implies that the class can be overridden with polymorphism. 
    //This is necessary especially for the deconstructor, as we must ensure that the proper object is deleted (object in base or derived class)
    virtual ~LibraryItem() = default;

    virtual void checkOut();
    virtual void returnItem();

    virtual std::string getTitle();

    virtual void display() const = 0;  // Pure virtual function to make the class abstract. This means that the derived classse will have 
    //to implement their own versions of the display class
};

#endif  // LIBRARYITEM_H
