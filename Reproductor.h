#ifndef Reproductor_h
#define Reproductor_h
#include <vector>
#include <iostream>

#include "ListaReproduccion.h"


class Reproductor
{
private:
    ListaReproduccion lista; // Lista doblemente ligada de canciones
    NodoCancion *actual;     // Puntero a la canción actualmente en reproducción

public:
    Reproductor(const std::vector<Cancion> &canciones);
    void reproducir();
    void siguiente();
    void anterior();
    void eliminarCancion();
    void mostrarCanciones();
    bool menu();
};

// Constructor que inicializa la lista con el vector de canciones
Reproductor::Reproductor(const std::vector<Cancion> &canciones)
{
    for (int i = 0;i < canciones.size();i++){
        lista.insertion(canciones[i]);
    }
    actual = lista.head; // Inicia en la primera canción
}

// Función principal de reproducción
void Reproductor::reproducir() {
    if (actual == 0) {
        std::cout << "No hay canciones en la lista de reproducción.\n";
        return;
    }
    
    bool seguir = true;
    
    while (actual != 0 && seguir) {
        std::cout << "\nReproduciendo: " << actual->song.getTitulo()
        << " - " << actual->song.getArtista() << std::endl;

        seguir = menu(); // Llama al menú para realizar acciones adicionales

        // Si la opción es "Salir", el ciclo termina
        if (!seguir) {
            std::cout << "Reproducción detenida.\n";
            return;
        }

        // Si no hay más canciones y el usuario intenta continuar
        if (actual->next == 0 && seguir) {
            std::cout << "\nYa no hay más canciones que reproducir.\n";
        }
    }
}

// Saltar a la siguiente canción
void Reproductor::siguiente()
{
    if (actual == 0 || actual->next == 0) {
            std::cout << "No hay más canciones para reproducir.\n";
        }
    else {
            actual = actual->next;
    }
}

// Regresar a la canción anterior
void Reproductor::anterior()
{
    if (actual == 0 || actual->previous == 0) {
            std::cout << "No hay canciones anteriores para reproducir.\n";
    }
    else {
            actual = actual->previous;
    }
}

// Mostrar todas las canciones con índices
void Reproductor::mostrarCanciones()
{
    std::cout << "\nLista de canciones:\n";
    NodoCancion *p = lista.head;
    int index = 1;

    while (p != 0)
    {
        std::cout << index << ": " << p->song.imprimirCancion() << "\n";
        p = p->next;
        index++;
    }
}

// Eliminar una canción por índice
void Reproductor::eliminarCancion()
{
    if (lista.head == 0)
    {
        std::cout << "No hay canciones para eliminar.\n";
        return;
    }

    mostrarCanciones();
    int index;
    std::cout << "Ingresa el índice de la canción que deseas eliminar: ";
    std::cin >> index;
    index = index - 1;

    // Validar índice
    while (index < 0 || index >= lista.size)
    {
        std::cout << "Índice inválido.\n";
        return;
    }

    // Actualizar puntero actual si se elimina la canción en reproducción
    if (actual == lista.head)
    {
        actual = actual->next;
    }

    lista.deleteAt(index);

    std::cout << "Canción eliminada.\n";

    // Si no hay más canciones, actual se pone en 0
    if (lista.head == 0)
    {
        actual = 0;
    }
    else if (actual == 0)
    {
        actual = lista.tail;
    }
}

// Menú interactivo con ifs
bool Reproductor::menu()
{
    int opcion = 0;
    

    std::cout << "\n--- Menú Reproductor ---\n";
    std::cout << "1. Reproducir canción actual\n";
    std::cout << "2. Siguiente canción\n";
    std::cout << "3. Canción anterior\n";
    std::cout << "4. Eliminar canción\n";
    std::cout << "5. Mostrar lista de canciones\n";
    std::cout << "6. Salir\n";
    std::cout << "Selecciona una opción: ";
    std::cin >> opcion;
    
    while (opcion < 1 && opcion > 6){
        std::cout << "Selecciona una opción del 1 al 6: " << std::endl;
        std::cin >> opcion;
    }

    if (opcion == 1) {
        reproducir();
        return true;
    }
    else if (opcion == 2) {
        siguiente();
        return true;
    }
    else if (opcion == 3) {
        anterior();
        return true;
    }
    else if (opcion == 4) {
        eliminarCancion();
        return true;
    }
    else if (opcion == 5)
    {
        mostrarCanciones();
        return true;
    }
    else if (opcion == 6)
    {
            std::cout << "Saliendo del reproductor.\n";
            return false;
    }
    return false;

}

#endif
