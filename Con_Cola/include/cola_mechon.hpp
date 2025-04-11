#pragma once

#include <enemigo.hpp>
#include <nodo_cola_mechon.hpp>

/**
 * @class ColaMechon
 * @brief Representa una cola personalizada para manejar enemigos en un juego.
 * 
 * Esta clase implementa una estructura de datos tipo cola para almacenar y 
 * gestionar enemigos. Proporciona métodos para insertar, consultar y eliminar 
 * enemigos, así como para verificar si la cola está vacía.
 * 
 * Permite manejar el caso de que el enemigo que esta al frente se sub-divida en 2 enemigos.
 */
class ColaMechon {
    private:
        NodoColaMechon* _head;
        NodoColaMechon* _tail;

    public:
        ColaMechon();
        ~ColaMechon();

       /**
        * @brief Inserta un enemigo en la cola.
        */
        void pushEnemigo(Enemigo* enemigo);

       /**
        * @brief Devuelve al enemigo en el frente de la cola, pero sin eliminarlo.
        * 
        * @exception Lanza una excepcion cuando la cola esta vacia
        */
        Enemigo* frontEnemigo();

       /**
        * @brief Elimina al enemigo en el frente de la cola.
        * 
        * @exception Lanza una excepcion cuando la cola esta vacia
        */
        void popEnemigo();

        /**
         * @return `true` cuando esta vacia, `false` cuando esta vacia
         */
        bool isEmpty();

        /**
         * @brief SubDivide al enemigo que esta en el frente de la cola
         * 
         * @exception Lanza una excepcion cuando la cola esta vacia
         */
        void subDividePrimerEnemigo();
};
