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

void calcularDatosEstudiante(Estudiante &est) {
    est.edad = ANIO_ACTUAL - est.anioNacimiento;
    est.promedioColegio = (est.promedioMatematicas + est.promedioEspanol + est.promedioCiencias + est.promedioEstudiosSociales) / 4.0;
    est.porcentajeCriterioColegio = est.promedioColegio * 0.40;
    est.porcentajeExamenAdmision = est.notaExamen * 0.60;
    est.promedioAdmision = est.porcentajeCriterioColegio + est.porcentajeExamenAdmision;
    est.calificacion = obtenerCalificacion(est.promedioAdmision);

    // Mostrar informacion del estudiante
    system("cls");
    setColor(14); // Color Amarillo
    gotoxy(10, 2); cout << "Informacion del Estudiante:";
    gotoxy(10, 4); cout << "Cedula: " << est.cedula;
    gotoxy(10, 5); cout << "Nombre: " << est.nombre;
    gotoxy(10, 6); cout << "Anio de Nacimiento: " << est.anioNacimiento;
    gotoxy(10, 7); cout << "Edad: " << est.edad;
    gotoxy(10, 8); cout << "Promedio de Colegio: " << fixed << setprecision(2) << est.promedioColegio;
    gotoxy(10, 9); cout << "Porcentaje Criterio Colegio: " << est.porcentajeCriterioColegio;
    gotoxy(10, 10); cout << "Porcentaje Examen Admision: " << est.porcentajeExamenAdmision;
    gotoxy(10, 11); cout << "Promedio Admision: " << est.promedioAdmision;
    gotoxy(10, 12); cout << "Calificacion: " << est.calificacion;
    setColor(7); // Color Blanco
    gotoxy(10, 14); cout << "Pulse cualquier tecla para continuar...";
    _getch();
}

string obtenerCalificacion(float promedioAdmision) {
    if (promedioAdmision >= 85) {
        return "Admitido";
    } else if (promedioAdmision >= 75) {
        return "En Espera";
    } else {
        return "No Admitido";
    }
}

void mostrarEstadisticas() {
    system("cls");
    int admitidos = 0, enEspera = 0, noAdmitidos = 0;
    float promedioAdmitidos = 0, promedioEnEspera = 0, promedioNoAdmitidos = 0;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        Estudiante &est = estudiantes[i];
        if (est.calificacion == "Admitido") {
            admitidos++;
            promedioAdmitidos += est.promedioAdmision;
        } else if (est.calificacion == "En Espera") {
            enEspera++;
            promedioEnEspera += est.promedioAdmision;
        } else if (est.calificacion == "No Admitido") {
            noAdmitidos++;
            promedioNoAdmitidos += est.promedioAdmision;
        }
    }

    if (admitidos > 0) promedioAdmitidos /= admitidos;
    if (enEspera > 0) promedioEnEspera /= enEspera;
    if (noAdmitidos > 0) promedioNoAdmitidos /= noAdmitidos;

    setColor(14); // Color Amarillo
    gotoxy(10, 2); cout << "Estadisticas:";
    gotoxy(10, 4); cout << "Cantidad Estudiantes Admitidos: " << admitidos;
    gotoxy(10, 5); cout << "Promedio Estudiantes Admitidos: " << fixed << setprecision(2) << promedioAdmitidos;
    gotoxy(10, 6); cout << "Cantidad Estudiantes En Espera: " << enEspera;
    gotoxy(10, 7); cout << "Promedio Estudiantes En Espera: " << promedioEnEspera;
    gotoxy(10, 8); cout << "Cantidad Estudiantes No Admitidos: " << noAdmitidos;
    gotoxy(10, 9); cout << "Promedio Estudiantes No Admitidos: " << promedioNoAdmitidos;
    setColor(7); // Color Blanco
    gotoxy(10, 11); cout << "Pulse cualquier tecla para continuar...";
    _getch();
}

void mostrarGrafico() {
    system("cls");
    int admitidos = 0, enEspera = 0, noAdmitidos = 0;

    // Contar cantidad de estudiantes en cada categoría
    for (int i = 0; i < cantidadEstudiantes; i++) {
        Estudiante &est = estudiantes[i];
        if (est.calificacion == "Admitido") {
            admitidos++;
        } else if (est.calificacion == "En Espera") {
            enEspera++;
        } else if (est.calificacion == "No Admitido") {
            noAdmitidos++;
        }
    }

    // Mostrar gráfico según cantidad de estudiantes en cada categoría
    setColor(11); // Color Aqua
    gotoxy(10, 2); cout << "Grafico Estudiantes segun Estado";
    setColor(10); // Color Verde
    gotoxy(10, 4); cout << "Admitidos: ";
    hacerGraficos(admitidos, 4);
    setColor(14); // Color Amarillo
    gotoxy(10, 5); cout << "En Espera: ";
    hacerGraficos(enEspera, 5);
    setColor(12); // Color Rojo
    gotoxy(7, 6); cout << "No Admitidos: ";
    hacerGraficos(noAdmitidos, 6);
    setColor(7); // Color Blanco
    gotoxy(10, 10); cout << "Pulse cualquier tecla para regresar al menu.";
    _getch();
}

void hacerGraficos(int cantidad, int y) {
    int j = 20;
    for (int i = 0; i < cantidad; i++) {
        gotoxy(j++, y);
        printf("%c", 178); // Carácter de bloque sólido en la consola
    }
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main(int argc, char** argv) {
	mostrarMenu();
	return 0;
}
