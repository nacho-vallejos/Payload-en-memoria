README - Ejemplo de ejecución de shellcode embebido en .rdata

¿Qué es esto?

Este es un ejemplo para que entiendas cómo podés meter un payload (un código binario que hace algo) adentro de la sección `.rdata` de un ejecutable en C y después ejecutarlo en memoria. En este caso, el payload es un shellcode que abre la calculadora de Windows (`calc.exe`).

> **Ojo:** Esto es solo para aprender y probar en ambientes controlados, no lo uses para hacer cagadas ni en producción.

---

¿Qué hace el código?

1. Guarda un shellcode que abre la calculadora en un array que queda en la sección `.rdata` (que es de solo lectura por defecto).
2. Muestra por consola la dirección en memoria donde está ese shellcode.
3. Reserva un pedazo de memoria con permisos para leer, escribir y ejecutar.
4. Copia el shellcode a esa memoria ejecutable.
5. Espera que apretes Enter para no lanzarlo de una.
6. Ejecuta el shellcode, que abre la calculadora.

---

Requisitos

* Compilador para C en Windows (por ejemplo, Visual Studio, MinGW).
* Entorno Windows para correrlo.
* Entender que es solo un ejemplo didáctico.

---

 Cómo usarlo

1. Compilá el código con tu compilador de C preferido.
2. Ejecutá el programa desde la consola.
3. Vas a ver la dirección del shellcode y mensajes de que se reservó la memoria y se copió el payload.
4. Cuando te pida, apretá Enter y se va a abrir la calculadora de Windows.

---

## Advertencias

* No uses este código para nada ilegal o fuera de un entorno seguro.
* Ejecutar shellcodes puede ser peligroso si no entendés qué hace el código.
* Está pensado para aprender conceptos básicos de ejecución dinámica de código.

---

## Para qué sirve esto

* Entender cómo funcionan los payloads y su ejecución en memoria.
* Aprender sobre secciones de un ejecutable y permisos de memoria.
* Base para proyectos de seguridad informática y pentesting.

---

