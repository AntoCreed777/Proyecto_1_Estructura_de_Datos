#include "../include/enemigo.hpp"

Enemigo::Enemigo(int vida, int damage, bool super_enemigo) {
    this->_vida = vida;
    this->_damage = damage;
    this-> _super_enemigo = super_enemigo;
    this->_golpes_recibidos = 0;
}

Enemigo::~Enemigo() {}

int Enemigo::recibeDamage(int damage) {
    this->_golpes_recibidos++;

    int vida_aux = this->_vida;
    this->_vida -= damage;

    if (this->_vida <= 0) return vida_aux;
    else return damage;
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