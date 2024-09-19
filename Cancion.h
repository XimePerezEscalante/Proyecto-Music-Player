#ifndef Cancion_h
#define Cancion_h


class Cancion{
    private:
    std::string titulo;
    std::string artista;
    std::string genero;
    float duracion;
public:
    Cancion();
    Cancion(std::string,std::string,std::string);
    Cancion(std::string,std::string,std::string,float);
    std::string getTitulo(){return titulo;};
    std::string getArtista(){return artista;};
    std::string getGenero(){return genero;};
    float getDuracion(){return duracion;};
};


Cancion::Cancion(){
    titulo = "Sin nombre";
    artista = "Desconocido";
    genero = "Desconocido";
    duracion = 0.0;
}


Cancion::Cancion(std::string title,std::string artist,std::string genre){
    titulo = title;
    artista = artist;
    genero = genre;
    duracion = 2.5;
}

Cancion::Cancion(std::string title,std::string artist,std::string genre,float length){
    titulo = title;
    artista = artist;
    genero = genre;
    duracion = length;
}
#endif /* Cancion_h */
