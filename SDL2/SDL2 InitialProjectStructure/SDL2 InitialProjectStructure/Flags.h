#ifndef FLAGS_H_DEFINED
#define FLAGS_H_DEFINED

//#define DEBUG
#define APP_NAME "SDL Application"

/* 
* Initialize flags
*/
// TODO: Initialize here
#define INIT_VIDEO				// Uncomment to initialize
//#define INIT_TIMER			// Uncomment to initialize
//#define INIT_AUDIO			// Uncomment to initialize
//#define INIT_JOYSTICK			// Uncomment to initialize
//#define INIT_HAPTIC			// Uncomment to initialize
//#define INIT_GAMECONTROLLER   // Uncomment to initialize
//#define INIT_EVENTS			// Uncomment to initialize
//#define INIT_EVERYTHING		// Uncomment to initialize

#define APP_MAX_WINDOW_NUMBER 1		// Modify to be able to create more than 2 windows

/*
* Error messages flags (don't modify)
*/
#define ERR_WINDOW_OVERFLOW "ERROR - Cannot add window: To add more windows to the App first you must to set flag APP_MAX_WINDOW_NUMBER. (Flags.h)\n"
#define ERR_INDEX_WINDOW "ERROR - You're trying to get a window by invalid index: Verify getWindow() usages.\n"

#endif // !FLAGS_H_DEFINED

