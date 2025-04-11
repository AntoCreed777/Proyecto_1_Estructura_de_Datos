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

    while(!cola->isEmpty() && !mechon->isDead()){
        damage_acumulado += mechon->getDamage();
        Enemigo *enemigo = cola->frontEnemigo();

        // Primero el enemigo recibe damage
        enemigo->recibeDamage(mechon->getDamage());
        
        if(enemigo->isDead()){
            mechon->aumentarEnemigosEliminados();
            cola->popEnemigo();
            continue;
        }

        if(enemigo->seSubdivide()){
            cola->subDividePrimerEnemigo();
            enemigo = cola->frontEnemigo(); //Esto porque al sub dividirse se elimino al antiguo enemigo, pero ahora hay 2 nuevos enemigos en la cola
        }

        // Por ultimo, el enemigo recibe damage
        mechon->recibeDamage(enemigo->getDamage());
    }


    std::cout << damage_acumulado << std::endl;

    if (mechon->isDead()) std::cout << "RIP mechón" << std::endl;
    else std::cout << "EZ pizi" << std::endl;

    delete cola;
    delete mechon;

    return 0;
}
