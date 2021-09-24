# Comando trace para depuración de programas

Es una herramienta de línea de comandos útil para diagnosticar, dar instrucciones y ejecutar tarea de depuración. 

Los administradores del sistema encontramos en `strace` una herramienta práctica para resolver problemas con programas para los cuales la fuente no está disponible ya que no necesitan ser recompilados para rastrearlos.

La herramienta `strace` captura y registra todas las llamadas al sistema realizadas por un proceso y las señales recibidas por el proceso, `strace` se encarga de mostrar el nombre de cada llamada al sistema junto con sus argumentos entre paréntesis y su valor de retorno a error estándar, opcionalmente, será posible redirigirlo a un archivo.

## Uso de strace
Para instalar strace debemos ejecutar alguno de los siguientes comandos en sistemas debian:

``` 
sudo apt install strace
```

Las llamadas al sistema se pueden categorizar en diferentes eventos: los relacionados con la administración de procesos, los que toman un archivo como argumento, los que involucran redes, asignación de memoria, señales, IPC y también llamadas al sistema relacionadas con descriptores de archivos.

Para rastrear todas las llamadas al sistema realizadas por el comando `cat`, ejecutamos lo siguiente:

```
strace cat names.data
```
En este resultado, podemos ver varios tipos de llamadas al sistema, por ejemplo, una de ellas es: `openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3`

Donde:
* openat: Es el tipo de llamada al sistema
* Los argumentos de la llamada al sistema: `AT_FDCWD`, `“/etc/ld.so.cache”`, `O_RDONLY|O_CLOEXEC`
* `3`: Es el valor de retorno de la llamada al sistema

## Llamadas al sistema en Assambly

Las llamadas al sistema Linux se llaman exactamente de la misma manera que las llamadas al sistema en DOS:

Se pone el número de llamada del sistema en EAX (aquí estamos tratando con registros de 32 bits), se configura los argumentos para la llamada al sistema en EBX, ECX , etc. y se llama a la interrupción correspondiente (para DOS, 21h ; para Linux, 80h ). El resultado generalmente se devuelve en EAX.

El siguiente es un ejemplo de un programa `Hola Mundo` en Assembly que hace la llamada al sistema `write` para mostrar un mensaje en consola. Fijese en el primer bloque de instrucciones de _start:, ¿cuál es el número de la llamada al sistema?

````assembly
section .data
	hello:     db 'Hello world!',10    ; 'Hello world!' plus a linefeed character
	helloLen:  equ $-hello             ; Length of the 'Hello world!' string
	                                   ; (I'll explain soon)

section .text
	global _start

_start:
	mov eax,4            ; The system call for write (sys_write)
	mov ebx,1            ; File descriptor 1 - standard output
	mov ecx,hello        ; Put the offset of hello in ecx
	mov edx,helloLen     ; helloLen is a constant, so we don't need to say
	                     ;  mov edx,[helloLen] to get it's actual value
	int 80h              ; Call the kernel

	mov eax,1            ; The system call for exit (sys_exit)
	mov ebx,0            ; Exit with return code of 0 (no error)
	int 80h

````
Se provee el codigo anterior en este mismo repositorio.

¿Cómo se averigua cuáles son estas llamadas al sistema, qué hacen y qué argumentos toman? En primer lugar, todas las llamadas al sistema se enumeran en `/usr/include/asm/unistd.h`, junto con sus números (el valor para poner en EAX antes de llamar a int 80h ). Sin embargo, para su conveniencia, simplemente puede encontrarlos en el siguiente enlace.

### Compilación y vinculación
Si no tiene una terminal o consola abierta, abra una ahora.
Asegúrese de estar en el mismo directorio donde guardó hello.asm 

Para ensamblar el programa, escriba 
```
nasm -f elf hello.asm
```
Si hay algún error, NASM le dirá en qué línea hizo qué mal. Si usa una arquitectura de 64 bits use el argumento `elf64` en lugar de `elf64`

Ahora escriba 
```
ld -s -o hello hello.o
```
Esto vinculará el archivo objeto que NASM produjo en un archivo ejecutable. Ejecute su programa escribiendo ./hello

Debería ver ¡Hola mundo! impreso en la pantalla. ¡Felicidades! 

En el repositorio encontrara el programa nanosleep.asm que usa la llamada al sistema nanosleep().

### Tarea

Compilar los dos programas .asm y usar strace para verificar las llamadas al sistema, los argumentos que reciben y sus valores de retorno.

---
**Nota**
 Este no pretende ser una manual de Assembly, para mas informacion ir al siguiente [enlace](https://montcs.bloomu.edu/Information/LowLevel/Assembly/assembly-tutorial.html). 
