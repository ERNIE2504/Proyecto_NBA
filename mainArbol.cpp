#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Jugador {
public:
    string nombre;
    int puntos;
    int triples;
    int tirosLibres;
    int asistencias;
    int bloqueos;
    int altura;
    int anillos;
    int mvps;

    
    Jugador(string nombre, int puntos, int triples, int tirosLibres, int asistencias, int bloqueos, int altura, int anillos, int mvps)
        : nombre(nombre), puntos(puntos), triples(triples), tirosLibres(tirosLibres), asistencias(asistencias),
          bloqueos(bloqueos), altura(altura), anillos(anillos), mvps(mvps) {}
};


class Nodo {
public:
    Jugador jugador;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;

    Nodo(Jugador jugador)
        : jugador(jugador), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};


int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}


int obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

int compararEstadistica(Jugador j1, Jugador j2, int key) {
    switch (key) {
        case 1: if (j1.puntos != j2.puntos) return j1.puntos - j2.puntos;
                else return j1.nombre.compare(j2.nombre);
        case 2: if (j1.triples != j2.triples) return j1.triples - j2.triples;
                else return j1.nombre.compare(j2.nombre); 
        case 3: if (j1.tirosLibres != j2.tirosLibres) return j1.tirosLibres - j2.tirosLibres;
                else return j1.nombre.compare(j2.nombre);
        case 4: if (j1.asistencias != j2.asistencias) return j1.asistencias - j2.asistencias;
                else return j1.nombre.compare(j2.nombre); 
        case 5: if (j1.bloqueos != j2.bloqueos) return j1.bloqueos - j2.bloqueos;
                else return j1.nombre.compare(j2.nombre); 
        case 6: if (j1.altura != j2.altura) return j1.altura - j2.altura;
                else return j1.nombre.compare(j2.nombre); 
        case 7: if (j1.anillos != j2.anillos) return j1.anillos - j2.anillos;
                else return j1.nombre.compare(j2.nombre);  
        case 8: if (j1.mvps != j2.mvps) return j1.mvps - j2.mvps;
                else return j1.nombre.compare(j2.nombre); 
        default: return 0;
    }
}



Nodo* rotacionDerecha(Nodo* y) {
    Nodo* x = y->izquierdo;
    Nodo* T2 = x->derecho;
    x->derecho = y;
    y->izquierdo = T2;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    return x;
}

Nodo* rotacionIzquierda(Nodo* x) {
    Nodo* y = x->derecho;
    Nodo* T2 = y->izquierdo;
    y->izquierdo = x;
    x->derecho = T2;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    return y;
}


Nodo* insertar(Nodo* nodo, Jugador jugador, int key) {
    if (nodo == nullptr)
        return (new Nodo(jugador));
    
    
    if (compararEstadistica(jugador, nodo->jugador, key) > 0)
        nodo->izquierdo = insertar(nodo->izquierdo, jugador, key);
    
    else if (compararEstadistica(jugador, nodo->jugador, key) < 0)
        nodo->derecho = insertar(nodo->derecho, jugador, key);

    nodo->altura = 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && compararEstadistica(jugador, nodo->izquierdo->jugador, key) > 0)
        return rotacionDerecha(nodo);

    if (balance < -1 && compararEstadistica(jugador, nodo->derecho->jugador, key) < 0)
        return rotacionIzquierda(nodo);

    return nodo;
}


void imprimirEnOrden(Nodo* nodo, int key) {
    if (nodo == nullptr) return;

    
    imprimirEnOrden(nodo->izquierdo, key); 

    
    cout << nodo->jugador.nombre << ": ";
    switch (key) {
        case 1: cout << nodo->jugador.puntos << " puntos" << endl; break;
        case 2: cout << nodo->jugador.triples << " % triples anotados" << endl; break;
        case 3: cout << nodo->jugador.tirosLibres << " % tiros libres anotados" << endl; break;
        case 4: cout << nodo->jugador.asistencias << " asistencias" << endl; break;
        case 5: cout << nodo->jugador.bloqueos << " bloqueos" << endl; break;
        case 6: cout << nodo->jugador.altura << " cm" << endl; break;
        case 7: cout << nodo->jugador.anillos << " anillos" << endl; break;
        case 8: cout << nodo->jugador.mvps << " MVPs" << endl; break;
    }

    
    imprimirEnOrden(nodo->derecho, key);
}

int main() {
    vector<Jugador> jugadores = {
        Jugador("LeBron James", 1822, 41, 75, 589, 38, 206, 4, 4),
        Jugador("Kevin Durant", 2032, 41, 86, 378, 91, 211, 2, 1),
        Jugador("Stephen Curry", 1956, 41, 92, 379, 28, 191, 4, 2),
        Jugador("Jayson Tatum", 1987, 38, 83, 364, 43, 203, 1, 1),
        Jugador("Ben Simmons", 92, 0, 40, 86, 9, 208, 0, 0),
        Jugador("Og Anunoby", 325, 39, 79, 35, 23, 201, 0, 0),
        Jugador("Joel Embiid", 1353, 39, 88, 219, 66, 213, 0, 1),
        Jugador("Immanuel Quickley", 706, 40, 84, 257, 7, 191, 0, 0),
        Jugador("Zach Lavine", 487, 35, 85, 98, 8, 196, 0, 0),
        Jugador("Darius Garland", 1028, 37, 83, 373, 7, 185, 0, 0),
        Jugador("Isaiah Stewart", 503, 38, 75, 73, 38, 206, 0, 0),
        Jugador("Tyrese Haliburton", 1389, 36, 86, 752, 48, 196, 0, 0),
        Jugador("Giannis Antetokounmpo", 2222, 27, 68, 476, 79, 211, 1, 2),
        Jugador("Trae Young", 1389, 37, 86, 583, 11, 185, 0, 0),
        Jugador("Lamelo Ball", 526, 36, 87, 176, 4, 201, 0, 0),
        Jugador("Jimmy Butler", 1246, 41, 86, 298, 17, 201, 0, 0),
        Jugador("Jonathan Isaac", 393, 38, 72, 30, 70, 208, 0, 0),
        Jugador("Jordan Poole", 1356, 33, 88, 343, 25, 193, 1, 0),
        Jugador("Nikola Jokic", 2085, 36, 82, 708, 68, 213, 1, 3),
        Jugador("Anthony Edwards", 2049, 36, 84, 405, 42, 193, 0, 0),
        Jugador("Shai Gilgeous-Alexander", 2254, 35, 87, 465, 67, 198, 0, 0),
        Jugador("Deandre Ayton", 920, 10, 82, 90, 42, 211, 0, 0),
        Jugador("Laurie Markkanen", 1278, 40, 90, 110, 26, 213, 0, 0),

        // Agregar más jugadores...
    };

    int opcion;
    cout<<"";

    do {
        cout << "\n Selecciona la opcion por la cue quieras ordenar:" << endl;
        cout << "1. Mas puntos\n2. Mas % triples\n3. Mas % tiros libres\n4. Mas asistencias\n5. Mas bloqueos\n6. Mas altos\n7. Mas anillos\n8. Mas MVPs\n9. Salir" << endl;
        cin >> opcion;

        if (opcion == 9) {
            cout << "Hasta luego..." << endl;
            break; 
        }

        Nodo* root = nullptr;

        for (const auto& jugador : jugadores) {
            root = insertar(root, jugador, opcion);
        }

        imprimirEnOrden(root, opcion);

    } while (opcion != 9); 

    return 0;
}
