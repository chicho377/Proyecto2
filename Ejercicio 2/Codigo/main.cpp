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

// funcion para mostrar el menu principal
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

// funcion para ingresar los datos de los vehiculos
void ingresarDatosVehiculos() {
    char continuar;
    do {
        if (numVehiculos >= MAX_VEHICULOS) {
            gotoxy(22, 15); cout << "Se ha alcanzado el limite maximo de vehiculos.\n";
            break;
        }

        Vehiculo& veh = vehiculos[numVehiculos];  // referencia al vehiculo actual
        system("cls");
        setColor(11);
        gotoxy(20, 2); cout << "*******************************";
        gotoxy(20, 3); cout << "*   Ingresar Datos Vehiculos  *";
        gotoxy(20, 4); cout << "*******************************";
        setColor(14);
        gotoxy(22, 6); cout << "Ingrese el numero de placa: ";
        cin >> veh.placa;
        gotoxy(22, 7); cout << "Ingrese la marca: ";
        cin >> veh.marca;
        gotoxy(22, 8); cout << "Ingrese el modelo: ";
        cin >> veh.modelo;
        gotoxy(22, 9); cout << "Ingrese el tipo de vehiculo (1=Sencillo, 2=4x4, 3=Microbus o Camion): ";
        cin >> veh.tipoVehiculo;
        gotoxy(22, 10); cout << "Ingrese el tipo de lavado (1=Solo Lavado, 2=Lavado, Aspirado y Encerado): ";
        cin >> veh.tipoLavado;

        // calcular el precio basado en el tipo de vehiculo y tipo de lavado
        switch(veh.tipoVehiculo) {
            case 1:
                veh.precio = (veh.tipoLavado == 1) ? 3000 : 5000;
                break;
            case 2:
                veh.precio = (veh.tipoLavado == 1) ? 5000 : 7000;
                break;
            case 3:
                veh.precio = (veh.tipoLavado == 1) ? 7000 : 12000;
                break;
            default:
                gotoxy(22, 12); cout << "Tipo de vehiculo invalido.\n";
                continue;
        }

        // mostrar los datos ingresados
        setColor(15);
        gotoxy(22, 13); cout << "Factura #" << numFactura++;
        gotoxy(22, 14); cout << "Placa: " << veh.placa;
        gotoxy(22, 15); cout << "Marca: " << veh.marca;
        gotoxy(22, 16); cout << "Modelo: " << veh.modelo;
        gotoxy(22, 17); cout << "Tipo de vehiculo: " << ((veh.tipoVehiculo == 1) ? "Sencillo" : (veh.tipoVehiculo == 2) ? "4x4" : "Microbus o Camion");
        gotoxy(22, 18); cout << "Tipo de lavado: " << ((veh.tipoLavado == 1) ? "Solo Lavado" : "Lavado, Aspirado y Encerado");
        gotoxy(22, 19); cout << "Precio a pagar: " << veh.precio << " colones";

        numVehiculos++;

        // preguntar si desea continuar ingresando mas vehiculos
        setColor(14);
        gotoxy(22, 21); cout << "Desea continuar? (S/N): ";
        cin >> continuar;
    } while (continuar == 'S' || continuar == 's');
}

int main(int argc, char** argv) {
	return 0;
}
