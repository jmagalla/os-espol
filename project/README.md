# pa4: Synchronize Process 

## Objetivos

En esta tarea de programación usted aprenderá: 

* Diseñar un sistema que utilice el enfoque de comunicación entre procesos para un problema computacional (IPC)
* Aplicar los mecanismos de IPC en un problema real
* Aplicar las técnicas de sincronización para acceder a recursos compartidos

## Descripción del Problema 

Una compañía de servicios de taxis necesita una nueva estrategía diferenciadora entre sus competidores. Para esto, se decide reorganizar la logística de su flota de taxis, de manera que sus taxis lleguen en menor tiempo que los de la competencia. 

Para conseguirlo, se prentende tener taxis esperando en "sitios estratégicos”; definir estos sitios es la problemática que se debe resolver. 

Considere representar a los sitios de la ciudad mediante un conjunto de intersecciones (cruce de calles). Las distancias entre las intersecciones se representan mediante un grafo, donde cada nodo es una intersección y cada arista es un camino o calle bidireccional que une dos interseccciones. Como muestra la figura 1, las intersecciones 0, 1, 2, 3, y 4, y las distancias entre ellas, por ejemplo, la distancia entre la intersección 1 y 3 es 4, entre 0 y 3 es 7, etc. 

![alt text](https://github.com/jmagalla/os-espol/blob/master/project/GrafoBidirec-img.png?raw=true)

La Tabla 1, muestra la matriz cuadrada simétrica, con la diagonal principal en CERO y que representa al grafo antes descrito. 

|-|0|1|2|3|4|
|-|-|-|-|-|-|
|0|0|3|0|7|8|
|1|3|0|1|4|0|
|2|0|1|0|2|0|
|3|7|4|2|0|3|
|4|8|0|0|3|0|

Table: Tabla 1

De acuerdo a lo anterior, considere un sitio estratégico como aquella intersección que aparece más en las rutas de viaje para llegar de una intersección a otra. Considere también, que una ruta de viaje es el camino de menor costo de una intersección a otra. 

## Lo que tiene que hacer

Su trabajo es: 

1. Escriba un programa servidor `Graph_Server.c`, que cargue el grafo a partir de un archivo delimitado por comas .CSV, y lo alamacene en memoria compartida. 

2. Además, el programa servidor deberá permitir cambiar el valor de la distancia entre intersecciones por parte del usuario y actualizar el grafo compartido. 

3. Escriba un programa cliente Result-Client.c que luego de cargado el grafo, en la región de memoria compartida, o luego de hacer un cambio en las distancias, calcule los n sitios estratégicos en el menor tiempo posible. De manera que, deberá construir una versión paralela para obtener todas las rutas de viajes y así obtener las n intersecciones que más aparezcan en esas rutas.

Para encontrar el camino más corto entre una intersección y otra use el algoritmo de disjktra incluido en este repositorio. 

Como recomendaciones finales, antes de escribir una línea de código aterrice su diseño en un documento. En este diseño incluya las técnicas que hemos revisado, shared memory, exclusión mutua, syncronización entre procesos y programación multihilos. 

## Entregables
Documento .zip que debe incluir: (1) los fuentes, Grpah_Server.c ,Result-Client.c, y otros (2) el archivo Makefile que incluya las instrucciones de compilación y construcción, y (3) documento de texto en formato PDF, llamado ###-reporte-pa4.PDF, que describa a manera de reporte: - la problemática a resolver, - el diseño de la solución (con alguna herramienta que haya usado en cursos anteriores, como de ing. de software o de diseño de software)- las limitaciones que tuvieron y cómo las resolvieron, y - la descripción de las pruebas realizadas con sus salidas de pantalla. Las pruebas que incluyan deben tener el objetivo de verificar que su programa funcione correctamente. 

En el nombre del archivo ###-reporte-pa4.PDF debe reemplazar ### por su apellido-nombre. 

Nota: **No comprima la carpeta en donde están todos los archivos**, sino que se requiere que a partir de la selección de archivos se cree el ZIP. Si no sigue esta especificación será penalizado. 

Nota: **No debe usar el código desde fuentes de internet que resuelve este assigment**, ya que su código será pasado por software antiplagio que verifica la similitud con otras fuentes. No se arriesgue a ser sancionado por actos de deshonestidad académica. Resuelva el assigment por sus propios medios. 
