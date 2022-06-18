#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "passenger.h"


int initPassenger(Passenger lista[], int len)
{
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			lista[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarIndexPorIsEmpty(Passenger pArray[], int len)
{
	int retorno = -1;

		if(pArray != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(pArray[i].isEmpty == 1)
				{
					retorno = i;
					break;
				}
			}
		}

	return retorno;
}

int incrementarId()
{
    static int id = 1000;
    id++;
    return id;
}

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, char flyCode[])
{
	int retorno;
	int estaOk;
	int indexLibre;
	retorno = -1;
	estaOk = 0;

	if (list != NULL && len > 0 && name != NULL && lastName != NULL && price > 0
			&& typePassenger > 0 && flyCode != NULL ) {
		indexLibre = findFreeIndex(list, len);
		if (indexLibre != -1) {
			list[indexLibre].isEmpty = 0;
			strcpy(list[indexLibre].name, name);
			strcpy(list[indexLibre].lastname, lastName);
			list[indexLibre].id = passengerId();
			list[indexLibre].price = price;
			list[indexLibre].typePassenger = typePassenger;
			strcpy(list[indexLibre].flyCode, flyCode);

			estaOk = 1;
		}

	}
		if(estaOk == 1) {
			printf("Se cargo correctamente.\n");
			retorno = 0;
		}

		return retorno;
}

int listarPassenger(Passenger lista[], int len)
{
	int retorno = -1;

	if(lista != NULL && len >0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarPassenger(lista[i]);
		}
		retorno = 0;
	}
	return retorno;
}

	int buscarIndexPorId(Passenger lista[], int len, int id)
	{
		int retorno;
			retorno = -1;

			if (lista != NULL && len > 0) {
				for (int i = 0; i < len; i++) {
					if (lista[i].isEmpty == 1) {
						retorno = i;
						break;
					}
				}
			}
			return retorno;
	}

int modificarPassenger(Passenger listaPassenger[], int len, int idPassenger)
{
	int retorno = -1;
	int index;
	if (listaPassenger != NULL && len > 0 && idPassenger > 0)
	{
        index = buscarIndexPorId(listaPassenger, len, idPassenger);

    	if (index != -1)
    	{
    		mostrarPassenger(listaPassenger[index]);
			printf("Cambie el nombre:");
			fflush(stdin);
			scanf("%s", listaPassenger[index].name);
			printf("Cambie el apellido:");
			fflush(stdin);
			scanf("%s", listaPassenger[index].lastname);
			printf("Cambie el precio:");
			scanf("%f",&listaPassenger[index].price);
			printf("Cambie el codigo de vuelo:");
			fflush(stdin);
			scanf("%s", listaPassenger[index].flyCode);
			printf("Cambie el tipo de pasajero:");
			scanf("%d",&listaPassenger[index].typePassenger);
			retorno = 0;
	    }
	}
	return retorno;
}

int hayPassenger(Passenger *list, int len) {
	int retorno;
	retorno = 0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int modificarPassenger(Passenger *list, int len, int id, char * flyCode, int * statusFlight, int * modificoVuelo) {
	int retorno = -1;
	int indexAModificar;
	int opcion;

	int statusFlightAux;
	char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char flyCodeAux[10];
	int typePassengerAux;

	if (list != NULL && len > 0 && id > 0) {
		indexAModificar = findPassengerById(list, len, id);
		if (indexAModificar != -1) {
			do {
				if (getInt(&opcion,
						"¿Que opcion desea modificar?\n\n1)Nombre\n\n2)Apellido\n\n3)Precio\n\n4)Tipo de pasajero\n\n5)Codigo de vuelo.\n\n6)Volver al menu principal",
						"ERROR, ingrese una opcion valida.", 1, 6, 2)
						== 0) {
					switch (opcion) {
					case 1:
						if (getString(nombreAux,"Introduzca el nuevo nombre del pasajero:\n","El nombre no pudo ser validado, ingreselo nuevamente:\n",2) == 0) {
							strcpy(list[indexAModificar].name, nombreAux);
							strncpy(list[indexAModificar].name, nombreAux,sizeof(list[indexAModificar].name));
							retorno = 0;
							*modificoVuelo=0;
							mensaje("Nombre actualizado.\n");
						} else {
							mensaje("ERROR EN LA MODIFICACION.\n");
						}
						break;
					case 2:
						if (getString(apellidoAux,"Introduzca el nuevo apellido del pasajero:\n","El apellido no pudo ser validado, ingreselo nuevamente:\n",2) == 0) {
							strcpy(list[indexAModificar].lastname,apellidoAux);
							mensaje("Apellido actualizado.\n");
							retorno = 0;
							*modificoVuelo=0;
						} else {
							mensaje("ERROR EN LA MODIFICACION.\n");
						}
						break;
					case 3:
						if (utnGetFloat(&precioAux,"Ingrese el nuevo precio del viaje:","El valor es incorrecto, ingreselo nuevamente:\n",10000, 1000000, 2) == 0) {
							list[indexAModificar].price = precioAux;
							mensaje("Precio actualizado.\n");
							retorno = 0;
							*modificoVuelo=0;
						} else {
							mensaje("ERROR EN LA MODIFICACION.\n");
						}
						break;
					case 4:
						if (utn_getInt(&typePassengerAux,"Ingrese el nuevo tipo de pasajero:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase turista","Por favor, ingrese una opcion valida.", 1, 3,2) == 0) {
							retorno = 0;
							list[indexAModificar].typePassenger =typePassengerAux;
							mensaje("Tipo de pasajero actualizado.\n");
							*modificoVuelo=0;
						} else {
							mensaje("ERROR EN LA MODIFICACION.\n");
						}
						break;
					case 5:
						if (utn_getFlyCode(flyCodeAux,"Ingrese el nuevo codigo de vuelo:\n","Error, ingrese un codigo alfanumerico:", 2)== 0 && utn_getInt(&statusFlightAux,"Ingrese el estado del vuelo:\n1-Activo.\n2-Demorado.\n3-Cancelado.\n","Por favor, ingrese una opcion valida.", 1, 3, 2)==0) {
							strcpy(list[indexAModificar].flyCode, flyCodeAux);
							strcpy(flyCode, flyCodeAux);
							*statusFlight = statusFlightAux;
							mensaje("El codigo de vuelo se actualizo.\n");
							*modificoVuelo = 1;
							retorno = 0;
						}
						else {
							mensaje("La modificacion fallo.\n");
						}
						break;
					case 6:
						mensajeGenerico("Volviendo al menu principal...\n\n");
						break;
					}
				}
			} while (opcion != 6);
		} else {
			mensajeGenerico("El id no pertence a ningun pasajero cargado.\n");
		}

	}
	return retorno;
}

/// @brief
///
/// @return
int passengerId(void) {
	static int id = 999;
	id++;
	return id;
}
