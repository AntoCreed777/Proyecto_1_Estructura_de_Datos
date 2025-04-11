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
    int acumulador_enemigos_eliminados_mechon = 0;
    int acumulador_golpes_super_enemigo = 0;

    bool dividido = false;

    rep(i,numero_enemigos) {
        while(vida_enemigos[i] > 0) {
            //Upgrade damage Mechon
            if(acumulador_enemigos_eliminados_mechon == 5) {
                acumulador_enemigos_eliminados_mechon = 0;
                damage_mechon++;
                std::cout << "aumenta el damage mechon" << std::endl;
            }

            int aux_vida = vida_enemigos[i];
            vida_enemigos[i] -= damage_mechon;  //Enemigo recibe damage

            vida_mechon -= ataque_enemigos[i];  //El mechon recibe damage

            acumulador_golpes_super_enemigo++;
            
            std::cout << "vida mechon: " << vida_mechon << std::endl;
            
            //Aumentar el damage acumulado realizado
            if(vida_enemigos[i] <= 0) {
                acumulador_enemigos_eliminados_mechon++;
                damage_acumulado+=aux_vida;
                std::cout << "damage acumulado m: " << damage_acumulado << std::endl;

                break;
            }
            else {
                damage_acumulado += damage_mechon;
                std::cout << "damage acumulado v: " << damage_acumulado << std::endl;
            }

            //SI es un super enemigo y puede cumple requisito para dividirse
            if(super_enemigos[i] && acumulador_golpes_super_enemigo == 2) {
                dividido = true;
                break;
            }

            //Si se murio el mechon, finaliza la pelea
            if(vida_mechon <= 0) break;
        }

        std::cout << "enemigo: " << i << std::endl; 

        acumulador_golpes_super_enemigo = 0;

        //Si se murio el mechon, finaliza la pelea
        if(vida_mechon <= 0) break;

        if(dividido) {

            std::cout << std::endl << "se dividio" << std::endl;
            //Los 2 enemigos generados de la divicion de un super enemigo
            int enemigo1[2] = {vida_enemigos[i]-1,ataque_enemigos[i]-1};
            int enemigo2[2] = {vida_enemigos[i]-1,ataque_enemigos[i]-1};

            //Pelea con el primer enemigo
            while (true) {
                //Upgrade damage Mechon
                if(acumulador_enemigos_eliminados_mechon == 5) {
                    acumulador_enemigos_eliminados_mechon = 0;
                    damage_mechon++;
                }

                int aux_vida = enemigo1[0];
                enemigo1[0] -= damage_mechon;   //Enemigo recibe damage
    
                vida_mechon -= enemigo1[1];     //Mechon recibe damage

    
                //Aumentar el damage acumulado realizado
                if(enemigo1[0] <= 0) {
                    damage_acumulado+=aux_vida;
                    acumulador_enemigos_eliminados_mechon++;
                    break;
                }
                else damage_acumulado += damage_mechon;
    
                //Si se murio el mechon, finaliza la pelea
                if(vida_mechon <= 0) break;
            }

            //Si se murio el mechon, finaliza la pelea
            if(vida_mechon <= 0) break;

            //Pelea con el segundo enemigo
            while (true) {
                //Upgrade damage Mechon
                if(acumulador_enemigos_eliminados_mechon == 5) {
                    acumulador_enemigos_eliminados_mechon = 0;
                    damage_mechon++;
                }

                int aux_vida = enemigo2[0];
                enemigo2[0] -= damage_mechon;   //Enemigo recibe damage
    
                vida_mechon -= enemigo2[1];     //Mechon recibe damage

    
                //Aumentar el damage acumulado realizado
                if(enemigo2[0] <= 0) {
                    damage_acumulado+=aux_vida;
                    acumulador_enemigos_eliminados_mechon++;
                    break;
                }
                else damage_acumulado += damage_mechon;
    
                //Si se murio el mechon, finaliza la pelea
                if(vida_mechon <= 0) break;
            }
            dividido = false;
        }

        //Si se murio el mechon, finaliza la pelea
        if(vida_mechon <= 0) break;

        std::cout << std::endl;
    }

    std::cout << std::endl;

    std::cout << damage_acumulado << std::endl;

    if(vida_mechon <= 0) std::cout << "RIP mechón" << std::endl;
    else std::cout << "EZ pizi" << std::endl;
 
    return 0;
}