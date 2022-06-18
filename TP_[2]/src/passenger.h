/*
 * passenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: invitadopc
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#define LEN 2000


typedef struct {
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

typedef struct {
	int eTypePassenger;
	int description[20];
} TypePassenger;

int initPassenger(Passenger lista[], int len);

int buscarIndexPorId(Passenger lista[], int len, int id);

void mostrarPassenger(Passenger lista);

void mostrarPassenger2(Passenger onePassenger);

int addPassenger(Passenger *list, int len, int id, char name[], char lastName[],
		float price, int typePassenger, char flyCode[]);

int incrementarId();

int listarPassenger(Passenger lista[], int len);

int modificarPassenger(Passenger listaPassenger[], int len, int idPassenger);

int buscarIndexPorId(Passenger listaPassenger[], int len, int id);

int bajaPassenger(Passenger listaPassenger[], int len, int idPassenger);


#endif /* PASSENGER_H_ */
