#include <vector>
#include <iostream>
#include <algorithm>

#include "figures.h"

bool sort(Figure* a, Figure* b) {
    return a->getArea() < b->getArea();
}

int main()
{
    std::vector<Figure*> figures;
    std::cout << "1) Create figure" << std::endl;
    std::cout << "2) List figure with them parameters" << std::endl;
    std::cout << "3) List figure with them areas" << std::endl;
    std::cout << "4) Sum of areas" << std::endl;
    std::cout << "5) Sort" << std::endl;

    bool isRunning = true;

    while (isRunning) {
        int choice = 0;
        if (std::cin >> choice) {
           switch (choice) {
           case 1:
               {
                   Figures factories;
                   factories.show();
                   if (std::cin >> choice) {
                       Figure* figure;
                       factories.create(choice, figure);
                       figures.push_back(figure);
                   }
               }
               break;
           case 2:
               {
                   int i = 1;
                   for (Figure* figure : figures) {
                        std::cout << i << ") " << figure->getFigureName() << " " << figure->getParameters() << std::endl;
                        i++;
                   }
               }
               break;
           case 3:
               {
                   int i = 1;
                   for (Figure* figure : figures) {
                        std::cout << i << ") " << figure->getFigureName() << " " << figure->getArea() << std::endl;
                        i++;
                   }
               }
               break;
           case 4:
               {
                   float sum = 0;
                   for (Figure* figure : figures) {
                        sum += figure->getArea();
                   }
                   std::cout << "Sum: " << sum << std::endl;
               }
               break;
           case 5:
                std::sort(figures.begin(), figures.end(), sort);
                break;
           }
        } else {
            break;
        }
    }

    for (Figure* figure : figures) {
        delete figure;
    }
}
