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
	cout << "ejecucion" << endl;
	solomon sol("C102.txt");
	sol.mostrarlistado();
	//sol.mostrarpunto();
	cout << "adios" << endl;
	cin.get();
	cin.get();
	return 0;
}
