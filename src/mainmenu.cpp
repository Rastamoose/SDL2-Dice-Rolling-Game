#include <iostream>
#include <string>
#include <unordered_map>
#include "View.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Button.h"
#include "MainMenu.h"

MainMenu::MainMenu(ResourceManager* resources, const Point& screenSize):       
    changeView(""), backgroundShapes(BackgroundShapes(screenSize, 3, 15, 3, Colour(67,76,94,255), 20, 2)){

    buttons.emplace("play", Button(resources, "./res/img/mainmenu/menubutton/play", 1, 6, Point(0,215)));
    buttons.emplace("leaderboard", Button(resources, "./res/img/mainmenu/menubutton/leaderboard", 1, 6, Point(0,340)));
    buttons.emplace("settings", Button(resources, "./res/img/mainmenu/menubutton/settings", 1, 6, Point(0,465)));
    buttons.emplace("quit", Button(resources, "./res/img/mainmenu/menubutton/quit", 1, 8, Point(1184,30)));
}

void MainMenu::updateButtons(DisplayManager* display, double dt){
    // update and render all buttons
    for (auto& button: buttons){
        button.second.update(display->inputs, dt);
        button.second.render(display);
    }

    // check for viewchanges
    if (buttons.at("play").isPressed){
        changeView = "game";
    } else if (buttons.at("leaderboard").isPressed){
        changeView = "leaderboard";
    } else if (buttons.at("settings").isPressed){
        changeView = "settings";
    } else if (buttons.at("quit").isPressed){
        changeView = "quit";
    }
}

std::string MainMenu::update(DisplayManager* display, double dt){
    changeView = "";
    display->setBg(Colour(46, 52, 73, 255));
    backgroundShapes.update(display, dt);
    updateButtons(display, dt);
    
    return changeView;
}