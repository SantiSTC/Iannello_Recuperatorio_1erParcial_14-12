/*
 ============================================================================
 Name        : Recuperatorio_1erParcial_2022.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define T_C 3
#define T_A 100

int main(void) {
	setbuf(stdout, NULL);

	eCliente listaClientes[T_C] = {{1, 44444444, "Jorge", "Peña", OCUPADO}, {2, 11111111, "Manu", "Paoss", OCUPADO},{3, 88888888, "Juan", "Soles", OCUPADO}};
	eAlquiler listaAlquileres[T_A];

	int opcion;
	int retorno;
	int flagCarga = 1;
	int opcionInformes;

	InicializarAlquileres(listaAlquileres, T_A);
	InicializarClientes(listaClientes, T_C);

	do
	{
		opcion = MostrarMenu();

		switch(opcion)
		{
			case 1:
				retorno = CargarListaClientes(listaClientes, T_C);
				if(retorno > -1)
				{
					flagCarga = 1;
					printf("Se ha cargado correctamente al cliente...\n");
				}
				else
				{
					printf("No se ha podido cargar al cliente...\n");
				}
			break;
			case 2:
				if(flagCarga == 1)
				{
					retorno = ModificarCliente(listaClientes, T_C);
					if(retorno > 0)
					{
						printf("Se ha modificado correctamente al cliente...\n");
					}
					else
					{
						printf("No se ha podido modificar al cliente...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos un cliente antes de ingresar a esta opcion...\n");
				}
			break;
			case 3:
				if(flagCarga == 1)
				{
					retorno = EliminarCliente(listaClientes, T_C);
					if(retorno > 0)
					{
						printf("Se ha eliminado correctamente al cliente...\n");
					}
					else
					{
						printf("No se ha podido eliminar al cliente...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos un cliente antes de ingresar a esta opcion...\n");
				}
			break;
			case 4:
				if(flagCarga == 1)
				{
					retorno = CargarListaAlquileres(listaAlquileres, T_A, listaClientes, T_C);
					if(retorno > -1)
					{
						printf("Se ha cargado correctamente el alquiler...\n");
					}
					else
					{
						printf("No se ha podido cargar el alquiler...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos un cliente antes de ingresar a esta opcion...\n");
				}
			break;
			case 5:
				if(flagCarga == 1)
				{
					retorno = FinalizarAlquiler(listaAlquileres, T_A, listaClientes, T_C);
					if(retorno > -1)
					{
						printf("Se ha cargado correctamente el alquiler...\n");
					}
					else
					{
						printf("No se ha podido cargar el alquiler...\n");
					}
				}
				else
				{
					printf("Se debera cargar al menos un cliente antes de ingresar a esta opcion...\n");
				}
			break;
			case 6:
				MostrarListaAlquileres(listaAlquileres, T_A, listaClientes, T_C);
				opcionInformes = MenuInformes();

				switch(opcionInformes)
				{
					case 1:
						InformarElClienteConMasAlquileres(listaAlquileres, T_A, listaClientes, T_C);
					break;
					case 2:
						InformarEquipoMasAlquilado(listaAlquileres, T_A);
					break;
					case 3:
						InformarTiempoPromedioRealDeAlquileres(listaAlquileres, T_A);
					break;
					case 4:
						InformarClientesConSusAlquileres(listaAlquileres, T_A, listaClientes, T_C);
					break;
				}
			break;
		}


	}while(opcion != 7);


	return 0;
}
