#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>

class MenuItem {
private:
    std::string name;
public:
    MenuItem(std::string name);

    std::string getName();

    virtual void use();
};

class Menu : MenuItem
{
private:
    std::vector<MenuItem> items;
public:
    Menu();

    void addItem(MenuItem& item);

    void use() override;
};

#endif // MENU_H
