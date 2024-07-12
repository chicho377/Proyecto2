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

int main(int argc, char** argv) {
	return 0;
}
