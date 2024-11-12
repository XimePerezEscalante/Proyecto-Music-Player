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

int main(int argc, const char * argv[]) {
int main(int argc, const char *argv[])
{
    int opcion;
    std::string nombreUsuario;

    Biblioteca<Cancion> bibliotecaUsuario = Biblioteca<Cancion>();

    std::cout << bibliotecaUsuario.toString() << std::endl;

    bibliotecaUsuario.ordenGenero();

    std::cout << bibliotecaUsuario.toString() << std::endl;

    bibliotecaUsuario.ordenDuracion();

    std::cout << bibliotecaUsuario.toString() << std::endl;

    std::cout << "XPE - Reproductor de Música:\n1. Buscar por Artista\n2. Buscar por Género\n3. Buscar por Duración\n4. Agregar canción\n5. Eliminar canción" << std::endl;*/

    std::cout << "¡Bienvenid@!\nIngresa un nombre de usuario: ";
    std::cin >> nombreUsuario;
    
    std::cout << "\nXPE - Reproductor de Música:\n1. Ordenar por Artista\n2. Ordenar por Género\n3. Ordenar por Duración\n4. Agregar canción\n5. Eliminar canción\n6. Crear Lista de Reproducción" << std::endl;

    std::cin >> opcion;

    while (opcion < 1 || opcion > 6)
    {
        std::cout << "Escoge una opción del 1 al 6: " << std::endl;
        std::cin >> opcion;
    }

    if (opcion == 1)
    {
        bibliotecaUsuario.ordenArtista();

        std::cout << bibliotecaUsuario.toString() << std::endl;
    }

    else if (opcion == 2)
    {
        bibliotecaUsuario.ordenGenero();

        std::cout << bibliotecaUsuario.toString() << std::endl;
    }

    else if (opcion == 3)
    {
        bibliotecaUsuario.ordenDuracion();

        std::cout << bibliotecaUsuario.toString() << std::endl;
    }

    else if (opcion == 4)
    {
        bibliotecaUsuario.agregaCancion(crearCancion());
        bibliotecaUsuario.toString();
    }

    else if (opcion == 5)
    {
        int song;
        std::cout << "Eliminar cancion: " << std::endl;
        std::cout << bibliotecaUsuario.toString() << std::endl;
        std::cout << "Escoge el numero de la cancion: " << std::endl;
        std::cin >> song;
        bibliotecaUsuario.eliminaCancion(song);
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
                bibliotecaUsuario.crearPlaylist("");
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
                bibliotecaUsuario.crearPlaylist("nombreinput");
            }
        }
    }
    
    //Abrir archivo de texto
    std::ofstream MyFile("Biblioteca.txt");

      //Escribir en el archivo
    MyFile << "Biblioteca Musical de " << nombreUsuario << "\n\n";
    MyFile << bibliotecaUsuario.toString() << "\n";

      //Cerrar el archivo
      MyFile.close();
    return 0;
}
