/*
 * recogida.cpp
 *
 *  Created on: 14/11/2013
 *      Author: David
 */

#include "recogida.h"

precogida :: precogida () {
   id = -1;
   distancia =-1;
   visitado = false;
};

precogida :: precogida (int x, float d) {
   id = x;
   distancia = d;
};

int precogida :: getid () {
   return id;
};

float precogida :: getdistancia () {
   return distancia;
};

precogida :: precogida (const precogida &p) {
   id = p.id;
   distancia = p.distancia;
};

void precogida :: setid (int iid) {
   id = iid;
};

void precogida :: setdistancia (float o) {
   distancia = o;
};

void precogida :: setvisitado() {
   visitado = true;
};

bool precogida :: check_visitado() {
   return visitado;
};

bool precogida :: operator < (precogida p) const {
   if (distancia < p.getdistancia())
      return true;
   return false;
};

tvehiculo :: tvehiculo () {
   id = -1;
   ut = 0;
   ua = 0;
   coste = 0.0;
   visitados.push_back(0);
};

tvehiculo :: tvehiculo (int i, int uut) {
   id = i;
   ut = uut;
   ua = 0;
   visitados.push_back(0);
};

void tvehiculo :: insertar (int i) {
   visitados.push_back(i);
};

void tvehiculo :: impr_recorrido () {
   cout << "Recorrido del vehiculo "<< id << ": " << endl;
   for (list<int> :: iterator it = visitados.begin(); it != visitados.end(); it++)
      cout << "-" << (*it);
   cout << endl << endl;
};

int tvehiculo :: getid() {
   return id;
};

int tvehiculo :: getcarga_actual () {
   return ua;
};

int tvehiculo :: getcarga_max () {
   return ut;
};

void tvehiculo :: sumar_carga (int cg) {
   ua += cg;
};

void tvehiculo :: sumar_coste (float cost) {
   coste+=cost;
};

float tvehiculo :: get_coste () {
   return coste;
};

mdistancia :: mdistancia () {
   N = 0;
};

mdistancia :: mdistancia (int n) {
  N = n;
  vector<precogida> aux;
  precogida dummy;
  for (int i = 0; i < N; i++)
    aux.push_back(dummy);
  for (int i = 0; i < N; i++)
    md.push_back(aux);
};

mdistancia :: mdistancia (string nombre) {
   ifstream fich(nombre.c_str());
   fich >> N;
   vector<precogida> aux;
   precogida dummy;
   for (int i = 0; i < N; i++)
     aux.push_back(dummy);
   for (int i = 0; i < N; i++)
     md.push_back(aux);
   //fin de la inicializacion de la matriz
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        float dist;
        fich >> dist;
        md[i][j].setdistancia(dist);
        md[i][j].setid(j);
      };
};

int mdistancia :: getsize() {
   return N;
};

precogida mdistancia :: get(int i, int j) {
   return md[i][j];
};

void mdistancia :: ordenar_matriz() {
   for (int i = 0; i < N; i++) {
      std :: sort(md[i].begin(), md[i].end());
   }
};

void mdistancia :: imprimir() {
   for (int i = 0; i < N; i++) {
     for(int j=0;j < N; j++)
       cout << md[i][j].getdistancia() << "	";
   cout << endl;
   }
   cout << "------------------" << endl;
};

void mdistancia :: set_visitados(int i) {
   for (int j = 0; j < N; j++)
      md[i][j].setvisitado();
};

/*
ruta :: ruta() {
   mdistancia aux("entrada.txt");
   mraw = aux;
   mord = aux;
   mord.ordenar_matriz();
   insertar_visitado(0);
};

precogida ruta :: candidatos (int i) { // dado un punto buscamos los 3 mas cercanos que no hayan sido visitados ya, para poder seleccionar uno de forma aleatoria
   //srand(time(NULL));
   //srand(3);
   vector<precogida> tresmenores;
   int cuenta = 0;
   int j = 0;
   while (cuenta != 3 && j < mord.getsize() && !fin_visitas()) {
      if (comprobar_visitado(mord.get(i,j).getid()) == false && mord.get(i,j).getdistancia() != 0) {
         tresmenores.push_back(mord.get(i,j));
         cuenta++;
      }
      j++;
   };
   int indice = rand()% tresmenores.size(); // puede ser que en vez de 3 puntos tengamos dos o 1
   cout << "indice original: " << i << "," << tresmenores[indice].getid() << endl;
   cout << "distancia: " << tresmenores[indice].getdistancia() << endl;
   insertar_visitado(tresmenores[indice].getid());
   return tresmenores[indice];
};

void ruta :: buscar (tvehiculo &v, int media) {
   int cont = 0;
   int siguiente = 0;
   float coste = 0.0;
   //int carga_actual = 0;
   precogida ret;
   while (cont < mord.getsize() && v.getcarga_actual()+media <= v.getcarga_max() && !fin_visitas()) {
      //precogida ret;
      ret = candidatos(siguiente);
      cout << "----------->siguiente: " << ret.getid() << endl;
      cont++;
      //coste+= ret.getdistancia();
      v.sumar_coste(ret.getdistancia());
      siguiente = ret.getid();
      //carga_actual += media;
      v.insertar(siguiente);
      v.sumar_carga(media);
   }
   v.sumar_coste(getdistanciaij(ret.getid(),0)); //añadimos el coste de ir desde el ultimo punto hasta el origen
   v.insertar(0); //añadimos al recorrido del vehiculo la vuelta al origen
   cout << "distancia del ultimo punto al origen: " << getdistanciaij(ret.getid(),0) << endl;
   cout << "ultimo punto: " << ret.getid() << endl;
   cout << "cuenta: " << cont << endl;
   cout << "coste total: " << v.get_coste() << endl;
   cout << "carga: " << v.getcarga_actual() << endl;
   //v.impr_recorrido();
   cout << "Puntos totales visitados: " << endl;
   for (list<int> :: iterator it = visitados.begin(); it != visitados.end(); it++)
      cout << " " << (*it);
   cout << endl << "----------------" << endl;
};
*/

//eliminar de la matriz auxiliar o inutilizar los elementos ya visitados -- De todas formas tienes que recorrer la fila entera para identificar los utiles.

//insertar en un vector auxiliar los elementos no visitados y ordenarlos

ruta :: ruta() {
   mdistancia aux("entrada.txt");
   mraw = aux;
   mord = aux;    //nn
   //mord.ordenar_matriz();
   insertar_visitado(0);
};

vector<precogida> ruta :: ordenar_fila (int i) {
   vector<precogida> candidatos;
   int j = 0;
   while (j < mord.getsize() && !fin_visitas()) {
      if (!comprobar_visitado(mord.get(i,j).getid()) && mord.get(i,j).getdistancia() != 0)
         candidatos.push_back(mord.get(i,j));
      j++;
   }
   std :: sort(candidatos.begin(), candidatos.end());
   return candidatos;
};

precogida ruta :: candidatos (int i) { // dado un punto buscamos los 3 mas cercanos que no hayan sido visitados ya, para poder seleccionar uno de forma aleatoria
   vector <precogida> candidatos = ordenar_fila(i);
   int indice = 0;
   if (candidatos.size() >= 3)
      indice = rand()% 3;
   else
      indice = rand()% candidatos.size(); // puede ser que en vez de 3 puntos tengamos dos o 1
   cout << "indice original: " << i << "," << candidatos[indice].getid() << endl;
   cout << "distancia: " << candidatos[indice].getdistancia() << endl;
   insertar_visitado(candidatos[indice].getid());
   return candidatos[indice];
};

void ruta :: buscar (tvehiculo &v, int media) {
   int cont = 0;
   int siguiente = 0;
   float coste = 0.0;
   precogida ret;
   while (cont < mord.getsize() && v.getcarga_actual()+media <= v.getcarga_max() && !fin_visitas()) {
      //precogida ret;
      ret = candidatos(siguiente);
      cout << "----------->siguiente: " << ret.getid() << endl;
      cont++;
      v.sumar_coste(ret.getdistancia());
      siguiente = ret.getid();
      v.insertar(siguiente);
      v.sumar_carga(media);
   }
   v.sumar_coste(getdistanciaij(ret.getid(),0)); //añadimos el coste de ir desde el ultimo punto hasta el origen
   v.insertar(0); //añadimos al recorrido del vehiculo la vuelta al origen
   cout << "distancia del ultimo punto al origen: " << getdistanciaij(ret.getid(),0) << endl;
   cout << "ultimo punto: " << ret.getid() << endl;
   cout << "cuenta: " << cont << endl;
   cout << "coste total: " << v.get_coste() << endl;
   cout << "carga: " << v.getcarga_actual() << endl;
   //v.impr_recorrido();
   cout << "Puntos totales visitados: " << endl;
   for (list<int> :: iterator it = visitados.begin(); it != visitados.end(); it++)
      cout << " " << (*it);
   cout << endl << "----------------" << endl;
};


void ruta :: insertar_visitado (int i) {
   visitados.push_back(i);
};

bool ruta :: comprobar_visitado (int i) {
  for (list<int> :: iterator it = visitados.begin(); it != visitados.end(); it++)
     if (i == (*it))
        return true;
   return false;
};

bool ruta :: fin_visitas () {
   if (visitados.size() == mraw.getsize())
      return true;
   return false;
};

float ruta :: getdistanciaij (int i, int j) {
   precogida ret = mraw.get(i,j); //recuperamos el punto ij de la matriz sin alterar
   return ret.getdistancia(); //devolvemos la distancia de un punto a otro
};

resolver :: resolver () {
  for (int i = 0; i < 4; i++) {
     tvehiculo vec(i,15+i);
     vehiculos.push_back(vec);
  }
  coste_total = 0;
  cmed = 6;
};

void resolver :: ejecutar() {
   for (int i = 0; i < vehiculos.size(); i++) {
      rt.buscar(vehiculos[i],cmed);
      coste_total+=vehiculos[i].get_coste();
   }
};

int resolver :: get_coste_total() {
   return coste_total;
};

void optimo :: repetir (int n) {
   menor.ejecutar();
   struct timeval inicio, fin;
   for (int i = 0;i < n; i++) {
      gettimeofday(&inicio, NULL);
      cout << endl << endl << endl;
      resolver sol;
      sol.ejecutar();
      cout << "Sol->getcoste... " << sol.get_coste_total() << " VS " << menor.get_coste_total() << endl;
      if (sol.get_coste_total() < menor.get_coste_total()) {
	 cout << "=00000000mejor" << endl;
         menor = sol;
      }
      gettimeofday(&fin, NULL);
      cout << "Duracion del calculo: " << ((fin.tv_sec+(float)fin.tv_usec/1000000)-(inicio.tv_sec+(float)inicio.tv_usec/1000000)) << endl;
   };
   cout << "El mejor: " << menor.get_coste_total() << endl;
};

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
   punto_solomon punto;
   ifstream fich(nombre.c_str()); //comprobar cómo actúa con los enter, con las líneas enter vacías y cómo saltar de línea sin que ésta haya terminado
   int aux, auxil;
   aux = getNextLine(); //lee la primera línea, el nombre del fichero
   aux = getNextLine(); //lee VEHICLE
   do { //lee NUMBER CAPACITY
      aux = getNextLine(); //tengo el include de getnextline?
      if (aux != 0)
         break;
      aux = compareNoCase("NUMBER"); //tengo el include de comparenocase?
      if (aux != 0)
         break;
      aux = compareNoCase("CAPACITY");
         break;
   }
   while (false);
   aux = getNextLine();
   aux = getInteger(ncamiones); //comprobar que funciona eso
   aux = getInteger(capacidadcamiones); //idem
   do {
      aux = getNextLine();
      if (aux != 0)
         break;
      aux = compareNoCase("CUST");
      if (aux != 0)
         break;
      aux = compareNoCase("NO.");
      if (aux != 0)
         break;
      aux = compareNoCase("XCOORD.");
      if (aux != 0)
         break;
      aux = compareNoCase("YCOORD.");
      if (aux != 0)
         break;
      aux = compareNoCase("DEMAND");
      if (aux != 0)
         break;
      aux = compareNoCase("READY");
      if (aux != 0)
         break;
      aux = compareNoCase("TIME");
      if (aux != 0)
         break;
      aux = compareNoCase("DUE");
      if (aux != 0)
         break;
      aux = compareNoCase("DATE");
      if (aux != 0)
         break;
      aux = compareNoCase("SERVICE");
      if (aux != 0)
         break;
      aux = compareNoCase("TIME");
      if (aux != 0)
         break;
   }
   while (false);
   do
   {
      aux = getNextLine(); //lee fila de datos
      if (aux != 0) {
         aux = 0;
         break;
      }
      aux = getInteger(auxil); //lee id del cliente
      punto.setid(auxil);
      if (aux != 0)
         break;
      nclientes++;
      aux = getInteger(auxil); //lee coordenada x
      punto.setx(auxil);
      if (xmin > auxil)
         xmin = auxil;
      else if (xmax < auxil)
         xmax = auxil;
      if (aux != 0)
         break;
      aux = getInteger(auxil); //lee coordenada y
      punto.sety(auxil);
      if (ymin > auxil)
         ymin = auxil;
      else if (ymax < auxil)
         ymax = auxil;
      if (aux != 0)
         break;
      aux = getInteger(auxil); //lee demanda
      punto.setdemanda(auxil);
      if (aux != 0)
         break;
      aux = getInteger(auxil); //lee demanda
      punto.setrtime(auxil);
      if (aux != 0)
         break;
      aux = getInteger(auxil); //lee demanda
      punto.setddate(auxil);
      if (aux != 0)
         break;
      aux = getInteger(auxil); //lee demanda
      punto.setservtime(auxil);
      if (aux != 0)
         break;
      listado.push_back(punto);
   }
   while (true);
};

/*
Adaptar a mi código, en la clase solomon como operación
int InstanceData::getNextLine(int *piLineLength)
{
        int iLineLength;

        do
        {
                iLineLength = 0;
                m_pLinePos = m_pDataPos; //almacena la dirección de memoria en la que comienza el fichero de datos

                while (m_pDataPos < m_pDataEnd) //m_pDataPos inicialmente contiene la posición en la que comienza el fichero de datos
                { //m_pDataEnd almacena la posición de memoria en la que termina el fichero
                  //mientras no termine el fichero
                        if (*m_pDataPos == '\r') //si se encuentra al principio de una línea (\r es retorno de carro)
                        {
                                m_iLine++; //almacena el número de línea, inicializado a 1, en la primera iteración se incrementará a 2
                                m_pDataPos++; //incrementa la posición de memoria

                                if (m_pDataPos < m_pDataEnd) //si tras incrementar sigue sin ser el final del fichero
                                {
                                        if (*m_pDataPos == '\n') //si es el final de una línea
                                                m_pDataPos++;    //incrementa la posición de memoria
                                }

                                break;
                        }
                        else if (*m_pDataPos == '\n') //si es el final de una línea
                        {
                                m_iLine++;  //incrementar el número de línea
                                m_pDataPos++; //incrementar la posición de memoria
                                break;
                        }

                        iLineLength++; //se va incremenando, aparentemente tamaño de la línea
                        //dado que se inicializa a 0, parece utilizarse para indicar si una línea está vacía o no
                        //si vale 0, saltarse esa línea (más abajo)
                        m_pDataPos++; //incrementa la posicion de memoria
                }

                // skip empty lines
                while (iLineLength) //si vale 0, se sale del while
                {
                        switch (m_pLinePos[iLineLength-1])
                        {
                        case ' ': //si es un espacio
                        case '\t': //o es un tabulador
                                iLineLength--; //restarle uno al tamaño de la línea
                                continue; //volver a comprobar si queda algo en la línea

                        default: //si hay algo distinto de espacio o tabulador, habrá texto
                                break; //salir del while
                        }

                        break;
                }

                if (iLineLength != 0) //si la línea no está vacía
                {
                        m_pLineEnd = m_pLinePos + iLineLength; //identificamos el final de la línea sumándole a la posición de la línea el tamaño de la misma

                        if (piLineLength != NULL) //este puntero se pasa por parámetro, si no apunta a null
                                *piLineLength = iLineLength; //almacenar en esa posición de memoria el tamaño de la línea

                        return 0; // line found
                }

                if (m_pDataPos == m_pDataEnd) //si esos dos valores son iguales
                {
                        m_pLinePos = NULL;
                        return 1; // end of file
                }

                // get next line
        }
        while (true);

        return 0;
}

*/


/*
Idem
int InstanceData::compareNoCase(char *szValue)
{
        int iLength;

        // skip white spaces
        while (m_pLinePos < m_pLineEnd)
        {
                switch (*m_pLinePos)
                {
                case ' ':
                case '\t':
                        m_pLinePos++;
                        continue;

                default:
                        break;
                }

                break;
        }

        // end of line?
        if (m_pLinePos == m_pLineEnd)
                return 1;

        iLength = strlen(szValue);

        if (iLength > (m_pLineEnd-m_pLinePos))
                return 1;

#if defined(WIN32) || defined(WIN64)

        if (strnicmp(m_pLinePos, szValue, iLength) != 0)
                return 1;

#else

        if (strncasecmp(m_pLinePos, szValue, iLength) != 0)
                return 1;

#endif

        m_pLinePos += iLength;

        return 0;
}


*/

/*

int main () {

   ruta rt;
   tvehiculo camion1 (1,20);
   tvehiculo camion2 (2,50);
   rt.buscar(camion1,6);
   rt.buscar(camion2,6);
   camion1.impr_recorrido();
   camion2.impr_recorrido();

   resolver res;
   res.ejecutar();
   cout << "**** coste total: " << res.get_coste_total() << endl;
   */
   /*
   optimo opt;
   opt.repetir(100);

   solomon sol("C102.txt");
};

*/

