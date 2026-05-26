// ui.c - Interfaz de usuario de LaxOS
#include "kernel.h"

void laxos_ui_header() {
    printf("\n");
    printf("  ██╗      █████╗ ██╗  ██╗ ██████╗ ███████╗\n");
    printf("  ██║     ██╔══██╗╚██╗██╔╝██╔═══██╗██╔════╝\n");
    printf("  ██║     ███████║ ╚███╔╝ ██║   ██║███████╗\n");
    printf("  ██║     ██╔══██║ ██╔██╗ ██║   ██║╚════██║\n");
    printf("  ███████╗██║  ██║██╔╝ ██╗╚██████╔╝███████║\n");
    printf("  ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝\n");
    printf("              v%s — ARM 64bit\n\n", LAXOS_VERSION);
}

void laxos_ui_menu() {
    int opcion;

    laxos_ui_header();

    printf("  ╔═══════════════════════════╗\n");
    printf("  ║      MENU PRINCIPAL       ║\n");
    printf("  ╠═══════════════════════════╣\n");
    printf("  ║  1. Juegos                ║\n");
    printf("  ║  2. Configuracion         ║\n");
    printf("  ║  3. Sistema               ║\n");
    printf("  ║  4. Shell                 ║\n");
    printf("  ║  5. Apagar                ║\n");
    printf("  ╚═══════════════════════════╝\n");
    printf("\n  Selecciona una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("\n  >> Juegos: proximamente...\n");
            laxos_ui_menu();
            break;
        case 2:
            printf("\n  >> Configuracion:\n");
            laxos_leer("laxos.cfg");
            laxos_ui_menu();
            break;
        case 3:
            printf("\n  >> Sistema:\n");
            printf("  LaxOS v%s\n", LAXOS_VERSION);
            printf("  CPU: %d nucleos ARM\n", LAXOS_CPU_CORES);
            printf("  RAM: %d MB\n", LAXOS_RAM_MB);
            laxos_ui_menu();
            break;
        case 4:
            laxos_shell();
            laxos_ui_menu();
            break;
        case 5:
            printf("\n  Apagando LaxOS...\n");
            break;
        default:
            printf("\n  Opcion no valida\n");
            laxos_ui_menu();
    }
}