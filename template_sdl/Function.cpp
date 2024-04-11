#include "Function.h"
#include "Graphic.h"
#include "Clip.h"




int Play(SDL_Renderer * renderer) {

    Mix_Music* music = Mix_LoadMUS("Sound/music.mp3");
    TTF_Font* font = TTF_OpenFont("Font/Montserrat-Bold.ttf", FONT_SIZE);
    SDL_Texture* Background = loadTexture("Image/Background.png", renderer);
    

    SDL_Texture* ally_base_img = loadTexture("Image/base.png", renderer);
    SDL_Texture* enemy_base_img = loadTexture("Image/enemybase.png", renderer);

    SDL_Texture* spawn_img = loadTexture("Image/spawn.png", renderer);

    SDL_Texture* monsterTexture = loadTexture("Image/monster.png", renderer);
    SDL_Texture* heroTexture = loadTexture("Image/hero.png", renderer);
    SDL_Texture* gold_img = loadTexture("Image/gold.png", renderer);

    SDL_Texture* heroAttackTexture = loadTexture("Image/spawn.png", renderer);

    SDL_Texture* information = loadTexture("Image/information.png", renderer);
    vector<Enemy> monsters;
    vector<Ally> heroes;
    
    SDL_Event e;
    // Mix_PlayMusic(music, -1);

    // IMAGE


    // RECT

    SDL_Rect information_loc = { 0,0, 200, 200 };
    SDL_Rect spawnButton = { 200,icon_height,50,50 };

    SDL_Rect ally_base_pos = { 100, ground_height - 150, 200 , 200 };
    SDL_Rect enemy_base_pos = { 950, ground_height - 130, 200, 200 };
    

    //FONT

    // INT

    int gold = 200;
    int ally_base_health = 100;
    int enemy_base_health = 10000;
    int time_count = 0;
    int mouseX;
    int mouseY;
    int trangthai = 0;

    CLIP warrior_walk;
    SDL_Texture* Test = loadTexture("Image/warrior walk.png", renderer);
    warrior_walk.init(Test, WARRIOR_WALK_CLIP);

    CLIP warrior_attack;
    SDL_Texture* warrior_attack_texture = loadTexture("Image/warrior fight.png", renderer);
    warrior_attack.init(warrior_attack_texture, WARRIOR_ATTACK_CLIPS);
    int n = 100;
    while (true) {
        // Đợi 10 mili giây
        SDL_Delay(10);
        
        
        
        SDL_PollEvent(&e);

        time_count++;

        // RENDER
        SDL_RenderClear(renderer);

        Display_All(Background, ally_base_img, enemy_base_img, spawn_img, spawnButton, ally_base_pos, enemy_base_pos, renderer);
        Display_AllyBaseHealth(ally_base_health, renderer);
        Display_EnemyBaseHealth(enemy_base_health, renderer);
        Display_Gold(gold, gold_img, font, renderer);
        
        Display_Enemy(monsters, renderer);
        Display_Ally(heroes, renderer);



        if (e.type == SDL_QUIT or e.type == SDL_KEYDOWN) {
            trangthai = 2;
            break;
        }
        // spawn
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                mouseX = e.button.x;
                mouseY = e.button.y;

                if (gold > 20 && ClickBox(mouseX, mouseY, spawnButton) == true)
                {
                    heroes.push_back(Ally(warrior_walk, warrior_attack, 10000, 10, 20, 50));
                    monsters.push_back(Enemy(monsterTexture, enemy_spawn_point, 10000, 10, 50));
                    gold -= 20;
                }
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);
        Display_Information(mouseX, mouseY, information, renderer);

        if (gold < 99999 && time_count % 100 == 0) gold++;
        // game
        //if (time_count % 1 == 0) {

            // gain

            // regen
        //if (ally_base_health <= 10000)  ally_base_health++;
        if (enemy_base_health <= 10000) enemy_base_health++;

        //enemy spawn
        // if (time_count % 200 == 0) monsters.push_back(Enemy(monsterTexture, enemy_spawn_point, 100, 10, 20));


        int ally_farest = 0;
        int enemy_farest = 0;

        if (time_count % 50 == 0) {
           
            
            if (n > 1000) n = 100;
            else n += 5;

            if (!heroes.empty())
                ally_farest = heroes[0].position();
            if (!monsters.empty()) enemy_farest = monsters[0].position();

            if (monsters.empty()) {
                for (auto& hero : heroes)
                {
                    if (hero.position() >= enemy_spawn_point) enemy_base_health -= hero.Damage();
                    else hero.ally_move();
                    //hero.render(renderer);
                }
            }
            
            else if (heroes.empty()) {
                for (auto& monster : monsters) {
                    if (monster.position() <= ally_spawn_point) ally_base_health -= monster.Damage();
                    else monster.enemy_move();

                    //monster.render(renderer);
                }
            }

            else {

                ally_farest = heroes[0].position();
                enemy_farest = monsters[0].position();
                for (auto& monster : monsters) {

                    if (monster.position() <= ally_farest + 20 && monster.position() >= ally_farest - 20) heroes[0].takeDamage(monster.Damage());
                    else if (monster.position() <= ally_spawn_point) ally_base_health -= monster.Damage();
                    else monster.enemy_move();
                    //monster.render(renderer);

                }

                for (auto& hero : heroes)
                {
                    /*if (hero.position() <= enemy_farest + 20 && hero.position() >= enemy_farest - 20) monsters[0].takeDamage(hero.Damage());*/
                    if (hero.CanAttack(enemy_farest) == true) {
                        hero.get_attack_tick();
                        monsters[0].takeDamage(hero.Damage());
                    }
                    //else if (hero.CanAttack(enemy_spawn_point) == true) hero.Attack(enemy_base_health);
                    else hero.ally_move();
                    //hero.render(renderer);
                }

                /*if (!heroes.empty()) { if (heroes[0].isDestroyed() == true) heroes.erase(heroes.begin()); }
                if (!monsters.empty()) {
                    if (monsters[0].isDestroyed() == true) {
                        gold += monsters[0].Gold();
                        monsters.erase(monsters.begin());

                    }
                }*/

                if (heroes[0].isDestroyed() == true) heroes.erase(heroes.begin());
                if (monsters[0].isDestroyed() == true) {
                    gold += monsters[0].Gold();
                    monsters.erase(monsters.begin());

                }
            }

        }
        if (ally_base_health <= 0) {

            SDL_DestroyTexture(ally_base_img);
            trangthai = 3; // lose
            break;
        }

        if (enemy_base_health <= 0) {

            SDL_DestroyTexture(enemy_base_img);
            trangthai = 4; // win
            break;
        }
        //}

        // Present renderer
        SDL_RenderPresent(renderer);

    }


    SDL_DestroyTexture(Background);
    SDL_DestroyTexture(ally_base_img);
    SDL_DestroyTexture(enemy_base_img);
    SDL_DestroyTexture(spawn_img);
    SDL_DestroyTexture(monsterTexture);
    SDL_DestroyTexture(heroTexture);
    SDL_DestroyTexture(gold_img);
    SDL_DestroyTexture(heroAttackTexture);
    SDL_DestroyTexture(information);\

    monsters.clear();
    heroes.clear();

    Mix_FreeMusic(music);

    return trangthai;
}

int Start_Exit(SDL_Renderer* renderer) {

    SDL_Texture* Background = loadTexture("Image/Screenshot 2024-03-23 163743.png", renderer);
    SDL_Texture* Start = loadTexture("Image/Start.png", renderer);
    SDL_Texture* Exit = loadTexture("Image/exit.png", renderer);

    SDL_Rect startButton;
    SDL_Rect exitButton;

    SDL_Event e;

    SDL_QueryTexture(Start, NULL, NULL, &startButton.w, &startButton.h);
    SDL_QueryTexture(Exit, NULL, NULL, &exitButton.w, &exitButton.h);

    startButton.x = SCREEN_WIDTH / 2 - startButton.w / 2; //426
    startButton.y = SCREEN_HEIGHT / 2 - 100; // 300
    exitButton.x = SCREEN_WIDTH / 2 - startButton.w / 2 + exitButton.w / 2; //5-6
    exitButton.y = SCREEN_HEIGHT / 2; //400


    int trangthai = 0;
    while (true) {

        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            trangthai = 2;
            break;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;


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

        SDL_RenderCopy(renderer, Background, NULL, NULL);
        SDL_RenderCopy(renderer, Start, NULL, &startButton);
        SDL_RenderCopy(renderer, Exit, NULL, &exitButton);

        SDL_RenderPresent(renderer);


    }

    SDL_DestroyTexture(Start);
    SDL_DestroyTexture(Exit);
    SDL_DestroyTexture(Background);

    return trangthai;
}
int Win_Lose(SDL_Renderer* renderer, int trangthai) {

    
    
    SDL_Texture* Win = loadTexture("Image/win.jpg", renderer);
    SDL_Texture* Lose = loadTexture("Image/lose.jpg", renderer);


    /*if (trangthai == 4) Background = loadTexture("Image/win.jpg", renderer);
    else if (trangthai == 3) Background = loadTexture("Image/lose.png", renderer);*/

    SDL_Texture* PlayAgain = loadTexture("Image/playagain.png", renderer);
    SDL_Texture* Exit = loadTexture("Image/exit.png", renderer);

    SDL_Rect PlayAgainButton;
    SDL_Rect exitButton;

    SDL_Event e;

    SDL_QueryTexture(PlayAgain, NULL, NULL, &PlayAgainButton.w, &PlayAgainButton.h);
    SDL_QueryTexture(Exit, NULL, NULL, &exitButton.w, &exitButton.h);

    PlayAgainButton.x = SCREEN_WIDTH / 2 - PlayAgainButton.w / 2; //426
    PlayAgainButton.y = SCREEN_HEIGHT / 2 - 100; // 300
    exitButton.x = SCREEN_WIDTH / 2 - PlayAgainButton.w / 2 + exitButton.w / 2; //5-6
    exitButton.y = SCREEN_HEIGHT / 2; //400

    
    while (true) {

        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            trangthai = 2;
            break;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                int mouseX = e.button.x;
                int mouseY = e.button.y;


                if (mouseX >= PlayAgainButton.x && mouseX <= PlayAgainButton.x + PlayAgainButton.w &&
                    mouseY >= PlayAgainButton.y && mouseY <= PlayAgainButton.y + PlayAgainButton.h) {
                    // Handle play button click
                    SDL_DestroyTexture(PlayAgain);
                    SDL_DestroyTexture(Exit);
                    trangthai = 1;

                }
                if (mouseX >= exitButton.x && mouseX <= exitButton.x + exitButton.w &&
                    mouseY >= exitButton.y && mouseY <= exitButton.y + exitButton.h) {

                    SDL_DestroyTexture(PlayAgain);
                    SDL_DestroyTexture(Exit);
                    trangthai = 2;

                }
                /*trangthai = Start_Exit(mouseX, mouseY, startButton, exitButton, Start, Exit);*/
                if (trangthai != 0) break;
            }

        }

        SDL_RenderClear(renderer);
        if (trangthai == 3) SDL_RenderCopy(renderer, Lose, NULL, NULL);
        else if (trangthai == 4) SDL_RenderCopy(renderer, Win, NULL, NULL);
        SDL_RenderCopy(renderer, PlayAgain, NULL, &PlayAgainButton);
        SDL_RenderCopy(renderer, Exit, NULL, &exitButton);

        SDL_RenderPresent(renderer);


    }

    SDL_DestroyTexture(PlayAgain);
    SDL_DestroyTexture(Exit);
    SDL_DestroyTexture(Win);
    SDL_DestroyTexture(Lose);

    return trangthai;
}