# Problema del Productor-Consumidor con un Buffer Limitado 

## Objetivo:
Los estudiantes trabajarán juntos para entender y escribir fragmentos de código a mano para el problema del productor-consumidor en C, utilizando solo semáforos. Esta actividad se enfocará en usar semáforos binarios como mutex para sincronizar el acceso a recursos compartidos.

## Estructura de la Actividad:

1. **Formación de Grupos**:
   - Grupos de 4-5 estudiantes, con roles asignados: Coordinador, Escriba, Presentador, Analista de Código e Investigador.

2. **Preparación**:
   - Revisar conceptos de multiprocesamiento y uso de semáforos en C antes de la sesión.

3. **Pasos de la Actividad**:

   **Paso 1: Discusión del Problema (15 minutos)**
   - Discutir el problema del productor-consumidor:
     - Por qué es necesario sincronizar el acceso a recursos compartidos.
     - El papel de los semáforos para resolver el problema.

   **Paso 2: Escritura Colaborativa de Código (30 minutos)**
   - Cada estudiante escribe una sección del código a mano. El Coordinador se asegura de que haya progreso y consistencia.
   - Secciones del código:
     - Variables globales y recursos compartidos.
     - Inicialización de semáforos y plantillas de funciones de hilos.
     - Plantilla del main para crear hilos. Modifique para que desde consola se pueda especificarse el tamaño del buffer y el número de hilos productores y el número de hilos consumidores.

**Plantilla de Código para la Actividad**:

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

// Template for global or shared variables
typedef struct {
    int buffer[BUFFER_SIZE];
    int in;
    int out;
    sem_t full;           // Semaphore to track filled buffer slots
    sem_t empty;          // Semaphore to track empty buffer slots
    sem_t mutex;          // Binary semaphore acting as a mutex
} BoundedBuffer;

BoundedBuffer buf;

// Template for initialization of semaphores and buffer
void initBuffer() {
    buf.in = 0;
    buf.out = 0;
    sem_init(&buf.full, 0, 0);              // Initially no slots are filled
    sem_init(&buf.empty, 0, BUFFER_SIZE);   // All slots are initially empty
    sem_init(&buf.mutex, 0, 1);             // Binary semaphore initialized to 1 (acts as mutex)
}

// Template for producer runner function
void *producer(void *param) {
    // Implement logic to produce items and use semaphores
    return NULL;
}

// Template for consumer runner function
void *consumer(void *param) {
    // Implement logic to consume items and use semaphores
    return NULL;
}

// Main function template for creating threads
int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize buffer and semaphores
    initBuffer();

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to complete
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Cleanup semaphores
    sem_destroy(&buf.full);
    sem_destroy(&buf.empty);
    sem_destroy(&buf.mutex);

    return 0;
}
```

**Paso 3: Revisión por Pares y Explicación (20 minutos)**
- Intercambiar el código con otro grupo para su revisión. El Analista de Código revisa la lógica y la estructura.
- Los grupos presentan su código, con el Presentador explicando su implementación.

**Paso 4: Discusión General (15 minutos)**
- Discutir los desafíos y soluciones encontrados durante la escritura del código.
- Analizar cómo los semáforos binarios actúan como mutex y su importancia para prevenir condiciones de carrera.

**Preguntas de Cierre**:
- ¿Cuál es el papel de los semáforos para prevenir desbordamientos y vacíos en el buffer?
- ¿Cómo actúa un semáforo binario como mutex?

**Ejercicio Adicional**:
- Reflexionar sobre cómo manejar escenarios en los que el hilo del productor o consumidor es interrumpido. Escribir ideas en papel sobre cómo manejar tales situaciones usando semáforos.

**Resultado Esperado**:
Los estudiantes obtendrán experiencia práctica en el diseño de soluciones de sincronización usando solo semáforos. Esto reforzará su comprensión de las operaciones con semáforos y la sincronización en C.

