#include "menu.h"

Option::Option(const std::string& name) : name(name) {

}

const std::string& Option::getName() {
    return this->name;
}


void Menu::add(const std::shared_ptr<Option>& option) {
    this->options.push_back(option);
}

void Menu::open() {
    size_t i = 1;
    for (std::shared_ptr<Option>& option : this->options) {
        std::cout << i++ << ") " << option->getName() << std::endl;
    }
    this->isOpened = true;
    while (this->isOpened) {
        std::cout << "Choice: ";
        size_t choice;
        if (std::cin >> choice && choice >= 1 && choice <= this->options.size()) {
            this->options[choice - 1]->use(*this);
        }
    }
}

void Menu::close() {
    this->isOpened = false;
}
