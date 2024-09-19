# Proyecto_NBA
Este proyecto toma a los jugadores activos del 2024 de la NBA de los 30 equipos existentes y los va ordenando según el usuario quiera buscar las estadísticas de los jugadores. 
Hay 8 posibilidades de elección: Más puntos anotados, más triples encestados, más tiros libres encestados, más asistencias, más bloqueos, más altos, más anillos ganados y más mvp´s ganados  
> Un ejemplo sería:
>
> Paso 1: seleccionar la opción que se quiere ver
> Paso 2: dar enter y esperar

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa
Se debe utilizar diferentes funciones para encontrar lo que el usuario desee, por lo que se pueden usar dos tipos de diferentes algoritmos 
**QuickSort**
Mejor caso: O(n log n) (cuando el pivote divide de manera equilibrada)
Peor caso: O(n²) (si el pivote divide mal, aunque se puede mitigar usando una selección aleatoria)
**MergeSort**
Mejor caso: O(n log n) (siempre, ya que divide el array de manera constante)
Peor caso: O(n log n)

## SICT0302: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente
Para este problema se utilizará un algoritmo de tipo merge sort, para poder organizar los jugadores por orden descendente, quiere decir que de mayor a menor.
Puesto que su peor caso sería O (n log n) por lo que dará mayor estabilidad a las ordenaciones
