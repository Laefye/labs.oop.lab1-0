#include "menu.h"

Menu::Menu() {
    this->options.push_back(std::shared_ptr<Option>(new Option("Create a figure", &Menu::createFigure)));
    this->factories.push_back(std::shared_ptr<Factory>(new CircleFactory(this->params)));
    this->factories.push_back(std::shared_ptr<Factory>(new RectangleFactory(this->params)));
}

void Menu::open() {
    while (1) {
        size_t i = 1;
        for (std::shared_ptr<Option>& option : this->options) {
            std::cout << i++ << ") " << option->first << std::endl;
        }
        std::cout << "Choice: ";
        size_t choice;
        if (std::cin >> choice && choice >= 1 && choice <= this->options.size()) {
            (this->*(this->options[choice - 1]->second))();
        } else {
            break;
        }
    }
}

void Menu::createFigure() {
    size_t i = 1;
    for (std::shared_ptr<Factory>& factory : this->factories) {
        std::cout << i++ << ") " << factory->getName() << std::endl;
    }
    std::cout << "Choice: ";
    size_t choice;
    if (std::cin >> choice && choice >= 1 && choice <= this->factories.size()) {
        try {
            auto d = this->factories[choice - 1]->create();
        } catch (BadParams params) {
            std::cout << "Error: " << params.what() << std::endl;
        }
    }
}
