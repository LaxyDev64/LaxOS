// shell.c - Shell básica de LaxOS
#include "kernel.h"

void laxos_shell() {
    char comando[50];

    printf("=================================\n");
    printf("  LaxOS Shell v0.1\n");
    printf("  Escribe 'ayuda' para ver comandos\n");
    printf("=================================\n");

    while (1) {
        printf("LaxOS> ");
        scanf("%s", comando);

        if (strcmp(comando, "ayuda") == 0) {
            printf("Comandos disponibles:\n");
            printf("  ayuda    - muestra esta lista\n");
            printf("  info     - informacion del sistema\n");
            printf("  procesos - lista de procesos\n");
            printf("  memoria  - estado de la memoria\n");
            printf("  leer     - leer archivo laxos.cfg\n");
            printf("  salir    - apagar LaxOS\n");

        } else if (strcmp(comando, "info") == 0) {
            printf("Sistema: LaxOS v%s\n", LAXOS_VERSION);
            printf("CPU: %d nucleos ARM\n", LAXOS_CPU_CORES);
            printf("RAM: %d MB\n", LAXOS_RAM_MB);

        } else if (strcmp(comando, "procesos") == 0) {
            mostrar_procesos();

        } else if (strcmp(comando, "memoria") == 0) {
            gestionar_memoria();

        } else if (strcmp(comando, "leer") == 0) {
            laxos_leer("laxos.cfg");

        } else if (strcmp(comando, "salir") == 0) {
            printf("Apagando LaxOS...\n");
            break;

        } else {
            printf("Comando no reconocido: %s\n", comando);
        }
    }
}