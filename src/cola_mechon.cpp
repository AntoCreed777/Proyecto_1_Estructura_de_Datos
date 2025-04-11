#include <iostream>
#include "../include/cola_mechon.hpp"
#include "../include/enemigo.hpp"
#include "../include/nodo_cola_mechon.hpp"

ColaMechon::ColaMechon(){
    this->_head = nullptr;
    this->_tail = nullptr;
}

ColaMechon::~ColaMechon(){}

void ColaMechon::pushEnemigo(Enemigo *enemigo){
    NodoColaMechon *new_enemy = new NodoColaMechon(enemigo);   
    this->_tail->setNodoSiguiente(new_enemy);
    this->_tail = this->_tail->getNodoSiguiente();
}

Enemigo* ColaMechon::frontEnemigo(){
    return this->_head->getEnemigo();
}

Enemigo* ColaMechon::popEnemigo(){
    if(this->isEmpty()){
        throw std::runtime_error("¡No hay enemigos!");
    }
    
    NodoColaMechon *nodo_eliminar = this->_head;
    Enemigo* enemigo_nodo_head = nodo_eliminar->getEnemigo();
    
    this->_head = this->_head->getNodoSiguiente();
    delete nodo_eliminar;
    return enemigo_nodo_head;
}

bool ColaMechon::isEmpty(){
    return this->_head == nullptr;
}

void ColaMechon::duplicacionPrimerEnemigo(){
    Enemigo *enemigo1, *enemigo2;
    enemigo1 = new Enemigo(this->_head->getEnemigo()->getVida() - 1, this->_head->getEnemigo()->getDamage() - 1, false);
    enemigo2 = new Enemigo(this->_head->getEnemigo()->getVida() - 1, this->_head->getEnemigo()->getDamage() - 1, false);

    NodoColaMechon *nodo1 = new NodoColaMechon(enemigo1);
    NodoColaMechon *nodo2 = new NodoColaMechon(enemigo2);

    nodo1->setNodoSiguiente(nodo2);
    nodo2->setNodoSiguiente(this->_head->getNodoSiguiente());
    delete this->_head;
    this->_head = nodo1;
}
