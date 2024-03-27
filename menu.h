#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "paramsfrominput.h"
#include "figures/figures.h"
#include "factories/factory.h"
#include "factories/circlefactory.h"
#include "factories/rectanglefactory.h"
#include "factories/trianglefactory.h"


class Menu;

typedef std::pair<std::string, void (Menu::*)()> Option;


class Menu
{
private:
    Figures& figures;
    std::vector<std::shared_ptr<Option>> options;
    bool isOpened = false;
    ParamsFromInput params;
    std::vector<std::shared_ptr<Factory>> factories;

    void close();

    void createFigure();
    void listFiguresWithParams();
    void listFiguresWithAreas();
    void sumAreas();
    void sort();
    void removeByIndex();
    void removeMoreArea();
public:
    Menu(Figures& figures);
    void open();

};

#endif // MENU_H
