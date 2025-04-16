#include <iostream>
#include "../include/cola_mechon.hpp"
#include "../include/enemigo.hpp"
#include "../include/nodo_cola_mechon.hpp"

ColaMechon::ColaMechon() {
    this->_head = nullptr;
    this->_tail = nullptr;
}

ColaMechon::~ColaMechon() {
    if (this->isEmpty()) return;

    this->_head->destructorRecursivo();
}

void ColaMechon::pushEnemigo(Enemigo *enemigo) {
    NodoColaMechon *nodo_enemigo = new NodoColaMechon(enemigo);

    if (this->isEmpty()) {
        this->_head = nodo_enemigo;
        this->_tail = nodo_enemigo;
        return;
    }

    this->_tail->setNodoSiguiente(nodo_enemigo);
    this->_tail = nodo_enemigo;
}

Enemigo* ColaMechon::frontEnemigo() {
    if(this->isEmpty()) throw std::runtime_error("¡No hay enemigos!");
    return this->_head->getEnemigo();
}

void ColaMechon::popEnemigo() {
    if(this->isEmpty()) throw std::runtime_error("¡No hay enemigos!");
    
    NodoColaMechon *nodo_eliminar = this->_head;

    if (this->_head == this->_tail) this->_tail = nullptr;
    
    this->_head = this->_head->getNodoSiguiente();
    delete nodo_eliminar;
}

bool ColaMechon::isEmpty() {
    return this->_head == nullptr;
}

void ColaMechon::subDividePrimerEnemigo() {
    if(this->isEmpty()) throw std::runtime_error("¡No hay enemigos!");

    if (this->_head->getEnemigo()->getVida() - 1 <= 0 || this->_head->getEnemigo()->getDamage() - 1 <= 0) {
        throw std::runtime_error("¡El enemigo no puede dividirse más!");
    }

    Enemigo *enemigo1, *enemigo2;   // 2 enemigos los cuales tienen la misma vida y damage que su padre, pero menos 1 unidad cada uno
    enemigo1 = new Enemigo(this->_head->getEnemigo()->getVida() - 1, this->_head->getEnemigo()->getDamage() - 1, false);
    enemigo2 = new Enemigo(this->_head->getEnemigo()->getVida() - 1, this->_head->getEnemigo()->getDamage() - 1, false);

    NodoColaMechon *nodo1 = new NodoColaMechon(enemigo1);
    NodoColaMechon *nodo2 = new NodoColaMechon(enemigo2);

    nodo1->setNodoSiguiente(nodo2);
    nodo2->setNodoSiguiente(this->_head->getNodoSiguiente());
    delete this->_head;
    this->_head = nodo1;
}
