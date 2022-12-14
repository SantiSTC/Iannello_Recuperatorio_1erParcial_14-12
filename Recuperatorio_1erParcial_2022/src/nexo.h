/*
 * nexo.h
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "alquiler.h"
#include "cliente.h"
#include "inputs.h"

eAlquiler CargarAlquiler(eCliente listaClientes[], int sizeClientes);
int CargarListaAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
void MostrarUnAlquiler(eAlquiler unAlquiler, eCliente listaClientes[], int sizeClientes);
int MostrarListaAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int PedirIdAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int FinalizarAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int InformarElClienteConMasAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int MostrarListaAlquileresEnCurso(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int PedirIdAlquilerEnCurso(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);
int InformarClientesConSusAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes);

#endif /* NEXO_H_ */
