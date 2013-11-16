/*
 * solomon.h
 *
 *  Created on: 15/11/2013
 *      Author: David
 */
#include <iostream>
#include <vector>

using namespace std;

#ifndef SOLOMON_H_
#define SOLOMON_H_


class punto_solomon {
private:
   int id;
   int x;
   int y;
   int demanda;
   int rtime;
   int ddate;
   int servtime;
public:
   //constructor normal y con los parámetros
   punto_solomon ();
   punto_solomon (int aid, int ax, int ay, int ademanda, int artime, int addate, int aservtime);
   //getter y setter para todos
   void setid (int i);
   void setx (int i);
   void sety (int i);
   void setdemanda (int i);
   void setrtime (int i);
   void setddate (int i);
   void setservtime (int i);
   int getid ();
   int getx ();
   int gety ();
   int getdemanda ();
   int getrtime ();
   int getddate ();
   int setservtime ();
};

class solomon {
private:
   int ncamiones;
   int nclientes;
   int capacidadcamiones;
   vector <punto_solomon> listado;
   int xmin, xmax;
   int ymin, ymax;
public:
   solomon (); //inicializar a 0 los totales y los max y a 999 los mínimos
   //leer de fichero
   solomon (string nombre);
   //calcular distancia entre dos puntos

   //generar matriz de distancias -> pasar de vector de puntos_solomon a mdistancia

   //getter y setter de xmin,xmax,nclientes

   //mostrar todos los puntos
   void mostrarlistado();
   //mostrar un punto
   void mostrarpunto();
};

#endif /* SOLOMON_H_ */
