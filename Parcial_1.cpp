#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

double calcularDistanciaMasCercana(
    Point puntos[],
    int n,
    const Point &pUsuario,
    int &indiceMasCercano
) {
    if (n <= 0) {
        indiceMasCercano = -1;
        return 0.0;
    }

    double distanciaMinima = sqrt(
        pow(puntos[0].x - pUsuario.x, 2) +
        pow(puntos[0].y - pUsuario.y, 2)
    );

    indiceMasCercano = 0;

    for (int i = 1; i < n; i++) {
        double distancia = sqrt(
            pow(puntos[i].x - pUsuario.x, 2) +
            pow(puntos[i].y - pUsuario.y, 2)
        );

        if (distancia < distanciaMinima) {
            distanciaMinima = distancia;
            indiceMasCercano = i;
        }
    }

    return distanciaMinima;
}

int main() {
    int n;

    cout << "Ingrese la cantidad de puntos: ";
    cin >> n;

    if (n <= 0) {
        cout << "Cantidad invalida de puntos." << endl;
        return 0;
    }

    Point* puntos = new Point[n];


    for (int i = 0; i < n; i++) {
        cout << "\nPunto " << i + 1 << endl;
        cout << "  x: ";
        cin >> puntos[i].x;
        cout << "  y: ";
        cin >> puntos[i].y;
    }

    Point pUsuario;
    cout << "\nIngrese el punto de referencia:" << endl;
    cout << "  x: ";
    cin >> pUsuario.x;
    cout << "  y: ";
    cin >> pUsuario.y;

    int indiceMasCercano;

    double distancia = calcularDistanciaMasCercana(
        puntos,
        n,
        pUsuario,
        indiceMasCercano
    );

    if (indiceMasCercano != -1) {
        cout << "\nEl punto mas cercano es: ("
             << puntos[indiceMasCercano].x << ", "
             << puntos[indiceMasCercano].y << ")" << endl;

        cout << "Distancia minima: " << distancia << endl;
    } else {
        cout << "No se encontraron puntos." << endl;
    }

    delete[] puntos;

    return 0;
}