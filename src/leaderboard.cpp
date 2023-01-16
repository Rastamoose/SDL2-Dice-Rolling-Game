#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "View.h"
#include "DisplayManager.h"
#include "ResourceManager.h"
#include "Leaderboard.h"

Leaderboard::Leaderboard(ResourceManager* resources, const Point& screenSize):       
    changeView(""), backgroundShapes(BackgroundShapes(screenSize, 3, 15, 3, Colour(247,178,165,255), 20, 2)){}

std::string Leaderboard::update(DisplayManager* display, double dt){
    changeView = "";
    display->setBg(Colour(242, 139, 91, 255));
    backgroundShapes.update(display, dt);

    if (display->inputs->isPressed(SDL_SCANCODE_ESCAPE)){
        changeView = "mainmenu";
    }

    return changeView;
}