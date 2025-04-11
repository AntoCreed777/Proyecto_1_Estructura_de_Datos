#pragma once

/**
 * @brief Clase que representa a un enemigo
 * 
 * Esta clase modela un enemigo con las siguientes características principales:
 * - Posee una cantidad de vida.
 * - Tiene un valor de daño que puede infligir.
 * - Puede ser un "super enemigo", también conocido como CANO.
 * - Lleva un conteo de golpes recibidos si es un super enemigo.
 * 
 * Métodos principales:
 * - recibeDamage(int damage): Permite que el enemigo reciba daño y determina si ha muerto.
 * - getDamage(): Devuelve el daño que el enemigo puede infligir.
 * - isDead(): Indica si el enemigo ha muerto.
 */
class Enemigo {
    private:
        int _vida;
        int _damage;
        bool _super_enemigo; // En el enunciado se les llama CANO

        // Se usan cuando _super_enemigo == true
        int _golpes_recibidos;
        int minimo_golpes_para_dividirse;
        
    public:
        Enemigo(int vida, int damage, bool super_enemigo);
        ~Enemigo();
        
       /**
        * @brief Recibe el damage, el cual se le resta a la vida, devuelve `true` si es que murio, en caso contrario, devuelve `false`
        * 
        * @param int `damage` : El damage que se le hace al enemigo
        */
        bool recibeDamage(int damage);

       /**
        * @brief Devuelve el damage que el enemigo es capaz de hacer
        */
        int getDamage();

       /**
        * @brief Si no le queda vida, debuelve `true`, en caso contrario, devuelve `false`
        */
        bool isDead();

        /**
         * @brief Si la cantidad de golpes recibidos es igual a la cantidad minima de golpes necesarios para que se sub-divida
         * entonces devuelve `true`, en caso contrario devuelve `false`
         */
        bool seSubdivide();

};
