#pragma once
#include "Module.h"
#include "SDL/include/SDL.h"

class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio() {
		CleanUp();

	};

	bool Init();
	bool load(const char* file);
	void play();
	bool CleanUp();

private:

	SDL_AudioSpec spec;
	Uint32 audio_len;
	Uint8 *audio_buf;


};