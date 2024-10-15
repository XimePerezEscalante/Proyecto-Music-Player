//
//  ListaReproduccion.h
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 14/10/24.
//

#ifndef ListaReproduccion_h
#define ListaReproduccion_h

#include "Cancion.h"
#include <queue>


template <class T>
class ListaReproduccion{
private:
   std::queue<Cancion>  listaCanciones;
public:
    ListaReproduccion(Cancion);
    void agregarCancion(Cancion);
    void eliminarCancion(Cancion);
    void saltarCancion();
    void reproducir();
};

template <class T>
ListaReproduccion<T>::ListaReproduccion(Cancion first){
    listaCanciones.push(first);
}

template <class T>
void ListaReproduccion<T>::agregarCancion(Cancion next){
    listaCanciones.push(next);
}

template <class T>
void ListaReproduccion<T>::eliminarCancion(Cancion eliminada){
    if (listaCanciones.front() == eliminada){
        listaCanciones.pop();
    }
    else if (listaCanciones.back() == eliminada){
        listaCanciones.pop(listaCanciones.back());
    }
    else{
        while (listaCanciones.front() != eliminada){
            listaCanciones.push(eliminada);
            listaCanciones.pop();
        }
    }
}

template <class T>
void ListaReproduccion<T>::saltarCancion(){
    listaCanciones.pop();
}

template <class T>
void ListaReproduccion<T>::reproducir(){
    std::cout << "Reproduciendo " << listaCanciones.front().titulo << " - " << listaCanciones.front().artista << std::endl;
}

#endif /* ListaReproduccion_h */
