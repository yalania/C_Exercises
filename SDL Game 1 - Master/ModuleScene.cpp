#include "ModuleScene.h"


ModuleScene::ModuleScene()  {


}

bool ModuleScene::Init() {

	path = "GAME/sprites.png";
	x = 0;
	y = 0;
	section = { x, y, SCREEN_WIDTH, SCREEN_HEIGHT };
	return true;
}

update_status ModuleScene::Update() {

	SDL_Texture * loadedtexture = moduleTexture->Load(path);
	moduleRender->Blit(loadedtexture,x ,y, section);
	return UPDATE_CONTINUE;
}