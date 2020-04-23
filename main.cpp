#include <cstdlib>
#include "Arma.h"
#include "Armero.h"
#include "Ejercito.h"
#include "Guerrero.h"
#include "LanceroPlantilla.h"
#include "Arquero.h"
#include "Lancero.h"
#include "ItemCSV.h"
using namespace std;

//Algoritmo de ordenación con plantillas

template<typename T>
void ordena(T array[], int tam) {
    bool termina = true;
    do {
        termina = true;
        for (int i = 1; i < tam; i++) {
            if (!(*array[i - 1] <= *array[i])) {
                T aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
                termina = false;
            }
        }
    } while (!termina);
}

void visualiza(ItemCSV *g) {
    cout << g->toCSV() << endl;
}

int main(int argc, char** argv) {

    /********************** EJEMPLO POLIMORFISMO OBJETOS Y MÉTODOS************************/
    //Guerrero *g = new Guerrero("José", 1, 1, 1); Error porque no se pueden crear objetos de una clase abstracta
    Guerrero * array[10];
    array[0] = new Arquero();
    array[0]->SetNombre("Antonio");
    array[1] = new Lancero("María", 2, 2, 2, 5);
    
    //visualiza(g);
    visualiza(array[0]); //El bool se muestra como 0 y 1
    visualiza(array[1]);

    array[2] = new Lancero();
    array[2]->fromCSV("10;Miriam;4;4;14");
    visualiza(array[2]);

    array[2] = new Arquero();
    array[2]->fromCSV("1;Pablo;4;4;14");
    visualiza(array[2]);



    //g=a; //Los hijos si se pueden comportar como los padres
    //cout<<g->GetNombre()<<endl;
    /*Arquero *b=g; //Mal los padres no se pueden comportar como los hijos
    cout<<b->GetNombre()<<" - "<<b->IsFlechas()<<endl;*/

    /********************** EJEMPLO HERENCIA Y POLIMORFISMO************************/
    /*LanceroPlantilla<int, float> * lancero=new LanceroPlantilla<int, float>("Lancero1", 3, 3, 3, 3, 2.15);
    cout<<lancero->GetNombre()<<" - "<<lancero->GetSalto()<<endl;
    //incluso se pueden utilizar objetos de otras clases
    LanceroPlantilla<int, Arquero*> *lancero2=new LanceroPlantilla<int, Arquero*>("Lancero2", 3, 3, 3, 3, new Arquero()); 
    cout<<lancero2->GetNombre()<<" - "<<lancero2->GetSalto()->GetNombre()<<endl; //Se llamaba salto la variable
    
    //Ejemplo Plantilla
    const int tamMax = 3;
    LanceroPlantilla<int, bool> * arrayLanceros[tamMax];
    arrayLanceros[0] = new LanceroPlantilla<int, bool>("María", 3, 3, 3, 3, false);
    arrayLanceros[1] = new LanceroPlantilla<int, bool>("José", 2, 2, 2, 2, true);
    arrayLanceros[2] = new LanceroPlantilla<int, bool>("Joan", 5, 5, 5, 5, 5);

    for (int i = 0; i < tamMax; i++) {
        cout << arrayLanceros[i]->GetNombre()<<" - "<<arrayLanceros[i]->GetSalto()<< endl;
    }
    ordena(arrayLanceros, tamMax);
    for (int i = 0; i < tamMax; i++) {
        cout << arrayLanceros[i]->GetNombre()<< endl;
    }

    //Sin plantilla
    Arquero * arrayArquero[tamMax];
    arrayArquero[0] = new Arquero();
    arrayArquero[0]->SetNombre("Lucía");
    arrayArquero[0]->SetFuerza(3);
    arrayArquero[1] = new Arquero();
    arrayArquero[1]->SetNombre("Inma");
    arrayArquero[1]->SetFuerza(2);
    arrayArquero[2] = new Arquero();
    arrayArquero[2]->SetNombre("Antonio");

    for (int i = 0; i < tamMax; i++) {
        cout << arrayArquero[i]->GetNombre() << endl;
    }
    ordena(arrayArquero, tamMax);
    for (int i = 0; i < tamMax; i++) {
        cout << arrayArquero[i]->GetNombre() << endl;
    }*/

    //Falta liberar la memoria de este ejemplo

    /************** EJEMPLO RELACIONES ENTRE CLASES ****************/
    /*Guerrero *g=new Guerrero();
    cout<<g->GetNombre()<<" - "<<endl;
    Lancero *l=new Lancero("Antonio", 1,1,1,5);
    cout<<l->GetNombre()<<" - "<<l->GetFuerza()<<" - "<<l->GetRangoAtaque()<<endl;
    Arquero *a=new Arquero();
    cout<<a->GetNombre()<<" - "<<a->GetFuerza()<<" - "<<a->IsFlechas()<<endl;*/
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

