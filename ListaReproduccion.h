//
//  ListaReproduccion.h
//  MusicPlayer
//
//  Created by Ximena Perez Escalante on 14/10/24.
//

#ifndef ListaReproduccion_h
#define ListaReproduccion_h

#include "Cancion.h"

#include <sstream>
#include <iostream>

class ListaReproduccion;
class Reproductor;

class NodoCancion
{
private:
    Cancion song;
    NodoCancion *previous;
    NodoCancion *next;

public:
    NodoCancion(const Cancion &);
    friend class ListaReproduccion;
    friend class Reproductor;
};

NodoCancion::NodoCancion(const Cancion &cancion)
{
    song = cancion;
    previous = 0;
    next = 0;
}

class ListaReproduccion
{
private:
    int size; 
    NodoCancion *head;
    NodoCancion *tail;

public:
    ListaReproduccion();
    ~ListaReproduccion();
    void insertion(const Cancion &);
    int search(const std::string &titulo); // Búsqueda por título de la canción
    void update(int index, const Cancion &);
    void deleteAt(int index);
    std::string toStringForward() const;
    std::string toStringBackward() const;
    
    friend class NodoCancion;
    friend class Reproductor;
};

ListaReproduccion::ListaReproduccion()
{
    size = 0;
    head = 0;
    tail = 0;
}

ListaReproduccion::~ListaReproduccion()
{
    NodoCancion *p = head;
    while (p != 0)
    {
        NodoCancion *aux = p;
        p = p->next;
        delete aux;
    }
}

void ListaReproduccion::insertion(const Cancion &cancion)
{
    NodoCancion *newNode = new NodoCancion(cancion);
    if (head == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

int ListaReproduccion::search(const std::string &titulo)
{
    NodoCancion *p = head;
    int index = 0;

    while (p != 0)
    {
        if (p->song.getTitulo() == titulo)
        {
            return index;
        }
        p = p->next;
        index++;
    }
    return -1; // No encontrado
}

void ListaReproduccion::update(int index, const Cancion &cancion)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    NodoCancion *p = head;
    int count = 0;

    while (p != 0)
    {
        if (count == index)
        {
            p->song = cancion;
            return;
        }
        p = p->next;
        count++;
    }
}

void ListaReproduccion::deleteAt(int index)
{
    if (index < 0 || index >= size)
    {
        return;
    }

    NodoCancion *p = head;
    NodoCancion *prev = 0;

    int count = 0;
    while (p != 0)
    {
        if (count == index)
        {
            if (p == head)
            {
                head = head->next;
                if (head != 0)
                {
                    head->previous = 0;
                }
                else
                {
                    tail = 0;
                }
            }
            else if (p == tail)
            {
                tail = tail->previous;
                if (tail != 0)
                {
                    tail->next = 0;
                }
            }
            else
            {
                prev->next = p->next;
                if (p->next != 0)
                {
                    p->next->previous = prev;
                }
            }
            delete p;
            size--;
            return;
        }
        prev = p;
        p = p->next;
        count++;
    }
}

std::string ListaReproduccion::toStringForward() const
{
    std::stringstream aux;
    NodoCancion *p = head;

    aux << "[";
    while (p != 0)
    {
        aux << p->song.imprimirCancion();
        if (p->next != 0)
        {
            aux << " -> ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

std::string ListaReproduccion::toStringBackward() const
{
    std::stringstream aux;
    NodoCancion *p = tail;

    aux << "[";
    while (p != 0)
    {
        aux << p->song.imprimirCancion();
        if (p->previous != 0)
        {
            aux << " <- ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif /* ListaReproduccion_h */
