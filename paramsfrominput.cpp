#include "paramsfrominput.h"
#include <iostream>

void ParamsFromInput::get(const std::string &key, std::string &output) const {
    std::cout << key << ": ";
    if (!(std::cin >> output)) {
        throw BadParams(key);
    }
}

void ParamsFromInput::get(const std::string& key, double& output) const {
    std::cout << key << ": ";
    if (!(std::cin >> output)) {
        throw BadParams(key);
    }
}

void ParamsFromInput::get(const std::string& key, Point& output) const {
    std::cout << key << " (x, y): ";
    if (!(std::cin >> output.x)) {
        throw BadParams(key);
    }
    if (!(std::cin >> output.y)) {
        throw BadParams(key);
    }
}

