#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>


class Menu;

typedef std::pair<std::string, void (Menu::*)()> Option;


class Menu
{
private:
    std::vector<std::shared_ptr<Option>> options;
    bool isOpened = false;
    void add(const std::shared_ptr<Option>& option);
public:
    Menu();
    void open();
    void close();
};

#endif // MENU_H
