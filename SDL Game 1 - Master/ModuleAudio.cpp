#include "ModuleAudio.h"


static Uint32 audio_len_copy;
static Uint8 *audio_buf_copy;


void audioCallback(void *userdata, Uint8 *stream, int len) {

	if (audio_len_copy == 0)
		return;

	len = (len > audio_len_copy ? audio_len_copy : len);
	SDL_MixAudio(stream, audio_buf_copy, len, SDL_MIX_MAXVOLUME);

	audio_buf_copy += len;
	audio_len_copy -= len;
}



ModuleAudio::ModuleAudio() {

}

bool ModuleAudio::Init() {
	bool ret = true;
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		ret = false;
	}
	return ret;

}

void ModuleAudio::play() {
	if (SDL_OpenAudio(&spec, NULL) < 0) {
		return;
	}

	SDL_PauseAudio(0);

	while (audio_len_copy > 0) {
		SDL_Delay(100);
	}

	SDL_CloseAudio();
	audio_buf_copy = audio_buf;
	audio_len_copy = audio_len;
}


bool ModuleAudio::load(const char* file) {
	bool ret = true;
	if (SDL_LoadWAV(file, &spec, &audio_buf, &audio_len) == NULL) {
		ret = false;
	}
	else {

		spec.callback = audioCallback;
		spec.userdata = NULL;


		audio_buf_copy = audio_buf;
		audio_len_copy = audio_len;
	}

	return ret;
}

bool ModuleAudio::CleanUp() {
	SDL_FreeWAV(audio_buf);
	return true;
}

