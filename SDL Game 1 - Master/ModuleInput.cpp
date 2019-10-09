#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput()
{
}

// Destructor
ModuleInput::~ModuleInput()
{
	CleanUp();
}

// Called before render is available
bool ModuleInput::Init()
{
	moduleAudio = App->audio;

	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	moduleAudio->load(AUDIO_WAV);

	return ret;
}

// Called every draw update
update_status ModuleInput::Update()
{
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);
	Uint32 mouse = SDL_GetMouseState(NULL, NULL);

	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		return UPDATE_STOP;
	}
	if (mouse & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		moduleAudio->play();
	}


	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}