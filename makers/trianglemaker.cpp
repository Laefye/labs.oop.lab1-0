#include "trianglemaker.h"

TriangleMaker::TriangleMaker() : Maker("Triangle")
{

}

Figure* TriangleMaker::make() {
    std::string name;
    Point first;
    Point second;
    Point third;
    this->read("Name", name);
    this->read("First point", first);
    this->read("Second point", second);
    this->read("Third point", third);
    return new Triangle(name, first, second, third);
}
