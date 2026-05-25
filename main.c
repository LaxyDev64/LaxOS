// LaxOS - Kernel v0.5       
#include <stdio.h>
#include <string.h> 

#define LAXOS_VERSION   "0.6"   
#define LAXOS_RAM_MB    12288
#define LAXOS_CPU_CORES 8

void mostrar_bienvenida() {
    printf("Bienvenido a LaxOS v%s!\n", LAXOS_VERSION);
}
void mostrar_nombre() {
    printf("Sistema: LaxOS\n");
}
void mostrar_hardware() {
    int cores = LAXOS_CPU_CORES;
    int ram   = LAXOS_RAM_MB;
    printf("CPU: %d nucleos ARM\n", cores);
    printf("RAM: %d MB\n", ram);
}


void verificar_sistema() {
    int ram = LAXOS_RAM_MB;
    int cores = LAXOS_CPU_CORES;

    printf("=================================\n");
    printf("Verificando sistema...\n");

    if (ram >= 8192) {
        printf("RAM: OK (%d MB detectados)\n", ram);
    } else {
        printf("RAM: ERROR - memoria insuficiente\n");
    }

    if (cores >= 4) {
        printf("CPU: OK (%d nucleos detectados)\n", cores);
    } else {
        printf("CPU: ADVERTENCIA - pocos nucleos\n");
    }
    
    if (strcmp(LAXOS_VERSION, "0.6") == 0) {
        printf("Version: OK\n");
    } else {
        printf("Version: desactualizada\n");
    }
}
void escanear_nucleos() {
    printf("=================================\n");
    printf("Escaneando nucleos CPU...\n");

    for (int i = 1; i <= LAXOS_CPU_CORES; i++) {
        printf("Nucleo %d: OK\n", i);
    }

    printf("Todos los nucleos listos\n");

    
}

void escanear_memoria() {
    int bloque = 1024;
    int total  = LAXOS_RAM_MB / bloque;

    printf("Escaneando memoria...\n");
    for (int i = 1; i <= total; i++) {
          printf("Bloque %d: %d MB OK\n", i, bloque);
        
    }
}

void gestionar_memoria() {
    int ram_total = LAXOS_RAM_MB;
    int* ptr_ram  = &ram_total;

    printf("=================================\n");
    printf("Gestor de memoria LaxOS\n");
    printf("Valor RAM: %d MB\n", ram_total);
    printf("Direccion en memoria: %p\n", ptr_ram);
    printf("Valor via puntero: %d MB\n", *ptr_ram);

    *ptr_ram = *ptr_ram - 512;
    printf("RAM disponible para juegos: %d MB\n", ram_total);

    int cores_total = LAXOS_CPU_CORES;
    int* ptr_cores  = &cores_total;
    *ptr_cores = *ptr_cores - 2;
    printf("Nucleos para juegos: %d\n", cores_total);
    printf("=================================\n");
}

void laxos_init() {
    printf("=================================\n");
    mostrar_bienvenida();
    mostrar_nombre();
    mostrar_hardware();
    verificar_sistema();
    escanear_nucleos();    
    escanear_memoria(); 
    gestionar_memoria();   
    printf("Estado: Sistema listo\n");
    printf("=================================\n");
}


int main() {
    laxos_init();
    while (1) {}
    return 0;
}