#include "figurecontainer.h"

FigureContainer::FigureContainer()
{

}

FigureContainer::~FigureContainer() {
    for (Figure* figure : this->figures) {
        delete figure;
    }
}

void FigureContainer::add(Figure* figure) {
    figures.push_back(figure);
}


const std::vector<Figure*>& FigureContainer::getVector() {
    return this->figures;
}

std::string FigureContainer::getType(Figure* figure) const {
    std::string type = "Figure";
    if (dynamic_cast<Circle*>(figure)) {
        type = "Circle";
    } else if (dynamic_cast<Rectangle*>(figure)) {
        type = "Rectangle";
    } else if (dynamic_cast<Triangle*>(figure)) {
        type = "Triangle";
    }
    return type;
}

double FigureContainer::sumAreas() const {
    double sum = 0;
    for (Figure* figure : this->figures) {
        sum += figure->getArea();
    }
    return sum;
}

bool compare(Figure* a, Figure* b) {
    return a->getArea() < b->getArea();
}

void FigureContainer::sort() {
    std::sort(this->figures.begin(), this->figures.end(), compare);
}

void FigureContainer::remove(size_t index) {
    if (index >= figures.size()) {
        throw IncorrectFigureIndexException();
    }
    delete figures.at(index);
    figures.erase(figures.begin() + index);
}

void FigureContainer::removeBiggerArea(double area) {
    std::vector<Figure*>::iterator iter = this->figures.begin();
    while (iter != this->figures.end()) {
        if ((*iter)->getArea() > area) {
            this->figures.erase(iter);
            delete (*iter);
        } else {
            iter++;
        }
    }
}
