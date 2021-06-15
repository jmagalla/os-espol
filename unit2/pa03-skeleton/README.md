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

El canal alfa determina la transparencia de un píxel (0 significa transparente, 255 significa opaco). Debido a que cada píxel contiene valores para cada uno de estos cuatro canales, un BMP usa una sola palabra (4 bytes) para almacenar el color de cada píxel. (¡Tenga en cuenta la ventaja de un formato binario aquí! Si almacenamos las representaciones ASCII de los canales de cada píxel, es posible que necesitemos hasta 12 bytes para almacenar los valores de un solo píxel)

> Tenga en cuenta que el canal alfa no se usa realmente en mapas de bits (y muchos mapas de bits solo usan los canales R, G y B), pero nuestros mapas de bits están codificados como BMP de 32 bits, por lo que usan un canal alfa que siempre se establece en 255.


Los mapas de bits almacenan el contenido de una imagen como una gran matriz de píxeles (32 bits): cada fila de píxeles se almacena de forma contigua en el archivo. Las filas de píxeles se pueden almacenar de arriba hacia abajo o de abajo hacia arriba (ver más abajo). Entonces, ¿cómo sabemos cuántas filas de píxeles tenemos? o ¿cuántos píxeles hay en cada fila? Se usa el encabezado del mapa de bits . Un BMP incluye información al principio del archivo que describe el resto del archivo. Este encabezado también se almacena en formato binario y ocupa 54 bytes. Los detalles de lo que hay en el encabezado se incluyen en `bmp.h`, ver la estructura `BMP_Header` linea 33.

El orden de los campos en la estructura corresponde al orden de los datos en el encabezado del archivo.

Hay muchos datos aquí, pero los campos importantes son:
- `size`: el tamaño del archivo en bytes. Debe ser 54 + ancho * alto.
- `width_px`: cuántos píxeles de ancho tiene la imagen. Esta es la cantidad de píxeles que hay en cada "fila" de la imagen.
- `height_px`: cuántos píxeles de alto tiene la imagen. Esta es la cantidad de filas de píxeles. **Tenga en cuenta algo importante**. Este número puede ser negativo. Si el número es negativo, no significa que la imagen tenga una altura negativa. Significa que las filas se almacenan de arriba a abajo en el archivo. Un número positivo significa que se almacenan de abajo hacia arriba.
- `bits_per_pixel`: para nuestras imágenes, será 32.

Una vez que haya leído el encabezado, sabrá cuántos píxeles hay en la imagen y puede leerlos en una matriz bidimensional. La estructura para contener una imagen general está en bmp.h:

```c
typedef struct __attribute__((packed)) BMP_Image {
    BMP_Header header;
    int data_size;
    int width;
    int height;
    int bytes_per_pixel; // This amount should be equals to number of bits/8
    Pixel ** pixels;
} BMP_Image;
```

(Tenga en cuenta que norm_heightcontiene la altura de la imagen en píxeles. Almacenamos esto por separado height_pxporque este último puede ser negativo. norm_heightSiempre debe ser positivo).

La Pixelestructura de datos es:

typedef struct __attribute__((packed)) Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
} Pixel;
Tenga en cuenta que el orden en que se definen los campos en esta estructura coincide con el orden en que existen en el archivo (por lo que si un píxel ocupa 4 bytes en el archivo, el primer byte es el valor del canal azul, el segundo es el valor del verde, etc.).

> Tenga en cuenta que el orden de los canales aquí se lee como "BGRA", que parece invertido del orden al que estamos acostumbrados (alfa + RGB). Esto se debe a que los BMP son un formato little-endian: lo que normalmente escribiríamos como primer byte es en realidad el último byte de la palabra de 4 bytes.

### Procesamiento básico de imágenes
Una de las tareas más básicas de manipulación de imágenes es filtrar una imagen: aplicarle una transformación para desenfocar la imagen, enfocar la imagen, etc. Resulta que existe un marco general para manipular imágenes que puede desenfocar o enfocar imágenes, o detectar bordes, usando la misma estrategia. La idea es realizar una convolución utilizando un filtro de caja . Para entender lo que esto significa, pensemos en cómo podemos difuminar una imagen.

Consideremos que nuestra imagen es una gran cuadrícula de píxeles. Para difuminar una imagen, una cosa que podríamos hacer es "difuminar" los colores a través de la imagen: mezclar los colores de cada píxel con los colores de sus vecinos. Podemos hacer esto de una manera general usando un filtro de caja, que se parece a una cuadrícula de 3 por 3 en sí misma:

    1 1 1
    1 1 1
    1 1 1

Si superponemos el centro del filtro de caja en la parte superior de un solo píxel de destino, entonces los píxeles circundantes se ubican "encima" de los píxeles vecinos del destino. Para aplicar un filtro de caja, tomamos cada canal, multiplicamos los valores en cada celda del filtro de caja por el valor del canal del píxel sobre el que se encuentran y los sumamos (en este caso, por ejemplo, multiplicamos cada de los canales rojos por 1 y súmelos juntos, sumando efectivamente los canales rojos del píxel de destino y los ocho de sus vecinos, y repita para cada uno de los otros tres canales). Luego normalizamos los valores del canal dividiéndolos por un factor de normalización especificado para el filtro en particular. En este caso, el factor de normalización es 9.0. Esto nos da los nuevos valores de canal para el píxel de destino.

Por ejemplo, si los valores del canal rojo para el píxel de destino y sus vecinos son:

    201 191 210
    293 100 102
    200  75  50

El canal rojo de salida para el píxel de destino será 158.

Si hacemos esto para cada canal y cada píxel de la imagen, podemos generar los nuevos valores en una nueva imagen para crear una versión borrosa de la imagen.

## Lo que tiene que hacer 

## Pruebas

## Entregable
