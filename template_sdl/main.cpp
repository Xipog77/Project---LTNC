
#define SDL_MAIN_HANDLED

#include "Graphic.h"
#include "Function.h"


SDL_Window* window = initWindow();
SDL_Renderer* renderer = initRenderer(window);


int main() {


    TTF_Init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    int trangthai = 0;

    trangthai = Start_Exit(renderer);

    // play
    if (trangthai == 1) {

        while (trangthai != 2) {
            trangthai = Play(renderer);

            if (trangthai != 2) trangthai = Win_Lose(renderer, trangthai);
        }
    }

    if (trangthai == 2) quitSDL(window, renderer);

    quitSDL(window, renderer);

}








//
//#define SDL_MAIN_HANDLED
//
//#include "Graphic.h"
//#include "Function.h"
//
//
//
////SDL_Window* window = NULL;
////SDL_Renderer* renderer = NULL;
//
//SDL_Window* window = initWindow();
//SDL_Renderer* renderer = initRenderer(window);
//
//
//int main() {
//
//
//TTF_Init();
//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
//
////SDL_Texture* Background = loadTexture("Image/Background.png", renderer);
//////SDL_Texture* Start = loadTexture("Image/Start.png", renderer);
//////SDL_Texture* Exit = loadTexture("Image/exit.png", renderer);
////
////SDL_Texture* ally_base_img = loadTexture("Image/base.png", renderer);
////SDL_Texture* enemy_base_img = loadTexture("Image/enemybase.png", renderer);
////
////SDL_Texture* spawn_img = loadTexture("Image/spawn.png", renderer);
////
////SDL_Texture* monsterTexture = loadTexture("Image/monster.png", renderer);
////SDL_Texture* heroTexture = loadTexture("Image/hero.png", renderer);
////SDL_Texture* gold_img = loadTexture("Image/gold.png", renderer);
////
////SDL_Texture* heroAttackTexture = loadTexture("Image/spawn.png", renderer);
////
////SDL_Texture* information = loadTexture("Image/information.png", renderer);
//    
//    int trangthai = 0;
//    //SDL_Event e;
//
//    //SDL_Rect startButton;
//    //SDL_Rect exitButton;
//
//    Mix_Music* music = Mix_LoadMUS("Sound/music.mp3");
//    //TTF_Font* font = TTF_OpenFont("Font/Montserrat-Bold.ttf", FONT_SIZE);
//
//    //SDL_QueryTexture(Start, NULL, NULL, &startButton.w, &startButton.h);
//    //SDL_QueryTexture(Exit, NULL, NULL, &exitButton.w, &exitButton.h);
//
//    //startButton.x = SCREEN_WIDTH / 2 - startButton.w / 2; //426
//    //startButton.y = SCREEN_HEIGHT / 2 - 100; // 300
//    //exitButton.x = SCREEN_WIDTH / 2 - startButton.w / 2 + exitButton.w / 2; //5-6
//    //exitButton.y = SCREEN_HEIGHT / 2; //400
//
//
//    //// Vector to store monsters
//    //vector<Enemy> monsters;
//    //vector<Ally> heroes;
//        
//
//// khoi dong
////while (true) {
////
////        SDL_PollEvent(&e);
////        if (e.type == SDL_QUIT) break;
////        else if (e.type == SDL_MOUSEBUTTONDOWN) {
////            if (e.button.button == SDL_BUTTON_LEFT) {
////                int mouseX = e.button.x;
////                int mouseY = e.button.y;
////                
////                trangthai = Start_Exit(mouseX, mouseY, startButton, exitButton, Start, Exit);
////                    if (trangthai != 0) break;
////            }
////
////        }
////
////        SDL_RenderClear(renderer);
////           
////        SDL_RenderCopy(renderer, Background, NULL, NULL);
////        SDL_RenderCopy(renderer, Start, NULL, &startButton);
////        SDL_RenderCopy(renderer, Exit, NULL, &exitButton);
////
////        SDL_RenderPresent(renderer);
////        
////        
////}
//    
//    trangthai = Start_Exit(renderer);
//
//// play
//    if (trangthai == 1) {
//
//        while (trangthai != 2) {
//            trangthai = Play(renderer);
//
//            trangthai = Win_Lose(renderer, trangthai);
//        }
//    }
////{
////            
////    Mix_PlayMusic(music, -1);
////            
////    // IMAGE
////            
////    
////    // RECT
////            
////    SDL_Rect information_loc = {0,0, 200, 200};
////    SDL_Rect spawnButton = { 200,icon_height,50,50 };
////            
////    SDL_Rect ally_base_pos = { 100, ground_height - 150, 200 , 200};
////    SDL_Rect enemy_base_pos = { 950, ground_height - 130, 200, 200 };
////            
////    
////
////    //FONT
////
////    // INT
////
////    int gold = 200;
////    int ally_base_health = 10000;
////    int enemy_base_health = 10000;
////    int time_count = 0;
////    int mouseX;
////    int mouseY;
////
////    while (true) {
////        // Đợi 10 mili giây
////        SDL_Delay(10);
////        SDL_PollEvent(&e);
////
////        time_count++;
////                
////        // RENDER
////        SDL_RenderClear(renderer);
////       
////        Display_All(Background, ally_base_img, enemy_base_img, spawn_img, spawnButton, ally_base_pos, enemy_base_pos, renderer);
////        Display_AllyBaseHealth(ally_base_health, renderer);
////        Display_EnemyBaseHealth(enemy_base_health, renderer);
////        Display_Gold( gold, gold_img, font, renderer);
////        Display_Ally(heroes, renderer);
////        Display_Enemy(monsters, renderer);
////
////        if (e.type == SDL_QUIT or e.type == SDL_KEYDOWN) break; 
////        // spawn
////        else if (e.type == SDL_MOUSEBUTTONDOWN) {
////            if (e.button.button == SDL_BUTTON_LEFT) {
////                mouseX = e.button.x;
////                mouseY = e.button.y;
////    
////                    if (gold > 20 && ClickBox(mouseX, mouseY, spawnButton) == true)
////                    {
////                        heroes.push_back(Ally(heroTexture, heroAttackTexture, 100, 10, 20, 150));
////                        gold -= 20;
////                    }
////            }
////        }
////            
////        SDL_GetMouseState(&mouseX, &mouseY);
////        Display_Information(mouseX, mouseY, information, renderer);
////            
////        if (gold < 99999 && time_count % 100 == 0) gold++;
////        // game
////        //if (time_count % 1 == 0) {
////
////            // gain
////                
////            // regen
////            if (ally_base_health <= 10000)  ally_base_health++;
////            if (enemy_base_health <= 10000) enemy_base_health++;
////
////            //enemy spawn
////            if (time_count % 200 == 0) monsters.push_back(Enemy(monsterTexture, enemy_spawn_point, 100, 10, 20));
////
////                    
////            int ally_farest = 0;
////            int enemy_farest = 0;
////
////            if (time_count%50 == 0){
////            if (!heroes.empty()) 
////            ally_farest = heroes[0].position();
////            if (!monsters.empty()) enemy_farest = monsters[0].position();
////            
////            if (monsters.empty()) {
////                for (auto& hero : heroes)
////                {
////                    if (hero.position() >= enemy_spawn_point) enemy_base_health -= hero.Damage();
////                    else hero.ally_move();
////                    //hero.render(renderer);
////                }
////            }
////
////            else if (heroes.empty()) {
////                for (auto& monster : monsters) {
////                    if (monster.position() <= ally_spawn_point) ally_base_health -= monster.Damage();
////                    else monster.enemy_move();
////
////                    //monster.render(renderer);
////                }
////            }
////            
////            else {
////
////                ally_farest = heroes[0].position();
////                enemy_farest = monsters[0].position();
////                for (auto& monster : monsters) {
////
////                    if (monster.position() <= ally_farest + 20 && monster.position() >= ally_farest - 20) heroes[0].takeDamage(monster.Damage());
////                    else if (monster.position() <= ally_spawn_point) ally_base_health -= monster.Damage();
////                    else monster.enemy_move();
////                    //monster.render(renderer);
////
////                }
////
////                for (auto& hero : heroes)
////                {
////                    /*if (hero.position() <= enemy_farest + 20 && hero.position() >= enemy_farest - 20) monsters[0].takeDamage(hero.Damage());*/
////                    if (hero.CanAttack(enemy_farest) == true) monsters[0].takeDamage(hero.Damage());
////                    //else if (hero.CanAttack(enemy_spawn_point) == true) hero.Attack(enemy_base_health);
////                    else hero.ally_move();
////                    //hero.render(renderer);
////                }
////
////                /*if (!heroes.empty()) { if (heroes[0].isDestroyed() == true) heroes.erase(heroes.begin()); }
////                if (!monsters.empty()) {
////                    if (monsters[0].isDestroyed() == true) {
////                        gold += monsters[0].Gold();
////                        monsters.erase(monsters.begin());
////
////                    }
////                }*/
////
////                if (heroes[0].isDestroyed() == true) heroes.erase(heroes.begin());
////                if (monsters[0].isDestroyed() == true) {
////                    gold += monsters[0].Gold();
////                    monsters.erase(monsters.begin());
////
////                }
////            }
////            
////            }
////            if (ally_base_health <= 0) {
////
////                SDL_DestroyTexture(ally_base_img);
////                cout << "LOSE!";
////                break;
////            }
////
////            if (enemy_base_health <= 0) {
////
////                SDL_DestroyTexture(enemy_base_img);
////                cout << "WIN!";
////                break;
////            }
////        //}
////
////        // Present renderer
////        SDL_RenderPresent(renderer);
////
////    }
////
////    
////            
////            
////}
//
//    if (trangthai == 2) quitSDL(window, renderer, music);
//    
//quitSDL(window, renderer, music);
//
//}
//
