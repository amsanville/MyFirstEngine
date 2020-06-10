#ifndef MAP_H
#define MAP_H
#include"Game.h"

class Map {
private:
	// Rectangles for rendering
	SDL_Rect src, dest;
	
	// Tile sheets
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	// Array of integers to indicate what the map will look like on the screen
	int map[20][25];
public:
	Map();
	~Map();

	void loadMap(const int arr[20][25]);
	void drawMap();
};

#endif
