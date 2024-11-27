# Problema 257. Binary Tree Paths Leetcode

## Link Problema
https://leetcode.com/problems/binary-tree-paths/description/

## EXPLICACIÓN DEL PROBLEMA 
Dado un árbol binario, necesitamos devolver una lista de todos los caminos desde la raíz hasta las hojas.
Un camino de raíz a hoja es una secuencia de nodos que comienza en el nodo raíz y termina en un nodo hoja (es decir, un nodo sin hijos).


## Estrategia de solución
La solución utiliza recursión para recorrer el árbol de manera exhaustiva, acumulando el camino actual como una cadena que se pasa a las llamadas recursivas. Cuando se alcanza una hoja, el camino acumulado se agrega al resultado final.

Caso Base:
Si el árbol está vacío (nodo null), no hay caminos que agregar, por lo que se devuelve un vector vacío.

Caso Nodo Hoja:
Si el nodo actual no tiene hijos (izquierdo ni derecho), significa que llegamos al final de un camino. Agregamos ese valor del nodo al camino actual y lo almacenamos como un camino completo.

Recursión:
Si el nodo tiene hijos, llamamos recursivamente a sus subárboles izquierdo y derecho, acumulando el camino actual.
Después de procesar ambos subárboles, se juntan los resultados obtenidos.

## Funcionamiento
Entrada:
       1
      / \
     2   3
      \
       5

Nodo raíz 1:
Camino actual: "1"
Llamadas recursivas a:
Subárbol izquierdo (nodo 2)
Subárbol derecho (nodo 3)

Nodo 2:
Camino acumulado: "1->2"
Llamada recursiva a:
Subárbol derecho (nodo 5)
Nodo 5 (hoja):

Camino acumulado: "1->2->5"
Se agrega el camino al resultado.

Nodo 3 (hoja):
Camino acumulado: "1->3"
Se agrega el camino al resultado.

Salida:
["1->2->5", "1->3"]

## Complejidad
Complejidad Temporal:

Se recorre cada nodo del árbol exactamente una vez.
Complejidad: 
O(n), donde n es el número de nodos.

Complejidad Espacial:
Pila de Recursión: En el peor caso (árbol degenerado), el espacio utilizado será proporcional a la altura del árbol, que es
O(n). En un árbol balanceado, es O(logn).

Espacio para resultados: Depende del número de hojas m y la longitud promedio de los caminos O(m⋅h).
