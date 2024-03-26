#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <memory>
#include <iostream>


class Menu;

class Option {
private:
    const std::string name;
public:
    Option(const std::string& name);

    const std::string& getName();

    virtual void use(Menu& menu) = 0;
};

class Menu
{
private:
    std::vector<std::shared_ptr<Option>> options;
    bool isOpened = false;
protected:
    void add(const std::shared_ptr<Option>& option);
public:
    void open();
    void close();
};

#endif // MENU_H
