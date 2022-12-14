/*
 * nexo.c
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#include "nexo.h"

eAlquiler CargarAlquiler(eCliente listaClientes[], int sizeClientes)
{
	eAlquiler unAlquiler;

	unAlquiler.id = ObtenerIdAutoIncrementalAlquiler();
	unAlquiler.idCliente = PedirIdCliente(listaClientes, sizeClientes);
	unAlquiler.equipo = PedirEquipo();
	unAlquiler.tiempoEstimado = PedirTiempo("Ingrese el tiempo estimado de alquiler (en dias): ");
	PedirString("Ingrese el nombre del operador: ", unAlquiler.operador);

	unAlquiler.estadoAlquiler = ALQUILADO;
	unAlquiler.estadoLista = OCUPADO;

	return unAlquiler;
}

int CargarListaAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int index;

	index = BuscarEspacioAlquiler(listaAlquileres, sizeAlquileres);

	if(index > -1)
	{
		listaAlquileres[index] = CargarAlquiler(listaClientes, sizeClientes);
	}

	return index;
}

void MostrarUnAlquiler(eAlquiler unAlquiler, eCliente listaClientes[], int sizeClientes)
{
	for(int i=0; i<sizeClientes; i++)
	{
		if(listaClientes[i].id == unAlquiler.idCliente)
		{
			if(unAlquiler.estadoAlquiler == FINALIZADO)
			{
				printf("| %-3d| %-11s | %-9d | %-10s | %-11d | %-7d | FINALIZADO |\n", unAlquiler.id, listaClientes[i].apellido, unAlquiler.equipo, unAlquiler.operador, unAlquiler.tiempoEstimado, unAlquiler.tiempoReal);
			}
			else
			{
				printf("| %-3d| %-11s | %-9d | %-10s | %-11d |    -    | ALQUILADO  |\n", unAlquiler.id, listaClientes[i].apellido, unAlquiler.equipo, unAlquiler.operador, unAlquiler.tiempoEstimado);
			}



		}
	}
}

int MostrarListaAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;

	printf("==================================================================================\n"
			"| ID |   Cliente   | ID Equipo |  Operador  | T. Estimado | T. Real |   Estado   |\n"
			"=================================================================================\n");

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(listaAlquileres[i].estadoLista == OCUPADO)
		{
			MostrarUnAlquiler(listaAlquileres[i], listaClientes, sizeClientes);
		}
	}

	printf("=================================================================================\n");

	return retorno;
}

int MostrarListaAlquileresEnCurso(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;

	printf("==================================================================================\n"
			"| ID |   Cliente   | ID Equipo |  Operador  | T. Estimado | T. Real |   Estado   |\n"
			"=================================================================================\n");

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(listaAlquileres[i].estadoLista == OCUPADO && listaAlquileres[i].estadoAlquiler == ALQUILADO)
		{
			MostrarUnAlquiler(listaAlquileres[i], listaClientes, sizeClientes);
		}
	}

	printf("=================================================================================\n");

	return retorno;
}


int PedirIdAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	int id;

	MostrarListaAlquileres(listaAlquileres, sizeAlquileres, listaClientes, sizeClientes);
	id = PedirID();

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(id == listaAlquileres[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;
}

int PedirIdAlquilerEnCurso(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	int id;

	MostrarListaAlquileresEnCurso(listaAlquileres, sizeAlquileres, listaClientes, sizeClientes);
	id = PedirID();

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(id == listaAlquileres[i].id)
		{
			retorno = id;
			break;
		}
	}

	return retorno;
}

int FinalizarAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno;
	int idAlquiler;

	idAlquiler = PedirIdAlquilerEnCurso(listaAlquileres, sizeAlquileres, listaClientes, sizeClientes);

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(listaAlquileres[i].id == idAlquiler)
		{
			listaAlquileres[i].tiempoReal = PedirTiempo("Ingrese el tiempo real de alquiler (en dias): ");
			listaAlquileres[i].estadoAlquiler = FINALIZADO;
			retorno = 1;
		}
	}


	return retorno;
}

int InformarElClienteConMasAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;
	int contador = 0;
	int contador2 = 0;
	int mayor = 0;

	for(int i=0; i<sizeClientes; i++)
	{
		contador = 0;

		for(int j=0; j<sizeAlquileres; j++)
		{
			if(listaAlquileres[j].idCliente == listaClientes[i].id)
			{
				contador++;
			}
		}

		if(contador > mayor)
		{
			mayor = contador;
		}
	}

	printf("==================================================\n"
			"| ID |    DNI    |    Nombre    |    Apellido    |\n"
			"==================================================\n");

	for(int i=0; i<sizeClientes; i++)
	{
		contador2 = 0;

		for(int j=0; j<sizeAlquileres; j++)
		{
			if(listaAlquileres[j].idCliente == listaClientes[i].id)
			{
				contador2++;
			}
		}

		if(contador2 == mayor)
		{
			MostrarUnCliente(listaClientes[i]);
			retorno = 1;
		}

	}

	printf("==================================================\n");

	printf("Con %d alquileres.\n", mayor);

	return retorno;
}

int InformarClientesConSusAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres, eCliente listaClientes[], int sizeClientes)
{
	int retorno = 0;

	for(int i=0; i<sizeClientes; i++)
	{
		printf("==================================================\n"
				"| ID |    DNI    |    Nombre    |    Apellido    |\n"
				"==================================================\n");

		MostrarUnCliente(listaClientes[i]);

		printf("==================================================\n");

		printf("Alquileres pertenecientes: \n");

		for(int j=0; j<sizeAlquileres; j++)
		{
			if(listaAlquileres[j].idCliente == listaClientes[i].id)
			{
				MostrarUnAlquiler(listaAlquileres[j], listaClientes, sizeClientes);
			}
		}

	}

	return retorno;
}







