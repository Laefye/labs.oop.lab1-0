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
            Figure* figure = *iter;
            iter = this->figures.erase(iter);
            delete figure;
        } else {
            iter++;
        }
    }
}
