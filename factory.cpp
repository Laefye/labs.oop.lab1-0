#include "factory.h"

Factory::Factory(std::string name) {
    this->name = name;
}

Factory::~Factory() {

}

std::string Factory::getName() {
    return this->name;
}

void Factory::create(Figure*& output) {
    output = 0;
}
