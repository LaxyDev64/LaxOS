// users.c - Sistema de usuarios de LaxOS
#include "users.h"
#include <stdio.h>
#include <string.h>

Usuario usuarios[MAX_USUARIOS];
int usuario_actual = 0;

void users_init() {
    memset(usuarios, 0, sizeof(usuarios));
    strcpy(usuarios[0].nombre, "LaxyDev64");
    usuarios[0].color_r = 0;
    usuarios[0].color_g = 180;
    usuarios[0].color_b = 220;
    usuarios[0].activo  = 1;
}

void users_guardar() {
    FILE* f = fopen("users.cfg", "w");
    if (!f) return;
    for (int i = 0; i < MAX_USUARIOS; i++) {
        if (usuarios[i].activo)
            fprintf(f, "%s,%d,%d,%d\n",
                usuarios[i].nombre,
                usuarios[i].color_r,
                usuarios[i].color_g,
                usuarios[i].color_b);
    }
    fclose(f);
    printf("Usuarios guardados\n");
}

void users_cargar() {
    FILE* f = fopen("users.cfg", "r");
    if (!f) { users_init(); return; }
    int i = 0;
    while (i < MAX_USUARIOS &&
           fscanf(f, "%31[^,],%d,%d,%d\n",
               usuarios[i].nombre,
               &usuarios[i].color_r,
               &usuarios[i].color_g,
               &usuarios[i].color_b) == 4) {
        usuarios[i].activo = 1;
        i++;
    }
    fclose(f);
}

Usuario* users_actual() {
    return &usuarios[usuario_actual];
}