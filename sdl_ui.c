// sdl_ui.c - Interfaz gráfica de LaxOS con SDL2
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "tinyfiledialogs.h"
#include "users.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ANCHO    854
#define ALTO     480
#define MAX_ROMS 15

const char* EMU_DUCKSTATION = "E:/duckstation/duckstation-qt-x64-ReleaseLTCG.exe";

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

void dibujar_texto(SDL_Renderer* r, TTF_Font* f, const char* txt,
                   int x, int y, SDL_Color color) {
    if (!f || !txt) return;
    SDL_Surface* s = TTF_RenderText_Blended(f, txt, color);
    if (!s) return;
    SDL_Texture* t = SDL_CreateTextureFromSurface(r, s);
    SDL_Rect dest  = {x, y, s->w, s->h};
    SDL_RenderCopy(r, t, NULL, &dest);
    SDL_DestroyTexture(t);
    SDL_FreeSurface(s);
}

void dibujar_circulo(SDL_Renderer* r, int cx, int cy, int radio) {
    for (int y = -radio; y <= radio; y++)
        for (int x = -radio; x <= radio; x++)
            if (x*x + y*y <= radio*radio)
                SDL_RenderDrawPoint(r, cx+x, cy+y);
}

char* obtener_hora() {
    static char buf[16];
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    sprintf(buf, "%02d:%02d", tm->tm_hour, tm->tm_min);
    return buf;
}

char roms[MAX_ROMS][256];
int  num_roms = 0;

void guardar_roms() {
    FILE* f = fopen("roms.cfg", "w");
    if (!f) return;
    for (int i = 0; i < MAX_ROMS; i++)
        if (strlen(roms[i]) > 0)
            fprintf(f, "%d=%s\n", i, roms[i]);
    fclose(f);
    printf("ROMs guardadas\n");
}

void cargar_roms_guardadas() {
    FILE* f = fopen("roms.cfg", "r");
    if (!f) return;
    int slot;
    char ruta[256];
    while (fscanf(f, "%d=%255[^\n]\n", &slot, ruta) == 2)
        if (slot >= 0 && slot < MAX_ROMS)
            strncpy(roms[slot], ruta, 255);
    fclose(f);
    printf("ROMs cargadas\n");
}

const char* detectar_emulador(const char* rom) {
    const char* ext = strrchr(rom, '.');
    if (!ext) return NULL;
    if (strcmp(ext, ".iso") == 0 ||
        strcmp(ext, ".bin") == 0 ||
        strcmp(ext, ".cue") == 0 ||
        strcmp(ext, ".pbp") == 0)
        return EMU_DUCKSTATION;
    return NULL;
}

void cargar_rom(int slot) {
    const char* filtros[] = {
        "*.nes","*.smc","*.sfc","*.snes",
        "*.gb","*.gbc","*.gba",
        "*.n64","*.z64","*.v64",
        "*.nds","*.dsi","*.3ds","*.cia",
        "*.wbfs","*.iso","*.wad",
        "*.xci","*.nsp",
        "*.sms","*.md","*.gen","*.bin",
        "*.gg","*.sat","*.cue",
        "*.gdi","*.cdi","*.pbp","*.cso",
        "*.zip","*.7z","*.rom","*.img"
    };
    const char* ruta = tinyfd_openFileDialog(
        "LaxOS - Selecciona una ROM", "", 30,
        filtros, "Archivos ROM (todas las consolas)", 0
    );
    if (ruta) {
        strncpy(roms[slot], ruta, 255);
        if (slot >= num_roms) num_roms = slot + 1;
        guardar_roms();
    }
}

void lanzar_rom(int slot) {
    if (strlen(roms[slot]) == 0) { cargar_rom(slot); return; }
    const char* emu = detectar_emulador(roms[slot]);
    if (!emu) { printf("No hay emulador para esta ROM\n"); return; }
    char cmd[512];
    sprintf(cmd, "\"%s\" \"%s\"", emu, roms[slot]);
    system(cmd);
}

char* nombre_rom(int slot) {
    if (strlen(roms[slot]) == 0) return NULL;
    static char nombre[64];
    char* ultimo = strrchr(roms[slot], '\\');
    if (!ultimo) ultimo = strrchr(roms[slot], '/');
    if (ultimo) ultimo++;
    else ultimo = roms[slot];
    strncpy(nombre, ultimo, 63);
    char* punto = strrchr(nombre, '.');
    if (punto) *punto = 0;
    return nombre;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    SDL_Window* win = SDL_CreateWindow(
        "LaxOS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        ANCHO, ALTO, SDL_WINDOW_SHOWN
    );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* fuente       = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 16);
    TTF_Font* fuente_small = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 11);

    SDL_Texture* wifi    = cargar(ren, "assets/wifi.png");
    SDL_Texture* battery = cargar(ren, "assets/battery.png");
    SDL_Texture* gamepad = cargar(ren, "assets/gamepad.png");
    SDL_Texture* logo    = cargar(ren, "assets/logo.png");

    SDL_Color blanco = {255, 255, 255, 255};
    SDL_Color gris   = {160, 160, 160, 255};
    SDL_Color oscuro = {90,  90,  100, 255};

    memset(roms, 0, sizeof(roms));
    users_cargar();
    cargar_roms_guardadas();

    srand(42);
    int bx[18], by[18], br[18];
    for (int i = 0; i < 18; i++) {
        bx[i] = rand() % ANCHO;
        by[i] = rand() % ALTO;
        br[i] = 20 + rand() % 60;
    }

    SDL_Event e;
    int corriendo = 1;
    int slot_sel  = 0;

    while (corriendo) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                guardar_roms();
                users_guardar();
                corriendo = 0;
            }
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_RIGHT:  slot_sel = (slot_sel+1) % 15;    break;
                    case SDLK_LEFT:   slot_sel = (slot_sel-1+15) % 15; break;
                    case SDLK_DOWN:   slot_sel = (slot_sel+5) % 15;    break;
                    case SDLK_UP:     slot_sel = (slot_sel-5+15) % 15; break;
                    case SDLK_RETURN: lanzar_rom(slot_sel);             break;
                    case SDLK_s:      guardar_roms();                   break;
                    case SDLK_ESCAPE:
                        guardar_roms();
                        users_guardar();
                        corriendo = 0;
                        break;
                }
            }
        }

        // Fondo oscuro
        SDL_SetRenderDrawColor(ren, 30, 30, 35, 255);
        SDL_RenderClear(ren);

        // Burbujas
        for (int i = 0; i < 18; i++) {
            SDL_SetRenderDrawColor(ren, 48, 48, 55, 255);
            dibujar_circulo(ren, bx[i], by[i], br[i]);
        }

        // TOPBAR
        SDL_SetRenderDrawColor(ren, 18, 18, 22, 255);
        SDL_Rect topbar = {0, 0, ANCHO, 52};
        SDL_RenderFillRect(ren, &topbar);

        // Avatar con color del usuario
        Usuario* u = users_actual();
        SDL_SetRenderDrawColor(ren, u->color_r, u->color_g, u->color_b, 255);
        dibujar_circulo(ren, 28, 26, 18);
        if (logo) {
            SDL_Rect lr = {10, 8, 36, 36};
            SDL_RenderCopy(ren, logo, NULL, &lr);
        }
        dibujar_texto(ren, fuente_small, u->nombre, 52, 18, blanco);

        // Puntos de página
        for (int i = 0; i < 5; i++) {
            if (i == 0) SDL_SetRenderDrawColor(ren, 0, 180, 220, 255);
            else        SDL_SetRenderDrawColor(ren, 80, 80, 90, 255);
            dibujar_circulo(ren, ANCHO/2 - 40 + i*20, 26, 5);
        }

        // Reloj y sprites
        dibujar_texto(ren, fuente, obtener_hora(), ANCHO-200, 16, blanco);
        dibujar_parte(ren, wifi,    390, 0, 130, 130, ANCHO-155, 10, 30, 30);
        dibujar_parte(ren, battery,   0, 0,  97, 104, ANCHO-118, 10, 56, 30);

        // GRID 5x3
        int cols   = 5;
        int filas  = 3;
        int sw     = 138;
        int sh     = 108;
        int gap    = 10;
        int grid_x = (ANCHO - (cols * sw + (cols-1) * gap)) / 2;
        int grid_y = 60;

        for (int f = 0; f < filas; f++) {
            for (int c = 0; c < cols; c++) {
                int idx = f * cols + c;
                int x = grid_x + c * (sw + gap);
                int y = grid_y + f * (sh + gap);

                if (idx == slot_sel) {
                    SDL_SetRenderDrawColor(ren, 0, 180, 220, 255);
                    SDL_Rect borde = {x-3, y-3, sw+6, sh+6};
                    SDL_RenderFillRect(ren, &borde);
                }

                if (strlen(roms[idx]) > 0)
                    SDL_SetRenderDrawColor(ren, 0, 100, 160, 255);
                else
                    SDL_SetRenderDrawColor(ren, 52, 52, 60, 255);

                SDL_Rect slot = {x, y, sw, sh};
                SDL_RenderFillRect(ren, &slot);

                if (strlen(roms[idx]) > 0) {
                    char* nombre = nombre_rom(idx);
                    if (nombre)
                        dibujar_texto(ren, fuente_small, nombre, x+6, y+sh/2-8, blanco);
                } else {
                    SDL_SetRenderDrawColor(ren, 80, 80, 92, 255);
                    SDL_Rect ph = {x+sw/2-12, y+sh/2-3, 24, 6};
                    SDL_Rect pv = {x+sw/2-3, y+sh/2-12, 6, 24};
                    SDL_RenderFillRect(ren, &ph);
                    SDL_RenderFillRect(ren, &pv);
                }
            }
        }

        // BARRA INFERIOR
        SDL_SetRenderDrawColor(ren, 18, 18, 22, 255);
        SDL_Rect barra = {0, ALTO-62, ANCHO, 62};
        SDL_RenderFillRect(ren, &barra);

        const char* labels[] = {"ROM", "Ajustes", "WiFi", "Mii", "Control", "Config"};
        Uint8 cr[] = {220, 240, 60,  60,  220, 130};
        Uint8 cg[] = {80,  160, 140, 180, 60,  130};
        Uint8 cb[] = {80,  40,  220, 80,  80,  140};

        int n      = 6;
        int radio  = 22;
        int inicio = ANCHO/2 - (n * (radio*2 + 12)) / 2 + radio;

        for (int i = 0; i < n; i++) {
            int cx = inicio + i * (radio*2 + 12);
            int cy = ALTO - 32;
            SDL_SetRenderDrawColor(ren, cr[i], cg[i], cb[i], 255);
            dibujar_circulo(ren, cx, cy, radio);
            dibujar_texto(ren, fuente_small, labels[i], cx-18, cy+radio+3, gris);
        }

        dibujar_parte(ren, gamepad, 0, 0, 71, 96, 10, ALTO-52, 40, 40);

        dibujar_texto(ren, fuente_small,
            "Enter: cargar/lanzar  |  S: guardar  |  Flechas: navegar  |  Esc: salir",
            ANCHO/2-220, ALTO-14, oscuro);

        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    TTF_CloseFont(fuente);
    TTF_CloseFont(fuente_small);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}