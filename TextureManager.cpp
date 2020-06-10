#include "TextureManager.h"


// Load Texture
SDL_Texture* TextureManager::loadTexture(const char* filename) {
	// Create a temporary surface
	SDL_Surface* tempSurface = IMG_Load(filename);
	// Convert to a texture
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	// Clean up
	SDL_FreeSurface(tempSurface);
	// Return
	return tex;
}

// Draw
void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}