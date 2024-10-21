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

    
    Jugador() : nombre(""), puntos(0), triples(0), tirosLibres(0), asistencias(0), bloqueos(0), altura(0), anillos(0), mvps(0) {}

    
    Jugador(string nombre, int puntos, int triples, int tirosLibres, int asistencias, int bloqueos, int altura, int anillos, int mvps)
        : nombre(nombre), puntos(puntos), triples(triples), tirosLibres(tirosLibres), asistencias(asistencias),
          bloqueos(bloqueos), altura(altura), anillos(anillos), mvps(mvps) {}
};


void imprimirJugadores(const vector<Jugador>& jugadores, int opcion) {
    for (const auto& jugador : jugadores) {
        cout << jugador.nombre << ": ";
        switch (opcion) {
            case 1:
                cout << "Puntos: " << jugador.puntos << endl;
                break;
            case 2:
                cout << "% Triples: " << jugador.triples << endl;
                break;
            case 3:
                cout << "% Tiros libres: " << jugador.tirosLibres << endl;
                break;
            case 4:
                cout << "Asistencias: " << jugador.asistencias << endl;
                break;
            case 5:
                cout << "Bloqueos: " << jugador.bloqueos << endl;
                break;
            case 6:
                cout << "Altura: " << jugador.altura << " cm" << endl;
                break;
            case 7:
                cout << "Anillos ganados: " << jugador.anillos << endl;
                break;
            case 8:
                cout << "MVPs ganados: " << jugador.mvps << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    }
}


void merge(vector<Jugador>& jugadores, int l, int m, int r, int key) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Jugador> L(n1);
    vector<Jugador> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = jugadores[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = jugadores[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (key == 1 && L[i].puntos >= R[j].puntos) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 2 && L[i].triples >= R[j].triples) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 3 && L[i].tirosLibres >= R[j].tirosLibres) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 4 && L[i].asistencias >= R[j].asistencias) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 5 && L[i].bloqueos >= R[j].bloqueos) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 6 && L[i].altura >= R[j].altura) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 7 && L[i].anillos >= R[j].anillos) {
            jugadores[k] = L[i];
            i++;
        } else if (key == 8 && L[i].mvps >= R[j].mvps) {
            jugadores[k] = L[i];
            i++;
        } else {
            jugadores[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        jugadores[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        jugadores[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<Jugador>& jugadores, int l, int r, int key) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(jugadores, l, m, key);
    mergeSort(jugadores, m + 1, r, key);
    merge(jugadores, l, m, r, key);
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
        Jugador("Laurie Markkanen", 1278, 40, 90, 110, 26, 213, 0, 0)
    };

    int opcion;
    cout << "Selecciona la opcion por la quieras ordenar:" << endl;
    cout << "1. Mas puntos\n2. Mas % triples\n3. Mas % tiros libres\n4. Mas asistencias\n5. Mas bloqueos\n6. Mas altos\n7. Mas anillos\n8. Mas MVPs" << endl;
    cin >> opcion;

    mergeSort(jugadores, 0, jugadores.size() - 1, opcion);
    imprimirJugadores(jugadores, opcion);

    return 0;
}