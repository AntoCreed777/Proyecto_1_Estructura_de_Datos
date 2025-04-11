#include "../include/enemigo.hpp"

Enemigo::Enemigo(int vida, int damage, bool super_enemigo) {
    this->_vida = vida;
    this->_damage = damage;
    this-> _super_enemigo = super_enemigo;
    this->_golpes_recibidos = 0;
}

Enemigo::~Enemigo() {}

bool Enemigo::recibeDamage(int damage) {
    // Solo cuando los golpes recibidos no son suficientes para que se subDivida le aplico el damage
    if(++this->_golpes_recibidos < this->_minimo_golpes_para_dividirse)
        this->_vida -= damage;

    return this->_vida <= 0;
}

bool Enemigo::isDead() {
    return this->_vida <= 0;
}

bool Enemigo::seSubdivide() {
    if(!this->_super_enemigo) return false;
    return this->_golpes_recibidos >= this->_minimo_golpes_para_dividirse;
}

int Enemigo::getDamage() const {
    return this->_damage;
}

int Enemigo::getVida() const {
    return this->_vida;
}