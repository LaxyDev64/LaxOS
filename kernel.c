// kernel.c - Arranque de LaxOS
#include "kernel.h"

void laxos_init() {
    printf("=================================\n");
    printf("Bienvenido a LaxOS v%s!\n", LAXOS_VERSION);
    printf("Sistema: LaxOS\n");
    printf("CPU: %d nucleos ARM\n", LAXOS_CPU_CORES);
    printf("RAM: %d MB\n", LAXOS_RAM_MB);
    gestionar_memoria();
    mostrar_procesos();
    printf("Estado: Sistema listo\n");
    printf("=================================\n");
}