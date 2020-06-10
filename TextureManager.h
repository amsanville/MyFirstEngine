#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include"Game.h"

class TextureManager {
public:
	// Loads images from the files into an SDL_Texture
	static SDL_Texture* loadTexture(const char* filename);
	// Wrapper method for SDL_RenderCopy that uses the game's renderer
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);
};

#endif