#include <cmath>
#include <vector>
#include "Utils.h"
#include "DisplayManager.h"
#include "Cube.h"

// Conversions cause points to lose accuracy over time and thus become smaller (use -Wconversion flag to check)

Cube::Cube(const Point& ppos, int pwidth, const Colour& pcolour, int pthickness): pos(ppos), width(pwidth), colour(pcolour), thickness(pthickness){
    // initialise points
    float x = float(pos.x);
    float y = float(pos.y);
    points.push_back({x,y,x});
    points.push_back({x+width,y,x});
    points.push_back({x+width,y+width,x});
    points.push_back({x,y+width,x});

    points.push_back({x,y,x+width});
    points.push_back({x+width,y,x+width});
    points.push_back({x+width,y+width,x+width});
    points.push_back({x,y+width,x+width});

    // Calculate centeroid
    //
    for(auto& p : points){
        centeroid.x += p.x;
        centeroid.y += p.y;
        centeroid.z += p.z;
    }                               // add up all points on each axis then divide by total points
    centeroid.x /= points.size();
    centeroid.y /= points.size();
    centeroid.z /= points.size();
}

void Cube::rotate(Point3& point, double dt, float x, float y, float z){
    float rad = 0;
    
    rad = x*dt;
    point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
    point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

    rad = y*dt;
    point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
    point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

    rad = z*dt;
    point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
    point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;

}

void Cube::update(DisplayManager* display, double dt){
    for(auto& p : points){
        p.x -= centeroid.x;         // subtract centeroid from points of each axis
        p.y -= centeroid.y;
        p.z -= centeroid.z;
        rotate(p, dt, 0.001, 0.005, 0.002);
        p.x += centeroid.x;         // then add centeroid from points of each axis to restore points
        p.y += centeroid.y;
        p.z += centeroid.z;

        // subtract maximum of 2 from thickness when drawing corner points
        int tThickness = thickness;                             // temp thickness in 
        if (!(tThickness < 2)){
            --tThickness;
            if (!(tThickness < 2))  --tThickness;
        }    
        display->drawThickPoint(Point(p.x, p.y), tThickness, colour);
    }

    for(auto& con : connections){
        display->drawThickLine(Point(points[con.a].x, points[con.a].y), Point(points[con.b].x, points[con.b].y), thickness, colour);
    }
}