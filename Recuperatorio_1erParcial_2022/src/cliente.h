/*
 * cliente.h
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "inputs.h"

typedef struct
{
	int id;
	int dni;
	char nombre[50];
	char apellido[50];
	int estado;
}eCliente;

eCliente CargarCliente();
int BuscarEspacio(eCliente listaClientes[], int sizeClientes);
int CargarListaClientes(eCliente listaClientes[], int sizeClientes);
void MostrarUnCliente(eCliente unCliente);
int MostrarListaClientes(eCliente listaClientes[], int sizeClientes);
int ModificarCliente(eCliente listaClientes[], int sizeClientes);
int EliminarCliente(eCliente listaClientes[], int sizeClientes);
int PedirIdCliente(eCliente listaClientes[], int sizeClientes);
void InicializarClientes(eCliente listaClientes[], int sizeClientes);
int PedirDNI();

#endif /* CLIENTE_H_ */
