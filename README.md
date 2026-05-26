<img width="146" height="124" alt="LaxOS" src="https://github.com/user-attachments/assets/9e10864c-f70a-42d3-9761-af153c27543f" />


# LaxOS

> Sistema operativo para consola inspirado en Nintendo Switch, desarrollado desde cero en C para arquitectura ARM.

---

## Estado del proyecto

| Módulo | Progreso |
|--------|----------|
| — Kernel base | [██████████] 100% |
| — Gestión de memoria | [██████░░░░]  60% |
| — Gestión de procesos | [████░░░░░░]  40% |
| — Shell básica | [██████████] 100% |
| — Sistema de archivos | [██████████] 100% |
| — Interfaz de usuario | [          ]    0% |                                                                                                                         
---

##  Especificaciones objetivo

| Componente | Detalle |
|-----------|---------|
| CPU | 8 núcleos ARM Cortex-A78C |
| RAM | 12288 MB LPDDR5X |
| Arquitectura | ARM 64-bit |
| Lenguaje | C |

---

## Cómo compilar

```bash
gcc main.c kernel.c memory.c process.c shell.c filesystem.c ui.c -o laxos && ./laxos
```

---

## Versiones

| Versión | Descripción |
|---------|-------------|
| v0.8 | coming soon |
| v0.7.2 | sistema de archivos añadidos |
| v0.7.1 | shell añadido |
| v0.7 | LaxOS ahora tiene una tabla de procesos real yey :) |
| v0.6 | Gestión de memoria con punteros |
| v0.5 | Escaneo de CPU y RAM |
| v0.4 | Verificación de hardware |
| v0.3 | Funciones base |
| v0.1 | Primer arranque 
---

## Creado y Desarrollado por LaxyDev64 and LaxStudios
LaxStudio It's an indie studio created by LaxyDev64; studio Discord coming soon.
Don't confuse it with anything else :)
