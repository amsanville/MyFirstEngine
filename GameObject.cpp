#include"GameObject.h"
#include"TextureManager.h"

// Constructor
GameObject::GameObject(const char* textureSheet, int x, int y) {
	// Lload texture
	objTexture = TextureManager::loadTexture(textureSheet);

	// Set initial position
	xPos = x;
	yPos = y;
}

// Destructor
GameObject::~GameObject() {

}

// Update
void GameObject::update() {

	// This clips the sprite sheet
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	// This scales and translates the sprite into position on the screen
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
}

// Render
void GameObject::render() {
	// Draw the texture
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}