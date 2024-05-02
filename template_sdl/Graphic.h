#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "NPC.h"


const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int icon_height = 20;
const int speed = 7;
const int FONT_SIZE = 30;
const int gold_x = 1000;
const int gold_y = 10;



using namespace std;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);

void Display_EnemyBase(int enemy_base_health, SDL_Texture* enemy_base_img, SDL_Rect enemy_base_pos, SDL_Renderer* renderer);

void Display_AllyBase(int ally_base_health, SDL_Texture* ally_base_img, SDL_Rect ally_base_pos, SDL_Renderer* renderer);

void Display_SpawnButton(int mouseX, int mouseY,SDL_Texture* spawnIMG, SDL_Texture* information, SDL_Rect spawnbutton, SDL_Rect frame, SDL_Renderer* renderer);

bool ClickBox(int mouseX, int mouseY, SDL_Rect Box);

void Display_Gold ( int gold, SDL_Texture* gold_img, TTF_Font* font, SDL_Renderer* renderer);

void Display_Ally(vector<Ally> NPC, SDL_Renderer* renderer);

void Display_Enemy(vector<Enemy> NPC, SDL_Renderer* renderer);

void Display_Background(CLIP background, int tick, SDL_Renderer* renderer);
bool ClickBox(int mouseX, int mouseY, SDL_Rect Box);

SDL_Window* initWindow();

SDL_Renderer* initRenderer(SDL_Window* window);



