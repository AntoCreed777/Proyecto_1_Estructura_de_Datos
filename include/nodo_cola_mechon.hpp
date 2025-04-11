
#pragma once

#include <enemigo.hpp>

/**
 * @class NodoColaMechon
 * @brief Representa un nodo de una cola enlazada que contiene un objeto de tipo Enemigo.
 * 
 * Esta clase implementa un nodo que forma parte de una estructura de datos de tipo cola enlazada.
 * Cada nodo contiene un objeto de tipo Enemigo y un puntero al nodo siguiente en la cola.
 */
class NodoColaMechon {
    private:
        NodoColaMechon* _nodo_siguiente;
        Enemigo* _enemigo;

    public:
        NodoColaMechon(Enemigo* enemigo);
        ~NodoColaMechon();

        /**
         * @brief Funcion que desstruye tanto a si mismo como a todos los demas nodos con los que este ligado
         */
        void destructorRecursivo();

        /**
        * Permite cambiar el Nodo Siguiente
        */
        void setNodoSiguiente(NodoColaMechon* nodo_siguiente);

        /**
         * @brief Devuelve al nodo siguiente en la cola.
         * 
         * @return NodoColaMechon* 
         */
        NodoColaMechon* getNodoSiguiente();

        /**
        * Devuelve al enemigo que contiene el nodo
        */
        Enemigo* getEnemigo();
};
