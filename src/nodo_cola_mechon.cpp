#include "../include/nodo_cola_mechon.hpp"

NodoColaMechon::NodoColaMechon(Enemigo *enemigo) {
    this->_nodo_siguiente = nullptr;
    this->_enemigo = enemigo;
}

NodoColaMechon::~NodoColaMechon() {
    delete this->_enemigo;
}

void NodoColaMechon::destructorRecursivo() {
    if(this->_nodo_siguiente != nullptr) 
        this->_nodo_siguiente->destructorRecursivo();
    
    delete this;
}

void NodoColaMechon::setNodoSiguiente(NodoColaMechon* nodo_siguiente) {
    this->_nodo_siguiente = nodo_siguiente;
}

NodoColaMechon* NodoColaMechon::getNodoSiguiente() {
    return this->_nodo_siguiente;
}

Enemigo* NodoColaMechon::getEnemigo() {
    return this->_enemigo;
}
