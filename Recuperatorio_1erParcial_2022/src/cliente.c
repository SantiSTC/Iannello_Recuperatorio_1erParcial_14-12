/*
 * cliente.c
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#include "cliente.h"

eCliente CargarCliente()
{
	eCliente unCliente;

	unCliente.id = ObtenerIdAutoIncremental();
	unCliente.dni = PedirDNI();
	PedirString("Ingrese el nombre del cliente: ", unCliente.nombre);
	PedirString("Ingrese el apellido del cliente: ", unCliente.apellido);

	unCliente.estado = OCUPADO;

	return unCliente;
}

int BuscarEspacio(eCliente listaClientes[], int sizeClientes)
{
	int index = -1;

	for(int i = 0; i < sizeClientes; i++)
	{
		if(listaClientes[i].estado == LIBRE)
	    {
			index = i;
	        break;
	    }
	}

	return index;
}

int CargarListaClientes(eCliente listaClientes[], int sizeClientes)
{
	int index;

	index = BuscarEspacio(listaClientes, sizeClientes);

	if(index > -1)
	{
		listaClientes[index] = CargarCliente();
	}

	return index;
}

void MostrarUnCliente(eCliente unCliente)
{
	printf("| %-3d| %-9d | %-12s | %-14s |\n", unCliente.id, unCliente.dni, unCliente.nombre, unCliente.apellido);
}

int MostrarListaClientes(eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;

	printf("==================================================\n"
			"| ID |    DNI    |    Nombre    |    Apellido    |\n"
			"==================================================\n");

	for(int i=0; i<sizeClientes; i++)
	{
		if(listaClientes[i].estado == OCUPADO)
		{
			MostrarUnCliente(listaClientes[i]);
			retorno = 1;
		}
	}

	printf("==================================================\n");

	return retorno;
}

int ModificarCliente(eCliente listaClientes[], int sizeClientes)
{
	int idCliente;
	int opcion = 0;

	MostrarListaClientes(listaClientes, sizeClientes);
	idCliente = PedirID();

	for(int i=0; i<sizeClientes; i++)
	{
		if(listaClientes[i].id == idCliente)
		{
			opcion = MenuModificacion();

			switch(opcion)
			{
				case 1:
					PedirString("Ingrese el nuevo nombre del cliente: ", listaClientes[i].nombre);
				break;
				case 2:
					PedirString("Ingrese el nuevo apellido del cliente: ", listaClientes[i].apellido);
				break;
			}
		}
	}

	return opcion;
}

int EliminarCliente(eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int idCliente;

	MostrarListaClientes(listaClientes, sizeClientes);
	idCliente = PedirID();

	for(int i=0; i<sizeClientes; i++)
	{
		if(listaClientes[i].id == idCliente)
		{
			listaClientes[i].estado = LIBRE;
			retorno = 1;
		}
	}

	return retorno;
}

int PedirIdCliente(eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	int id;

	MostrarListaClientes(listaClientes, sizeClientes);
	id = PedirID();

	for(int i=0; i<sizeClientes; i++)
	{
		if(id == listaClientes[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;
}

void InicializarClientes(eCliente listaClientes[], int sizeClientes)
{
	int index;

	index = BuscarEspacio(listaClientes, sizeClientes);
	for(int i=0; i<sizeClientes; i++)
	{
		if(index != -1)
		{
			listaClientes[i].estado = LIBRE;
		}
	}
}

int PedirDNI()
{
	int unEntero;

	printf("Ingrese un DNI: ");
	scanf("%d", &unEntero);

	while(isdigit(unEntero) != 0 || unEntero > 99999999)
	{
		printf("ERROR, Ingrese un DNI valido\n");
		fflush(stdin);
		scanf("%d", &unEntero);
	}

	return unEntero;
}






