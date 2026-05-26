// process.c - Gestión de procesos de LaxOS
#include "kernel.h"

void mostrar_procesos() {
    struct Proceso procesos[4] = {
        {"LaxOS Kernel",    1, 512},
        {"Gestor RAM",      2, 256},
        {"Driver pantalla", 3, 128},
        {"Driver audio",    4,  64}
    };

    printf("=================================\n");
    printf("Procesos activos en LaxOS:\n");

    for (int i = 0; i < 4; i++) {
        printf("PID %d | %s | %d MB\n",
            procesos[i].id,
            procesos[i].nombre,
            procesos[i].memoria_mb);
    }
    printf("=================================\n");
}