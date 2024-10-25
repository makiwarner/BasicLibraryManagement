#include "Book.h"
#include <iostream>

//Constructor for the Book class
Book::Book(const std::string& title, const std::string& author)
    : LibraryItem(title), author(author) {}

//Override the display function for Book
void Book::display() const {
    std::cout << "Book: " << title << " by " << author << '\n';
}
