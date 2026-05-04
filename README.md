# Tienda en C (Proyecto Terminal Universidad)

## Premisa
Una tienda desea implementar un programa en C que permita
registrar su inventario de productos.

---

## ¿Que debe permitir el programa?
- **Que el programa permita calcular el precio total del inventario.**
- **Permita encontrar el producto más caro y el más barato.**
- **Calcular el precio promedio de todos los productos**
- **Buscar un producto por su nombre y mostrar su precio**
- **El programa solo debe permitir un limite de 10 productos**

## Preguntas

---

### ¿Cómo manejarías la relación entre los nombres y los precios del producto?
Que las matrices de nombre y precio compartan el mismo valor de indice respectivamente
es decir nombre[0][1] = " Coca Cola" y precio[0][1] = "0.55".

### ¿Cómo podrías hacerlo si no puedes usar estructuras ni punteros?
Creando funciones que me permitan retornar valores.

###¿Podría existir más de una alternativa de solución para el problema?

**Solucion 1**: Crear un programa donde exista comparaciones, donde
se compara cada producto con todos los del arreglo y definiendo dos valores
uno mayor y uno menor, el valor mayor sera asignado al numero que sea mayor
en todos los casos posibles, y el menor sera asignado al que sea menor
en todos los casos

**Solucion 2**: Ordenar los productos de mayor a menor, intercambiando la posicion
del dato guardado, es decir, si 
```c 
producto[0] 
es menor que 
```c
product[1] 

se intercambiarian 
de lugar, de manera que cuando el usuario pida imprimir cual es el producto mas 
caro y cual es el producto mas barato el valor se imprima automaticamente 
sin la necesidad de realizar algun proceso matematica.

### ¿Qué alternativa podria ser más eficiente y adecuada para este problema?

La solucion 1 creo que seria la adecuada, ya que el programa solo recorreria
la lista de productos una sola vez, a diferencia de la solución 2
donde se recorre varias veces la lista de nombres asignados, que no es malo,
pero puede llevar a que el nombre del producto en un descuido no comparta 
el mismo indice que el precio.

