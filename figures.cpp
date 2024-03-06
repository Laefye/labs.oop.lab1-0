#include "figures.h"
#include <iostream>

Figures::Figures() {
    factories.push_back(new CircleFactory());
    factories.push_back(new RectangleFactory());
}

Figures::~Figures() {
    for (Factory* factory : factories) {
        delete factory;
    }
}

void Figures::show() {
    int i = 1;
    for (Factory* factory : factories) {
        std::cout << i << ") " << factory->getName() << std::endl;
        i++;
    }
}

void Figures::create(int indexFactory, Figure*& output) {
    factories[indexFactory - 1]->create(output);
}
