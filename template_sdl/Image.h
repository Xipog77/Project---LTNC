#pragma once

#include "Graphic.h"

using namespace std;


class Ally_hero {
public:
    Ally_hero(SDL_Texture* texture, int pos, int health, int damage, int gold);
    void render(SDL_Renderer* renderer);
    int Gold() const;
    int Damage() const;
    bool isDestroyed() const;
    int position() const;
    void takeDamage(int take_damage);
    void ally_move();
    int attack(int target) const;

private:
    SDL_Texture* attackTexture;
    SDL_Texture* texture;
    int x = ally_spawn_point;
    int gold;
    int health;
    int maxhealth;
    int damage;
    bool destroyed = false;
};