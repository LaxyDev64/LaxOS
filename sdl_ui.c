// sdl_ui.c - Interfaz gráfica de LaxOS con SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define ANCHO  854
#define ALTO   480

SDL_Texture* cargar(SDL_Renderer* r, const char* ruta) {
    SDL_Surface* s = IMG_Load(ruta);
    if (!s) { printf("Error: %s\n", IMG_GetError()); return NULL; }
    SDL_SetColorKey(s, SDL_TRUE, SDL_MapRGB(s->format, 0, 0, 0));
    SDL_Texture* t = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    return t;
}

void dibujar_parte(SDL_Renderer* r, SDL_Texture* t,
                   int sx, int sy, int sw, int sh,
                   int dx, int dy, int dw, int dh) {
    if (!t) return;
    SDL_Rect src  = {sx, sy, sw, sh};
    SDL_Rect dest = {dx, dy, dw, dh};
    SDL_RenderCopy(r, t, &src, &dest);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* win = SDL_CreateWindow(
        "LaxOS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        ANCHO, ALTO, SDL_WINDOW_SHOWN
    );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // Cargar sprites
    SDL_Texture* wifi    = cargar(ren, "assets/wifi.png");
    SDL_Texture* battery = cargar(ren, "assets/battery.png");
    SDL_Texture* gamepad = cargar(ren, "assets/gamepad.png");

    SDL_Event e;
    int corriendo = 1;

    while (corriendo) {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_QUIT) corriendo = 0;

        // Fondo degradado azul
        for (int y = 0; y < ALTO; y++) {
            int r2 = 10 + (y * 20 / ALTO);
            int g  = 60 + (y * 40 / ALTO);
            int b  = 180 - (y * 60 / ALTO);
            SDL_SetRenderDrawColor(ren, r2, g, b, 255);
            SDL_RenderDrawLine(ren, 0, y, ANCHO, y);
        }

        // Topbar oscura
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 120);
        SDL_Rect topbar = {0, 0, ANCHO, 44};
        SDL_RenderFillRect(ren, &topbar);

        // WiFi — 4to icono (señal completa cyan)
        dibujar_parte(ren, wifi,    390, 0, 130, 130, ANCHO-180, 4, 36, 36);

        // Batería — 1er icono (llena azul)
        dibujar_parte(ren, battery,   0, 0,  90,  50, ANCHO-90,  4, 36, 36);

        // Gamepad — 1er icono (conectado)
        dibujar_parte(ren, gamepad,   0, 0,  80,  80, ANCHO-230, 4, 36, 36);

        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}