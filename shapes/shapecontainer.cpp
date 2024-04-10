#include "shapecontainer.h"

ShapeCotainer::ShapeCotainer()
{

}

ShapeCotainer::~ShapeCotainer() {
    for (Shape* figure : this->figures) {
        delete figure;
    }
}

void ShapeCotainer::add(Shape* figure) {
    figures.push_back(figure);
}


const std::vector<Shape*>& ShapeCotainer::getVector() {
    return this->figures;
}

std::string ShapeCotainer::getType(Shape* figure) const {
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

double ShapeCotainer::sumAreas() const {
    double sum = 0;
    for (Shape* figure : this->figures) {
        sum += figure->getArea();
    }
    return sum;
}

bool compare(Shape* a, Shape* b) {
    return a->getArea() < b->getArea();
}

void ShapeCotainer::sort() {
    std::sort(this->figures.begin(), this->figures.end(), compare);
}

void ShapeCotainer::remove(size_t index) {
    if (index >= figures.size()) {
        throw IncorrectFigureIndexException();
    }
    delete figures.at(index);
    figures.erase(figures.begin() + index);
}

void ShapeCotainer::removeBiggerArea(double area) {
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
