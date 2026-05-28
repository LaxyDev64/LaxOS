// shell.c - Shell mejorada de LaxOS v2.0
#include "kernel.h"
#include <time.h>
#include <stdlib.h> 

void shell_ayuda() {
    printf("\n  Comandos de LaxOS Shell:\n");
    printf("  ------------------------\n");
    printf("  ayuda      - muestra esta lista\n");
    printf("  info       - informacion del sistema\n");
    printf("  arch       - arquitectura del sistema\n");
    printf("  procesos   - lista de procesos activos\n");
    printf("  memoria    - estado de la memoria\n");
    printf("  hora       - muestra la hora actual\n");
    printf("  leer       - leer laxos.cfg\n");
    printf("  guardar    - guardar nota en archivo\n");
    printf("  limpiar    - limpiar pantalla\n");
    printf("  salir      - volver al menu\n\n");
}

void shell_info() {
    printf("\n  Sistema:      LaxOS v%s\n", LAXOS_VERSION);
    printf("  CPU:          %d nucleos\n", LAXOS_CPU_CORES);
    printf("  RAM:          %d MB\n", LAXOS_RAM_MB);
    printf("  RAM juegos:   %d MB\n", LAXOS_RAM_MB - 512);
    printf("  Nucleos disp: %d\n\n", LAXOS_CPU_CORES - 2);
}

void shell_hora() {
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    printf("\n  Hora actual: %02d:%02d:%02d\n\n",
        tm_info->tm_hour,
        tm_info->tm_min,
        tm_info->tm_sec);
}

void shell_guardar() {
    char nota[200];
    printf("  Escribe tu nota: ");
    getchar();
    fgets(nota, sizeof(nota), stdin);
    laxos_escribir("nota.txt", nota);
}

void laxos_shell() {
    char cmd[50];

    printf("\n");
    printf("  +----------------------------------+\n");
    printf("  |      LaxOS Shell v2.0            |\n");
    printf("  |  Escribe 'ayuda' para comandos   |\n");
    printf("  +----------------------------------+\n\n");

    while (1) {
        printf("  LaxOS> ");
        scanf("%s", cmd);

        if      (strcmp(cmd, "ayuda")    == 0) shell_ayuda();
        else if (strcmp(cmd, "info")     == 0) shell_info();
        else if (strcmp(cmd, "hora")     == 0) shell_hora();
        else if (strcmp(cmd, "procesos") == 0) mostrar_procesos();
        else if (strcmp(cmd, "memoria")  == 0) gestionar_memoria();
        else if (strcmp(cmd, "leer")     == 0) laxos_leer("laxos.cfg");
        else if (strcmp(cmd, "guardar")  == 0) shell_guardar();
        else if (strcmp(cmd, "limpiar")  == 0) system("cls");
        else if (strcmp(cmd, "arch")     == 0) {
            printf("\n  Arquitectura: %s (%d bit)\n\n", ARCH_NAME, ARCH_BITS);
        }
        else if (strcmp(cmd, "salir")    == 0) {
            printf("\n  Volviendo al menu...\n\n");
            break;
        }
        else printf("\n  Comando no reconocido: %s\n\n", cmd);
    }
}