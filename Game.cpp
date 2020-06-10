#include"Game.h"
#include"TextureManager.h"
#include"GameObject.h"
#include"Map.h"
#include<iostream>

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;
Map* map;

// Constructor
Game::Game() : isRunning(false), window(nullptr){
}

// Destructor
Game::~Game() {
}

// Initialize
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	// Flag for putting the window in full screen mode
	// Note: as a general rule, SDL uses integer flags that are in all caps and
	// constants. The value of these flags is opaque by design. Expect code
	// like the code below.
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Attempt to initialize
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!..." << std::endl;

		// Create the window
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// Check if the window is made
		if (window) {
			std::cout << "Window Created!..." << std::endl;
		}

		// Create the renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		// Check if the renderer was created
		if (renderer) {
			// Set render draw color to white
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer Created!..." << std::endl;
		}

		isRunning = true;

		player = new GameObject("assets/Square.png");
		map = new Map();
	}
	else {
		isRunning = false;
	}
}

// Handle Events
void Game::handleEvents() {
	// Event to handle capture user input
	SDL_Event event;

	// Poll the event
	SDL_PollEvent(&event);

	// Check for types of events
	switch (event.type) {
		case SDL_QUIT:
			// If x is pressed, quit
			isRunning = false;
			break;
		default:
			break;
	}
}

// Update
void Game::update() {
	player->update();
}

// Render
void Game::render() {
	// Clear the screen
	SDL_RenderClear(renderer);

	// Render the map
	map->drawMap();

	// Render the Game Objects
	player->render();

	// Flip the screen
	SDL_RenderPresent(renderer);
}

// Clean
void Game::clean() {
	// Clean up the window
	SDL_DestroyWindow(window);
	window = nullptr;
	// Clean up the renderer
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	// Quit SDL
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

// Running
bool Game::running() {
	return isRunning;
}