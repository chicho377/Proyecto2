#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

// constante
const int MAX_VEHICULOS = 100;

// estructura para almacenar la informacion de los vehiculos
struct Vehiculo {
    string placa;
    string marca;
    string modelo;
    int tipoVehiculo;
    int tipoLavado;
    int precio;
};

// variables globales
Vehiculo vehiculos[MAX_VEHICULOS];
int numVehiculos = 0;
int numFactura = 1;

// prototipos de funciones
void gotoxy(int x, int y);
void setColor(int color);
void mostrarMenu();
void ingresarDatosVehiculos();
void verEstadisticasVehiculos();
void verEstadisticasLavados();
void verGraficoVehiculos();
void verGraficoLavados();
void hacer_graficos(int a, int y);

int main(int argc, char** argv) {
	return 0;
}
