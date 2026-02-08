#include <iostream>
#include <string>

using namespace std;
double calcularPromedio(double nota1, double nota2, double nota3) {
    return (nota1 + nota2 + nota3) / 3.0;
}
string determinarCondicion(double promedio) {
    if (promedio >= 60.0) return "APROBADO";
    return "REPROBADO";
}
int main() {
    double nota1, nota2, nota3;
    cout << "CALCULADORA DE PROMEDIO" << endl;
    cout << "Ingrese nota 1: ";
    cin >> nota1;
    cout << "Ingrese nota 2: ";
    cin >> nota2;
    cout << "Ingrese nota 3: ";
    cin >> nota3;
    if (nota1 < 0 || nota1 > 100 || nota2 < 0 || nota2 > 100 || nota3 < 0 || nota3 > 100) {
        cout << "Error: Notas deben ser 0-100" << endl;
        return 1;
    }
    double promedio = calcularPromedio(nota1, nota2, nota3);
    string condicion = determinarCondicion(promedio);
    cout << "\n RESULTADOS" << endl;
    cout << "Notas: " << nota1 << ", " << nota2 << ", " << nota3 << endl;
    cout << "Promedio: " << promedio << endl; 
    cout << "Condicion: " << condicion << endl;
    return 0;
}