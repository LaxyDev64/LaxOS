// filesystem.c - Sistema de archivos de LaxOS
#include "kernel.h"
#include <stdio.h>

void laxos_escribir(char* nombre, char* contenido) {
    FILE* archivo = fopen(nombre, "w");

    if (archivo == NULL) {
        printf("ERROR: No se pudo crear %s\n", nombre);
        return;
    }

    fprintf(archivo, "%s", contenido);
    fclose(archivo);
    printf("Archivo guardado: %s\n", nombre);
}

void laxos_leer(char* nombre) {
    char linea[256];
    FILE* archivo = fopen(nombre, "r");

    if (archivo == NULL) {
        printf("ERROR: No se encontro %s\n", nombre);
        return;
    }

    printf("Contenido de %s:\n", nombre);
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea);
    }

    fclose(archivo);
}

void laxos_filesystem_init() {
    printf("=================================\n");
    printf("Sistema de archivos LaxOS\n");

    // Crea archivo de configuracion del sistema
    laxos_escribir("laxos.cfg",
        "version=0.8\n"
        "ram=12288\n"
        "cores=8\n"
        "modo=consola\n"
    );

    // Lee el archivo recien creado
    laxos_leer("laxos.cfg");
    printf("=================================\n");
}