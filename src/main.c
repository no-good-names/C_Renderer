#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <SDL.h>
#include <math.h>

#include "main_type.h"

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 200
#define TARGET_DELTATIME 16.67

static struct {
    SDL_Window *g_window;
    SDL_Renderer *g_renderer;
    SDL_Texture *g_texture;
    bool quit;
} state;

/*
void rendering(SDL_Window *window, SDL_Renderer *renderer) {
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(state.g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
*/

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    int RGB[3] = {255, 255, 255};

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH*4, WINDOW_HEIGHT*4, 0, &state.g_window, &state.g_renderer);
    SDL_RenderSetScale(state.g_renderer, 4, 4);

    // Color
    SDL_SetRenderDrawColor(state.g_renderer, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(state.g_renderer, RGB[0], RGB[1], RGB[2], 255);

    for (int i = 0; i <= WINDOW_WIDTH; i++) {
        SDL_RenderDrawPoint(state.g_renderer, i, i);
    }
    // Update the screen
    SDL_RenderPresent(state.g_renderer);

    SDL_Event event;

    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    SDL_DestroyRenderer(state.g_renderer);
    SDL_DestroyWindow(state.g_window);
    SDL_Quit();


    return 0;
}
