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

// funcion para mover el cursor a una posicion especifica en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// funcion para cambiar el color del texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Funcion para mostrar el menu principal
void mostrarMenu() {
    system("cls");
    setColor(11);
    gotoxy(20, 2); cout << "***************************";
    gotoxy(20, 3); cout << "*      Menu Principal     *";
    gotoxy(20, 4); cout << "***************************";
    setColor(14);
    gotoxy(22, 6); cout << "1- Ingresar Datos Vehiculos";
    gotoxy(22, 7); cout << "2- Ver Estadisticas Vehiculos Lavados";
    gotoxy(22, 8); cout << "3- Ver Estadisticas Lavados";
    gotoxy(22, 9); cout << "4- Ver Grafico Vehiculos Lavados";
    gotoxy(22, 10); cout << "5- Ver Grafico Lavados";
    gotoxy(22, 11); cout << "6- Salir";
    setColor(15);
    gotoxy(22, 13); cout << "Seleccione una opcion: ";
}

int main(int argc, char** argv) {
	return 0;
}
