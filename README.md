<img width="146" height="124" alt="LaxOS" src="https://github.com/user-attachments/assets/9e10864c-f70a-42d3-9761-af153c27543f" />


# LaxOS

> Sistema operativo para consola inspirado en Nintendo Switch, desarrollado desde cero en C para arquitectura ARM y x86_64.

---
## Links
<p align="center">
  <a href="https://discord.gg/6UeZGESd"><img src="https://img.shields.io/discord/1072873391855501312?label=discord&logo=discord&color=5865F2" alt="Discord"/></a>
</p>

---
## Estado del proyecto

| Módulo | Progreso |
|--------|----------|
| — Kernel base | [██████████] 100% |
| — Gestión de memoria | [██████░░░░]  60% |
| — Gestión de procesos | [████░░░░░░]  40% |
| — Shell | [██████████] 100% |
| — Sistema de archivos | [██████████] 100% |
| — Interfaz de usuario (terninal) | [██████████] 100% |   
| — Interfaz interactiva | [█░░░░░░░░░]  01% |
---

##  Especificaciones objetivo

| Componente | Detalle |
|-----------|---------|
| CPU | 8 núcleos ARM Cortex-A78C |
| RAM | 12288 MB LPDDR5X |
| Arquitectura | ARM 64-bit-x86_64|
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
| v0.8.1 | libreria de interfaz + fotos de la interfaz estan listas |
| v0.8 | ¡LaxOS con interfaz completa! |
| v0.7.3 | agregado mas arquitectora para mas consolas/pc |
| v0.7.2 | sistema de archivos añadidos |
| v0.7.1 | shell añadido |
| v0.7 | LaxOS ahora tiene una tabla de procesos real yey :) |
| v0.6 | Gestión de memoria con punteros |
| v0.5 | Escaneo de CPU y RAM |
| v0.4 | Verificación de hardware |
| v0.3 | Funciones base |
| v0.1 | Primer arranque 
---

## Fotos de la interfaz (alpha)
<img width="856" height="512" alt="Captura de pantalla 2026-05-28 001040" src="https://github.com/user-attachments/assets/217e0938-36da-4a07-9e48-0e5785abf7e6" />
<img width="1918" height="1026" alt="Captura de pantalla 2026-05-27 235308" src="https://github.com/user-attachments/assets/2bdfce2f-66e3-4533-ac9d-42a719be1e21" />

---
## Creado y Desarrollado por LaxyDev64 and LaxStudios
LaxStudio It's an indie studio created by LaxyDev64; studio Discord coming soon.
Don't confuse it with anything else :)
