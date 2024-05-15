#include "Function.h"
#include "Graphic.h"
#include "Clip.h"

int Play(SDL_Renderer* renderer) {

    Mix_Volume(1, MIX_MAX_VOLUME / 2);
    Mix_Music* music = Mix_LoadMUS("Audio/y2mate.com - Two Steps From Hell  To Glory.mp3");

    TTF_Font* font = TTF_OpenFont("Font/SVN-Determination Sans.otf", FONT_SIZE);
    
    // IMAGE
    SDL_Texture* background_texture = loadTexture("Image/ezgif.com-gif-to-sprite-converter (4).png", renderer);
    SDL_Texture* ally_base_img = loadTexture("Image/base.png", renderer);
    SDL_Texture* enemy_base_img = loadTexture("Image/enemybase.png", renderer);
    SDL_Texture* frame = loadTexture("Image/Frame/frame1.png", renderer);
    SDL_Texture* warrior_spawn_img = loadTexture("Image/Frame/warrior frame.png", renderer);
    SDL_Texture* archer_spawn_img = loadTexture("Image/Frame/archer frame.png", renderer);
    SDL_Texture* knight_spawn_img = loadTexture("Image/Frame/knight frame.png", renderer);
    SDL_Texture* hero_spawn_img = loadTexture("Image/Frame/hero frame.png", renderer);
    SDL_Texture* catapult_spawn_img = loadTexture("Image/Frame/catapult frame.png", renderer);
    SDL_Texture* spell_spawn_img = loadTexture("Image/Frame/spell frame.png", renderer);
    SDL_Texture* gold_img = loadTexture("Image/gold.png", renderer);
    SDL_Texture* warrior_information = loadTexture("Image/Frame/warrior info.png", renderer);
    SDL_Texture* archer_information = loadTexture("Image/Frame/archer info.png", renderer);
    SDL_Texture* knight_information = loadTexture("Image/Frame/knight info.png", renderer);
    SDL_Texture* hero_information = loadTexture("Image/Frame/hero info.png", renderer);
    SDL_Texture* catapult_information = loadTexture("Image/Frame/balista info.png", renderer);
    SDL_Texture* spell_information = loadTexture("Image/Frame/spell info.png", renderer);

    SDL_Texture* warrior_attack_texture = loadTexture("Image/NPC/warrior fight.png", renderer);
    SDL_Texture* warrior_walk_texture = loadTexture("Image/NPC/warrior walk.png", renderer);
    SDL_Texture* skull_attack_texture = loadTexture("Image/NPC/skull fight.png", renderer);
    SDL_Texture* skull_walk_texture = loadTexture("Image/NPC/skull walk.png", renderer);
    SDL_Texture* archer_attack_texture = loadTexture("Image/NPC/archer attack.png", renderer);
    SDL_Texture* archer_walk_texture = loadTexture("Image/NPC/archer walk1.png", renderer);
    SDL_Texture* alien_attack_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (2).png", renderer);
    SDL_Texture* alien_walk_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (1).png", renderer);
    SDL_Texture* knight_attack_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (7).png", renderer);
    SDL_Texture* knight_walk_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (8).png", renderer);
    SDL_Texture* ghost_attack_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (6).png", renderer);
    SDL_Texture* ghost_walk_texture = loadTexture("Image/NPC/ezgif.com-gif-to-sprite-converter (5).png", renderer);
    SDL_Texture* hero_attack_texture = loadTexture("Image/NPC/hero attack 1.png", renderer);
    SDL_Texture* hero_walk_texture = loadTexture("Image/NPC/hero walk.png", renderer);
    SDL_Texture* boss_attack_texture = loadTexture("Image/NPC/boss attack 1.png", renderer);
    SDL_Texture* boss_walk_texture = loadTexture("Image/NPC/boss walk.png", renderer);

    SDL_Texture* spell_texture = loadTexture("Image/NPC/spell strike.png", renderer);
    SDL_Texture* catapult_texture = loadTexture("Image/NPC/catapult.png", renderer);

    
    // RECT
    SDL_Rect warrior_frame = { 115, 220, 210, 245 };
    SDL_Rect archer_frame = { 390, 220, 210, 245 };
    SDL_Rect knight_frame = { 675, 220, 210, 245 };
    SDL_Rect hero_frame = { 50, 30, 105, 120 };
    SDL_Rect catapult_frame = { 0,0,800,800 };
    SDL_Rect spell_frame = { 0,0,800,800 };
    SDL_Rect frame_rect = { 0, 0,400,250 };
    SDL_Rect frame_frame = { 0, -10,375,220 };
    SDL_Rect catapult_spawn_button = { 150, icon_height + 80, 70, 70 };
    SDL_Rect Hero_spawn_button = { 250, icon_height + 80, 70, 70};
    SDL_Rect Warrior_spawn_button = { 50,icon_height,70,70 };
    SDL_Rect Archer_spawn_button = { 150, icon_height, 70, 70 };
    SDL_Rect Knight_spawn_button = { 250, icon_height, 70, 70 };
    SDL_Rect Spell_spawn_button = { 50, icon_height + 80, 70, 70 };
    SDL_Rect ally_base_pos = { ally_spawn_point, ground_height - 200, 200 , 200 };
    SDL_Rect enemy_base_pos = { enemy_spawn_point, ground_height - 200, 200, 200 };

    // SOUND
    Mix_Chunk* warrior_sound = Mix_LoadWAV("Audio/warrior attack.mp3");
    Mix_Chunk* skull_sound = Mix_LoadWAV("Audio/skull attack.mp3");
    Mix_Chunk* archer_sound = Mix_LoadWAV("Audio/archer attack.mp3");
    Mix_Chunk* alien_sound = Mix_LoadWAV("Audio/alien attack.mp3");
    Mix_Chunk* knight_sound = Mix_LoadWAV("Audio/knight attack.mp3");
    Mix_Chunk* ghost_sound = Mix_LoadWAV("Audio/ghost attack.mp3");
    Mix_Chunk* hero_sound = Mix_LoadWAV("Audio/hero attack.mp3");
    Mix_Chunk* boss_sound = Mix_LoadWAV("Audio/boss attack.mp3");
    Mix_Chunk* spell_chunk = Mix_LoadWAV("Audio/spell.mp3");
    Mix_Chunk* catapult_chunk = Mix_LoadWAV("Audio/catapult.mp3");

    //CLIP
    CLIP background;
    CLIP spell;
    CLIP catapult;
    CLIP warrior_attack;
    CLIP warrior_walk;
    CLIP skull_attack;
    CLIP skull_walk;
    CLIP archer_attack;
    CLIP archer_walk;
    CLIP alien_attack;
    CLIP alien_walk;
    CLIP knight_attack;
    CLIP knight_walk;
    CLIP ghost_attack;
    CLIP ghost_walk;
    CLIP hero_attack;
    CLIP hero_walk;
    CLIP boss_attack;
    CLIP boss_walk;
    
    
    background.init(background_texture, BACKGROUND, NON_SPECIAL_MOVESET, NON_RESIZE, 0, NULL);
    catapult.init(catapult_texture, BALISTA_TURRET_ATTACK, NON_SPECIAL_MOVESET, CATAPULT_RESIZE,3, catapult_chunk);
    spell.init(spell_texture, SPELL_CLIPS, NON_SPECIAL_MOVESET, NON_RESIZE, 4, spell_chunk);
    warrior_attack.init(warrior_attack_texture, WARRIOR_ATTACK_CLIPS, NON_SPECIAL_MOVESET, WARRIOR_RESIZE,1, warrior_sound);
    warrior_walk.init(warrior_walk_texture, WARRIOR_WALK_CLIP, NON_SPECIAL_MOVESET, WARRIOR_RESIZE, 1, NULL);
    skull_attack.init(skull_attack_texture, SKULL_ATTACK_CLIPS, SKULL_ATTACK_SPECIAL_MOVESET, NON_RESIZE, 2, skull_sound);
    skull_walk.init(skull_walk_texture, SKULL_WALK_CLIPS, NON_SPECIAL_MOVESET, NON_RESIZE, 2, NULL);
    archer_attack.init(archer_attack_texture, ARCHER_ATTACK_CLIPS, ARCHER_ATTACK_SPECIAL_MOVESET, ARCHER_RESIZE, 1, archer_sound);
    archer_walk.init(archer_walk_texture, ARCHER_WALK_CLIPS, NON_SPECIAL_MOVESET, ARCHER_RESIZE, 1, NULL);
    alien_attack.init(alien_attack_texture, ALIEN_ATTACK_CLIPS, ALIEN_ATTACK_SPECIAL_MOVESET, ALIEN_RESIZE, 2, alien_sound);
    alien_walk.init(alien_walk_texture, ALIEN_WALK_CLIPS, NON_SPECIAL_MOVESET, ALIEN_RESIZE, 2, NULL);
    knight_attack.init(knight_attack_texture, KNIGHT_ATTACK_CLIPS, KNIGHT_ATTACK_SPECIAL_MOVESET, KNIGHT_RESIZE, 1, knight_sound);
    knight_walk.init(knight_walk_texture, KNIGHT_WALK_CLIPS, KNIGHT_WALK_SPECIAL_MOVESET, KNIGHT_RESIZE, 1, NULL);
    ghost_attack.init(ghost_attack_texture, GHOST_ATTACK_CLIPS, NON_SPECIAL_MOVESET, GHOST_RESIZE, 2, ghost_sound);
    ghost_walk.init(ghost_walk_texture, GHOST_WALK_CLIPS, NON_SPECIAL_MOVESET, GHOST_RESIZE, 2, NULL);
    hero_attack.init(hero_attack_texture, HERO_ATTACK_CLIPS, NON_SPECIAL_MOVESET, HERO_RESIZE, 1, hero_sound);
    hero_walk.init(hero_walk_texture, HERO_WALK_CLIPS, HERO_WALK_SPECIAL_MOVESET, HERO_RESIZE, 1, NULL);
    boss_attack.init(boss_attack_texture, BOSS_ATTACK_CLIPS, BOSS_ATTACK_SPECIAL_MOVESET, NON_RESIZE, 2, boss_sound);
    boss_walk.init(boss_walk_texture, BOSS_WALK_CLIPS, BOSS_WALK_SPECIAL_MOVESET, NON_RESIZE, 2, NULL);
    

    bool spell_buy = false;
    bool catapult_buy = false;

    int phase = 1;
    int gold = 300;
    int ally_base_health = 10000;
    int enemy_base_health = 10000;
    int time_count = 0;
    int mouseX;
    int mouseY;
    int trangthai = 0;
    int spell_tick = 0;
    int background_tick = 0;
    int catapult_tick = 0;
    int ally_farest = 0;
    int enemy_farest = 0;
    int ally_dis = enemy_spawn_point;
    int enemy_dis = ally_spawn_point;

    vector<Enemy> monsters;
    vector<Ally> heroes;

    Ally warrior = Ally(warrior_walk, warrior_attack, 1000, 100, 100);
    Ally archer = Ally(archer_walk, archer_attack, 500, 100, 300);
    Ally knight = Ally(knight_walk, knight_attack, 2000, 200, 200);
    Ally hero = Ally(hero_walk, hero_attack, 20000, 400, 100);

    Enemy skull = Enemy(skull_walk, skull_attack, 1000, 100, 20, 100);
    Enemy alien = Enemy(alien_walk, alien_attack, 500, 100, 40, 300);
    Enemy ghost = Enemy(ghost_walk, ghost_attack, 2000, 200, 100, 200);
    Enemy boss = Enemy(boss_walk, boss_attack, 30000, 500, 0, 150);

    SDL_Event e;

    Mix_PlayMusic(music, -1);
    srand(static_cast<unsigned int>(time(NULL)));

    while (true) {
        
        SDL_Delay(30);
        SDL_PollEvent(&e);
        SDL_GetMouseState(&mouseX, &mouseY);
       
        // RENDER
        SDL_RenderClear(renderer);
        Display_Background(background, background_tick, renderer);
        Display_AllyBase(ally_base_health,ally_base_img,ally_base_pos, renderer);
        Display_EnemyBase(enemy_base_health, enemy_base_img, enemy_base_pos, renderer);
        Display_Gold(gold, gold_img, font, renderer);
        Display_Enemy(monsters, renderer);
        Display_Ally(heroes, renderer);
        SDL_RenderCopy(renderer, frame, NULL, &frame_frame );
        Display_SpawnButton(mouseX, mouseY, hero_spawn_img, hero_information, Hero_spawn_button, hero_frame, renderer);
        Display_SpawnButton(mouseX, mouseY, catapult_spawn_img, catapult_information, catapult_spawn_button, catapult_frame, renderer);
        Display_SpawnButton(mouseX, mouseY, spell_spawn_img, spell_information, Spell_spawn_button, spell_frame, renderer);
        Display_SpawnButton(mouseX, mouseY, knight_spawn_img, knight_information, Knight_spawn_button, knight_frame, renderer);
        Display_SpawnButton(mouseX, mouseY, archer_spawn_img, archer_information, Archer_spawn_button, archer_frame, renderer);
        Display_SpawnButton(mouseX, mouseY, warrior_spawn_img, warrior_information, Warrior_spawn_button, warrior_frame, renderer);
        if (catapult_buy) catapult.RenderClip(0, renderer, catapult_tick);
        if (spell_buy) spell.RenderClip(monsters[0].position(), renderer, spell_tick);
        if (time_count % 20 == 0) background_tick = (background_tick + 1) % 5;

        time_count++;
        ally_farest = 0;
        enemy_farest = 0;
        ally_dis = enemy_spawn_point;
        enemy_dis = ally_spawn_point;

        if (e.type == SDL_QUIT) {
            trangthai = 2;
            break;
        }
        // spawn
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                mouseX = e.button.x;
                mouseY = e.button.y;

                if (gold >= 20 && ClickBox(mouseX, mouseY, Warrior_spawn_button) && heroes.size() <= 10)
                {
                    heroes.push_back(warrior);
                    //monsters.push_back(skull);
                    gold -= 20;
                }

                if (gold >= 40 && ClickBox(mouseX, mouseY, Archer_spawn_button) && heroes.size() <= 10)
                {
                    heroes.push_back(archer);
                    //monsters.push_back(alien);
                    gold -= 40;
                }

                if (gold >= 100 && ClickBox(mouseX, mouseY, Knight_spawn_button) && heroes.size() <= 10) {
                    heroes.push_back(knight);
                    //monsters.push_back(ghost);
                    gold -= 100;
                }

                if (gold >= 100 && ClickBox(mouseX, mouseY, Spell_spawn_button) && monsters.empty() == false && spell_buy == false) {
                    spell_buy = true;
                    spell_tick = 0;
                    gold -= 100;
                }

                if (gold >= 500 && ClickBox(mouseX, mouseY, catapult_spawn_button) && catapult_buy == false) {
                    catapult_buy = true;
                    gold -= 500;
                    SDL_DestroyTexture(catapult_spawn_img);
                }

                if (gold >= 1000 && ClickBox(mouseX, mouseY, Hero_spawn_button) && heroes.size() <= 10) {
                    
                    heroes.push_back(hero);
                    gold -= 1000;
                }

            }
        }

        if (phase == 1) {
            if (time_count % 200 == 0 && enemy_base_health >= 0 && monsters.size() <= 5) {

                if (rand() % 2)
                {
                    monsters.push_back(skull);
                }
                else if (time_count > 500 && rand() % 3 == 0) {
                    monsters.push_back(alien);
                }
                else if (time_count > 800 && rand() % 5 == 0) {
                    monsters.push_back(ghost);
                }

                if (time_count > 1000) {
                    if (rand() % 4)
                    {
                        monsters.push_back(alien);
                    }
                    else if (time_count > 1500 && rand() % 6 == 0) {
                        monsters.push_back(alien);
                    }
                    else if (time_count > 2000 && rand() % 8 == 0) {
                        monsters.push_back(ghost);
                    }
                }
                if (time_count > 2000) {
                    if (rand() % 2)
                    {
                        monsters.push_back(skull);
                    }
                    else if (time_count > 2500 && rand() % 3 == 0) {
                        monsters.push_back(alien);
                    }
                    else if (time_count > 3000 && rand() % 4 == 0) {
                        monsters.push_back(ghost);
                    }
                }
            }
            if (time_count % 20 == 0) {
                if (gold < 99999) gold++;
                if (ally_base_health <= 10000)  ally_base_health++;
                if (enemy_base_health <= 10000) enemy_base_health++;
            }
            if (time_count % 5 == 0) {

                if (monsters.empty()) {
                    for (auto& hero : heroes)
                    {
                        if (hero.CanAttack(enemy_spawn_point)) {
                            enemy_base_health -= hero.Attack();
                        }
                        else {
                            hero.ally_move(ally_dis);
                        }
                        ally_dis = hero.position();
                    }
                }
                else if (heroes.empty()) {
                    enemy_farest = monsters[0].position();
                    for (auto& monster : monsters) {
                        if (monster.CanAttack(ally_spawn_point)) {
                            
                            ally_base_health -= monster.Attack();
                        }
                        else {
                            
                            monster.enemy_move(enemy_dis);
                        }
                        enemy_dis = monster.position();
                    }

                    if (catapult_buy) {
                        if (enemy_farest < 500) {
                            catapult_tick = (catapult_tick + 1) % 5;
                            if (catapult_tick == 3)  monsters[0].health -= 100;
                        }
                        else catapult_tick = 0;
                    }

                    if (spell_buy) {

                        spell_tick = (spell_tick + 1) % 6;

                        if (spell_tick == 4) {
                            monsters[0].health -= 1000;
                            spell_buy = false;
                            
                        }
                    }

                    if (monsters[0].health <= 0) {
                        gold += monsters[0].gold;
                        monsters.erase(monsters.begin());

                    }
                }
                else {
                    ally_farest = heroes[0].position();
                    enemy_farest = monsters[0].position();
                    for (auto& monster : monsters) {

                        if (monster.CanAttack(ally_farest)) {
                            
                            heroes[0].health -= monster.Attack();

                        }
                        else if (monster.CanAttack(ally_spawn_point)) {
                            
                            ally_base_health -= monster.Attack();
                        }
                        else {
                            
                            monster.enemy_move(enemy_dis);
                        }
                        enemy_dis = monster.position();

                    }
                    for (auto& hero : heroes)
                    {
                        if (hero.CanAttack(enemy_farest)) {
                            
                            monsters[0].health -= hero.Attack();
                        }
                        else if (hero.CanAttack(enemy_spawn_point)) {
                           
                            enemy_base_health = hero.Attack();
                        }
                        else {
                            
                            hero.ally_move(ally_dis);
                        }
                        ally_dis = hero.position();
                    }

                    if (catapult_buy) {
                        if (enemy_farest < 500) {
                            catapult_tick = (catapult_tick + 1) % 5;
                            if (catapult_tick == 3)  monsters[0].health -= 100;
                        }
                        else catapult_tick = 0;
                    }

                    if (spell_buy) {
                        spell_tick = (spell_tick + 1) % 6;

                        if (spell_tick == 4) {
                            monsters[0].health -= 1000;
                            spell_buy = false;
                        }
                    }

                    if (heroes[0].health <= 0) heroes.erase(heroes.begin());
                    if (monsters[0].health <= 0) {
                        gold += monsters[0].gold;
                        monsters.erase(monsters.begin());
                    }
                }
                if (ally_base_health <= 0) {
                    SDL_DestroyTexture(ally_base_img);
                    trangthai = 3;
                    phase = 0;
                    break;
                }
                if (enemy_base_health <= 0) {
                    SDL_DestroyTexture(enemy_base_img);
                    monsters.push_back(boss);
                    phase = 2;
                }
            }
        }

        if (phase == 2 && time_count % 5 == 0){
            
            if (time_count % 20 == 0) {
                if (gold < 99999) gold++;
                if (ally_base_health <= 10000)  ally_base_health++;
            }
            
            if (heroes.empty()) {
                if (monsters[0].CanAttack(ally_spawn_point)) {
                    
                    ally_base_health -= monsters[0].Attack();
                }
                else {
                    
                    monsters[0].enemy_move(0);
                }

                if (catapult_buy) {
                    if (monsters[0].position() < 500) {
                        catapult_tick = (catapult_tick + 1) % 5;
                        if (catapult_tick == 3) { 
                            gold += 2;
                            monsters[0].health -= 100; }
                    }
                    else catapult_tick = 0;
                }
                if (spell_buy) {
                    spell_tick = (spell_tick + 1) % 6;

                    if (spell_tick == 4) {
                        monsters[0].health -= 1000;
                        spell_buy = false;
                    }
                }

            }
            else {
                ally_farest = heroes[0].position();

                if (monsters[0].CanAttack(ally_farest)) {
                    
                    heroes[0].health -= monsters[0].Attack();
                    for (auto& hero : heroes) hero.health -= 10;

                }
                else if (monsters[0].CanAttack(ally_spawn_point)) {
                    
                    ally_base_health -= monsters[0].Attack();
                }
                else {
                    
                    monsters[0].enemy_move(enemy_dis);
                }

                for (auto& hero : heroes)
                {
                    if (hero.CanAttack(monsters[0].position())) {
                        
                        monsters[0].health -= hero.Attack();
                        gold += 2;

                    }
                    else {
                        
                        hero.ally_move(ally_dis);
                    }
                    ally_dis = hero.position();
                }

                if (catapult_buy) {
                    if (monsters[0].position() < 500) {
                        catapult_tick = (catapult_tick + 1) % 5;
                        if (catapult_tick == 3) {
                            gold += 2;
                            monsters[0].health -= 100;
                        }
                    }
                    else catapult_tick = 0;
                }
                if (spell_buy) {
                    spell_tick = (spell_tick + 1) % 6;
                    if (spell_tick == 4) {
                        monsters[0].health -= 1000;
                        spell_buy = false;
                    }
                }
                if (heroes[0].health <= 0) heroes.erase(heroes.begin());
                if (monsters[0].health <= 0) {
                    trangthai = 4;
                    break;

                }
            }
        }
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyTexture(background_texture);
    SDL_DestroyTexture(ally_base_img);
    SDL_DestroyTexture(enemy_base_img);
    SDL_DestroyTexture(frame);
    SDL_DestroyTexture(warrior_spawn_img);
    SDL_DestroyTexture(archer_spawn_img);
    SDL_DestroyTexture(knight_spawn_img);
    SDL_DestroyTexture(hero_spawn_img);
    SDL_DestroyTexture(catapult_spawn_img);
    SDL_DestroyTexture(spell_spawn_img);
    SDL_DestroyTexture(gold_img);
    SDL_DestroyTexture(warrior_information);
    SDL_DestroyTexture(archer_information);
    SDL_DestroyTexture(knight_information);
    SDL_DestroyTexture(hero_information);
    SDL_DestroyTexture(catapult_information);
    SDL_DestroyTexture(spell_information);
    SDL_DestroyTexture(warrior_attack_texture);
    SDL_DestroyTexture(warrior_walk_texture);
    SDL_DestroyTexture(skull_attack_texture);
    SDL_DestroyTexture(skull_walk_texture);
    SDL_DestroyTexture(archer_attack_texture);
    SDL_DestroyTexture(archer_walk_texture);
    SDL_DestroyTexture(alien_attack_texture);
    SDL_DestroyTexture(alien_walk_texture);
    SDL_DestroyTexture(knight_attack_texture);
    SDL_DestroyTexture(knight_walk_texture);
    SDL_DestroyTexture(ghost_attack_texture);
    SDL_DestroyTexture(ghost_walk_texture);
    SDL_DestroyTexture(hero_walk_texture);
    SDL_DestroyTexture(hero_attack_texture);
    SDL_DestroyTexture(boss_attack_texture);
    SDL_DestroyTexture(boss_walk_texture);
    SDL_DestroyTexture(spell_texture);
    SDL_DestroyTexture(catapult_texture);
    monsters.clear();
    heroes.clear();
    SDL_DestroyRenderer(renderer);
    Mix_FreeMusic(music);
        

    return trangthai;
}
int Start_Exit(SDL_Renderer * renderer) {

        SDL_Texture* Background = loadTexture("Image/play1.png", renderer);
        SDL_Texture* Start = loadTexture("Image/Start.png", renderer);
        SDL_Texture* Exit = loadTexture("Image/exit.png", renderer);
        SDL_Texture* Select = loadTexture("Image/select.png", renderer);

        SDL_Rect background_frame = { 0, 0, 512, 307 };
        SDL_Rect startButton_frame = {220, 140, 70,35};
        SDL_Rect exitButton_frame = {220, 185, 70, 35};
        SDL_Rect startButton = {SCREEN_WIDTH/2 - 70,SCREEN_HEIGHT/2 - 70 ,140,70};
        SDL_Rect exitButton = { SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT/2 + 30 ,140,70};
        SDL_Rect background_rect = { 0,0, SCREEN_WIDTH, SCREEN_HEIGHT };
        
        SDL_Event e;

        int mouseX;
        int mouseY;

        int trangthai = 0;
        while (true) {

            SDL_GetMouseState(&mouseX, &mouseY);
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                trangthai = 2;
                break;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    
                    if (mouseX >= startButton.x && mouseX <= startButton.x + startButton.w &&
                        mouseY >= startButton.y && mouseY <= startButton.y + startButton.h) {
                        // Handle play button click
                        SDL_DestroyTexture(Start);
                        SDL_DestroyTexture(Exit);
                        trangthai = 1;

                    }
                    if (mouseX >= exitButton.x && mouseX <= exitButton.x + exitButton.w &&
                        mouseY >= exitButton.y && mouseY <= exitButton.y + exitButton.h) {

                        SDL_DestroyTexture(Start);
                        SDL_DestroyTexture(Exit);
                        trangthai = 2;

                    }
                    /*trangthai = Start_Exit(mouseX, mouseY, startButton, exitButton, Start, Exit);*/
                    if (trangthai != 0) break;
                }

            }

            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, Background, &background_frame, NULL);
            Display_Selection(mouseX, mouseY, Start, Select, startButton, startButton_frame, renderer);
            Display_Selection(mouseX, mouseY, Exit, Select, exitButton, exitButton_frame, renderer);
            
            //SDL_RenderCopy(renderer, Start, &startButton_frame, &startButton);
            //SDL_RenderCopy(renderer, Exit, &exitButton_frame, &exitButton);

            SDL_RenderPresent(renderer);


        }

        SDL_DestroyTexture(Start);
        SDL_DestroyTexture(Exit);
        SDL_DestroyTexture(Background);

        return trangthai;
    }
int Win_Lose(SDL_Renderer* renderer, int trangthai) {

    SDL_Texture* Win = loadTexture("Image/win1.png", renderer);
    SDL_Texture* Lose = loadTexture("Image/lose 1.png", renderer);
    SDL_Texture* Select = loadTexture("Image/select.png", renderer);

    SDL_Texture* PlayAgain = loadTexture("Image/play again.png", renderer);
    SDL_Texture* Exit = loadTexture("Image/exit.png", renderer);

    SDL_Rect PlayAgainButton_frame = { 180, 135, 155, 40 };
    SDL_Rect exitButton_frame = { 220, 185, 70, 35 };
    SDL_Rect PlayAgainButton = { SCREEN_WIDTH / 2 - 155,SCREEN_HEIGHT / 2 - 30 ,155 * 2, 40 * 2};
    SDL_Rect exitButton = { SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2 + 50 ,140,70 };

    SDL_Event e;
    int mouseX;
    int mouseY;
    
    while (true) {

        SDL_GetMouseState(&mouseX, &mouseY);
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            trangthai = 2;
            break;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                
                if (ClickBox(mouseX, mouseY, PlayAgainButton)) {
                    SDL_DestroyTexture(PlayAgain);
                    SDL_DestroyTexture(Exit);
                    trangthai = 1;
                }

                if (ClickBox(mouseX, mouseY, exitButton)) {
                    SDL_DestroyTexture(PlayAgain);
                    SDL_DestroyTexture(Exit);
                    trangthai = 2;
                }
                if (trangthai != 0) break;
            }

        }

        SDL_RenderClear(renderer);
        if (trangthai == 3) SDL_RenderCopy(renderer, Lose, NULL, NULL);
        else if (trangthai == 4) SDL_RenderCopy(renderer, Win, NULL, NULL);
        SDL_RenderCopy(renderer, PlayAgain, &PlayAgainButton_frame, &PlayAgainButton);
        Display_Selection(mouseX, mouseY, PlayAgain, Select, PlayAgainButton, PlayAgainButton_frame, renderer);
        Display_Selection(mouseX, mouseY, Exit, Select, exitButton, exitButton_frame, renderer);

        SDL_RenderPresent(renderer);


    }

    SDL_DestroyTexture(PlayAgain);
    SDL_DestroyTexture(Exit);
    SDL_DestroyTexture(Win);
    SDL_DestroyTexture(Lose);

    return trangthai;
}
