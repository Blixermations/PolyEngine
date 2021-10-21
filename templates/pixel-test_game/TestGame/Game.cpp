#include "Game.h"
using namespace std;

// vars

Game::Game()
{}
Game::~Game()
{}



void Game::init(const char* title, int xpos, int ypos, int width, int heigth, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Ready." << std::endl;
		system("timeout 2 >nul");

		window = SDL_CreateWindow(title, xpos, ypos, width, heigth, flags);

		if (window) {
			std::cout << "Window made with title " << title << std::endl;
			system("timeout 2 >nul");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			std::cout << "SDL_Image version : " << SDL_IMAGE_MAJOR_VERSION << "." << SDL_IMAGE_MINOR_VERSION << "." << SDL_IMAGE_PATCHLEVEL << std::endl;
			std::cout << "Renderer created!" << std::endl;
			system("timeout 2 >nul");

			// lets now draw a bg color.
		}
		isRunning = true;
	}
	else {
		//std::cout << "sdl2 not running." << title << std::endl;
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	// add some stuff for update when your making like key binds and stuff.
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned." << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "Poly Engine is now exiting." << std::endl;
	system("timeout 1 >nul");

}