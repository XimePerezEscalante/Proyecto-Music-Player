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
    std::vector<Cancion> listaCanciones = {Cancion("Beloved","Celeste","Baladas",3.58),
    Cancion("Angel of my Dreams","JADE","Pop",3.18),Cancion("Stealin' Love","Leigh-Anne","Pop",2.20),
    Cancion("Tears","Perrie","Pop",2.55),Cancion("Hold On","The Internet","R&B/Soul",6.46),
    Cancion("Only Human","SiR","R&B/Soul",4.25),
    Cancion("the fear is not real","WILLOW","Contemporary Jazz",3.38),
    Cancion("How Many Mics","The Fugees","Hip-Hop/Rap",4.29),
    Cancion("Cpu","Raury","Alternativa",4.29),
    Cancion("Down","Blackbear","R&B/Soul",2.20),
    Cancion("mirrored heart","FKA twigs","Electrónica",4.33)};
    
    Biblioteca<Cancion> bibliotecaUsuario(listaCanciones);
    
    std::cout << "XPE - Reproductor de Música:\n1. Ordenar por Artista\n2. Ordenar por Género\n3. Ordenar por Duración\n4. Crear Lista de Reproducción" << std::endl;
    
    std::cin >> opcion;
    
    if (opcion == 1){
        bibliotecaUsuario.ordenArtista();
        
        std::cout << bibliotecaUsuario.toString() << std::endl;
    }
    
    else if (opcion == 2){
        bibliotecaUsuario.ordenGenero();
        
        std::cout << bibliotecaUsuario.toString() << std::endl;
    }
    
    else if (opcion == 3){
        bibliotecaUsuario.ordenDuracion();
        
        std::cout << bibliotecaUsuario.toString() << std::endl;
    }
    
    else{
        Cancion song("Midnight Cowboy", "Jade", "Pop", 3.31);
        ListaReproduccion<Cancion> lista(song);
        lista.reproducir();
    }
    return 0;
}
