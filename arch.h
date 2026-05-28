// arch.h - Soporte multi-arquitectura de LaxOS
#ifndef ARCH_H
#define ARCH_H

// Detecta automaticamente la arquitectura
#if defined(__aarch64__) || defined(__arm__)
    #define ARCH_NAME    "ARM Cortex-A78C"
    #define ARCH_BITS    64
    #define ARCH_TYPE    "ARM"

#elif defined(__x86_64__)
    #define ARCH_NAME    "x86_64"
    #define ARCH_BITS    64
    #define ARCH_TYPE    "x64"

#elif defined(__i386__)
    #define ARCH_NAME    "x86"
    #define ARCH_BITS    32
    #define ARCH_TYPE    "x86"

#else
    #define ARCH_NAME    "Desconocida"
    #define ARCH_BITS    0
    #define ARCH_TYPE    "UNKNOWN"
#endif

#endif