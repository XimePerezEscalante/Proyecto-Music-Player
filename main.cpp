#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <fstream>

#include "Biblioteca.h"

Cancion crearCancion()
{
    std::string name;
    std::string artist;
    std::string genre;
    float length;
    std::cout << "Por favor introduce guion bajo en lugar de espacios" << std::endl;
    std::cout << "Nombre: ";
    std::cin >> name;
    std::cout << "Artista: ";
    std::cin >> artist;
    std::cout << "Género: ";
    std::cin >> genre;
    std::cout << "Duración: ";
    std::cin >> length;

    return Cancion(name, artist, genre, length);
}

Cancion crearCancion(std::string name, std::string artist, std::string genre, float length)
{
    Cancion song(name, artist, genre, length);
    std::cout << song.imprimirCancion() << std::endl;
    return song;
}

int preguntar()
{
    int opcion;

    std::cout << "1. Ordenar por Artista\n2. Ordenar por Género\n3. Ordenar por Duración\n4. Agregar canción\n5. Eliminar canción\n6. Crear Lista de Reproducción\n7. Salir"" << std::endl;

    std::cin >> opcion;

    while (opcion < 1 || opcion > 6)
    {
        std::cout << "Escoge una opción del 1 al 6: " << std::endl;
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

        else if (opcion == 6)
        {
            // Variables de input
            int opc;
            int opc2;

            std::cout << "Crear Lista de Reproduccion:\n1. Crear (Sin nombre)\n2. Cambiar nombre" << std::endl;
            std::cin >> opc;
            while (opc < 1 || opc > 2)
            {
                std::cout << "Escoge una opcion (1 o 2)" << std::endl;
                std::cin >> opc;
            }

            std::cout << "Agregar canciones:\n 1. De tu biblioteca\n2. Nueva cancion\n3. Lista de Reproduccion vacia" << std::endl;
            std::cin >> opc2;

            while (opc < 1 || opc > 2)
            {
                std::cout << "Escoge una opcion (1 o 2)" << std::endl;
                std::cin >> opc;
            }

            if (opc == 1)
            {
                if (opc2 == 1)
                {
                }
                else if (opc2 == 2)
                {
                }
                else if (opc2 == 3)
                {
                    bibUsuario.crearPlaylist("");
                }
            }
            else if (opc == 2)
            {
                if (opc2 == 1)
                {
                }
                else if (opc2 == 2)
                {
                }
                else if (opc2 == 3)
                {
                    bibUsuario.crearPlaylist("nombreinput");
                }
            }
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

    // Cargar archivos para crear la librería predeterminada
    leerArchivos(bibliotecaUsuario);
    
    std::cout << "\nXPE - Reproductor de Música:\nSe cargó la librería predeterminada" << std::endl;
    
    acciones(preguntar(),bibliotecaUsuario);
    
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
