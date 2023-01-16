// CLASS THAT PROVIDES FUNCTIONALITY TO LOAD AND ORGANISE FILES (AUDIO, TEXTURES ETC)
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.h"

class ResourceManager{
    SDL_Renderer* renderer;
    std::unordered_map<std::string, SDL_Texture*> textures;

    public:
    ResourceManager(SDL_Renderer* prenderer);                                //requires renderer from windowmanager (should be passed in main.cpp)
    ~ResourceManager();             // free all textures 
    void loadTexture(const std::string& name, const char* file);     // load texture and add to texture hashmap
    void delTexture(const std::string& name);
    SDL_Texture* getTexture(const std::string& name);                        // return corresponding texture
    Point getTexSize(const std::string& name);                       // return size of a texture
};

#endif