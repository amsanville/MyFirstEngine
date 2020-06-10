#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include"Game.h"
class GameObject {
private:
	// Position on screen
	int xPos;
	int yPos;
	//Texture for the object
	SDL_Texture* objTexture;
	// Rectangles for rendering it
	SDL_Rect srcRect, destRect;

public:
	// Contructor creates texture and gives GameObject a renderer
	GameObject(const char* textureSheet, int x = 0, int y = 0);
	// Destructor
	~GameObject();

	// Update the according to the step
	void update();
	// Render according to the current texture
	void render();

};


#endif
