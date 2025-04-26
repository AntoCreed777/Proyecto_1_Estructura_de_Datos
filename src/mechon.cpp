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
    if(this->_enemigos_eliminados == 5) {
        this->_enemigos_eliminados = 0;
        this->_damage += 1;
    }
}

bool Mechon::isDead() {
    return this->_vida <= 0;
}

int Mechon::getDamage() const{
    return this->_damage;
}

int Mechon::getVida() const{
    return this->_vida;
}