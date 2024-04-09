#include "polygonmaker.h"

PolygonMaker::PolygonMaker() : Maker("Polygon")
{

}

Figure* PolygonMaker::make() {
    std::string name;
    std::vector<Point> points;
    read("Name", name);
    read("Points", points);
    return new Polygon(name, points);
}
