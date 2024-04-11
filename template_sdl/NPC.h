#pragma once

#include "Graphic.h"
#include "Clip.h"

const int ally_spawn_point = 150;

using namespace std;

struct CLIP {
    SDL_Texture* texture;
    SDL_Rect clips[5];

    void init(SDL_Texture* _texture, const int _clips[][4]) {
        texture = _texture;

        SDL_Rect clip;
        for (int i = 0; i < 5; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips[i] = clip;
        }
    }
    void RenderClip(int x, SDL_Renderer* renderer,int tick) {

        // currentFrame = (currentFrame + 1) % 5;
        SDL_Rect clip = clips[tick];
        SDL_Rect renderQuad = { x,  450, clip.w, clip.h };
        SDL_RenderCopy(renderer, texture, &clip, &renderQuad);
    }

};

class Ally {
public:
    Ally (CLIP walk, CLIP attack, int health, int damage, int gold, int range);
    void render(SDL_Renderer* renderer);
    int Gold() const;
    int Damage() const;
    bool isDestroyed() const;
    int position() const;
    void takeDamage(int take_damage);
    void ally_move();
    int Attack(int target);
    bool CanAttack(int distance);
    void get_attack_tick();
    
private:
    
    CLIP walk;
    CLIP attack;
    int walk_tick = 0;
    int attack_tick = 0;
    int pos = ally_spawn_point;
    int gold;
    int health;
    int maxhealth;
    int damage;
    int range;
    bool destroyed = false;
    bool isAttacking = false;
    
};

class Enemy {
public:
    Enemy(SDL_Texture* texture, int pos, int health, int damage, int gold);
    void render(SDL_Renderer* renderer);
    int Gold() const;
    int Damage() const;
    bool isDestroyed() const;
    int position() const;
    void takeDamage(int take_damage);
    void enemy_move();
    void ally_move();
    int attack(int target) const;
    

private:
    SDL_Texture* texture;
    int x;
    int gold;
    int health;
    int maxhealth;
    int damage;
    bool isAttacking = false;
    bool destroyed = false;
};

