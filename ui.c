// ui.c - Interfaz de usuario de LaxOS
#include "kernel.h"
#include <time.h>
#include <stdlib.h>

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

    while (1) {
        system("cls");
        laxos_ui_header();
        laxos_ui_juegos();
        laxos_ui_barra();
   char cmd[20];
    printf("\n  Selecciona: ");
    fflush(stdout);
    scanf("%s", cmd);

    if      (strcmp(cmd,"1")==0 || strcmp(cmd,"juegos")==0)  opcion = 1;
    else if (strcmp(cmd,"2")==0 || strcmp(cmd,"tienda")==0)  opcion = 2;
    else if (strcmp(cmd,"3")==0 || strcmp(cmd,"albumes")==0) opcion = 3;
    else if (strcmp(cmd,"4")==0 || strcmp(cmd,"config")==0)  opcion = 4;
    else if (strcmp(cmd,"5")==0 || strcmp(cmd,"ajuste")==0)  opcion = 5;
    else if (strcmp(cmd,"6")==0 || strcmp(cmd,"apagar")==0)  opcion = 6;
    else opcion = -1;
    
        switch (opcion) {
            case 1:
                printf("\n  >> Juegos: Sonic | Pac-Man | Rayman | DOOM\n");
                break;
            case 2:
                printf("\n  >> Tienda: proximamente...\n");
                break;
            case 3:
                printf("\n  >> Albumes: proximamente...\n");
                break;
            case 4:
                laxos_leer("laxos.cfg");
                break;
            case 5:
                printf("\n  >> Sistema: LaxOS v%s | %d nucleos | %d MB\n",
                    LAXOS_VERSION, LAXOS_CPU_CORES, LAXOS_RAM_MB);
                break;
            case 6:
                printf("\n  Apagando LaxOS...\n\n");
                return;
            default:
                printf("\n  Opcion no valida\n");
        }

        printf("\n  Presiona Enter para continuar...");
        getchar(); getchar();
    }
}