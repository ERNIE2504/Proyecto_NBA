# Proyecto_NBA

Este proyecto toma a los jugadores activos del 2024 de la NBA de los 30 equipos existentes y los va ordenando según el usuario quiera buscar las estadísticas de los jugadores. 
Hay 8 posibilidades de elección: Más puntos anotados, más triples encestados, más tiros libres encestados, más asistencias, más bloqueos, más altos, más anillos ganados y más mvp´s ganados  
> Un ejemplo sería:
>
> Paso 1: seleccionar la opción que se quiere ver
> Paso 2: dar enter y esperar

## Descripción Avance 1:
Se implementó el algoritmo de ordenamiento merge sort que lo ordena de mayor a menor las estadisticas de los jugadores
## Descripción Avance 2:
Se implementó el uso del Árbol AVL, este se caracteriza por estar balanceado, por lo que incluye las rotaciones necesarias para mantener este balance y regresar a los jugadores de manera descendente, esto quiere decir de mayor a menor.
## Descripción Avance 3:
Se agregó la lectura y escritura de datos en un archivo .txt

### Cambios del primer avance:
Se modificó que el programa siga ejecutándose hasta que el usuario quiera salir, en vez de ejecutarlo cada vez que quieras ver algo diferente.
Se agregó funciones para leer y escribir archivos de texto

### Cambios del segundo avance:
Se actualizó el comando para ejecutar el programa y se describió lo solicitado

## Instrucciones para ejecutar el programa:
g++ -std=c++11 mainAlgoritmo.cpp -o app1   (Avance 1) para compilar
./ app1 (Para ejecutar el programa)

g++ -std=c++11 mainAvl.cpp -o app2 (Avance 2) para compilar
./app2 (Para ejecutar el programa)
type output.txt (para mostrar el resultado en cuanto termine el programa) 

## Descripción de las entradas del proyecto
Las entradas ya están en el programa

## Descripción de las salidas en el proyecto 
Si seleccionaste la opción 1 debe salir algo así:
Shai Gilgeous-Alexander: 2254 puntos
Giannis Antetokounmpo: 2222 puntos
Nikola Jokic: 2085 puntos
Anthony Edwards: 2049 puntos
Kevin Durant: 2032 puntos
Jayson Tatum: 1987 puntos
Stephen Curry: 1956 puntos
LeBron James: 1822 puntos
Tyrese Haliburton: 1389 puntos
Trae Young: 1389 puntos
Jordan Poole: 1356 puntos
Joel Embiid: 1353 puntos
Laurie Markkanen: 1278 puntos
Jimmy Butler: 1246 puntos
Darius Garland: 1028 puntos
Deandre Ayton: 920 puntos
Immanuel Quickley: 706 puntos
Lamelo Ball: 526 puntos
Isaiah Stewart: 503 puntos
Zach Lavine: 487 puntos
Jonathan Isaac: 393 puntos
Og Anunoby: 325 puntos
Ben Simmons: 92 puntos

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa
Se debe utilizar diferentes funciones para encontrar lo que el usuario desee, por lo que se pueden usar dos tipos de diferentes algoritmos 
**QuickSort**
Mejor caso: O(n log n) (cuando el pivote divide de manera equilibrada)
Peor caso: O(n²) (si el pivote divide mal, aunque se puede mitigar usando una selección aleatoria)
**MergeSort**
Mejor caso: O(n log n) (siempre, ya que divide el array de manera constante)
Peor caso: O(n log n)

## Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa
En el programa se pueden utilizar diferentes tipos de árboles, pero los árboles AVL se autobalancea para asegurar que todas las operaciones futuras sigan siendo rápidas. Sin embargo no ocurre lo mismo que un BST ya que en este su peor caso sería O(n), por lo que se decidirá usar un árbol AVL

## Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa
Mege sort tiene complejidad de O(n log n)
Clases Nodo y Jugador tiene complejidad O(1) ya que es constante
Funcion Altura es O(n)
Carga de datos desde el archivo: O(n)
Inserción en el árbol AVL:O(nlogn)
Recorrido inorder: O(n)
Complejidad total del programa: O(n logn)

## SICT0302: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente
Para este problema se utilizará un algoritmo de tipo merge sort, para poder organizar los jugadores por orden descendente, quiere decir que de mayor a menor.
Puesto que su peor caso sería O (n log n) por lo que dará mayor estabilidad a las ordenaciones

### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
En el proyecto se optó por usar el árbol AVL, ya que tiene operación de búsqueda y de inserción rápida que ocurre en 𝑂(log⁡𝑛) al igual que en su peor caso O(logn) mejorando el rendimiento


## SICT0303: Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructras correctos.
Se ha implementado un árbol AVL en el proyecto para consultar información de manera eficiente y precisa. La clave de esta implementación es que el árbol AVL se autobalancea, lo que asegura que las operaciones de búsqueda siempre se ejecuten en  O(logn), lo que permite consultas rápidas independientemente de la cantidad de jugadores almacenados

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta
Se ha implementado funciones que permiten cargar datos externos en un archivo txt donde contienen las estadisticas de los jugadores, lo que asegura que el sistema pueda actualizarse y mantenerse flexible,  para manejar grandes cantidades de información sin depender de la entrada manual

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
Se ha implementado funciones que permiten escribir datos en un archivo txt donde contienen los resultados de las opciones del programa
#### José Ernesto Solís Ramírez A01706233
