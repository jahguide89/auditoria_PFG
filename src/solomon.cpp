/*
 * solomon.cpp
 *
 *  Created on: 15/11/2013
 *      Author: David
 */

#include "solomon.h"
#include <fstream>
#include <vector>

punto_solomon :: punto_solomon () {
   id = 0;
   x = 0;
   y = 0;
   demanda = 0;
   rtime = 0;
   ddate = 0;
   servtime = 0;
};

punto_solomon :: punto_solomon (int aid, int ax, int ay, int ademanda, int artime, int addate, int aservtime) {
   id = aid;
   x = ax;
   y = ay;
   demanda = ademanda;
   rtime = artime;
   ddate = addate;
   servtime = aservtime;
};

void punto_solomon :: setid (int i) {
   id = i;
};

void punto_solomon :: setx (int i) {
   x = i;
};

void punto_solomon :: sety (int i) {
   y = i;
};

void punto_solomon :: setdemanda (int i) {
   demanda = i;
};

void punto_solomon :: setrtime (int i) {
   rtime = i;
};

void punto_solomon :: setddate (int i) {
   ddate = i;
};

void punto_solomon :: setservtime (int i) {
   servtime = i;
};

int punto_solomon :: getid () {
   return id;
};

int punto_solomon :: getx () {
   return x;
};

int punto_solomon :: gety () {
   return y;
};

int punto_solomon :: getdemanda () {
   return demanda;
};

int punto_solomon :: getrtime () {
   return rtime;
};

int punto_solomon :: getddate () {
   return ddate;
};

int punto_solomon :: setservtime () {
   return servtime;
};

solomon :: solomon () {
   ncamiones = 0;
   nclientes = 0;
   capacidadcamiones = 0;
   xmin = 9999;
   xmax = 0;
   ymin = 9999;
   ymax = 0;
};

//getNextLine no devuelve nada, devuelve 1 si es el final del fichero, sino devuelve 0
//simplemente comprueba que no se haya acabado el fichero
//
solomon :: solomon (string nombre) {
   ifstream file(nombre.c_str());
   string aux;
   for (int i = 0; i < 4; i++) //saltamos las 4 primeras palabras
      file >> aux;
   file >> ncamiones;
   file >> capacidadcamiones;
   for (int i = 0; i < 12; i++)//saltamos las siguientes 12 palabras
       file >> aux;
   //empezamos a leer todos los numeros
   while (!file.eof()) { //saltamos las siguientes 12 palabras
      int num;
      punto_solomon p;
      file >> num;
      p.setid(num);
      file >> num;
      p.setx(num);
      file >> num;
      p.sety(num);
      file >> num;
      p.setdemanda(num);
      file >> num;
      p.setrtime(num);
      file >> num;
      p.setddate(num);
      file >> num;
      p.setservtime(num);
      listado.push_back(p);
   }
   file.close();
   vector <int> dummy;
   for (unsigned int i = 0; i < listado.size(); i++)
	   dummy.push_back(-1);
   for (unsigned int i = 0; i < listado.size(); i++)
	   matriz.push_back(dummy);

};

void solomon :: mostrarmatriz () {
	for (unsigned int i = 0; i < matriz.size(); i++) {
		for (unsigned int j = 0; j < matriz.size(); j++)
           cout << matriz[i][j];
        cout << endl;
	}
}

void solomon :: mostrarlistado () {
   cout << "Numero de camiones: " << ncamiones << endl;
   cout << "Capacidad de camiones: " << capacidadcamiones << endl;
   for (unsigned int i = 0; i < listado.size(); i++) {
	   cout << "X: " << listado[i].getx() << ", Y: " << listado[i].gety() << endl;
   }

};

void solomon :: mostrarpunto () {
   cout << "id: " << listado[1].getid() << endl;
   cout << "x: " << listado[1].getx() << endl;
   cout << "y: " << listado[1].gety() << endl;
};

