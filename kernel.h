// kernel.h - Definiciones globales de LaxOS
#ifndef KERNEL_H
#define KERNEL_H

#include <stdio.h>
#include <string.h>

#define LAXOS_VERSION   "0.8"
#define LAXOS_RAM_MB    12288
#define LAXOS_CPU_CORES 8

// Struct de proceso disponible para todos
struct Proceso {
    char* nombre;
    int   id;
    int   memoria_mb;
};

// Declaraciones de funciones
void laxos_init();
void gestionar_memoria();
void mostrar_procesos();
void laxos_shell();
void laxos_filesystem_init();
void laxos_escribir(char* nombre, char* contenido);
void laxos_leer(char* nombre);
void laxos_ui_menu();
void laxos_ui_header();

#endif