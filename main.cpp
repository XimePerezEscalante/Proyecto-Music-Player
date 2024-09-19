#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include "Biblioteca.h"


int main(int argc, const char * argv[]) {
    std::vector<Cancion> listaCanciones = {Cancion("Beloved","Celeste","Baladas",3.58),Cancion("Angel of my Dreams","JADE","Pop",3.18),
  Cancion("Stealin' Love","Leigh-Anne","Pop",2.20),Cancion("Tears","Perrie","Pop",2.55),Cancion("Hold On","The Internet","R&B/Soul",6.46),
  Cancion("Only Human","SiR","R&B/Soul",4.25),Cancion("the fear is not real","WILLOW","Contemporary Jazz",3.38),
  Cancion("How Many Mics","The Fugees","Hip-Hop/Rap",4.29),Cancion("CPU","Raury","Alternativa",4.29),
  Cancion("DOWN","blackbear","R&B/Soul",2.20),Cancion("mirrored heart","FKA twigs","Electrónica",4.33)};
    
    Biblioteca<Cancion> bibliotecaUsuario(listaCanciones);
    
    bibliotecaUsuario.ordenArtista("Raury");
    
    std::cout << bibliotecaUsuario.toString() << std::endl;
    
    std::cout << "XPE - Reproductor de Música:\n1. Ordenar por Artista\n2. Ordenar por Género\n3. Ordenar por Duración" << std::endl;
  
    return 0;
}