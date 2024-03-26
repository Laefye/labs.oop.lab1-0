#include "mainmenu.h"
#include <iostream>

class HelloWorld : public Option {
public:
    HelloWorld() : Option("Say Hello World") {

    }

    void use(Menu& menu) override {
        std::cout << "Hello World, and opening new menu" << std::endl;
        MainMenu m;
        m.open();
    }
};

class Quit : public Option {
public:
    Quit() : Option("Quit") {

    }

    void use(Menu& menu) override {
        std::cout << "Quiting..." << std::endl;
        menu.close();
    }
};


MainMenu::MainMenu()
{
    add(std::shared_ptr<Option>{new HelloWorld()});
    add(std::shared_ptr<Option>{new Quit()});
}
