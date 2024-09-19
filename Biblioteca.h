#ifndef Biblioteca_h
#define Biblioteca_h

#include "Cancion.h"
#include <vector>
#include <sstream>
#include <cstring>

template <class T>
class Biblioteca{
private:
    int numCanciones;
    std::vector<T> canciones;
    
    void swap(std::vector<T>&, int, int);
    void copy(std::vector<T>&, std::vector<T>&, int, int);
    void merge(std::vector<T>&, std::vector<T>&, int, int, int);
    void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
    Biblioteca();
    Biblioteca(std::vector<T>);
    void ordenArtista(std::string);
    void ordenGenero(std::string);
    void ordenDuracion();
    void agregaCancion(Cancion);
    void eliminaCancion(Cancion);
    
    std::string toString();
};

template <class T>
Biblioteca<T>::Biblioteca(){
    numCanciones = 0;
}

template <class T>
Biblioteca<T>::Biblioteca(std::vector<T> songs){
    numCanciones = songs.size();
    canciones = songs;
}


template <class T>
void Biblioteca<T>::copy(std::vector<T> &source, std::vector<T> &temp, int low, int high) {
    for (int i = low; i <= high; i++) {
        source[i] = temp[i];
    }
}

template <class T>
void Biblioteca<T>::swap(std::vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
void Biblioteca<T>::ordenArtista(std::string artist){
    std::vector<T> aux(canciones);
    std::vector<T> tmp(numCanciones);

    mergeSplit(aux, tmp, 0, numCanciones - 1);
}

template <class T>
void Biblioteca<T>::merge(std::vector<T> &original, std::vector<T> &temp, int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (original[i].getArtista() < original[j].getArtista()) {
            temp[k] = original[i];
            i++;
        }
        else {
            temp[k] = original[j];
            j++;
        }
        k++;
    }
    
    if (i > mid) {
        for (; j <= high; j++) {
            temp[k++] = original[j];
        }
    }
    
    else {
        for (; i <= mid; i++) {
            temp[k++] = original[i];
        }
    }
}

template <class T>
void Biblioteca<T>::mergeSplit(std::vector<T> &original, std::vector<T> &temp, int low, int high) {
    int mid;

    if ( (high - low) < 1 ) {
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(original, temp, low, mid);
    mergeSplit(original, temp, mid + 1, high);
    merge(original, temp, low, mid, high);
    copy(original, temp, low, high);
}

template <class T>
std::string Biblioteca<T>::toString() {
    std::stringstream aux;

    aux << "[" << canciones[0].getArtista();
    for (unsigned int i = 1; i < numCanciones; i++) {
        aux << ", " << canciones[i].getArtista();
    }
    aux << "]";
    return aux.str();
}



#endif /* Biblioteca_h */
