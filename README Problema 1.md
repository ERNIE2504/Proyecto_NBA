# Problema 905. Sort Array by Parity. Leetcode

## LINK DEL PROBLEEMA:
https://leetcode.com/problems/sort-array-by-parity/submissions/1452991707/

## EXPLICACIÓN DEL PROBLEMA 
Este problema requiere ordenar un arreglo de números enteros, pero los números pares deben de ir primero que los números impares. De acuerdo a esto llegamos a la conclusión de utilizar métodos como el merge sort o el quick sort 

## ELECCIÓN MERGE 
1. Complejidad Temporal: El requisito de O(nlogn) descarta los algoritmos de ordenamiento más simples como el bubble sort o el insertion sort, 
que tienen complejidad O(n^2).
2. Consumo de Espacio:En el caso de merge utiliza una complejidad de O(n) debido al uso de arreglos temporales para dividir y fusionar.

## FUNCIONAMIENTO MERGE 
El Merge funciona de la siguiente manera, se centra en fusionar dos subarreglos, colocando los números pares primero y los impares después.
un ejemplo sería: 
left = [3, 2]
right = [4, 1]

Se recorren ambos subarreglos buscando números pares:
De left: el único par es 2, así que result = [2].
De right: el único par es 4, así que result = [2, 4].

Se recorren nuevamente buscando números impares:
De left: el único impar es 3, así que result = [2, 4, 3].
De right: el único impar es 1, así que result = [2, 4, 3, 1].

Resultado final:
result = [2, 4, 3, 1], donde los pares aparecen primero y los impares después.

## COMPLEJIDAD
1. Temporal: O(nlogn), ya que estamos dividiendo el arreglo repetidamenteO(logn)) y fusionando cada par de mitades (O(n)).
2. Espacial:O(n), debido al uso de arreglos temporales para dividir y fusionar.
