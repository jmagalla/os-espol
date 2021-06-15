# pa3: Binary Files and Processing Image

## Objetivos:
En esta tarea de programación aprederá:
- Leer / escribir archivos binarios 
- Mapas de bits 
- Procesamiento básico de imágenes 
- Programación multihilos básica 

## Preliminar
### Leer y escribir archivos binarios

A diferencia de los archivos de texto, en un archivo binario, un número no se representará como su representación de caracteres ASCII, sino como la secuencia de bits que representa ese número. El número 17 ocupa dos caracteres en un archivo ASCII, pero podemos representar el número 17 en un solo byte en un archivo binario, con los bits: `00010001`. Para leer los datos binarios que contiene el número 17, usaríamos el siguiente código:
~~~c
uint8_t x;
fread(&x, 1, 1, bin_in);
~~~
El cual lee un fragmento de datos de 1 byte en la variable `x` ( `uint8_t` es un tipo que significa "entero sin signo que ocupa 8 bits").

De manera similar, para escribir 27 en un binario sin procesar, usaríamos el siguiente código:
~~~c
uint8_t x = 27;
fwrite(&x, 1, 1, bin_out);
~~~
Lo que escribiría 1 byte (con el valor `00011011`) en el archivo de salida.

### Mapas de bits
El formato de archivo de mapa de bits (BMP) es uno de los formatos de imagen más simples. Almacena datos de imágenes píxel a píxel. Para un píxel dado, un mapa de bits almacena 4 valores ( channels): el canal rojo, el canal azul, el canal verde y el canal alfa. El rojo, el azul y el verde se explican por sí mismos: determinan la intensidad de los valores de rojo / azul / verde de un píxel dado en su pantalla. Estos números pueden oscilar entre 0 (el canal no existe en el píxel) y 255 (intensidad máxima). Los valores RGB se combinan de diferentes formas para producir colores:

- (255, 255, 255): la intensidad máxima en todos los canales es blanca
- (0, 0, 0): la intensidad cero en todos los canales es negra
- (255, 0, 0): rojo puro
- (0, 255, 0): verde puro
- (0, 0, 255): azul puro
- (255, 255, 0): amarillo
- (255, 0, 255): Magenta
- (0, 255, 255): cian

El canal alfa determina la transparencia de un píxel (0 significa transparente, 255 significa opaco). Debido a que cada píxel contiene valores para cada uno de estos cuatro canales, un BMP usa una sola palabra (4 bytes) para almacenar el color de cada píxel. (¡Tenga en cuenta la ventaja de un formato binario aquí! Si almacenamos las representaciones ASCII de los canales de cada píxel, es posible que necesitemos hasta 12 bytes para almacenar los valores de un solo píxel).

---
**Nota:** 
Tenga en cuenta que el canal alfa no se usa realmente en mapas de bits (y muchos mapas de bits solo usan los canales R, G y B), pero nuestros mapas de bits están codificados como BMP de 32 bits, por lo que usan un canal alfa que siempre se establece en 255.
---
Los mapas de bits almacenan el contenido de una imagen como una gran matriz de píxeles (32 bits): cada fila de píxeles se almacena de forma contigua en el archivo. Las filas de píxeles se pueden almacenar de arriba hacia abajo o de abajo hacia arriba (ver más abajo). Entonces, ¿cómo sabemos cuántas filas de píxeles tenemos? o ¿cuántos píxeles hay en cada fila? Usamos el encabezado del mapa de bits . Un BMP incluye información al principio del archivo que describe el resto del archivo. Este encabezado también se almacena en formato binario y ocupa 54 bytes. Los detalles de lo que hay en el encabezado se incluyen en bmp.h:

## Lo que tiene que hacer 

## Pruebas

## Entregable
