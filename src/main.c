/*

Created by: no-good-name
Created on 2023-07-31
Updated: 2023-08-18

*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <SDL.h>

#include "main_type.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static struct {
    SDL_Window *g_window;
    SDL_Renderer *g_renderer;
    SDL_Texture *g_texture;
    struct {
        int x;
        int y;
    } mouse;
    bool quit;
} state;

static void init(void) {
    system("cls");
    SDL_Init(SDL_INIT_EVERYTHING);

    state.g_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    state.g_renderer = SDL_CreateRenderer(state.g_window, -1, SDL_RENDERER_ACCELERATED);
    state.g_texture = SDL_CreateTexture(state.g_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

    state.quit = false;
}

static void deinit(void) {
    SDL_DestroyTexture(state.g_texture);
    SDL_DestroyRenderer(state.g_renderer);
    SDL_DestroyWindow(state.g_window);
    SDL_Quit();
}

void input(void) {
    const uint8_t *keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_ESCAPE]) {
        state.quit = true;
    }
    if(keystate[SDL_SCANCODE_SPACE]) {
        SDL_GetMouseState(&state.mouse.x, &state.mouse.y);
        printf("x: %d, y: %d\n", state.mouse.x, state.mouse.y);
    }
}

void gradient(int w, int h, color_t c1, color_t c2) {
    uint32_t *pixels = (uint32_t *)malloc(w * h * sizeof(uint32_t));
    for (int i = 0; i < w * h; i++) {
        float t = (float)i / (float)(w * h);
        uint8_t r = (uint8_t)(c1.r + (c2.r - c1.r) * t);
        uint8_t g = (uint8_t)(c1.g + (c2.g - c1.g) * t);
        uint8_t b = (uint8_t)(c1.b + (c2.b - c1.b) * t);
        uint8_t a = (uint8_t)(c1.a + (c2.a - c1.a) * t);
        pixels[i] = (a << 24) | (b << 16) | (g << 8) | r;
    }
    SDL_UpdateTexture(state.g_texture, NULL, pixels, w * sizeof(uint32_t));
    free(pixels);
}

int main(int argc, char *argv[]) {
    init();
    color_t c1 = { 255, 0, 0, 255 };
    color_t c2 = { 0, 0, 255, 255 };
    
    int over = 0;

    while (!state.quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                state.quit = true;
            }
        }
        if (state.quit == true) {
            break;
        }
        input();
        gradient(WINDOW_WIDTH, WINDOW_HEIGHT, c1, c2);

        SDL_RenderClear(state.g_renderer);
        SDL_RenderCopy(state.g_renderer, state.g_texture, NULL, NULL);
        SDL_RenderPresent(state.g_renderer);
    }

    deinit();
    printf("R: %d G: %d B: %d\n", c1.r, c1.g, c1.b);
    printf("R1: %d G1: %d B1: %d\n", c2.r, c2.g, c2.b);

    return EXIT_SUCCESS;
}
