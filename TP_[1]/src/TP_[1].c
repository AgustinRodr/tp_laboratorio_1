/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcionDelMenu;
	int validacionRetorno;
	int km;
	int precioAerolineas;
	float precioXkmAerolineas;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioXkmLatam;
	int precioLatam;
	float precioDebitoLatam;
	float cargaForzadaDebitoLatam;
	float precioCreditoLatam;
	float cargaForzadaCreditoLatam;
	float precioBitcoinLatam;
	float cargaForzadaPrecioBitcoinLatam;
	float diferenciaPrecios;
	float cargaForzadaPrecioDebitoAerolineas;
	float cargaForzadaPrecioCreditoAerolineas;
	float cargaForzadaPrecioBitcoinAerolineas;
	float cargaForzadaPrecioXkmAerolineas;
	float cargaForzadaPrecioXkmLatam;
	float cargaForzadaDiferenciaPrecios;

	do{

		mostrar();

		validacionRetorno = getInt(&opcionDelMenu,"\nIngrese la opcion que desea:\n","La opcion es incorrecta:\n",7,1,1);
		if(validacionRetorno == 0){
			switch(opcionDelMenu){
			case 1:
				validacionRetorno = getInt(&km,"\nIngrese los kilometros:\n","Los kilometros son incorrectos\n",1000000,7090,2);
				if(validacionRetorno == 0){
					printf("%d",km);
				}else{
					printf("Los kilometros no fueron ingresados bien.");
				}
				break;
			case 2:
				validacionRetorno = getInt(&precioAerolineas,"Ingrese el precio de vuelo Aerolineas:\n","El precio es incorrecto:\n",162965,15000,2);
				if(validacionRetorno == 0){
					printf("%d",precioAerolineas);
				}else{
					printf("El precio no fue ingresado bien");
				}
				break;
			case 3:
				validacionRetorno = getInt(&precioLatam,"Ingrese el precio de vuelo Latam:\n","El precio es incorrecto:\n",159339,15000,2);
				if(validacionRetorno == 0){
					printf("%d",precioLatam);
				}else{
					printf("El precio no fue ingresado bien");
				}
				break;
			case 4:
				precioDebitoAerolineas = descuento(precioAerolineas, 10);
				precioDebitoLatam = descuento(precioLatam,10);

				precioCreditoAerolineas = interes(precioAerolineas, 25);
				precioCreditoLatam = interes(precioLatam, 25);

				precioBitcoinAerolineas = enBitcoin(precioAerolineas, 4606954.55);
				precioBitcoinLatam = enBitcoin(precioLatam, 4606954.55);

				precioXkmAerolineas = precioxUnidad(precioAerolineas,km);
				precioXkmLatam = precioxUnidad(precioLatam,km);

				diferenciaPrecios = diferencia(precioAerolineas,precioLatam);

				break;
			case 5:
				printf("\nAerolineas:\na) Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio con bitcoin: $%.8f\nd)Precio unitario: $%.2f\n",precioDebitoAerolineas,precioCreditoAerolineas,precioBitcoinAerolineas,precioXkmAerolineas);

				printf("\nLatam: \na) Precio con tarjeta de debito: $%2.f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio con bitcoin: $%.8f\nd)Precio unitario: $%.2f",precioDebitoLatam,precioCreditoLatam,precioBitcoinLatam,precioXkmLatam);

				printf("\nLa diferencia de precio es: $%.2f",diferenciaPrecios);
				break;
			case 6:
				cargaForzadaPrecioDebitoAerolineas = descuento(precioAerolineas, 10);
				cargaForzadaDebitoLatam = descuento(precioLatam, 10);

				cargaForzadaPrecioCreditoAerolineas = interes(precioAerolineas, 25);
				cargaForzadaCreditoLatam = interes(precioLatam, 25);

				cargaForzadaPrecioBitcoinAerolineas = enBitcoin(precioAerolineas, 4606954.55);
				cargaForzadaPrecioBitcoinLatam = enBitcoin(precioLatam, 4606954.55);

				cargaForzadaPrecioXkmAerolineas = precioxUnidad(precioAerolineas,km);
				cargaForzadaPrecioXkmLatam = precioxUnidad(precioLatam,km);

				cargaForzadaDiferenciaPrecios = diferencia(precioAerolineas,precioLatam);

				printf("\nKMS ingresado: %f\n\nPrecio Aerolineas:$%.2f\na)Precio con tarjeta de debito: $%.4f\nb) Precio con tarjeta de credito: $%.4f\nc) Precio pagando con bitcoin: $%.2f\nd)Precio unitario: $%.2f",cargaForzadaPrecioDebitoAerolineas,cargaForzadaPrecioCreditoAerolineas,cargaForzadaPrecioBitcoinAerolineas,cargaForzadaPrecioXkmAerolineas);
				printf("\nPrecio Latam:$%.2f\na)Precio con tarjeta de debito: $%.2f\nb) Precio con tarjeta de credito: $%.2f\nc) Precio pagando con bitcoin: $%.2f\nd)Precio unitario: $%.2f",cargaForzadaDebitoLatam,cargaForzadaCreditoLatam,cargaForzadaPrecioBitcoinLatam,cargaForzadaPrecioXkmLatam);
				printf("\nLa diferencia de precio es: $%.2f",cargaForzadaDiferenciaPrecios);
				break;
			case 7:
				printf("Que tenga un buen dia.\n");
				break;
			}

		}
	}while(opcionDelMenu != 7);

	return 0;
}
