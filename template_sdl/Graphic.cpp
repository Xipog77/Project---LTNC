#include "Graphic.h"
#include "NPC.h"

using namespace std;

const SDL_Color Gold_Color = { 250, 200, 0, 0 };
const SDL_Color Black_Color = { 0, 0, 0, 255 };
char Gold_Text[16];

SDL_Rect gold_number_pos = { gold_x, gold_y, 0, 0 };
SDL_Rect gold_number_border_pos = { gold_x - 2, gold_y - 2, 0, 0 };
SDL_Rect gold_img_pos = { 960, 12, 35 ,35 };

const string WINDOW_TITLE = "Deffend The Kingdom";

void logSDLError(std::ostream& os, const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}


SDL_Window* initWindow() {

    SDL_Window* window;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    //fullscreeen
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, 
    //   SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    return window;


}

SDL_Renderer* initRenderer(SDL_Window* window) {

    SDL_Renderer* renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return renderer;

}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit;
    TTF_Quit();
    SDL_Quit();
    return;
}

SDL_Texture* loadTexture(const std::string& path, SDL_Renderer* renderer) {
    // Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    // Create texture from surface pixels
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (texture == nullptr) {
        std::cerr << "Unable to create texture from " << path.c_str() << "! SDL Error: " << SDL_GetError() << std::endl;
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    /*cout << "LOADING: " << path << endl;*/

    return texture;
}

void Display_EnemyBase(int enemy_base_health,  SDL_Texture* enemy_base_img, SDL_Rect enemy_base_pos, SDL_Renderer* renderer) {

    SDL_RenderCopy(renderer, enemy_base_img, NULL, &enemy_base_pos);

    SDL_Rect EnemyBaseHealthBar = { enemy_spawn_point, ground_height - 100 - enemy_base_pos.h , static_cast<int>(64 * (static_cast<double>(enemy_base_health) / 5000)), 13 };
    if (enemy_base_health < 0) EnemyBaseHealthBar.w = 0;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &EnemyBaseHealthBar);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color
    //cout << enemy_base_health << endl;
    return;
    
}

void Display_AllyBase(int ally_base_health,  SDL_Texture* ally_base_img, SDL_Rect ally_base_pos, SDL_Renderer* renderer) {

    SDL_RenderCopy(renderer, ally_base_img, NULL, &ally_base_pos);

    SDL_Rect AllyBaseHealthBar = { ally_spawn_point, ground_height - 100 - ally_base_pos.h , static_cast<int>(64 * (static_cast<double>(ally_base_health) / 5000)), 13 };
    if (ally_base_health < 0) AllyBaseHealthBar.w = 0;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &AllyBaseHealthBar);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color
    return;
}
void Display_Background(CLIP background, int tick, SDL_Renderer* renderer) {
    
    SDL_RenderCopy(renderer, background.texture, &background.clips[tick], NULL);
}

void Display_SpawnButton(int mouseX, int mouseY, SDL_Texture* spawnImg , SDL_Texture* information, SDL_Rect spawnButton, SDL_Rect frame, SDL_Renderer* renderer) {
    SDL_Rect information_loc = { 0,0, 225, 180 };
    SDL_Rect information_pic = { 600, 650, 750 , 600 };
    SDL_RenderCopy(renderer, spawnImg, &frame, &spawnButton);
    if (mouseX >= spawnButton.x && mouseX <= spawnButton.x + spawnButton.w &&
        mouseY >= spawnButton.y && mouseY <= spawnButton.y + spawnButton.h)
    {
        information_loc.x = mouseX;
        information_loc.y = mouseY;
        SDL_RenderCopy(renderer, information, &information_pic, &information_loc);
    }
    return;
}

void Display_Gold(int gold, SDL_Texture* gold_img, TTF_Font* font, SDL_Renderer* renderer) {

    snprintf(Gold_Text, sizeof(Gold_Text), "Gold: %d", gold);
    SDL_Surface* gold_number_surface = TTF_RenderText_Solid(font, Gold_Text, Gold_Color);
    SDL_Texture* gold_number_texture = SDL_CreateTextureFromSurface(renderer, gold_number_surface);
    SDL_Surface* gold_number_border_surface = TTF_RenderText_Solid(font, Gold_Text, Black_Color);
    SDL_Texture* gold_number_border_texture = SDL_CreateTextureFromSurface(renderer, gold_number_border_surface);

    SDL_QueryTexture(gold_number_texture, NULL, NULL, &gold_number_pos.w, &gold_number_pos.h);

    gold_number_border_pos.w = gold_number_pos.w;
    gold_number_border_pos.h = gold_number_pos.h;

    SDL_RenderCopy(renderer, gold_img, NULL, &gold_img_pos);
    SDL_RenderCopy(renderer, gold_number_border_texture, NULL, &gold_number_border_pos);
    SDL_RenderCopy(renderer, gold_number_texture, NULL, &gold_number_pos);
    return;
}

void Display_Ally(vector<Ally> NPC, SDL_Renderer* renderer) {

    for (auto& n : NPC) {
        n.render(renderer);
    }
    return;
}
void Display_Enemy(vector<Enemy> NPC, SDL_Renderer* renderer) {

    for (auto& n : NPC) {
        n.render(renderer);
    }
    return;
}

bool ClickBox(int mouseX, int mouseY, SDL_Rect Box) {

    if (mouseX >= Box.x && mouseX <= Box.x + Box.w && mouseY >= Box.y && mouseY <= Box.y + Box.h) return true;
    
    return false;
}
