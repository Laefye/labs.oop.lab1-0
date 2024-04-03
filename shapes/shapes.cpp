#include "shapes.h"

Shapes::Shapes()
{

}

Shapes::~Shapes() {
    for (Shape* figure : this->figures) {
        delete figure;
    }
}

void Shapes::add(Shape* figure) {
    figures.push_back(figure);
}


const std::vector<Shape*>& Shapes::getVector() {
    return this->figures;
}

std::string Shapes::getType(Shape* figure) const {
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

double Shapes::sumAreas() const {
    double sum = 0;
    for (Shape* figure : this->figures) {
        sum += figure->getArea();
    }
    return sum;
}

bool compare(Shape* a, Shape* b) {
    return a->getArea() < b->getArea();
}

void Shapes::sort() {
    std::sort(this->figures.begin(), this->figures.end(), compare);
}

void Shapes::remove(size_t index) {
    if (index >= figures.size()) {
        throw IncorrectFigureIndexException();
    }
    delete figures.at(index);
    figures.erase(figures.begin() + index);
}

void Shapes::removeBiggerArea(double area) {
    std::vector<Shape*>::iterator iter = this->figures.begin();
    while (iter != this->figures.end()) {
        if ((*iter)->getArea() > area) {
            this->figures.erase(iter);
            delete (*iter);
        } else {
            iter++;
        }
    }
}
