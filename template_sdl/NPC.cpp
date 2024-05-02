#include "Clip.h"
#include "Graphic.h"
#include "NPC.h"

Ally::Ally(CLIP walk, CLIP attack, int health, int damage, int range) : walk(walk), attack(attack), health(health), maxhealth(health), damage(damage), range(range) {}

void Ally::render(SDL_Renderer* renderer) {

    if (isAttacking == true) { 
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

int  Ally::position() const {
    return pos;
}
void Ally::ally_move(int distance) {
    get_walk_tick();
    if (pos + 100 <= distance)  pos += speed;
    else if (pos + 100 >= enemy_spawn_point && pos <= enemy_spawn_point) pos = enemy_spawn_point;
    //cout << "ally" << x << endl;
}
void Ally :: get_attack_tick() {
    attack_tick = (attack_tick + 1) % 5;
    walk_tick = 0;

}
void Ally::get_walk_tick() {
    walk_tick = (walk_tick + 1) % 5;
    attack_tick = 0;
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

int Ally::Attack() {
    get_attack_tick();
    if (attack_tick == 3) return damage;
    else return 0;
}

Enemy::Enemy(CLIP walk, CLIP attack, int health, int damage, int gold, int range) : walk(walk), attack(attack), health(health), maxhealth(health), damage(damage), gold(gold), range(range) {}

void Enemy::render(SDL_Renderer* renderer) {
    
    if (isAttacking == true) {

        attack_tick = (attack_tick + 1) % 5;
        attack.RenderClip(pos, renderer, attack_tick);
    }
    else {

        walk_tick = (walk_tick + 1) % 5;
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
int  Enemy::position() const {
    return pos;
}
void Enemy::get_attack_tick() {
    attack_tick = (attack_tick + 1) % 5;
    walk_tick = 0;

}
void Enemy::get_walk_tick() {
  
    walk_tick = (walk_tick + 1) % 5;
    attack_tick = 0;
}
void Enemy::enemy_move(int distance) {

    get_walk_tick();
    if (pos - 100 >= distance)  pos -= speed;
    else if (pos - 100 <= ally_spawn_point && pos >= ally_spawn_point) pos = ally_spawn_point;
}
bool Enemy::CanAttack(int distance) {
    if (pos + range >= distance && pos - range <= distance) {
        isAttacking = true;
        return true;
    }
    else {
        isAttacking = false;
        return false;
    }
}
int Enemy::Attack() {

    get_attack_tick();
    if (attack_tick == 3) return damage;
    else return 0;
}
