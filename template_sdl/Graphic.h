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
const int ground_height = 450;
const int icon_height = 600;

const int enemy_spawn_point = 1000;
const int speed = 10;
const int FONT_SIZE = 30;
const int gold_x = 1000;
const int gold_y = 10;



using namespace std;

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer);

void Display_EnemyBaseHealth(int enemy_base_health, SDL_Renderer* renderer);

void Display_AllyBaseHealth(int ally_base_health, SDL_Renderer* renderer);

void Display_Information(int mouseX, int mouseY, SDL_Texture* information, SDL_Renderer* renderer);

bool ClickBox(int mouseX, int mouseY, SDL_Rect Box);

void Display_Gold ( int gold, SDL_Texture* gold_img, TTF_Font* font, SDL_Renderer* renderer);

void Display_Ally(vector<Ally> NPC, SDL_Renderer* renderer);

void Display_Enemy(vector<Enemy> NPC, SDL_Renderer* renderer);

void Display_All(SDL_Texture* Background, SDL_Texture* ally_base_img, SDL_Texture* enemy_base_img, SDL_Texture* spawn_img, SDL_Rect spawnButton, SDL_Rect ally_base_pos, SDL_Rect enemy_base_pos, SDL_Renderer* renderer);

//int Start_Exit(int mouseX, int mouseY, SDL_Rect startButton, SDL_Rect exitButton, SDL_Texture* Start, SDL_Texture* Exit);

SDL_Window* initWindow();

SDL_Renderer* initRenderer(SDL_Window* window);


//void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
//{
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
//        logSDLError(std::cout, "SDL_Init", true);
//
//    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//
//
//    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, 
//    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
//    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
//
//
//    //Khi thông thường chạy với môi trường bình thường ở nhà
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
//        SDL_RENDERER_PRESENTVSYNC);
//    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
//    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
//    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
//
//    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
//    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
//}
