#include "Library.h" 

// unique_ptr: holds exclusive ownership of a dynamically allocated object
void Library::addItem(std::unique_ptr<LibraryItem> item) {
    items.push_back(std::move(item));
}

void Library::displayAllItems() const {
    for (const auto& item : items) {
        item->display();
    }
}

void Library::checkOutItem(const std::string& title) {
    for (auto& item : items) {
        if (item->getTitle() == title) {
            item->checkOut();
            return;
        }
    }
    std::cout << title << " not found in library.\n";
}

void Library::returnItem(const std::string& title) {
    for (auto& item : items) {
        if (item->getTitle() == title) {
            item->returnItem();
            return;
        }
    }
    std::cout << title << " not found in library.\n";
}
