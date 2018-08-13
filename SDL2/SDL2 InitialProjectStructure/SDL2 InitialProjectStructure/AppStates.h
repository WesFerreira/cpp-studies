#ifndef STATES_H_INCLUDED
#define STATES_H_INCLUDED

class App
{
public:
	App();
	static void init();
private:

};

App::App()
{
}

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
	}
	catch (const std::exception& e) {
		std::cout << SDL_GetError;
	}
}

#endif // !STATES_H_INCLUDED
