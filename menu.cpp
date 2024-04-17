#include "menu.h"

Menu::Menu(FigureContainer& container) : container(container) {
    this->options.push_back(new Option("Create a figure", &Menu::createFigure));
    this->options.push_back(new Option("List figures with params", &Menu::listWithParams));
    this->options.push_back(new Option("List figures with areas", &Menu::listWithAreas));
    this->options.push_back(new Option("Sort by areas", &Menu::sort));
    this->options.push_back(new Option("Remove by index", &Menu::removeByIndex));
    this->options.push_back(new Option("Remove more than input area", &Menu::removeMoreArea));
    this->makers.push_back(new CircleMaker());
    this->makers.push_back(new RectangleMaker());
    this->makers.push_back(new TriangleMaker());
    this->makers.push_back(new PolygonMaker());
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
        } else if (std::cin.fail()) {
            this->clearFromInput();
        }
        std::cout << std::endl;
    }
}

void Menu::createFigure() {
    size_t i = 1;
    for (Maker* maker : this->makers) {
        std::cout << i++ << ") " << maker->getName() << std::endl;
    }
    std::cout << "Choice: ";
    size_t choice;
    if (std::cin >> choice && choice >= 1 && choice <= this->makers.size()) {
        try {
            this->container.add(this->makers[choice - 1]->make());
        } catch (std::exception& err) {
            std::cout << "Error: " << err.what() << std::endl;
        }
    } else if (std::cin.fail()) {
        this->clearFromInput();
    }
}

void Menu::listWithParams() {
    size_t i = 1;
    for (Figure* shape : this->container.getVector()) {
        std::cout << i++ << ") " << shape->getParams() << std::endl;
    }
}

void Menu::listWithAreas() {
    size_t i = 1;
    for (Figure* shape : this->container.getVector()) {
        std::cout << i++ << ") " << shape->getParams() << " = " << shape->getArea() << std::endl;
    }
}

void Menu::sumAreas() {
    std::cout << "Sum: " << this->container.sumAreas() << std::endl;
}

void Menu::sort() {
    this->container.sort();
    this->listWithAreas();
}

void Menu::removeByIndex() {
    std::cout << "Index: ";
    size_t index;
    if (std::cin >> index) {
        try {
            this->container.remove(index - 1);
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
        this->container.removeBiggerArea(area);
    }
    this->listWithAreas();
}

void Menu::clearFromInput() {
    std::cin.clear();
    std::string buffer;
    std::cin >> buffer;
}
