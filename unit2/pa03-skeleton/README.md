# pa3: Binary Files and Processing Image

## Objetivos:
En esta tarea de programación aprederá:
- Leer / escribir archivos binarios 
- Mapas de bits 
- Procesamiento básico de imágenes 
- Programación multihilos básica 

## Preliminar
### Leer y escribir archivos binarios

A diferencia de los archivos de texto, en un archivo binario, un número no se representará como su representación de caracteres ASCII, sino como la secuencia de bits que representa ese número. El número 17 ocupa dos caracteres en un archivo ASCII, pero podemos representar el número 17 en un solo byte en un archivo binario, con los bits: 00010001. Para leer los datos binarios que contiene el número 17, usaríamos el siguiente código:
~~~
uint8_t x;
fread(&x, 1, 1, bin_in);
~~~
Que se lee en un fragmento de datos de 1 byte en la variable x( uint8_tes un tipo que significa "entero sin signo que ocupa 8 bits").

De manera similar, para escribir 27en un archivo ASCII, usaríamos el siguiente código:

uint8_t x = 27;
fprintf(ascii_out, "%d", x);
Lo que escribiría dos caracteres en el archivo de salida. Para escribir los datos sin procesar, haríamos:

uint8_t x = 27;
fwrite(&x, 1, 1, bin_out);
Lo que escribiría 1 byte (con el valor 00011011) en el archivo de salida.

## Lo que tiene que hacer 

## Pruebas

## Entregable
