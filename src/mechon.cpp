#include "../include/mechon.hpp"

Mechon::Mechon(int vida) {
    this->_vida = vida;
    this->_damage = 2;
    this->_enemigos_eliminados = 0;
}

Mechon::~Mechon() {}

void Mechon::recibeDamage(int damage) {
    this->_vida -= damage;
}

void Mechon::aumentarEnemigosEliminados() {
    this->_enemigos_eliminados++;
}

bool Mechon::isDead() {
    return this->_vida <= 0;
}

int Mechon::getDamage() const{
    return this->_damage;
}