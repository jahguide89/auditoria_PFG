
#include <iostream>
#include "recogida.h"
#include "solomon.h"
using namespace std;

int main(int argc, char  *argv[]) {
	cout << argc << endl;
	cout << argv[1] << endl;
	solomon sol(argv[1]);
	sol.mostrarlistado();
	sol.calcularmatriz();
	mdistancia matriz;
	matriz = sol.convertir();
	optimo opt(matriz);
	opt.repetir(100,';');
	cin.get();
}
