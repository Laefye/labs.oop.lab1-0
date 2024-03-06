#include "menu.h"
#include <iostream>

MenuItem::MenuItem(std::string name) {
    this->name = name;
}

void MenuItem::use() {
    std::cout << "nor te";
}

std::string MenuItem::getName() {
    return this->name;
}

Menu::Menu() : MenuItem("Menu") {

}

void Menu::addItem(MenuItem& item) {
    this->items.push_back(item);
}

void Menu::use() {
    size_t itemNumber = 1;
    for (MenuItem& item : this->items) {
        std::cout << itemNumber << ") " << item.getName() << std::endl;
    }
    if (std::cin >> itemNumber && itemNumber > 0 && itemNumber <= items.size()) {
        items[itemNumber - 1].use();
    }
}
