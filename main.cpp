#include"Game.h"


Game* game = nullptr;

int main(int argc, char *argv[]) {
	// Target frame rate
	const int FPS = 60;
	// Time between frames
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	// Declare new game
	game = new Game();
	// Initialize
	game->init("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	// Game Loop
	while (game->running()) {
		// Get the current running time
		frameStart = SDL_GetTicks();
		
		// Handle User Input
		game->handleEvents();
		// Update all objects
		game->update();
		// Render
		game->render();

		// How long the frame has taken
		// Note: casting here means that it will conver the Uint32 to int after the
		// arithmetic is done.
		frameTime = SDL_GetTicks() - frameStart;

		// Check for delay
		if (frameDelay > frameTime) {
			// Delay by the amount of time left
			SDL_Delay(frameDelay - frameTime);
		}
	}

	// Clean up the game
	game->clean();
	delete game;
	return 0;
}