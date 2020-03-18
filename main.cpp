#include <cstdlib>
#include "Arma.h"
#include "Armero.h"
#include "Ejercito.h"
#include "Guerrero.h"
#include "Lancero.h"

using namespace std;

int main(int argc, char** argv) {
    
    Lancero *l=new Lancero();
    cout<<l->GetNombre()<<" - "<<l->GetRangoAtaque()<<endl;
    /*try {
        Armero *armero1 = new Armero("Gollum", 45);
        Armero *armero2 = new Armero("Bilbo", 50);
        //armero1->crearArma("Excalibur",50); Excepción porque el poder es superior al límite del armero
        Arma *a1 = armero1->crearArma("Excalibur", 30);
        Arma *a2 = armero2->crearArma("Tizona", 30);
        Arma *a3 = armero2->crearArma("Narsil", 35);
        Arma *a4 = armero1->crearArma("Sable láser", 45);

        Guerrero *g1 = new Guerrero("Aren", 80, 60, 100);
        Guerrero *g2 = new Guerrero("Axe", 60, 30, 130);
        Guerrero *g3 = new Guerrero("Daven", 60, 80, 110);
        Guerrero *g4 = new Guerrero(*g1); //Llama al constructor copia
        cout << g4->GetNombre() << endl;
        g4->SetNombre("Egil");
        g4->SetFuerza(70);

        cout << g1->GetNumArmasActual() << " - " << g2->GetNumArmasActual() << " - " << g3->GetNumArmasActual() << " - " << g4->GetNumArmasActual() << endl;
        g1->anadirArma(a1);
        a1 = nullptr; //Si hago un delete aquí liberaría la zona de memoria reservada del arma por lo que se pierden
        //los datos. Así evitamos que un arma la pueda tener más de un guerrero. Sin embargo si apuntamos a nulo y 
        //no lo vamos a volver a utilizar podriamos liberar la memoria reservada
        g1->anadirArma(a2);
        a2 = nullptr;
        //g1->soltarArma(3);Excepción porque los guerreros solo pueden tener tres armas (0-1-2) <-pos en el array
        //g2->anadirArma(a1); Excepción porque a1 no contiene ningún arma
        g3->anadirArma(a3);
        a3 = nullptr;
        g4->anadirArma(a4);
        a4 = nullptr;
        cout << g1->GetNumArmasActual() << " - " << g2->GetNumArmasActual() << " - " << g3->GetNumArmasActual() << " - " << g4->GetNumArmasActual() << endl;
        a1 = g1->soltarArma(1);
        g4->anadirArma(a1);
        a1 = nullptr;
        cout << g1->GetNumArmasActual() << " - " << g2->GetNumArmasActual() << " - " << g3->GetNumArmasActual() << " - " << g4->GetNumArmasActual() << endl;
        //g1->desarmar(); //Devuelve un array dinámico con punteros a armas, si no lo guardamos, se perderán los punteros a las armas que suelta el guerrero
        //cout<<g1->GetNumArmasActual()<<" - "<<g2->GetNumArmasActual()<<" - "<<g3->GetNumArmasActual()<<" - "<<g4->GetNumArmasActual()<<endl;

        Ejercito *ejercito1 = new Ejercito("Madagascar", "Tyrion Lannister", "Compañía Dorada", 50); //Creamos un ejército con un escuadrón (Compañia dorada)
        //Vemos como el tamaño del array crece a medida que insertamos elementos
        cout << "max- " << ejercito1->getMAXescuadrones() << endl;
        ejercito1->anadirEscuadron("Caminantes Blancos", 100);
        cout << "max- " << ejercito1->getMAXescuadrones() << endl;
        ejercito1->anadirEscuadron("Salvajes", 50);
        cout << "max- " << ejercito1->getMAXescuadrones() << endl;

        //Listamos todos los escuadrones del ejército también valdria ejercito1->getEscuadrones()[i]->getNombre() que devuelve el array de escuadrones   
        for (int i = 0; i < ejercito1->getNumEscuadronesActual(); i++) {
            cout << ejercito1->getEscuadron(i)->getNombre() << " - " << ejercito1->getEscuadron(i)->getNumGuerrerosActual() << endl;
        }

        ejercito1->getEscuadron(0)->anadirGuerrero(g1);
        g1 = nullptr;
        ejercito1->getEscuadron(1)->anadirGuerrero(g2);
        g2 = nullptr;
        ejercito1->getEscuadron(1)->anadirGuerrero(g3);
        g3 = nullptr;
        ejercito1->getEscuadron(1)->anadirGuerrero(g4);
        g4 = nullptr;

        //Listamos todos los escuadrones del ejército también valdria ejercito1->getEscuadrones()[i]->getNombre() que devuelve el array de escuadrones   
        for (int i = 0; i < ejercito1->getNumEscuadronesActual(); i++) {
            cout << ejercito1->getEscuadron(i)->getNombre() << " - " << ejercito1->getEscuadron(i)->getNumGuerrerosActual() << endl;
        }

        g1 = ejercito1->getEscuadron(0)->eliminarGuerrero(0);
        ejercito1->getEscuadron(1)->anadirGuerrero(g1);
        g1 = nullptr;

        for (int i = 0; i < ejercito1->getNumEscuadronesActual(); i++) {
            cout << ejercito1->getEscuadron(i)->getNombre() << " - " << ejercito1->getEscuadron(i)->getNumGuerrerosActual() << endl;
        }

        cout << "PRUEBA CONSTRUCTOR COPIA EJERCITO" << endl;
        Ejercito *ejercito2 = new Ejercito(*ejercito1);
        for (int i = 0; i < ejercito2->getNumEscuadronesActual(); i++) {
            cout << ejercito2->getEscuadron(i)->getNombre() << " - " << ejercito2->getEscuadron(i)->getNumGuerrerosActual() << endl;
        }

        //Liberamos la memoria que había reservada para las armas y los guerreros (no se hace en la clase)
        //por que no son relaciones de composición
        for (int i = 0; i < ejercito1->getEscuadron(1)->getNumGuerrerosActual(); i++) { //Para cada guerrero
            for (int j = 0; j < ejercito1->getEscuadron(1)->getGuerreros()[i]->GetNumArmasActual(); j++) { //Para cada arma 
                delete ejercito1->getEscuadron(1)->getGuerreros()[i]->GetArma(j);//Libero la memoria reservada por cada arma. 
                //No se hace desde dentro de la clase porque son totalmente independientes
            }
            delete ejercito1->getEscuadron(1)->getGuerreros()[i]; //Eliminamos la memoria reservada para cada guerrero
        }

        //Liberamos la memoria que había reservada para las armas y los guerreros (no se hace en la clase)
        //por que no son relaciones de composición
        for (int i = 0; i < ejercito2->getEscuadron(1)->getNumGuerrerosActual(); i++) { //Para cada guerrero
            for (int j = 0; j < ejercito2->getEscuadron(1)->getGuerreros()[i]->GetNumArmasActual(); j++) { //Para cada arma 
                delete ejercito2->getEscuadron(1)->getGuerreros()[i]->GetArma(j);//Libero la memoria reservada por cada arma. 
                //No se hace desde dentro de la clase porque son totalmente independientes
            }
            delete ejercito2->getEscuadron(1)->getGuerreros()[i]; //Eliminamos la memoria reservada para cada guerrero
        }
        
        delete ejercito2; //Elimina los ejércitos y los escuadrones al tener una relación de composición
        delete ejercito1; //Elimina los ejércitos y los escuadrones al tener una relación de composición

    } catch (const out_of_range &e) {
        cout << e.what();
    } catch (const string &s) {
        cout << s;
    }*/

    return 0;
}

