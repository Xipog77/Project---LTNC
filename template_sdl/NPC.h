#pragma once

#include "Graphic.h"
#include "Clip.h"

const int ally_spawn_point = 50;
const int enemy_spawn_point = 1000;
const int ground_height = 700;

using namespace std;

struct CLIP {
    SDL_Texture* texture;
    SDL_Rect clips[5];
    int SPECIAL_MOVESET[5];
    Mix_Chunk* soundEffect;
    int size[2];
    int chanel;

    void init(SDL_Texture* _texture, const int _clips[5][4],const int _SPECIAL_MOVESET[5], const int _size[2], int _chanel, Mix_Chunk* _soundEffect) {
        texture = _texture;
        soundEffect = _soundEffect;
        size[0] = _size[0];
        size[1] = _size[1];
        chanel = _chanel;
        SDL_Rect clip;
        for (int i = 0; i < 5; i++) {

            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips[i] = clip;
            SPECIAL_MOVESET[i] = _SPECIAL_MOVESET[i];
        }
    }
    void RenderClip(int x, SDL_Renderer* renderer,int tick) {

        // currentFrame = (currentFrame + 1) % 5;
        SDL_Rect clip = clips[tick];
        SDL_Rect renderQuad = { x + SPECIAL_MOVESET[tick],  ground_height - clip.h - size[1] , clip.w + size[0], clip.h + size[1]};
       /* if (renderQuad.w > 120 && renderQuad.h > 120) {
            renderQuad.w = 100;
            renderQuad.h = 100;
        }*/
        //SDL_Rect renderQuad = { x + SPECIAL_MOVESET[tick],  ground_height - 50, 100 , 100};
        //SDL_RenderCopy(renderer, texture, &clip, &renderQuad
        
        if (tick == 3 && soundEffect != NULL && !Mix_Playing(chanel)) {
            Mix_VolumeChunk(soundEffect, MIX_MAX_VOLUME / 3);
            Mix_PlayChannel(chanel, soundEffect, 0);
        }
        SDL_RenderCopy(renderer, texture, &clip, &renderQuad);
    }

};

class Ally {
public:
    Ally (CLIP walk, CLIP attack, int health, int damage, int range);
    void render(SDL_Renderer* renderer);
    int position() const;
    void ally_move(int distance);
    bool CanAttack(int distance);
    void get_attack_tick();
    void get_walk_tick();
    int Attack();
    int health;
    int damage;
    
private:
    
    CLIP walk;
    CLIP attack;
    int walk_tick = 0;
    int attack_tick = 0;
    int pos = ally_spawn_point;
    int maxhealth;
    int range;
    bool destroyed = false;
    bool isAttacking = false;
    
};

class Enemy {
public:
    Enemy(CLIP walk, CLIP attack, int health, int damage, int gold, int range);
    void render(SDL_Renderer* renderer);
    int position() const;
    void enemy_move(int distance);
    void get_attack_tick();
    void get_walk_tick();
    bool CanAttack(int distance);
    int health;
    int gold;
    int range;
    int damage;
    int Attack();
    
private:
    CLIP walk;
    CLIP attack;
    int walk_tick = 0;
    int attack_tick = 0;
    int maxhealth;
    int pos = enemy_spawn_point - 50;
    bool isAttacking = false;
    bool destroyed = false;
};