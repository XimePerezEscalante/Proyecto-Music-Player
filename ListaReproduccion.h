//
//  ListaReproduccion.h
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 14/10/24.
//

#ifndef ListaReproduccion_h
#define ListaReproduccion_h

#include <queue>

template <class T>
class ListaReproduccion
{
private:
    std::string nombre;
    int numCanciones;
    int reproduciendo;
    std::queue<Cancion> listaCanciones;

public:
    // Constructores
    ListaReproduccion();
    ListaReproduccion(std::string);
    ListaReproduccion(Cancion);
    ListaReproduccion(Cancion, std::string);

    void agregarCancion(Cancion);
    void eliminarCancion(Cancion);
    void saltarCancion();
    void reproducir();

    // getters
    std::string getNombre() { return nombre; }
    int getNumCanciones() { return numCanciones; }

    // setters
    void setNombre(std::string newName) { nombre = newName; }
};

template <class T>
ListaReproduccion<T>::ListaReproduccion()
{
    nombre = "Sin Titulo";
    numCanciones = 0;
    reproduciendo = 0;
}

template <class T>
ListaReproduccion<T>::ListaReproduccion(std::string name)
{
    nombre = name;
    numCanciones = 0;
    reproduciendo = 0;
}

template <class T>
ListaReproduccion<T>::ListaReproduccion(Cancion first)
{
    nombre = "Sin Título";
    listaCanciones.push(first);
    numCanciones = 1;
    reproduciendo = 0;
}

template <class T>
ListaReproduccion<T>::ListaReproduccion(Cancion first, std::string name)
{
    nombre = name;
    listaCanciones.push(first);
    numCanciones = 1;
    reproduciendo = 0;
}

template <class T>
void ListaReproduccion<T>::agregarCancion(Cancion next)
{
    listaCanciones.push(next);
    numCanciones++;
}

template <class T>
void ListaReproduccion<T>::eliminarCancion(Cancion eliminada)
{
    if (listaCanciones.front() == eliminada)
    {
        listaCanciones.pop();
    }
    else if (listaCanciones.back() == eliminada)
    {
        listaCanciones.pop(listaCanciones.back());
    }
    else
    {
        while (listaCanciones.front() != eliminada)
        {
            listaCanciones.push(eliminada);
            listaCanciones.pop();
        }
    }
    numCanciones--;
}

template <class T>
void ListaReproduccion<T>::saltarCancion()
{
    listaCanciones.pop();
}

template <class T>
void ListaReproduccion<T>::reproducir()
{
    if (numCanciones > 0)
    {
        std::cout << "Reproduciendo " << listaCanciones.front().titulo << " - " << listaCanciones.front().artista << std::endl;
    }
    else
    {
        std::cout << "Error: " << nombre << " es una Lista de Reproduccion vacia" << std::endl;
    }
}

#endif /* ListaReproduccion_h */
