#ifndef GAME_H
#define GAME_H
#include"SDL.h"
#include"SDL_image.h"

/*
Game Class

Super class that handles all SDL Subsystems and game loop.
*/
class Game {
private:
	bool isRunning;
	SDL_Window* window;
public:
	// Render for all objects in the game
	static SDL_Renderer* renderer;

	// Constructor
	Game();
	// Destructor
	~Game();

	/*
	Initialize

	Initializes SDL Subsystems and creates a window according to the specifications
	passed.
	@param title - Title of the window
	@param xpos - The initial x-position of the window
	@param ypos - The initial y-position of the window
	@param width - The width of the window
	@param height - The height of the window
	@param fullscreen - Boolean for fullscreen mode
	*/
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	/*
	Handle Events

	Handles the user input into the game.
	*/
	void handleEvents();

	/*
	Update

	Updates the game according to the inputs.
	*/
	void update();

	/*
	Render

	Uses the renderer to draw the game into the game window.
	*/
	void render();

	/*
	Clean

	Clean up SDL Subsystems.
	*/
	void clean();

	/*
	Running
	
	Accessor to tell us if the game is running.
	*/
	bool running();
};

#endif
