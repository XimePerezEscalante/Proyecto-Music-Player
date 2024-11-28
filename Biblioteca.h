//
//  Biblioteca.h
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 18/09/24.
//

#ifndef Biblioteca_h
#define Biblioteca_h

#include "Cancion.h"
#include "ListaReproduccion.h"
#include "Playlist.h"
#include "Reproductor.h"

#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cctype>
#include <queue>

template <class T>
class Biblioteca
{
private:
    int numCanciones;
    std::vector<T> canciones;                    // Vector con canciones

    // Funciones para hacer Merge Sort
    void swap(std::vector<T> &, int, int);
    void copy(std::vector<T> &, std::vector<T> &, int, int);
    void merge(std::vector<T> &, std::vector<T> &, int, int, int, int);
    void mergeSplit(std::vector<T> &, std::vector<T> &, int, int, int);

public:
    Biblioteca();
    Biblioteca(std::vector<T>);

    std::string modifyString(std::string);

    void ordenArtista();
    void ordenGenero();
    void ordenDuracion();

    void agregaCancion(Cancion);
    void eliminaCancion(int);

    void reproducir();

    // Getter
    Cancion getCancion(int index) { return canciones[index - 1]; }

    std::string toString();
};

template <class T>
Biblioteca<T>::Biblioteca()
{
    numCanciones = 0;
}

template <class T>
Biblioteca<T>::Biblioteca(std::vector<T> songs)
{
    numCanciones = songs.size();
    canciones = songs;
}

template <class T>
void Biblioteca<T>::agregaCancion(Cancion song)
{
    canciones.push_back(song);
    numCanciones++;

    std::cout << "Canción agregada:" << std::endl;
    std::cout << song.imprimirCancion() << std::endl;
}

template <class T>
void Biblioteca<T>::eliminaCancion(int song)
{
    canciones.erase(canciones.begin() + (song - 1)); // iterador al index de la canción
    numCanciones--;

    std::cout << "Canción eliminada" << std::endl;
    std::cout << toString() << std::endl;
}

// Convertir string a minúsculas
template <class T>
std::string Biblioteca<T>::modifyString(std::string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

template <class T>
void Biblioteca<T>::copy(std::vector<T> &original, std::vector<T> &temp, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        original[i] = temp[i];
    }
}

template <class T>
void Biblioteca<T>::swap(std::vector<T> &v, int i, int j)
{
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
void Biblioteca<T>::merge(std::vector<T> &original, std::vector<T> &temp, int low, int mid, int high, int option)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        // Ordenar por artista
        if (option == 1)
        {
            // Crear una copia del string en minúsculas para la comparación
            std::string minusculasI = modifyString(original[i].getArtista());
            std::string minusculasJ = modifyString(original[j].getArtista());

            if (minusculasI <= minusculasJ)
            {
                temp[k] = original[i];
                i++;
            }
            else
            {
                temp[k] = original[j];
                j++;
            }
        }
        // Ordenar por género
        else if (option == 2)
        {
            // Crear una copia del string en minúsculas para la comparación
            std::string minusculasI = modifyString(original[i].getGenero());
            std::string minusculasJ = modifyString(original[j].getGenero());

            if (minusculasI < minusculasJ)
            {
                temp[k] = original[i];
                i++;
            }
            else
            {
                temp[k] = original[j];
                j++;
            }
        }
        // Ordenar por duración
        else if (option == 3)
        {
            if (original[i].getDuracion() < original[j].getDuracion())
            {
                temp[k] = original[i];
                i++;
            }
            else
            {
                temp[k] = original[j];
                j++;
            }
        }
        k++;
    }

    if (i > mid)
    {
        for (; j <= high; j++)
        {
            temp[k++] = original[j];
        }
    }

    else
    {
        for (; i <= mid; i++)
        {
            temp[k++] = original[i];
        }
    }
}

template <class T>
void Biblioteca<T>::mergeSplit(std::vector<T> &original,
                               std::vector<T> &temp, int low, int high, int option)
{
    int mid;

    if ((high - low) < 1)
    {
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(original, temp, low, mid, option);
    mergeSplit(original, temp, mid + 1, high, option);
    merge(original, temp, low, mid, high, option);
    copy(original, temp, low, high);
}

template <class T>
std::string Biblioteca<T>::toString()
{
    std::stringstream aux;

    for (unsigned int i = 0; i < numCanciones; i++)
    {
        aux << i + 1 << ". " << canciones[i].imprimirCancion() << "\n";
    }
    aux << "\n";
    return aux.str();
}

template <class T>
void Biblioteca<T>::ordenArtista()
{
    if (numCanciones > 0){
        std::vector<T> aux(canciones);
        std::vector<T> tmp(numCanciones);
        std::cout << "Orden Alfabetico por Artista" << "\n"
        << std::endl;
        
        mergeSplit(aux, tmp, 0, numCanciones - 1, 1);
        canciones = aux;
    }
    else{
        std::cout << "No hay canciones en tu biblioteca" << std::endl;
    }
}

template <class T>
void Biblioteca<T>::ordenGenero()
{
    if (numCanciones > 0){
        std::vector<T> aux(canciones);
        std::vector<T> tmp(numCanciones);
        std::cout << "Orden Alfabetico por Género" << "\n"
        << std::endl;
        
        mergeSplit(aux, tmp, 0, numCanciones - 1, 2);
        canciones = aux;
    }
    else{
        std::cout << "No hay canciones en tu biblioteca" << std::endl;
    }
}

template <class T>
void Biblioteca<T>::ordenDuracion()
{
    if (numCanciones > 0){
        std::vector<T> aux(canciones);
        std::vector<T> tmp(numCanciones);
        std::cout << "Duracion de Menor a Mayor" << "\n"
        << std::endl;
        
        mergeSplit(aux, tmp, 0, numCanciones - 1, 3);
        canciones = aux;
    }
    else{
        std::cout << "No hay canciones en tu biblioteca" << std::endl;
    }
}

template <class T>
void Biblioteca<T>::reproducir()
{
    int opcion;

    Reproductor play(canciones);
    play.reproducir();
}

#endif /* Biblioteca_h */
