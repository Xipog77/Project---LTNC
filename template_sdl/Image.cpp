#include "Graphic.h"
#include "Image.h"



//Ally_hero::Ally_hero(SDL_Texture* texture, SDL_Texture* attackTexture, int pos, int health, int damage, int gold) : texture(texture), x(pos), health(health), maxhealth(health), damage(damage), gold(gold) {}

void Ally_hero::render(SDL_Renderer* renderer) {
    SDL_Rect destRect = { x, ground_height, 50, 50 };
    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    if (health != maxhealth) {
        SDL_Rect healthBarRect = { x, 425, static_cast<int>(64 * (static_cast<double>(health) / maxhealth)), 5 };
        if (health < 0) healthBarRect.w = 0;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &healthBarRect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color

    }
}
int  Ally_hero::Gold() const {
    return gold;
}
int  Ally_hero::Damage() const {
    return damage;
}
bool Ally_hero::isDestroyed() const {
    return destroyed;
}
int  Ally_hero::position() const {
    return x;
}
void Ally_hero::takeDamage(int take_damage) {
    health -= take_damage;
    if (health <= 0)
        destroyed = true;
}
void Ally_hero::ally_move() {
    if (x + 20 <= enemy_spawn_point)  x += speed;
    else x = enemy_spawn_point;
    //cout << "ally" << x << endl;
}
int  Ally_hero::attack(int target) const {
    return target - damage;

}
