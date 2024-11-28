# Proyecto Music Player
Este proyecto pretende simular un reproductor de música como lo son Apple Music, SoundCloud, Spotify, entre otros. En él se pueden agregar o eliminar canciones a la biblioteca del usuario y ordenar las canciones por género, artista o duración.
## SICT0302B: Toma decisiones
### Selecciona y usa una estructura lineal adecuada al problema
Para crear Playlists se utilizará una lista ligada porque las canciones se agregarán y reproducirán de manera ordenada en este programa (todavía no se implementa).
### Selecciona un algoritmo de ordenamiento adecuado al problema
Se usa Merge Sort porque en su peor escenario tiene una complejidad de O(nlogn) y se encuentra en las funciones dentro del objeto Biblioteca en las funciones ordenArtista, ordenGenero y ordenDuracion.
## SICT0301B: Evalúa los componentes
### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
Los casos de prueba se encuentran en el main por el momento, ahí se demuestra lo siguiente:
1. Ordenamiento de las canciones en orden alfabético de los artistas
2. Ordenamiento de las canciones en orden alfabético por género
3. Ordenamiento de las canciones por su duración (de menor a mayor)
### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes
#### Ordenamiento de canciones
Para el algoritmo de merge sort se utilizaron las siguientes funciones:
* swap: O(1) porque sólo se hace el cambio de dos valores dentro del vector.
* copy: O(n) porque hace una copia de los elementos del vector original a uno temporal.
* merge: O(n) porque recorre todos los elementos para compararlos y moverlos.
* mergeSplit: O(n log n) porque se usa recursión para dividir el vector.
* ordenArtista / ordenGenero / ordenDuracion: O(n log n) porque manda a llamar a mergeSplit, así que tienen la misma complejidad.
Demás funciones de Biblioteca:
* eliminaCancion y agregaCancion: O(1) porque se usan las funciones de la biblioteca vector.
* modifyString: O(n) porque recorre todo el string.
ListaReproduccion:
* insertion: O(1) porque siempre se añade al final.
* search: O(n) porque puede que recorra todos los elementos.
* update: O(n) porque puede que recorra todos los elementos.
* delete at: O(n) porque puede que recorra todos los elementos.
Reproductor:
* siguiente / anterior / salir: O(1) porque se mueve una canción en la lista o se sale de la función.
## SICT0302B: Toma decisiones
### Implementa mecanismos para consultar información de las estructras correctos
Se usan los getters de Cancion, friend class para acceder a los atributos privados y en el caso de mostrar información, los métodos toString().
### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta
Los archivos Canciones.txt, Artistas.txt y Duraciones.txt contienen la información correspondiente de cada canción en una línea.
### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En el archivo Biblioteca.txt se agregan las canciones en el último orden que haya seleccionado el usuario.
