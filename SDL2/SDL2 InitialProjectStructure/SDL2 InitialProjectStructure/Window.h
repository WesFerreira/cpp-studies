/*This base code copyrighted by Lazy Foo' Productions -> http://lazyfoo.net/tutorials/SDL/36_multiple_windows/index.php
* Rewrited by Wes Ferreira.
*/

#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <sstream>

class Window
{
public:
	// Methods
	Window();
	bool init();

	void handleEvent(SDL_Event& e);
	void focus();
	void render();
	void free();

	// Has & Is
	bool hasMouseFocus();
	bool hasKeyboardFocus();
	bool isMinimized();
	bool isShown();

	// Getters & Setters
	int getWidth();
	int getHeight();
	int getID();

	void setTitle(char*);
	void setSize(int, int);
	void setPosition(int, int);
	void setFlags(Uint32);
	void setBorders(bool);

private:
	//Window data
	SDL_Window* instance;
	SDL_Renderer* renderer;

	int id;
	char *title = APP_NAME;

	int width = 600;
	int height = 400;
	int x = 200;
	int y = 200;
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	bool bordered = true;

	//Window focus
	bool mouseFocus;
	bool keyboardFocus;
	bool fullScreen;
	bool minimized;
	bool shown;
};

/*
* Constructor
*/
Window::Window()
{
	//Initialize non-existant window
	instance = NULL;
	renderer = NULL;

	mouseFocus = false;
	keyboardFocus = false;
	fullScreen = false;
	shown = false;
	id = -1;
}

/*
* Create window
*/
bool Window::init()
{
	instance = SDL_CreateWindow(title,
		x,
		y,
		width,
		height,
		flags
	);

	if (instance != NULL)
	{
		if (bordered) {
			SDL_SetWindowBordered(instance, SDL_TRUE);
		}
		else {
			SDL_SetWindowBordered(instance, SDL_FALSE);
		}
		mouseFocus = true;
		keyboardFocus = true;

		//Create renderer for window
		renderer = SDL_CreateRenderer(instance, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			SDL_DestroyWindow(instance);
			instance = NULL;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Grab window identifier
			id = SDL_GetWindowID(instance);

			//Flag as opened
			shown = true;
		}
	}
	else
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	}

	return instance != NULL && renderer != NULL;
}

void Window::handleEvent(SDL_Event& e)
{
	//If an event was detected for this window
	if (e.type == SDL_WINDOWEVENT && e.window.windowID == id)
	{
#ifdef DEBUG
		//Caption update flag
		bool updateCaption = false;
#endif // DEBUG

		switch (e.window.event)
		{
			//Window appeared
		case SDL_WINDOWEVENT_SHOWN:
			shown = true;
			break;

			//Window disappeared
		case SDL_WINDOWEVENT_HIDDEN:
			shown = false;
			break;

			//Get new dimensions and repaint
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			// Do Something
			break;

			//Repaint on expose
		case SDL_WINDOWEVENT_EXPOSED:
			// Do Something
			break;

			//Mouse enter
		case SDL_WINDOWEVENT_ENTER:
			mouseFocus = true;
#ifdef DEBUG
			updateCaption = true;
#endif // DEBUG

			break;

			//Mouse exit
		case SDL_WINDOWEVENT_LEAVE:
			mouseFocus = false;
#ifdef DEBUG
			updateCaption = true;
#endif // DEBUG

			break;

			//Keyboard focus gained
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			keyboardFocus = true;
#ifdef DEBUG
			updateCaption = true;
#endif // DEBUG			

			break;

			//Keyboard focus lost
		case SDL_WINDOWEVENT_FOCUS_LOST:
			keyboardFocus = false;
#ifdef DEBUG
			updateCaption = true;
#endif // DEBUG			

			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			minimized = true;
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
			break;

			//Hide on close
		case SDL_WINDOWEVENT_CLOSE:
			SDL_HideWindow(instance);
			break;
		}

#ifdef DEBUG
		//Update window caption with new data
		if (updateCaption)
		{
			std::stringstream caption;
			caption << "*DebugMode* " << title << " - ID: " << id << " MouseFocus:" << ((mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((keyboardFocus) ? "On" : "Off");
			SDL_SetWindowTitle(instance, caption.str().c_str());
		}
#endif // DEBUG


	}
}

/*
* Focuses on window
*/
void Window::focus()
{
	//Restore window if needed
	if (!shown)
	{
		SDL_ShowWindow(instance);
	}

	//Move window forward
	SDL_RaiseWindow(instance);
}

/*
* Shows windows contents
*/
void Window::render()
{
	if (!minimized)
	{
		//Clear screen
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		//Update screen
		SDL_RenderPresent(renderer);
	}
}

/*
* Deallocates internals
*/
void Window::free()
{
	if (instance != NULL)
	{
		SDL_DestroyWindow(instance);
	}

	mouseFocus = false;
	keyboardFocus = false;
	width = 0;
	height = 0;
}

// Has & Is
bool Window::hasMouseFocus()
{
	return mouseFocus;
}

bool Window::hasKeyboardFocus()
{
	return keyboardFocus;
}


bool Window::isMinimized()
{
	return minimized;
}

bool Window::isShown()
{
	return shown;
}

// Getters & Setters
int Window::getWidth()
{
	return width;
}

int Window::getID()
{
	return id;
}

int Window::getHeight()
{
	return height;
}


void Window::setTitle(char *newTitle) {
	title = newTitle;
}

void Window::setSize(int w, int h) {
	height = h;
	width = w;
}

void Window::setPosition(int positionX, int positionY) {
	x = positionX;
	y = positionY;
}

void Window::setFlags(Uint32 newFlags) {
	flags = newFlags;
}

void Window::setBorders(bool newBordered) {
	bordered = newBordered;
}

#endif // !WINDOW_H_INCLUDED

