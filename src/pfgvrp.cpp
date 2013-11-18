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
    /*
	solomon sol("C102.txt");
	sol.mostrarlistado();
	//sol.mostrarpunto();
	sol.mostrarmatriz();
	sol.calcularmatriz();
	sol.mostrarmatriz();
	cout << "adios!!!" << endl;
	cin.get();
	return 0;
	*/

   //cout << "**** coste total: " << res.get_coste_total() << endl;
    //mdistancia matriz("entrada.txt");
	solomon sol("C102.txt");
	sol.calcularmatriz();
	sol.mostrarmatriz();
	mdistancia matriz;
	matriz = sol.convertir();
	cout << "aqui" << endl;
	matriz.imprimir();
	cin.get();
	optimo opt(matriz);
	opt.repetir(1);
	cin.get();


}
