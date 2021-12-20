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

![alt Figura 1](https://github.com/jmagalla/os-espol/blob/master/project/GrafoBidirec-img.png)

La Tabla 1, muestra la matriz cuadrada simétrica, con la diagonal principal en CERO y que representa al grafo antes descrito. 

|-|0|1|2|3|4|
|-|-|-|-|-|-|
|0|0|3|0|7|8|
|1|3|0|1|4|0|
|2|0|1|0|2|0|
|3|7|4|2|0|3|
|4|8|0|0|3|0|

Table: Tabla 1

1) En el menor tiempo posible determinar los 3 mejores puntos de espera. Un punto de espera es aquel que aparece en como parte de la ruta de multiples viajes

2) Recalcule automaticamente los 3 puntos si hay un cambio en las distancias entre intersecciones o una interseccion deja de estar habilitada por ejemplo por reparaciones en la via.

Entonces su sistema debe de tener al menos dos componentes: (a) Un programa que cargue el grafo y permita cambiar sus valores y (b) Un programa que calcule y muestre los 3 puntos de espera al inicio y si el grafo cambia. Las acciones de a y b deben realizarse sin tener que reinicar ningun componente de su sistema.

