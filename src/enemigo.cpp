#include "../include/enemigo.hpp"
#include <iostream> 

Enemigo::Enemigo(int vida, int damage, bool super_enemigo){
    this->_vida = vida;
    this->_damage = damage;
    this-> _super_enemigo = super_enemigo;
    this->_golpes_recibidos = 0;
}

Enemigo::~Enemigo(){}

bool Enemigo::recibeDamage(int damage){
    if(++this->_golpes_recibidos >= this->_minimo_golpes_para_dividirse)
    this->_vida -= damage;

    return this->_vida <= 0;
}

int Enemigo::getDamage(){
    return this->_damage;
}

int Enemigo::getVida(){
    return this->_vida;
}

bool Enemigo::isDead(){
    return this->_vida <= 0;
}

bool Enemigo::seSubdivide(){
    if(!this->_super_enemigo){
        return false;
    }
    return this->_golpes_recibidos >= this->_minimo_golpes_para_dividirse;
}
