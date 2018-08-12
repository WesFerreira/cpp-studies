/*
	Created by WesFerreira 12/08/2018 
		  ♥Happy father's day♥
*/
#include "commons.h"

using namespace std;
int main(int argc, char * argv[])
{
	// SDL working test.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
	}
	else
	{
		cout << "SDL initialization succeeded!";
	}
	cin.get();
	// Test end.

	return 0;
}