#include <vector>
#include <iostream>
#include "menu.h"
#include "figures/figures.h"

int main()
{
    Figures figures;
    Menu menu{figures};
    menu.open();
}
