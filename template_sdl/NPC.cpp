#include "Clip.h"
#include "Graphic.h"
#include "NPC.h"

Ally::Ally(CLIP walk, CLIP attack, int health, int damage, int gold, int range) : walk(walk), attack(attack), health(health), maxhealth(health), damage(damage), gold(gold), range(range) {}

void Ally::render(SDL_Renderer* renderer) {

    if (isAttacking == true) { 
        
        attack_tick = (attack_tick + 1) % 5;
        attack.RenderClip(pos, renderer,attack_tick);
    }
    else {
        
        
        walk.RenderClip(pos, renderer, walk_tick);
    }

    if (health != maxhealth) {
        SDL_Rect healthBarRect = { pos, 425, static_cast<int>(64 * (static_cast<double>(health) / maxhealth)), 5 };
        if (health < 0) healthBarRect.w = 0;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
        SDL_RenderFillRect(renderer, &healthBarRect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color

    }
}
int  Ally::Gold() const {
    return gold;
}
int  Ally::Damage() const {
    return damage;
}
bool Ally::isDestroyed() const {
    return destroyed;
}
int  Ally::position() const {
    return pos;
}
void Ally::takeDamage(int take_damage) {
    health -= take_damage;
    if (health <= 0)
        destroyed = true;
}
void Ally::ally_move() {
    walk_tick = (walk_tick + 1) % 5;
    attack_tick = 0;
    if (pos + 20 <= enemy_spawn_point)  pos += speed;
    else pos = enemy_spawn_point;
    //cout << "ally" << x << endl;
}
void Ally :: get_attack_tick() {
    attack_tick = (attack_tick + 1) % 5;
}
int  Ally::Attack(int target) {


    if (isAttacking == true) {
       
        return target - damage;
    }
    else {

        return target;
    }
}

    bool Ally::CanAttack(int distance) {
        if (pos + range >= distance && pos - range <= distance ){
            isAttacking = true;
            return true;
        }
        else {
            isAttacking = false;
                return false;
        }
    }







Enemy::Enemy(SDL_Texture* texture, int pos, int health, int damage, int gold) : texture(texture), x(pos), health(health), maxhealth(health), damage(damage), gold(gold) {}

void Enemy::render(SDL_Renderer* renderer) {
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
int  Enemy::Gold() const {
    return gold;
}
int  Enemy::Damage() const {
    return damage;
}
bool Enemy::isDestroyed() const {
    return destroyed;
}
int  Enemy::position() const {
    return x;
}
void Enemy::takeDamage(int take_damage) {
    health -= take_damage;
    if (health <= 0)
        destroyed = true;
}
void Enemy::enemy_move() {

    if (x - 20 > ally_spawn_point) x -= speed;
    else x = ally_spawn_point;

    //cout << "enemy" << x << endl;

}
void Enemy::ally_move() {
    if (x + 20 <= enemy_spawn_point)  x += speed;
    else x = enemy_spawn_point;
    //cout << "ally" << x << endl;
}
int  Enemy::attack(int target) const {
    return target - damage;

}