#include "figures.h"
#include <algorithm>

const char* ImpossibleCasting::what() const noexcept {
    return "Impossible to cast figure";
}

const char* IncorrectFigureIndex::what() const noexcept {
    return "Incorrect figure index";
}

Figures::Figures()
{

}

void Figures::add(const std::shared_ptr<Figure>& figure) {
    figures.push_back(figure);
}


const std::vector<std::shared_ptr<Figure>>& Figures::getVector() {
    return this->figures;
}

std::string Figures::getType(const std::shared_ptr<Figure>& figure) const {
    std::string type = "Figure";
    Figure* pointer = figure.get();
    if (dynamic_cast<Circle*>(pointer)) {
        type = "Circle";
    } else if (dynamic_cast<Rectangle*>(pointer)) {
        type = "Rectangle";
    } else if (dynamic_cast<Triangle*>(pointer)) {
        type = "Triangle";
    }
    return type;
}

double Figures::sumAreas() const {
    double sum = 0;
    for (const std::shared_ptr<Figure>& figure : this->figures) {
        sum += figure->getArea();
    }
    return sum;
}

bool compare(std::shared_ptr<Figure>& a, std::shared_ptr<Figure>& b) {
    return a->getArea() < b->getArea();
}

void Figures::sort() {
    std::sort(this->figures.begin(), this->figures.end(), compare);
}

void Figures::remove(size_t index) {
    if (index >= figures.size()) {
        throw IncorrectFigureIndex();
    }
    figures.erase(figures.begin() + index);
}

void Figures::removeBiggerArea(double area) {
    std::vector<std::shared_ptr<Figure>>::iterator iter = this->figures.begin();
    while (iter != this->figures.end()) {
        if ((*iter)->getArea() > area) {
            this->figures.erase(iter);
        } else {
            iter++;
        }
    }
}
