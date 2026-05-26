// memory.c - Gestión de memoria de LaxOS
#include "kernel.h"

void gestionar_memoria() {
    int ram_total   = LAXOS_RAM_MB;
    int* ptr_ram    = &ram_total;
    int cores_total = LAXOS_CPU_CORES;
    int* ptr_cores  = &cores_total;

    printf("=================================\n");
    printf("Gestor de memoria LaxOS\n");
    printf("Direccion en memoria: %p\n", ptr_ram);
    *ptr_ram   = *ptr_ram - 512;
    *ptr_cores = *ptr_cores - 2;
    printf("RAM para juegos: %d MB\n", ram_total);
    printf("Nucleos para juegos: %d\n", cores_total);
    printf("=================================\n");
}