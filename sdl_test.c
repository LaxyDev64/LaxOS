// sdl_test.c - Primer test SDL2 de LaxOS
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[])  {
    // Inicializar SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error SDL2: %s\n", SDL_GetError());
        return 1;
    }

    // Crear ventana — tamaño del Wii U Gamepad (854x480)
    SDL_Window* ventana = SDL_CreateWindow(
        "LaxOS",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        854, 480,
        SDL_WINDOW_SHOWN
    );

    // Crear renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, 0);

    // Color de fondo azul LaxOS
    SDL_SetRenderDrawColor(renderer, 30, 100, 200, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    // Esperar 3 segundos
    SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    printf("SDL2 funciona!\n");
    return 0;
}