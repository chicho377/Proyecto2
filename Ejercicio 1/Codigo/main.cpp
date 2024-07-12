#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <conio.h>
#include <windows.h>

using namespace std;

// constantes
const int ANIO_ACTUAL = 2024;
const int MAX_ESTUDIANTES = 100;

// estructura para almacenar los datos del estudiante
struct Estudiante {
    string cedula;
    string nombre;
    int anioNacimiento;
    float promedioMatematicas;
    float promedioEspanol;
    float promedioCiencias;
    float promedioEstudiosSociales;
    float notaExamen;
    int edad;
    float promedioColegio;
    float porcentajeCriterioColegio;
    float porcentajeExamenAdmision;
    float promedioAdmision;
    string calificacion;
};

// variables globales
Estudiante estudiantes[MAX_ESTUDIANTES];
int cantidadEstudiantes = 0;

// prototipos funciones y procedimientos
void mostrarMenu();
void ingresarDatos();
void mostrarEstadisticas();
void mostrarGrafico();
void calcularDatosEstudiante(Estudiante &est);
string obtenerCalificacion(float promedioAdmision);
void gotoxy(int x, int y);
void setColor(int color);
void hacerGraficos(int cantidad, int y);

// implementacion de las funciones y procedimientos
void mostrarMenu() {
    int opcion;
    do {
        system("cls");
        setColor(11); // Color Aqua
        gotoxy(10, 2); cout << "Menu Principal";
        gotoxy(10, 4); cout << "1) Ingresar Datos";
        gotoxy(10, 5); cout << "2) Estadisticas";
        gotoxy(10, 6); cout << "3) Grafico";
        gotoxy(10, 7); cout << "4) Salir";
        gotoxy(10, 9); cout << "Ingrese su Opcion: ";
        setColor(7); // Color Blanco
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatos();
                break;
            case 2:
                mostrarEstadisticas();
                break;
            case 3:
                mostrarGrafico();
                break;
            case 4:
                gotoxy(10, 11); cout << "Saliendo...\n";
                break;
            default:
                gotoxy(10, 11); cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void ingresarDatos() {
    char continuar;
    do {
        if (cantidadEstudiantes >= MAX_ESTUDIANTES) {
            gotoxy(10, 11); cout << "Se ha alcanzado el limite maximo de estudiantes.\n";
            break;
        }

        Estudiante &est = estudiantes[cantidadEstudiantes];
        gotoxy(10, 11); cout << "Ingrese la cedula del estudiante: ";
        cin >> est.cedula;
        gotoxy(10, 12); cout << "Ingrese el nombre del estudiante: ";
        cin.ignore();
        getline(cin, est.nombre);
        gotoxy(10, 13); cout << "Ingrese el anio de nacimiento del estudiante: ";
        cin >> est.anioNacimiento;
        gotoxy(10, 14); cout << "Ingrese el promedio final de Matematicas: ";
        cin >> est.promedioMatematicas;
        gotoxy(10, 15); cout << "Ingrese el promedio final de Espanol: ";
        cin >> est.promedioEspanol;
        gotoxy(10, 16); cout << "Ingrese el promedio final de Ciencias: ";
        cin >> est.promedioCiencias;
        gotoxy(10, 17); cout << "Ingrese el promedio final de Estudios Sociales: ";
        cin >> est.promedioEstudiosSociales;
        gotoxy(10, 18); cout << "Ingrese la nota del examen de admision: ";
        cin >> est.notaExamen;

        calcularDatosEstudiante(est);
        cantidadEstudiantes++;

        gotoxy(10, 19); cout << "Datos del estudiante ingresados correctamente.\n";
        gotoxy(10, 20); cout << "Desea continuar (S/N)? ";
        cin >> continuar;

        // Limpiar el buffer de entrada para evitar problemas con getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (continuar == 'S' || continuar == 's');
}

int main(int argc, char** argv) {
	return 0;
}
