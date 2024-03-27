#include "menu.h"

Menu::Menu(Figures& figures) : figures(figures) {
    this->options.push_back(std::shared_ptr<Option>(new Option("Create a figure", &Menu::createFigure)));
    this->options.push_back(std::shared_ptr<Option>(new Option("List figures with params", &Menu::listFiguresWithParams)));
    this->options.push_back(std::shared_ptr<Option>(new Option("List figures with areas", &Menu::listFiguresWithAreas)));
    this->options.push_back(std::shared_ptr<Option>(new Option("Sort by areas", &Menu::sort)));
    this->options.push_back(std::shared_ptr<Option>(new Option("Remove by index", &Menu::removeByIndex)));
    this->options.push_back(std::shared_ptr<Option>(new Option("Remove more than input area", &Menu::removeMoreArea)));
    this->factories.push_back(std::shared_ptr<Factory>(new CircleFactory(this->params)));
    this->factories.push_back(std::shared_ptr<Factory>(new RectangleFactory(this->params)));
    this->factories.push_back(std::shared_ptr<Factory>(new TriangleFactory(this->params)));
}

void Menu::open() {
    while (1) {
        std::cout << "Menu: " << std::endl;
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
            this->figures.add(this->factories[choice - 1]->create());
        } catch (BadParams params) {
            std::cout << "Error: " << params.what() << std::endl;
        }
    }
}

void Menu::listFiguresWithParams() {
    size_t i = 1;
    for (const std::shared_ptr<Figure>& figure : this->figures.getVector()) {
        std::cout << i++ << ") " << this->figures.getType(figure) << " (" << figure->getParams() << ")" << std::endl;
    }
}

void Menu::listFiguresWithAreas() {
    size_t i = 1;
    for (const std::shared_ptr<Figure>& figure : this->figures.getVector()) {
        std::cout << i++ << ") " << this->figures.getType(figure) << " = " << figure->getArea() << std::endl;
    }
}

void Menu::sumAreas() {
    std::cout << "Sum: " << this->figures.sumAreas() << std::endl;
}

void Menu::sort() {
    this->figures.sort();
    this->listFiguresWithAreas();
}

void Menu::removeByIndex() {
    std::cout << "Index: ";
    size_t index;
    if (std::cin >> index) {
        try {
            this->figures.remove(index - 1);
        }  catch (IncorrectFigureIndex figure) {
            std::cout << "Error: " << figure.what() << std::endl;
        }
    }
    this->listFiguresWithParams();
}

void Menu::removeMoreArea() {
    std::cout << "Area: ";
    double area;
    if (std::cin >> area) {
        this->figures.removeBiggerArea(area);
    }
    this->listFiguresWithAreas();
}


