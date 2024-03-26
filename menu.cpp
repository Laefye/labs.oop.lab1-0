#include "menu.h"

Menu::Menu() {
    add(std::shared_ptr<Option>(new Option("pized", &Menu::close)));
}

void Menu::add(const std::shared_ptr<Option>& option) {
    this->options.push_back(option);
}

void Menu::open() {
    size_t i = 1;
    for (std::shared_ptr<Option>& option : this->options) {
        std::cout << i++ << ") " << option->first << std::endl;
    }
    this->isOpened = true;
    while (this->isOpened) {
        std::cout << "Choice: ";
        size_t choice;
        if (std::cin >> choice && choice >= 1 && choice <= this->options.size()) {
            (this->*(this->options[choice - 1]->second))();
        }
    }
}

void Menu::close() {
    this->isOpened = false;
}
