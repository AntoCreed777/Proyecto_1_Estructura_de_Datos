#include <iostream>
#include <vector>
#include "../include/cola_mechon.hpp"
#include "../include/mechon.hpp"
#include "../include/enemigo.hpp"

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repx(i,x,n) for(int i=x;i<(int)n;i++)
#define invrep(i,n) for(int i=n;i>=0;i--)
#define pb push_back

void FunctionOptimization() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(0);
}

int main() {
    //FunctionOptimization();

    int vida_mechon, numero_enemigos;

    std::cin >> vida_mechon >> numero_enemigos;

    std::vector<int> vida_enemigos(numero_enemigos);
    std::vector<int> ataque_enemigos(numero_enemigos);
    std::vector<bool> super_enemigos(numero_enemigos);  // En el enunciado se les denomina CANO

    rep(i,numero_enemigos) std::cin >> vida_enemigos[i];
    rep(i,numero_enemigos) std::cin >> ataque_enemigos[i];
    rep(i,numero_enemigos) {    //Esto es porque me da error de formato el std::cin con el vector<bool>
        int aux;
        std::cin >> aux;
        if (aux) super_enemigos[i] = true;
        else super_enemigos[i] = false;
    }
    
    ColaMechon *cola = new ColaMechon();

    rep(i,numero_enemigos) {
        Enemigo *nuevo_enemigo = new Enemigo(vida_enemigos[i], ataque_enemigos[i], super_enemigos[i]);
        cola->pushEnemigo(nuevo_enemigo);
    }

    Mechon *mechon = new Mechon(vida_mechon);
    int damage_acumulado = 0;

    int contador_ciclos_batalla = 0;

    while(!cola->isEmpty() && !mechon->isDead()){
        std::cout << ++contador_ciclos_batalla << std::endl;
        std::cout << "Vida Mechon: " << mechon->getVida() << std::endl; 
        
        Enemigo *enemigo = cola->frontEnemigo();

        // Primero el enemigo recibe damage
        int aux = enemigo->recibeDamage(mechon->getDamage());
        damage_acumulado += aux;
        std::cout << "damage realizado a enemigo " << aux << std::endl;

        mechon->recibeDamage(enemigo->getDamage());
        std::cout << "Ataque a mechon " << enemigo->getDamage() << std::endl << std::endl;
        
        if(enemigo->isDead()){
            std::cout << "Enemigo muerto" << std::endl << std::endl;
            mechon->aumentarEnemigosEliminados();
            cola->popEnemigo();
            continue;
        }

        if(enemigo->seSubdivide()){
            std::cout << "Se dividio" << std::endl;
            cola->subDividePrimerEnemigo();
            enemigo = cola->frontEnemigo(); //Esto porque al sub dividirse se elimino al antiguo enemigo, pero ahora hay 2 nuevos enemigos en la cola
        }
    }


    std::cout << damage_acumulado << std::endl;

    if (cola->isEmpty()) std::cout << "EZ pizi" << std::endl;
    else std::cout << "RIP mechón" << std::endl;

    delete cola;
    delete mechon;

    return 0;
}