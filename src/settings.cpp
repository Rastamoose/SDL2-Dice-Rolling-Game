#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "View.h"
#include "DisplayManager.h"
#include "ResourceManager.h"
#include "Settings.h"

Settings::Settings(ResourceManager* resources, const Point& screenSize):       
    changeView(""), backgroundShapes(BackgroundShapes(screenSize, 3, 15, 3, Colour(67,76,94,255), 20, 2)){}

std::string Settings::update(DisplayManager* display, double dt){
    changeView = "";
    display->setBg(Colour(233, 190, 76, 255));
    backgroundShapes.update(display, dt);

    if (display->inputs->isPressed(SDL_SCANCODE_ESCAPE)){
        changeView = "mainmenu";
    }

    return changeView;
}