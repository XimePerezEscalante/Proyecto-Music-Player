//
//  main.cpp
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 18/09/24.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <fstream>

#include "Biblioteca.h"

std::string modifyString(std::string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == '_')
        {
            word[i] = ' ';
        }
    }
    return word;
}

Cancion crearCancion()
{
    std::string name;
    std::string artist;
    std::string genre;
    float length;
    std::cout << "Por favor introduce guion bajo en lugar de espacios\nNombre: ";
    std::cin >> name;
    name = modifyString(name);
    std::cout << "Artista: ";
    std::cin >> artist;
    artist = modifyString(artist);
    std::cout << "Género: ";
    std::cin >> genre;
    genre = modifyString(genre);
    std::cout << "Duración: ";
    std::cin >> length;

    return Cancion(name, artist, genre, length);
}

Cancion crearCancion(std::string name, std::string artist, std::string genre, float length)
{
    Cancion song(name, artist, genre, length);
    //std::cout << song.imprimirCancion() << std::endl;
    return song;
}

int preguntar()
{
    int opcion;

    std::cout << "\n\n1. Ordenar por Artista\n2. Ordenar por Género" << std::endl;
    std::cout << "3. Ordenar por Duración\n4. Agregar canción" << std::endl;
    std::cout << "5. Eliminar canción\n6. Reproducir" << std::endl;
    std::cout << "7. Salir" << std::endl;

    std::cin >> opcion;

    while (opcion < 1 || opcion > 7
    )
    {
        std::cout << "Escoge una opción del 1 al 7: " << std::endl;
        std::cin >> opcion;
    }

    return opcion;
}

void acciones(int opcion, Biblioteca<Cancion> &bibUsuario)
{

    while (opcion >= 1 && opcion <= 6)
    {

        if (opcion == 1)
        {
            bibUsuario.ordenArtista();

            std::cout << bibUsuario.toString() << std::endl;
        }

        else if (opcion == 2)
        {
            bibUsuario.ordenGenero();

            std::cout << bibUsuario.toString() << std::endl;
        }

        else if (opcion == 3)
        {
            bibUsuario.ordenDuracion();

            std::cout << bibUsuario.toString() << std::endl;
        }

        else if (opcion == 4)
        {
            bibUsuario.agregaCancion(crearCancion());
            bibUsuario.toString();
        }

        else if (opcion == 5)
        {
            int song;
            std::cout << "Eliminar cancion: " << std::endl;
            std::cout << bibUsuario.toString() << std::endl;
            std::cout << "Escoge el numero de la cancion: " << std::endl;
            std::cin >> song;
            bibUsuario.eliminaCancion(song);
        }
        else if (opcion == 6){
            bibUsuario.reproducir();
        }
        opcion = preguntar();
    }
    
}

void leerArchivos(Biblioteca<Cancion> &bibUsuario)
{
    // Strings que se usarán en el output del archivo de texto
    std::string dur; //duracion
    std::string name;
    std::string artist;
    std::string genre;
    float length;

    // Leer archivos
    std::ifstream DuracionArchivo("Duraciones.txt");
    std::ifstream Artists("Artistas.txt");
    std::ifstream Genres("Generos.txt");
    std::ifstream Songs("Canciones.txt");

    // While loop con getline() para leer el archivo línea por línea
    while (getline(DuracionArchivo, dur) && getline(Artists, artist) && getline(Genres, genre) && getline(Songs, name))
    {
        length = std::stof(dur);
        bibUsuario.agregaCancion(crearCancion(name, artist, genre, length));
    }

    // Cerrar archivos
    DuracionArchivo.close();
    Artists.close();
    Genres.close();
    Songs.close();
}

int main(int argc, const char *argv[])
{
    int opcion;
    std::string nombreUsuario;

    Biblioteca<Cancion> bibliotecaUsuario = Biblioteca<Cancion>();
    
    std::cout << "¡Bienvenid@!\nIngresa un nombre de usuario: ";
    std::cin >> nombreUsuario;
    
    leerArchivos(bibliotecaUsuario);
    
    std::cout << "\nXPE - Reproductor de Música:\nSe cargó la librería predeterminada" << std::endl;
    
    acciones(preguntar(), bibliotecaUsuario);
    
    std::cout << "¡Hasta luego " << nombreUsuario << "!" << std::endl;

    // Abrir archivo de texto
    std::ofstream MyFile("Biblioteca.txt");

    // Escribir en el archivo
    MyFile << "Biblioteca Musical de " << nombreUsuario << "\n\n";
    MyFile << bibliotecaUsuario.toString() << "\n";

    // Cerrar el archivo
    MyFile.close();

    return 0;
}
