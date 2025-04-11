#include <iostream>
#include <vector>
#include <tuple>

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

    int damage_acumulado = 0;
    int damage_mechon = 2;
    int acumulador_golpes_mechon = 0;
    int acumulador_golpes_super_enemigo = 0;

    bool dividido = false;

    rep(i,numero_enemigos) {
        while(vida_enemigos[i] > 0) {
            int aux_vida = vida_enemigos[i];
            vida_enemigos[i] -= damage_mechon;

            vida_mechon -= ataque_enemigos[i];

            acumulador_golpes_mechon++;
            acumulador_golpes_super_enemigo++;

            if(acumulador_golpes_mechon == 5) {
                acumulador_golpes_mechon = 0;
                damage_mechon++;
            }
            
            if(vida_enemigos[i] <= 0) {
                damage_acumulado+=aux_vida;
                break;
            }
            else damage_acumulado += damage_mechon;

            if(super_enemigos[i] && acumulador_golpes_super_enemigo == 2) {
                dividido = true;
                break;
            }

            if(vida_mechon <= 0) break;
        }

        acumulador_golpes_super_enemigo = 0;

        if(dividido) {

            int enemigo1[2] = {vida_enemigos[i]-1,ataque_enemigos[i]-1};
            int enemigo2[2] = {vida_enemigos[i]-1,ataque_enemigos[i]-1};

            while (true) {
                int aux_vida = enemigo1[0];
                enemigo1[0] -= damage_mechon;
    
                vida_mechon -= enemigo1[1];

                if(acumulador_golpes_mechon == 5) {
                    acumulador_golpes_mechon = 0;
                    damage_mechon++;
                }
    
                if(enemigo1[0] <= 0) {
                    damage_acumulado+=aux_vida;
                    break;
                }
                else damage_acumulado += damage_mechon;
    
                if(vida_mechon <= 0) break;
            }

            if(vida_mechon <= 0) break;

            while (true) {
                int aux_vida = enemigo2[0];
                enemigo2[0] -= damage_mechon;
    
                vida_mechon -= enemigo2[1];

                if(acumulador_golpes_mechon == 5) {
                    acumulador_golpes_mechon = 0;
                    damage_mechon++;
                }
    
                if(enemigo2[0] <= 0) {
                    damage_acumulado+=aux_vida;
                    break;
                }
                else damage_acumulado += damage_mechon;
    
                if(vida_mechon <= 0) break;
            }
            dividido = false;
        }

        if(vida_mechon <= 0) break;

    }

    std::cout << damage_acumulado << std::endl;

    if(vida_mechon <= 0) std::cout << "RIP mechón" << std::endl;
    else std::cout << "EZ pizi" << std::endl;
 
    return 0;
}