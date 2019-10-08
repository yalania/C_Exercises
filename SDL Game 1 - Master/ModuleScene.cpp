#include "ModuleScene.h"
#include "Application.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
ModuleScene::ModuleScene()  {


}

bool ModuleScene::Init() {

	x = 5;
	y = 5;
	moduleTexture = App->textures;
	moduleRender = App->renderer;
	return true;
}

update_status ModuleScene::PreUpdate() {

	SDL_Rect section;
	section.x = x;
	section.y = y;
	section.w = 32;
	section.h = 32;

	SDL_Texture * loadedtexture = moduleTexture->Load(SPRITE_FILE);
	moduleRender->Blit(loadedtexture,x ,y, &section);
	LOG("1");
	return UPDATE_CONTINUE;
}