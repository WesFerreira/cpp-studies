/*
	Created by WesFerreira 12/08/2018
		  ♥Happy father's day♥
*/
#include "commons.h"
#include "App.h"
#include "Window.h"

using namespace std;

int main(int argc, char *argv[])
{
	SDL_Event e;
	bool running = true;
	App::getInstance()->init(); // Init all SDL systems and all windows

	while (running)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				running = true;
			}

			//Handle window events
			for (int i = 0; i < APP_MAX_WINDOW_NUMBER; ++i)
			{
				App::getInstance()->getWindows[i].handleEvent(e);
			}

			// Non-specific window events
			/*if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_1:
					App::getInstance()->getWindows[0].focus();
					break;
				}
			}*/

			// Specific window events
			/*if (e.window.windowID == App::getInstance()->getWindows[0].getID()) {
				if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym){

					case SDLK_SPACE:
						cout << "win1" << endl;
						break;
					}
				}
			}*/
		}

		App::getInstance()->updates();

		//Application closed all windows
		if (App::getInstance()->allWindowsClosed())
		{
			running = false;
		}
	}

	//Free resources and close SDL
	App::getInstance()->close();
	return 0;
}
