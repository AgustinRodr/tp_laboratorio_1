/*
 * viaje.h
 *
 *  Created on: 14 may. 2022
 *      Author: invitadopc
 */

#ifndef VIAJE_H_
#define VIAJE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ACTIVO 1
#define ESPERA 2
#define CANCELADO 3

struct {
    char flyCode[10];
    int  statusFlight;
    int  isEmpty;
} typedef Viaje;

int initViaje(Viaje *viajes, int len);

int addViaje(Viaje *viajes, int len, char flyCode[], int statusFlight);

int busarIndexLibreVuelo(Viaje *list, int len);

int viajesOk(Viaje *viajes, int len, char array[][10]);

int bajaViaje(Viaje *vuelos, int len, char flycode[]);

int buscarVueloPorId(Viaje*list, int len, char flyCode[]);

int hayViaje(Viaje *vuelos, int len);

int modificarViajes(Viaje *viajes, int len, char flyCode[], int statusFlight, int flagMod);






#endif /* VIAJE_H_ */
