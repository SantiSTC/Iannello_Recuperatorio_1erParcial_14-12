/*
 * inputs.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Santiago
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define LIBRE 0
#define OCUPADO 1

#define FINALIZADO 0
#define ALQUILADO 1

#define AMOLADORA 10
#define MEZCLADORA 11
#define TALADRO 12

int ObtenerIdAutoIncremental();
int MostrarMenu();
int ElegirOpcion(int max, int min);
int PedirID();
int PedirDia();
int PedirMes();
int PedirAnio();
void PedirString(char* mensaje, char* nombre);
int MenuModificacion();
int PedirEntero();
int PedirTiempo(char* mensaje);
int PedirEquipo();
int MenuInformes();


#endif /* INPUTS_H_ */
