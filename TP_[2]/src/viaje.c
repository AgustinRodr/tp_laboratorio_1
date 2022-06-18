/*
 * viaje.c
 *
 *  Created on: 14 may. 2022
 *      Author: invitadopc
 */

#ifndef VIAJE_C_
#define VIAJE_C_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ACTIVO 1
#define ESPERA 2
#define CANCELADO 3

int initViaje(Viaje *viajes, int len)
{
	int retorno;
	retorno = -1;

	if (viajes != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			viajes[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int addViaje(Viaje *viajes, int len, char flyCode[], int statusFlight)
{
	int retorno;
	int indexLibre;
	int flag = 0;
	retorno = -1;

	if (viajes != NULL && len > 0 && flyCode != NULL && statusFlight > 0) {
		for (int i = 0; i < len; i++) {
			if(viajes[i].isEmpty == 0){
				if (stricmp(flyCode, viajes[i].flyCode) == 0) {
				viajes[i].statusFlight = statusFlight;
				flag = 1;
				retorno = 0;
				break;
				}
			}
		}
		if (flag == 0) {
			indexLibre = findFreeIndexFlight(viajes, len);
			strncpy(viajes[indexLibre].flyCode, flyCode,
					sizeof(viajes[indexLibre].flyCode));
			viajes[indexLibre].statusFlight = statusFlight;
			viajes[indexLibre].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}

int busarIndexLibreVuelo(Viaje *list, int len)
{
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int viajesOk(Viaje *viajes, int len, char array[][10])
{
	int retorno = -1;
	int j = 0;
	if (viajes != NULL && len > 0 && array != NULL) {
		for (int i = 0; i < len; i++) {
			if (viajes[i].isEmpty == 0 && viajes[i].statusFlight == ACTIVO) { // 1 ES ACTIVO
				strncpy(array[j], viajes[i].flyCode, 10);
				j++;
				break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int bajaViaje(Viaje *vuelos, int len, char flycode[])
{
	int retorno = -1;

		if(vuelos != NULL && len >0 && flycode!= NULL){
			for(int i = 0; i < len; i++){
				if(vuelos[i].isEmpty == 0 && stricmp(vuelos[i].flyCode, flycode) == 0){
					vuelos[i].isEmpty=1;
					break;
				}
				retorno = 0;
			}
		}

	return retorno;
}

int buscarVueloPorId(Viaje*list, int len, char flyCode[])
{
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && flyCode != NULL) {
		for (int i = 0; i < len; i++) {
			if (stricmp(list[i].flyCode, flyCode) && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int hayViaje(Viaje *vuelos, int len)
{
	int retorno;
	retorno = -1;

	if (vuelos != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vuelos[i].statusFlight == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int modificarViajes(Viaje *viajes, int len, char flyCode[], int statusFlight, int flagMod)
{
	int retorno;
	int indexLibre;
	int flag;
	retorno = -1;
	flag = 0;

	if (viajes != NULL && len > 0 && flyCode != NULL && statusFlight > 0) {
		if(flagMod == 1){
			for (int i = 0; i < len; i++) {
				if (stricmp(flyCode, viajes[i].flyCode) == 0 && viajes[i].isEmpty == 0) {
					viajes[i].statusFlight = statusFlight;
					flag = 1;
				break;
				}
			}
		if (flag == 0) {
			indexLibre = findFreeIndexFlight(viajes, len);
			strncpy(viajes[indexLibre].flyCode, flyCode,sizeof(viajes[indexLibre].flyCode));
			viajes[indexLibre].statusFlight = statusFlight;
			viajes[indexLibre].isEmpty = 0;
		}
		}
		retorno = 0;
	}
	return retorno;
}

#endif /* VIAJE_C_ */
