#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <vector>
#include "Utils.h"
#include "DisplayManager.h"
// Conversions cause points to lose accuracy over time and thus become smaller (use -Wconversion flag to check)

struct Point3{
    float x,y,z;
};

struct Connection{
    int a,b;
};

class Cube{
    Point pos;
    int width;
    Colour colour;
    int thickness;
    std::vector<Point3> points;
    std::vector<Connection> connections{
         {0,4},
         {1,5},
         {2,6},
         {3,7},
         
         {0,1},
         {1,2},
         {2,3},
         {3,0},

         {4,5},
         {5,6},
         {6,7},
         {7,4}
    };
    Point3 centeroid{0,0,0};         // centre needed as reference for rotation so points dont fly off

    void rotate(Point3& point, double dt, float x=1, float y=1, float z=1);

    public:
    Cube(const Point& ppos, int pwidth, const Colour& pcolour, int thickness);
    void update(DisplayManager* display, double dt);
};

#endif