#include "Game.h"

Game* game = nullptr;

const char *programName = "SDL2: Template";

int main(int argc, char *argv[]) {
	std::cout << "Poly Engine Version 1.0.0" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	system("timeout 2 >nul");
	std::cout << "Please wait for everything to load up." << std::endl;
	std::cout << "If there is a error, please contact the developer." << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	system("timeout 2 >nul");
	std::cout << "Loading SDL2..." << std::endl;
	system("timeout 4 >nul");

	game = new Game();

	game->init(programName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false); //  if you want a full screen game, change false to true.

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	// goto Game.cpp to change some values and to add sprites, tutorial in the file.

	return 0;
}