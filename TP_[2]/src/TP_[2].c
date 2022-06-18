/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "passenger.h"
#include "viaje.c"


#define LEN 2000

int main(void) {
	setbuf(stdout, NULL);

	int validacionRetorno;
	int flag = 0;
	int idIngresado;
	int opcionDelMenu;
	char codigoDeViajes[LEN][10];
	int idAux;
	char nameAux[51];
	char lastnameAux[51];
	float priceAux;
	char flycodeAux[10];
	int statusFlightModificado;
	int typePassengerAux;
	int statusFlightAux;
	char flycodeAuxModificado[10];
	int vueloModificado = 0;
	char seguir = 's';
	Passenger passenger[LEN];
	Viaje viajes[LEN];
	initPassengers(passenger, LEN);
	initVuelos(viajes, LEN);
	do {
		validacionRetorno = getInt(&opcionDelMenu,"***************MENU PRINCIPAL***************\n\nIngrese la opcion que desea:\n \n1)ALTA:\n2)MODIFICAR:\n3)BAJA:\n4)INFORMAR:\n5)SALIR:\n","La opcion es incorrecta:\n", 7, 1, 1);
		if(validacionRetorno == 0)
		{
			switch(opcionDelMenu){

			case 1:
				if(buscarIndexPorId(passenger, LEN) != -1)
				{
					if(getString(nameAux,"Ingrese el nombre del pasajero:\n","El nombre no pude ser validado.", 2) == 0& getString(lastnameAux,"Ingrese el apellido del pasajero:\n","El nombre no pude ser validado.",2))
					{
						if(addPassenger(passenger, LEN, idAux, nameAux, lastnameAux, priceAux, flycodeAux, typePassengerAux, flycodeAux)==0)
						{
							if(addViaje(viajes, LEN, flycodeAux, statusFlightAux) == 0){
								viajesActivos(viajes, LEN, codigoDeViajes);
							}
						}
					}else{
						printf("ERROR EN LA CARGA DE PASAJERO.");
					}
				}else{
					printf("No hay lugar");
				}
				break;
			case 2:

				if(hayPassenger(passenger, LEN) == 1)
				{
					if(getInt(&idAux,"Ingrese id del pasajero a modificar\n","Ingrese una id valida\n",1000,80000,2)==0){
						if(modificarPassenger(passenger, LEN, idAux, flycodeAuxModificado, &statusFlightModificado, &vueloModificado)==0)
						{
							modificarViajes(viajes, LEN, flycodeAuxModificado, statusFlightModificado, vueloModificado);
							viajesActivos(viajes, LEN, codigoDeViajes);
						}
					}
				}else{
					mensaje("No se cargo ningun pasajero.\n");
				}
				break;
			case 3:

				break;
			case 4:


				break;

			case 5:

				break;
			}
		}
	} while (seguir == 's');

	return EXIT_SUCCESS;
}
