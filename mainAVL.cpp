#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 
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


void imprimirEnOrden(Nodo* nodo, int key, ofstream& outFile) {
    if (nodo == nullptr) return;
    imprimirEnOrden(nodo->izquierdo, key, outFile);
    
    outFile << nodo->jugador.nombre << ": ";
    switch (key) {
        case 1: outFile << nodo->jugador.puntos << " puntos" << endl; break;
        case 2: outFile << nodo->jugador.triples << " % triples anotados" << endl; break;
        case 3: outFile << nodo->jugador.tirosLibres << " % tiros libres anotados" << endl; break;
        case 4: outFile << nodo->jugador.asistencias << " asistencias" << endl; break;
        case 5: outFile << nodo->jugador.bloqueos << " bloqueos" << endl; break;
        case 6: outFile << nodo->jugador.altura << " cm" << endl; break;
        case 7: outFile << nodo->jugador.anillos << " anillos" << endl; break;
        case 8: outFile << nodo->jugador.mvps << " MVPs" << endl; break;
    }
    imprimirEnOrden(nodo->derecho, key, outFile);
}


vector<Jugador> leerJugadoresDesdeArchivo(const string& filename) {
    vector<Jugador> jugadores;
    ifstream file(filename);
    string linea, nombre;
    int puntos, triples, tirosLibres, asistencias, bloqueos, altura, anillos, mvps;

    while (getline(file, linea)) {
        stringstream ss(linea);
        getline(ss, nombre, ',');
        ss >> puntos; ss.ignore();
        ss >> triples; ss.ignore();
        ss >> tirosLibres; ss.ignore();
        ss >> asistencias; ss.ignore();
        ss >> bloqueos; ss.ignore();
        ss >> altura; ss.ignore();
        ss >> anillos; ss.ignore();
        ss >> mvps;
        jugadores.emplace_back(nombre, puntos, triples, tirosLibres, asistencias, bloqueos, altura, anillos, mvps);
    }
    return jugadores;
}

int main() {
    
    vector<Jugador> jugadores = leerJugadoresDesdeArchivo("jugadores.txt");

    int opcion;
    ofstream outFile("output.txt");

    do {
        cout << "\n Selecciona la opcion por la cual quieres ordenar:" << endl;
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

        
        imprimirEnOrden(root, opcion, outFile);

    } while (opcion != 9);

    outFile.close();
    return 0;
}
