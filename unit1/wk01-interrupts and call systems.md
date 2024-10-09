# Actividad: Interrupciones y Llamadas al Sistema

## Objetivo
Los estudiantes aprenderán los conceptos de interrupciones y llamadas al sistema, su relación con el hardware y software, y cómo un sistema operativo las maneja para interactuar con los recursos del sistema.

## Parte 1: Conceptos Teóricos

1. **Interrupciones:**
   - Define qué es una interrupción.
   - Explica los tipos de interrupciones: de hardware y software.
   - Describe cómo el sistema operativo maneja una interrupción (mecanismo de atención a interrupciones).
   - Ejemplo: Interrupción de reloj (timer) para gestionar el cambio de procesos.

2. **Llamadas al Sistema (System Calls):**
   - Define qué es una llamada al sistema.
   - Explica su rol como interfaz entre las aplicaciones de usuario y el núcleo del sistema operativo.
   - Presenta los pasos que sigue un proceso cuando realiza una llamada al sistema.
   - Ejemplo: `read()` y `write()` en UNIX/Linux para operaciones de E/S.

## Parte 2: Ejemplo Práctico

1. **Simulación de una interrupción de teclado (hardware):**
   - Los estudiantes deben simular el flujo de cómo una interrupción de teclado pasa del hardware al sistema operativo. Detalla las siguientes etapas:
     - La CPU recibe una señal de interrupción del teclado.
     - Se guarda el contexto del proceso actual.
     - Se llama al manejador de interrupciones del teclado.
     - Se procesa la entrada y el control vuelve al proceso original.
  
   Pregunta para los estudiantes:
   - Describe los pasos que realiza el sistema operativo al recibir una interrupción de teclado.

2. **Ejecución de una llamada al sistema:**
   - Realiza un ejemplo con código que invoque una llamada al sistema. Para esto, en un entorno de Linux o simulador:
   ```c
   #include <unistd.h>
   #include <stdio.h>

   int main() {
       char buffer[100];
       ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
       if (bytesRead > 0) {
           buffer[bytesRead] = '\0';  // Aseguramos que sea una cadena válida
           printf("Leíste: %s\n", buffer);
       }
       return 0;
   }
   ```

   Pregunta para los estudiantes:
   - Describe qué sucede desde que el proceso ejecuta la llamada `read()` hasta que se completa la lectura del teclado y el proceso recibe la entrada.

**Parte 3: Reflexión**

- ¿Qué diferencias observas entre una interrupción de hardware y una llamada al sistema en términos de su origen y cómo las maneja el sistema operativo?
- Investiga cómo las interrupciones son usadas en sistemas embebidos y compara su manejo con los sistemas operativos generales.

---

Esta actividad ayuda a los estudiantes a comprender el flujo del control entre el hardware, el sistema operativo, y las aplicaciones.