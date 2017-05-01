#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cabecera.h"

void main ()
{
    int tablero[6][7];
    int turno, columna, cont=0, fin=0;
    char limpiar, respuesta;

    system("COLOR FC");//personalizacion del color del programa
    portada();

    while (fin==0)
    {
        turnoComienzo(&turno);
        printf("Turno: %d\n", turno);
        if (turno==1)
        {
            printf ("Juega primero el ordenador");
        }
        else printf ("Juegas tu");

        printf("\nPresione Enter\n");//para limpiar la pantalla
        scanf("%c",&limpiar);
        system("cls");
        vaciartablero(tablero);
        pintartablero(tablero);

        while (!llenotablero(tablero) && !enraya(tablero, turno))
        {
            printf("\nJugador %d, introduzca columna: ", turno);
            if (turno==1)
            {
                if (cont==0)
                {
                    columna=4;
                    cont++;
                }
                else
                {
                    srand (time (NULL));//aleatorio jugada
                    columna=rand()%(7-1+1)+1;
                }
            }
            else
            {
                scanf("%d", &columna);
            }
            while (columna<1 || columna >7)
                {
                    printf("Valor de columna incorrecto, introduzca un valor de 1 a 7: ");
                    scanf("%d", &columna);
                }


            if (!llenaColumna(tablero, columna))
                {

                system("cls");
                pintarFicha(tablero, turno, columna);
                pintartablero(tablero);

                if (turno == 1) turno = 2;
                else turno = 1;
                }
            else
            {
                printf("\nLa columna esta llena, introduzca otra columna: ");
            }
        }

        if(enraya(tablero, turno))
            {
                if(turno==1)  printf("\nHas perdido\n");
                else printf("\nHas ganado\n");
            }
            else printf("\nEmpate");

            printf("Quieres volver a jugar? (y/n): \n");
            scanf("%c", &respuesta);
            if(respuesta=='n') fin=1;


    }

}
