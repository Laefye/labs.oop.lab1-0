#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "shapes/shapes.h"
#include "makers/maker.h"
#include "makers/circlemaker.h"
#include "makers/rectanglemaker.h"
#include "makers/trianglemaker.h"
#include "exceptions/incorrectfigureindexexception.h"


class Menu;

typedef std::pair<std::string, void (Menu::*)()> Option;


class Menu
{
private:
    Shapes& shapes;
    std::vector<Option*> options;
    std::vector<Maker*> makers;

    void close();

    void createShape();
    void listWithParams();
    void listWithAreas();
    void sumAreas();
    void sort();
    void removeByIndex();
    void removeMoreArea();
public:
    Menu(Shapes& shapes);
    ~Menu();
    void open();

};

#endif // MENU_H
