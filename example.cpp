#include <iostream>
using namespace std;

// Función para calcular la altura
double calcularAltura(int edad, bool es_niña) {
  // Definir los intervalos de altura para niñas y niños
  double alturas_niña[] = {59, 65,    70,     74,     77,     80.5,  86,
                           95, 99.14, 105.95, 112.22, 117.27, 122.62};
  double alturas_niño[] = {60,   65,     72,    76,     79,    82.5,  88,
                           96.5, 100.13, 106.4, 112.77, 118.5, 122.86};

  // Determinar el vector de alturas a utilizar
  // Esto es un "if" elegante para elegir el vector de alturas según el género
  // Se lee como "si es_niña entonces utilizar alturas_niña, sino utilizar
  // alturas_niño" Porque double*? : Porque el vector de alturas es un puntero a
  // double y que sea puntero significa que puede apuntar a cualquier dirección
  // de memoria
  double *alturas = (es_niña) ? alturas_niña : alturas_niño;

  // Calcular la altura correspondiente a la edad
  if (edad < 3) {
    return 50.3; // Si es menor de 3 años, la altura es fija
  } else if (edad <= 96) {
    int indice = (edad - 3) /
                 3; // Calcular el índice correspondiente al intervalo de edad
    return alturas[indice]; // Devolver la altura correspondiente al índice
  } else {
    return alturas[12]; // Si la edad supera los 96 años, devolver la altura
                        // máxima
  }
}

int main() {
  int edad, n1;
  cout << "Menciona si es 1. niña. 2. niño\n";
  cin >> n1;
  cout << "Menciona la edad de tu hijo en años\n";
  cin >> edad;

  // Determinar si es niña o niño
  bool es_niña = (n1 == 1);

  // Calcular y mostrar la altura
  double altura = calcularAltura(edad, es_niña);
  cout << ((es_niña) ? "La niña mide " : "El niño mide ") << altura << " cm"
       << endl;

  return 0;
}
