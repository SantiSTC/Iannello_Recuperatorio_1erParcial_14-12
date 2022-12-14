/*
 * alquiler.h
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#ifndef ALQUILER_H_
#define ALQUILER_H_

#include "inputs.h"

typedef struct
{
	int id;
	int idCliente;
	int equipo;
	char operador[50];
	int tiempoEstimado;
	int tiempoReal;
	int estadoAlquiler;
	int estadoLista;
}eAlquiler;

int ObtenerIdAutoIncrementalAlquiler();
int BuscarEspacioAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres);
void InicializarAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres);
int InformarEquipoMasAlquilado(eAlquiler listaAlquileres[], int sizeAlquileres);
int InformarTiempoPromedioRealDeAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres);


#endif /* ALQUILER_H_ */
