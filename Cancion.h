//
//  Cancion.h
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 18/09/24.
//

#ifndef Cancion_h
#define Cancion_h

#include <iostream>
#include <sstream>

template <class T>
class ListaReproduccion;

class Cancion
{
private:
    std::string titulo;
    std::string artista;
    std::string genero;
    float duracion;

public:
    // Constructores
    Cancion();
    Cancion(std::string, std::string, std::string);
    Cancion(std::string, std::string, std::string, float);
    // Getters
    std::string getTitulo() { return titulo; };
    std::string getArtista() { return artista; };
    std::string getGenero() { return genero; };
    float getDuracion() { return duracion; };

    std::string imprimirCancion();

    friend class ListaReproduccion<Cancion>;
};

// Constructor por omisión
Cancion::Cancion()
{
    titulo = "Sin nombre";
    artista = "Desconocido";
    genero = "Desconocido";
    duracion = 0.0;
}

// Constructor con parámetros (menos la duración)
Cancion::Cancion(std::string title, std::string artist, std::string genre)
{
    titulo = title;
    artista = artist;
    genero = genre;
    duracion = 2.5;
}

// Constructor con todos los parámetros
Cancion::Cancion(std::string title, std::string artist, std::string genre, float length)
{
    titulo = title;
    artista = artist;
    genero = genre;
    duracion = length;
}

std::string Cancion::imprimirCancion()
{
    std::stringstream aux;
    aux << titulo << " - " << artista << " - " << genero << " - " << duracion;
    return aux.str();
}

#endif /* Cancion_h */
