#include "shapes/shapes.h"
#include "menu.h"

int main()
{
    Shapes shapes;
    Menu menu{shapes};
    menu.open();
}
