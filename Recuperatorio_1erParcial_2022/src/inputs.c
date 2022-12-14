/*
 * inputs.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Santiago
 */

#include "inputs.h"

int ObtenerIdAutoIncremental()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}

int MostrarMenu()
{
	int opcion;

	printf("\n----------------------------------------\n"
			"            Menu Principal\n"
			"1. Alta cliente\n"
			"2. Modificar cliente\n"
			"3. Baja cliente\n"
			"4. Nuevo alquiler\n"
			"5. Fin de alquiler\n"
			"6. Informar\n"
			"7. Salir\n"
			"----------------------------------------\n");

	opcion = ElegirOpcion(7, 1);

	return opcion;
}

int MenuInformes()
{
	int opcion;

	printf("\n----------------------------------------\n"
			"            Menu Principal\n"
			"1. Clientes con mas alquileres\n"
			"2. Equipo mas alquilado\n"
			"3. Tiempo real promedio de los alquileres\n"
			"4. Todos los clientes con sus alquileres\n"
			"----------------------------------------\n");

	opcion = ElegirOpcion(4, 1);

	return opcion;
}

int MenuModificacion()
{
	int opcion;

	printf("\n--------------------------------\n"
			"          Modificaciones\n"
			"1. Modificar nombre\n"
			"2. Modificar apellido\n"
			"---------------------------------\n");

	opcion = ElegirOpcion(2, 1);

	return opcion;
}

int PedirEquipo()
{
	int opcion;

	printf("\n--------------------------------\n"
			"            Equipos\n"
			"10. Amoladora\n"
			"11. Mezcladora\n"
			"12. Taladro\n"
			"---------------------------------\n");

	opcion = ElegirOpcion(12, 10);

	return opcion;
}

int PedirID()
{
	char idAux[10];
	int validar;
	int id;

	validar = getStringNumeros("Ingrese un ID: ", idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0)
	{
		validar = getStringNumeros("ERROR, Ingrese un ID valido: ", idAux);
		id = atoi(idAux);
	}

	return id;
}

int ElegirOpcion(int max, int min)
{
	char opcion[50];
	int validar;
	int opcionElegida;

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > max || opcionElegida < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

int PedirEntero()
{
	int unEntero;

	scanf("%d", &unEntero);

	while(isdigit(unEntero) != 0)
	{
		printf("ERROR, debe ingresar un numero\n");
		fflush(stdin);
		scanf("%d", &unEntero);
	}

	return unEntero;
}

int PedirTiempo(char* mensaje)
{
	int dias;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &dias);

	while(isdigit(dias) != 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &dias);
	}

	return dias;
}

int PedirDia()
{
	int dia;

		printf("\nIngrese el dia: ");
		dia = PedirEntero();
		while(dia < 1 || dia > 31)
		{
			printf("\nERROR, Ingrese un dia valido: ");
			dia = PedirEntero();
		}

	return dia;
}

int PedirMes()
{
	int mes;

	printf("\nIngrese el mes: ");
	mes = PedirEntero();
	while(mes < 1 || mes > 12)
	{
		printf("\nERROR, Ingrese un mes valido: ");
		mes = PedirEntero();
	}

	return mes;
}

int PedirAnio()
{
	int anio;

	printf("\nIngrese el año: ");
	anio = PedirEntero();
	while(anio < 0 || anio > 10000)
	{
		printf("\nERROR, Ingrese un año valido: ");
		anio = PedirEntero();
	}

	return anio;
}

void PedirString(char* mensaje, char* nombre)
{
	int validar;

	validar= getStringLetras(mensaje, nombre);
	while(validar == 0 || strcmp(nombre, "")==0)
	{
		validar= getStringLetras(mensaje, nombre);
	}

}



