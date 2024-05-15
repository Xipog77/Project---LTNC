
#define SDL_MAIN_HANDLED

#include "Graphic.h"
#include "Function.h"


extern SDL_Window* window = initWindow();
extern SDL_Renderer* renderer = initRenderer(window);


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

