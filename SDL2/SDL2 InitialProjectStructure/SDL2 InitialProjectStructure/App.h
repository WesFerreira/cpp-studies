#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/*
 Singleton pattern class
*/

#include "Window.h"

class App
{

public:
	/////////////////////	SINGLETON	//////////////////////
	/* Static access method. */
	static App* getInstance();
	//////////////////////////////////////////////////////////

	void init();
	void close();
	void updates();
	bool allWindowsClosed();

	//////////GETTERS & SETTERS//////////
	Window getWindows[APP_MAX_WINDOW_NUMBER];


private:
	/////////////////////	SINGLETON	//////////////////////
	/* Here will be the instance stored. */
	static App* instance;
	/* Private constructor to prevent instancing. */
	App();
	//////////////////////////////////////////////////////////


};

/* 
* Null, because instance will be initialized on demand.
*/
App* App::instance = 0;

App* App::getInstance()
{
	if (instance == 0)
	{
		instance = new App();
	}
	return instance;
}

App::App()
{}

/*
* To initialize go to Flags.h and uncomment what you want to initialize
*/
void App::init() {
	try {
#ifdef INIT_VIDEO
		SDL_InitSubSystem(SDL_INIT_VIDEO);
		std::cout << "VIDEO initialized." << std::endl;
#endif // INIT_VIDEO

#ifdef INIT_TIMER
		SDL_InitSubSystem(SDL_INIT_TIMER);
		std::cout << "TIMER initialized." << std::endl;
#endif // INIT_TIMER

#ifdef INIT_AUDIO
		SDL_InitSubSystem(SDL_INIT_AUDIO);
		std::cout << "AUDIO initialized." << std::endl;
#endif // INIT_AUDIO

#ifdef INIT_JOYSTICK
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		std::cout << "JOYSTICK initialized." << std::endl;
#endif // INIT_JOYSTICK

#ifdef INIT_HAPTIC
		SDL_InitSubSystem(SDL_INIT_HAPTIC);
		std::cout << "HAPTIC initialized." << std::endl;
#endif // INIT_HAPTIC

#ifdef INIT_GAMECONTROLLER
		SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
		std::cout << "GAMECONTROLLER initialized." << std::endl;
#endif // INIT_GAMECONTROLLER

#ifdef INIT_EVENTS
		SDL_InitSubSystem(SDL_INIT_EVENTS);
		std::cout << "EVENTS initialized." << std::endl;
#endif // INIT_EVENTS

#ifdef INIT_EVERYTHING
		SDL_Init(SDL_INIT_EVERYTHING);
		std::cout << "EVERYTHING initialized." << std::endl;
#endif // INIT_EVERYTHING

		// Initialize all the windows
		for (int i = 0; i < APP_MAX_WINDOW_NUMBER; ++i)
		{
			App::getInstance()->getWindows[i].init();
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << " || \n" << SDL_GetError(); // Print any error
	}
}

void App::close()
{
	//Destroy windows
	for (int i = 0; i < APP_MAX_WINDOW_NUMBER; ++i)
	{
		getWindows[i].free();
	}

	//Quit SDL subsystems
	SDL_Quit();
}

void App::updates() {
	//Update all windows

	for (int i = 0; i < APP_MAX_WINDOW_NUMBER; ++i)
	{
		getWindows[i].render();
	}
}

/*
* Check if all windos is closed
*/
bool App::allWindowsClosed() {
	//Check all windows
	bool allWClosed = true;
	for (int i = 0; i < APP_MAX_WINDOW_NUMBER; ++i)
	{
		if (getWindows[i].isShown())
		{
			allWClosed = false;
			break;
		}
	}
	return allWClosed;
}

// Getters & Setters


#endif // !APP_H_INCLUDED
