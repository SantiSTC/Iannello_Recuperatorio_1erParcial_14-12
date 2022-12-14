/*
 * alquiler.c
 *
 *  Created on: 14 dic. 2022
 *      Author: Santiago
 */

#include "alquiler.h"

int ObtenerIdAutoIncrementalAlquiler()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}

int BuscarEspacioAlquiler(eAlquiler listaAlquileres[], int sizeAlquileres)
{
	int index = -1;

	for(int i = 0; i < sizeAlquileres; i++)
	{
		if(listaAlquileres[i].estadoLista == LIBRE)
	    {
			index = i;
	        break;
	    }
	}

	return index;
}

void InicializarAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres)
{
	int index;

	index = BuscarEspacioAlquiler(listaAlquileres, sizeAlquileres);
	for(int i=0; i<sizeAlquileres; i++)
	{
		if(index != -1)
		{
			listaAlquileres[i].estadoLista = LIBRE;
		}
	}
}

int InformarEquipoMasAlquilado(eAlquiler listaAlquileres[], int sizeAlquileres)
{
	int retorno = 0;
	int contadorTaladro = 0;
	int contadorAmoladora = 0;
	int contadorMezcladora = 0;

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(listaAlquileres[i].equipo == 10)
		{
			contadorAmoladora++;
		}
		else
		{
			if(listaAlquileres[i].equipo == 11)
			{
				contadorMezcladora++;
			}
			else
			{
				if(listaAlquileres[i].equipo == 12)
				{
					contadorTaladro++;
				}
			}
		}

		retorno = 1;
	}

	if(contadorAmoladora > contadorMezcladora && contadorAmoladora > contadorTaladro)
	{
		printf("El equipo mas alquilado es la amoladora con %d alquileres.\n", contadorAmoladora);
	}
	else
	{
		if(contadorMezcladora > contadorAmoladora && contadorMezcladora > contadorTaladro)
		{
			printf("El equipo mas alquilado es la mezcladora con %d alquileres.\n", contadorMezcladora);
		}
		else
		{
			if(contadorTaladro > contadorAmoladora && contadorTaladro > contadorMezcladora)
			{
				printf("El equipo mas alquilado es el taladro con %d alquileres.\n", contadorTaladro);
			}
		}
	}

	return retorno;
}

int InformarTiempoPromedioRealDeAlquileres(eAlquiler listaAlquileres[], int sizeAlquileres)
{
	int retorno = 0;
	int contadorAlquileres = 0;
	float sumadorTiempo = 0;
	float promedio;

	for(int i=0; i<sizeAlquileres; i++)
	{
		if(listaAlquileres[i].estadoLista == OCUPADO && listaAlquileres[i].estadoAlquiler == FINALIZADO)
		{
			contadorAlquileres++;
			sumadorTiempo += listaAlquileres[i].tiempoReal;
			retorno = 1;
		}
	}

	promedio = sumadorTiempo / contadorAlquileres;

	printf("El promedio de tiempo real de alquileres es de: %.2f\n", promedio);

	return retorno;
}
