#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "figures/figurecontainer.h"
#include "makers/maker.h"
#include "makers/circlemaker.h"
#include "makers/rectanglemaker.h"
#include "makers/trianglemaker.h"
#include "makers/polygonmaker.h"
#include "exceptions/incorrectfigureindexexception.h"


class Menu;

typedef std::pair<std::string, void (Menu::*)()> Option;


class Menu
{
private:
    FigureContainer& container;
    std::vector<Option*> options;
    std::vector<Maker*> makers;

    void close();

    void createFigure();
    void listWithParams();
    void listWithAreas();
    void sumAreas();
    void sort();
    void removeByIndex();
    void removeMoreArea();
    void clearFromInput();
public:
    Menu(FigureContainer& figures);
    ~Menu();
    void open();

};

#endif // MENU_H
