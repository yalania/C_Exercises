#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 386;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the topground (red ship) with
	// coordinates x,y,w,h from Honda_stage.png

	// topground / red ship
	topground.x = 92;
	topground.y = 8;
	topground.w = 765;
	topground.h = 51;

	// Background / sky
	background.x = 128;
	background.y = 128;
	background.w = 768;
	background.h = 176;

	// water animation
	water.frames.push_back({ 848, 208, 40, 40 });
	water.frames.push_back({ 848, 256, 40, 40 });
	water.frames.push_back({ 848, 304, 40, 40 });
	water.speed = 0.08f;

	bath.x = 312;
	bath.y = 310;
	bath.w = 332;
	bath.h = 60;

}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading Honda scene");

	graphics = App->textures->Load("Honda_stage.png");

	App->player->Enable();
	//App->audio->PlayMusic("Honda.ogg", 0);
	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading Honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSceneHonda::Update()
{

	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, 0, 170, &ground);
	App->renderer->Blit(graphics, 0, 0, &background, 1.0f); // sea and sky
	App->renderer->Blit(graphics, -50, 0, &topground, 1.0f);
	//App->renderer->Blit(graphics, 560, 8, &(water.GetCurrentFrame()), 1.0f); // water animation


	App->renderer->Blit(graphics, 250, 140, &bath, 1.0f);


	return UPDATE_CONTINUE;
}