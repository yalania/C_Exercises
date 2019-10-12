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

	// ceiling 
	ceiling.x = 92;
	ceiling.y = 8;
	ceiling.w = 765;
	ceiling.h = 51;

	// Background 
	background.x = 128;
	background.y = 128;
	background.w = 768;
	background.h = 176;

	// water animation
	water.frames.push_back({ 8, 450, 288, 20 });
	water.frames.push_back({ 296, 450, 288, 20 });
	water.frames.push_back({ 592, 450, 288, 20 });
	water.speed = 0.08f;

	bath.x = 160;
	bath.y = 64;
	bath.w = 332;
	bath.h = 60;

}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading Honda scene");

	graphics = App->textures->Load("Honda_stage2.png");

	App->player->Enable();
	App->audio->PlayMusic("Honda.ogg", 0);
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
	App->renderer->Blit(graphics, 0, 0, &background, 1.0f);
	App->renderer->Blit(graphics, -50, 0, &ceiling, 1.0f);


	App->renderer->Blit(graphics, 250, 140, &bath, 1.0f);
	App->renderer->Blit(graphics, 280, 156, &(water.GetCurrentFrame()), 1.0f); // water animation


	return UPDATE_CONTINUE;
}