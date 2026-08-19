// users.h - Sistema de usuarios de LaxOS
#ifndef USERS_H
#define USERS_H

#define MAX_USUARIOS 4
#define MAX_NOMBRE   32

typedef struct {
    char nombre[MAX_NOMBRE];
    int  color_r;
    int  color_g;
    int  color_b;
    int  activo;
} Usuario;

void users_init();
void users_guardar();
void users_cargar();
Usuario* users_actual();

#endif