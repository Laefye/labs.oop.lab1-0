#include "figures/figurecontainer.h"
#include "menu.h"

int main()
{
    FigureContainer container;
    Menu menu{container};
    menu.open();
}
