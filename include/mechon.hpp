#pragma once

/**
 * @class Mechon
 * @brief Representa un Mechon en el juego con atributos de vida, daño y enemigos eliminados.
 * 
 * La clase Mechon modela a un peleador que tiene una cantidad de vida, un daño base que puede infligir,
 * y un contador de enemigos eliminados. A medida que el mechon elimina enemigos, su daño puede aumentar.
 */
class Mechon {
    private:
        int _vida;
        int _damage;    //Inicialmente es igual a 2
        int _enemigos_eliminados;
    public:
        Mechon(int vida);
        ~Mechon();

        /**
         * @brief Si la vida es igual a 0, devuelve `true`, en caso contrario devuelve `false`
         */
        bool isDead();

        /**
         * @brief Devuelve el damage que realiza el mechon
         */
        int getDamage();

        /**
         * @brief Cuando el mechon elimina a un enemigo, se llama a esta funcion para aumentar su contador de kills,
         * si este contador llega a 5, el damage del mechon aumenta en 1 unidad
         */
        void aumentarEnemigosEliminados();

        /**
         * @brief Recibe el damage que un enemigo le realiza al mechon
         */
        void recibeDamage(int damage);
};
