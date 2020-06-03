## Programa de Ejemplo para el deber de programación 1

Este programa lee el archivo que recibe como parámetro y muestra su contenido en pantalla, si no recibe un parámetro lee a partir de la entrada estándar. Muy similar al comando cat de linux

## Compilación

Para crear el programa ejecutable:

```bash
make clean
make
```

## Uso

Uso 1: 

```bash
./build/mycat names.data
```

Uso 2: 

```bash
sort names.data | ./build/mycat
``` 

