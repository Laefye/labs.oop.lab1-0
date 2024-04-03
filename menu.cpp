#include "menu.h"

Menu::Menu(Shapes& shapes) : shapes(shapes) {
    this->options.push_back(new Option("Create a shape", &Menu::createShape));
    this->options.push_back(new Option("List shapes with params", &Menu::listWithParams));
    this->options.push_back(new Option("List shapes with areas", &Menu::listWithAreas));
    this->options.push_back(new Option("Sort by areas", &Menu::sort));
    this->options.push_back(new Option("Remove by index", &Menu::removeByIndex));
    this->options.push_back(new Option("Remove more than input area", &Menu::removeMoreArea));
    this->makers.push_back(new CircleMaker());
    this->makers.push_back(new RectangleMaker());
    this->makers.push_back(new TriangleMaker());
}

Menu::~Menu() {
    for (Maker* maker : this->makers) {
        delete maker;
    }
    for (Option* option : this->options) {
        delete option;
    }
}

void Menu::open() {
    while (1) {
        std::cout << "Menu: " << std::endl;
        size_t i = 1;
        for (Option* option : this->options) {
            std::cout << i++ << ") " << option->first << std::endl;
        }
        std::cout << "Choice: ";
        size_t choice;
        if (std::cin >> choice && choice >= 1 && choice <= this->options.size()) {
            (this->*(this->options[choice - 1]->second))();
        } else {
            break;
        }
        std::cout << std::endl;
    }
}

void Menu::createShape() {
    size_t i = 1;
    for (Maker* maker : this->makers) {
        std::cout << i++ << ") " << maker->getName() << std::endl;
    }
    std::cout << "Choice: ";
    size_t choice;
    if (std::cin >> choice && choice >= 1 && choice <= this->makers.size()) {
        try {
            this->shapes.add(this->makers[choice - 1]->make());
        } catch (std::exception& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    }
}

void Menu::listWithParams() {
    size_t i = 1;
    for (Shape* shape : this->shapes.getVector()) {
        std::string params = "";
        shape->outputParams(params);
        std::cout << i++ << ") " << this->shapes.getType(shape) << " (" << params << ")" << std::endl;
    }
}

void Menu::listWithAreas() {
    size_t i = 1;
    for (Shape* shape : this->shapes.getVector()) {
        std::cout << i++ << ") " << this->shapes.getType(shape) << " = " << shape->getArea() << std::endl;
    }
}

void Menu::sumAreas() {
    std::cout << "Sum: " << this->shapes.sumAreas() << std::endl;
}

void Menu::sort() {
    this->shapes.sort();
    this->listWithAreas();
}

void Menu::removeByIndex() {
    std::cout << "Index: ";
    size_t index;
    if (std::cin >> index) {
        try {
            this->shapes.remove(index - 1);
        }  catch (IncorrectFigureIndexException& figure) {
            std::cout << "Error: " << figure.what() << std::endl;
        }
    }
    this->listWithParams();
}

void Menu::removeMoreArea() {
    std::cout << "Area: ";
    double area;
    if (std::cin >> area) {
        this->shapes.removeBiggerArea(area);
    }
    this->listWithAreas();
}
