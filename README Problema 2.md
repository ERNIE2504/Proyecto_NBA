# Problema 160. Intersection of Two Linked Lists. Plataforma leetcode

## Link al problema
https://leetcode.com/problems/intersection-of-two-linked-lists/description/

## Explicación del problema
El objetivo es encontrar el nodo donde dos listas enlazadas se intersectan, si es que existe. Para resolverlo eficientemente, se puede utilizar un enfoque que simula un recorrido "fusionado" de ambas listas.

## Elección de algoritmo
Complejidad Temporal:
El requisito de eficiencia descarta soluciones como la comparación de todos los nodos de una lista con los de la otra O(m⋅n)), ya que no escalaría bien para listas largas. En cambio, el enfoque con punteros tiene una complejidad de 
O(m+n), ideal para este problema.

Consumo de Espacio:
La solución requiere O(1) espacio adicional, ya que no utiliza estructuras auxiliares como pilas o arreglos para almacenar datos temporales.

## Funcionamiento de algoritmo
La solución utiliza dos punteros (ptrA y ptrB) que recorren ambas listas. Si un puntero llega al final de su lista, "salta" al inicio de la otra lista. Esto asegura que ambos punteros realizan una cantidad equivalente de pasos antes de encontrarse en el nodo de intersección.

Un ejemplo sería:

Entrada:
listA = [4, 1, 8, 4, 5]
listB = [5, 6, 1, 8, 4, 5]

Inicialización de punteros:

ptrA apunta al nodo 4 de listA.
ptrB apunta al nodo 5 de listB.
Primer recorrido:

ptrA avanza por listA: [4 → 1 → 8 → 4 → 5 → nullptr].
ptrB avanza por listB: [5 → 6 → 1 → 8 → 4 → 5 → nullptr].

Cuando ptrA llega a nullptr, se mueve a la cabeza de listB: 5.
Cuando ptrB llega a nullptr, se mueve a la cabeza de listA: 4.
Segundo recorrido:

Ambos punteros avanzan nuevamente. Debido a las compensaciones de longitud, ahora llegan al nodo 8 al mismo tiempo.
