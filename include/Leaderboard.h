#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include "View.h"
#include "DisplayManager.h"
#include "ResourceManager.h"
#include "BackgroundShapes.h"

class Leaderboard : public View{
    std::string changeView;
    BackgroundShapes backgroundShapes;

    void updateButtons(DisplayManager* display, double dt);

    public:
    Leaderboard(ResourceManager* resources, const Point& screenSize);
    std::string update(DisplayManager* display, double dt);
};

#endif