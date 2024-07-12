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

// funcion para ver estadisticas de vehiculos lavados segun tipo de vehiculo
void verEstadisticasVehiculos() {
    int cantidadSencillos = 0, cantidad4x4 = 0, cantidadMicrobus = 0;
    int dineroSencillos = 0, dinero4x4 = 0, dineroMicrobus = 0;

    // recorrer el arreglo de vehiculos para calcular las estadisticas
    for (int i = 0; i < numVehiculos; i++) {
        switch (vehiculos[i].tipoVehiculo) {
            case 1:
                cantidadSencillos++;
                dineroSencillos += vehiculos[i].precio;
                break;
            case 2:
                cantidad4x4++;
                dinero4x4 += vehiculos[i].precio;
                break;
            case 3:
                cantidadMicrobus++;
                dineroMicrobus += vehiculos[i].precio;
                break;
        }
    }

    // mostrar las estadisticas
    system("cls");
    setColor(11);
    gotoxy(20, 2); cout << "*******************************";
    gotoxy(20, 3); cout << "*  Estadisticas por Vehiculo  *";
    gotoxy(20, 4); cout << "*******************************";
    setColor(14);
    gotoxy(22, 6); cout << "Cantidad de Vehiculos Tipo Sencillos: " << cantidadSencillos;
    gotoxy(22, 7); cout << "Dinero Recaudado por Vehiculos Tipo Sencillos: " << dineroSencillos << " colones";
    gotoxy(22, 8); cout << "Cantidad de Vehiculos Tipo 4x4: " << cantidad4x4;
    gotoxy(22, 9); cout << "Dinero Recaudado por Vehiculos Tipo 4x4: " << dinero4x4 << " colones";
    gotoxy(22, 10); cout << "Cantidad de Vehiculos Tipo Microbus o Camion: " << cantidadMicrobus;
    gotoxy(22, 11); cout << "Dinero Recaudado por Vehiculos Tipo Microbus o Camion: " << dineroMicrobus << " colones";
    setColor(15);
    gotoxy(22, 13); cout << "<Pulse tecla para regresar al menu>";
    cin.ignore().get();  // esperar a que el usuario pulse una tecla
}

// funcion para ver estadisticas de vehiculos lavados segun tipo de lavado
void verEstadisticasLavados() {
    int cantidadSoloLavado = 0, cantidadCompleto = 0;
    int dineroSoloLavado = 0, dineroCompleto = 0;

    // recorrer el arreglo de vehiculos para calcular las estadisticas
    for (int i = 0; i < numVehiculos; i++) {
        switch (vehiculos[i].tipoLavado) {
            case 1:
                cantidadSoloLavado++;
                dineroSoloLavado += vehiculos[i].precio;
                break;
            case 2:
                cantidadCompleto++;
                dineroCompleto += vehiculos[i].precio;
                break;
        }
    }

    // mostrar las estadisticas
    system("cls");
    setColor(11);
    gotoxy(20, 2); cout << "*******************************";
    gotoxy(20, 3); cout << "*  Estadisticas por Lavado    *";
    gotoxy(20, 4); cout << "*******************************";
    setColor(14);
    gotoxy(22, 6); cout << "Cantidad de Vehiculos con Solo Lavado: " << cantidadSoloLavado;
    gotoxy(22, 7); cout << "Dinero Recaudado por Vehiculos con Solo Lavado: " << dineroSoloLavado << " colones";
    gotoxy(22, 8); cout << "Promedio Dinero Recaudado por Vehiculos con Solo Lavado: " << (cantidadSoloLavado > 0 ? dineroSoloLavado / cantidadSoloLavado : 0) << " colones";
    gotoxy(22, 9); cout << "Cantidad de Vehiculos con Lavado, Aspirado y Encerado: " << cantidadCompleto;
    gotoxy(22, 10); cout << "Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << dineroCompleto << " colones";
    gotoxy(22, 11); cout << "Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << (cantidadCompleto > 0 ? dineroCompleto / cantidadCompleto : 0) << " colones";
    setColor(15);
    gotoxy(22, 13); cout << "<Pulse tecla para regresar al menu>";
    cin.ignore().get();  // esperar a que el usuario pulse una tecla
}

// funcion para ver grafico de vehiculos lavados por tipo de vehiculo
void verGraficoVehiculos() {
    int cantidadSencillos = 0, cantidad4x4 = 0, cantidadMicrobus = 0;

    // recorrer el arreglo de vehiculos para calcular las cantidades
    for (int i = 0; i < numVehiculos; i++) {
        switch (vehiculos[i].tipoVehiculo) {
            case 1:
                cantidadSencillos++;
                break;
            case 2:
                cantidad4x4++;
                break;
            case 3:
                cantidadMicrobus++;
                break;
        }
    }

    // mostrar el grafico
    system("cls");
    setColor(11);
    gotoxy(20, 2); cout << "*******************************";
    gotoxy(20, 3); cout << "*   Grafico por Vehiculo     *";
    gotoxy(20, 4); cout << "*******************************";
    setColor(14);
    gotoxy(22, 6); cout << "Veh. Sencillos: ";
    hacer_graficos(cantidadSencillos, 6);
    gotoxy(22, 7); cout << "Veh. 4x4: ";
    hacer_graficos(cantidad4x4, 7);
    gotoxy(22, 8); cout << "Veh. Pesados: ";
    hacer_graficos(cantidadMicrobus, 8);
    setColor(15);
    gotoxy(22, 10); cout << "<Pulse tecla para regresar al menu>";
    cin.ignore().get();  // esperar a que el usuario pulse una tecla
}

// funcion para ver grafico de vehiculos lavados por tipo de lavado
void verGraficoLavados() {
    int cantidadSoloLavado = 0, cantidadCompleto = 0;

    // recorrer el arreglo de vehiculos para calcular las cantidades
    for (int i = 0; i < numVehiculos; i++) {
        switch (vehiculos[i].tipoLavado) {
            case 1:
                cantidadSoloLavado++;
                break;
            case 2:
                cantidadCompleto++;
                break;
        }
    }

    // mostrar el grafico
    system("cls");
    setColor(11);
    gotoxy(20, 2); cout << "*******************************";
    gotoxy(20, 3); cout << "*   Grafico por Lavado       *";
    gotoxy(20, 4); cout << "*******************************";
    setColor(14);
    gotoxy(22, 6); cout << "Sencillo: ";
    hacer_graficos(cantidadSoloLavado, 6);
    gotoxy(22, 7); cout << "Completo: ";
    hacer_graficos(cantidadCompleto, 7);
    setColor(15);
    gotoxy(22, 9); cout << "<Pulse tecla para regresar al menu>";
    cin.ignore().get();  // esperar a que el usuario pulse una tecla
}

// funcion para hacer los graficos
void hacer_graficos(int a, int y) {
    int i;
    int j = 40;
    for (i = 1; i <= a; i++) {
        gotoxy(j, y);
        printf("%c", 178);
        j++;
    }
}

int main(int argc, char** argv) {
	return 0;
}
