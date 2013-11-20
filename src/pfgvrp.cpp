//============================================================================
// Name        : pfgvrp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "recogida.h"
#include "solomon.h"
using namespace std;

int main() {

   //cout << "**** coste total: " << res.get_coste_total() << endl;
	solomon sol("C102.txt");
	sol.mostrarlistado();
	sol.calcularmatriz();
	sol.mostrarmatriz();
	mdistancia matriz;
	matriz = sol.convertir();
	cout << "aqui" << endl;
	matriz.imprimir();
	cin.get();
	cout << "Hola" << endl;
	optimo opt(matriz);
	opt.repetir(1);


}
