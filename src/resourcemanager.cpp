#include <iostream>
#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.h"
#include "ResourceManager.h"

ResourceManager::ResourceManager(SDL_Renderer* prenderer):
    renderer(prenderer){
    if(!(IMG_Init(IMG_INIT_PNG))){
        std::cout << "<RESOURCEMANAGER> IMG could not be initialised. SDL_ERROR: " << SDL_GetError() << std::endl;
    } else{
        std::cout << "<RESOURCEMANAGER> IMG initialised.\n";
    }
    
}

ResourceManager::~ResourceManager(){
    for(auto& item: textures){
        SDL_DestroyTexture(item.second);            // destroy texture               
    }
    std::cout << "<RESOURCEMANAGER> Textures successfully destroyed.\n";
}

void ResourceManager::loadTexture(const std::string& name, const char* file){
    SDL_Texture* tex = IMG_LoadTexture(renderer, file);
    textures.emplace(name, tex);                       // keep this here even if texture doesnt load successfully as to not cause crashes in other classes trying to access tex

    if (tex == NULL){
        std::cout << "<RESOURCEMANAGER> Failed to load a texture. Error: " << SDL_GetError() << std::endl;
    }
}

void ResourceManager::delTexture(const std::string& name){
    SDL_DestroyTexture(textures.at(name));
    textures.erase(name);
}

SDL_Texture* ResourceManager::getTexture(const std::string& name){
    return textures.at(name);                                    
}

Point ResourceManager::getTexSize(const std::string& name){
    Point size = Point(0, 0);
    SDL_QueryTexture(getTexture(name), NULL, NULL, &size.x, &size.y);
    return size;
}

