#include <SDL2/SDL.h>
#include <iostream>
using std::cout;
int main(){
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Event event;
    int fps = 60;
    int desiredDelta = 1000/fps;

    bool running = true;
    SDL_Rect r{10,10, 500/2, 500/2};

    int cor[3]{255, 255, 255};
    bool switchCor = false;

    SDL_CreateWindowAndRenderer(500, 500, 0, &window, &renderer);
    while (running) {
        int startLoop = SDL_GetTicks();
        while (SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
            else if(event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym)
                {
                case SDLK_a:
                    cout << "Tecla pressionada a\n";
                    break;
                default:
                    break;
                }
                cout << "Tecla pressionada: " << event.key.keysym.sym << '\n';
            }
            else if(event.type == SDL_MOUSEMOTION){
                SDL_GetMouseState(&r.x, &r.y);
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN){
                if(event.button.button == SDL_BUTTON_LEFT){
                    cout << "Botão esquerdo pressionado\n";
                    if(switchCor){
                        cor[0] = 255;
                        cor[1] = 255;
                        cor[2] = 255;
                    }else{
                        cor[0] = 0;
                        cor[1] = 200;
                        cor[2] = 0;
                    }
                    switchCor = !switchCor;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, cor[0], cor[1], cor[2], 255);
        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
        
        int delta = SDL_GetTicks() - startLoop;
        if(delta < desiredDelta){
            SDL_Delay(desiredDelta - delta);
        }
    }
    return 0;
}
