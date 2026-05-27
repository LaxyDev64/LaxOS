// ui.c - Interfaz de usuario de LaxOS
#include "kernel.h"
#include <time.h>

void laxos_ui_clock() {
    time_t t = time(NULL);
    struct tm* tm_info = localtime(&t);
    printf("  Hora: %02d:%02d  |  LaxOS v%s\n",
        tm_info->tm_hour,
        tm_info->tm_min,
        LAXOS_VERSION);
}

void laxos_ui_header() {
    printf("\n");
    printf("  +------------------------------------------+\n");
    laxos_ui_clock();
    printf("  |         ARM 64bit - Consola              |\n");
    printf("  +------------------------------------------+\n");
}

void laxos_ui_juegos() {
    printf("\n");
    printf("  +-----------+  +-----------+  +-----------+  +-----------+\n");
    printf("  |           |  |           |  |           |  |           |\n");
    printf("  |   SONIC   |  |  PAC-MAN  |  |  RAYMAN   |  |   DOOM    |\n");
    printf("  |           |  |           |  |           |  |           |\n");
    printf("  +-----------+  +-----------+  +-----------+  +-----------+\n");
    printf("\n");
    printf("  > SONIC FRONTIERS SELECCIONADO\n");
    printf("\n");
}

void laxos_ui_barra() {
    printf("  +--------+--------+--------+--------+--------+--------+\n");
    printf("  | Juegos | Tienda | Albumes | Config | Ajuste | Apagar |\n");
    printf("  +--------+--------+--------+--------+--------+--------+\n");
}

void laxos_ui_menu() {
    int opcion;

    laxos_ui_header();
    laxos_ui_juegos();
    laxos_ui_barra();

    printf("\n  Selecciona: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\n  >> Juegos: Sonic | Pac-Man | Rayman | DOOM\n");
            laxos_ui_menu();
            break;
        case 2:
            printf("\n  >> Tienda: proximamente...\n");
            laxos_ui_menu();
            break;
        case 3:
            printf("\n  >> Albumes: proximamente...\n");
            laxos_ui_menu();
            break;
        case 4:
            laxos_leer("laxos.cfg");
            laxos_ui_menu();
            break;
        case 5:
            printf("\n  >> Sistema:\n");
            printf("  LaxOS v%s\n", LAXOS_VERSION);
            printf("  CPU: %d nucleos ARM\n", LAXOS_CPU_CORES);
            printf("  RAM: %d MB\n", LAXOS_RAM_MB);
            laxos_ui_menu();
            break;
        case 6:
            printf("\n  Apagando LaxOS...\n");
            printf("  Hasta luego!\n\n");
            break;
        default:
            printf("\n  Opcion no valida\n");
            laxos_ui_menu();
    }
}