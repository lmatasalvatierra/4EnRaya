#include <stdio.h>
#include "cabecera.h"


int llenotablero(int tablero[6][7])
{

    int lleno=1;
    int fil=0;
    int col;

    while((fil<=5) && (lleno))
    {
        col=0;
        while((col<=6) && (lleno))
        {
            if(tablero[fil][col]==0)lleno=0;
            col++;
        }
        fil++;
    }
    return lleno;

}

int llenaColumna(int tablero[6][7], int columna)
{

    int llena=1;
    int fil=0;
    if(tablero[fil][columna-1]==0)
        llena=0;

    return llena;

}

void vaciartablero(int tablero[6][7])
{
    int col;
    int fil=0;

    while(fil<=5)
    {
        col=0;
        while(col<=6)
        {
            tablero[fil][col]=0;
            col++;
        }
        fil++;
    }
}


void pintarFicha(int tablero[6][7], int ficha, int columna)
{
    int fil=5, turno=0;
    while(turno==0)

    {
        if(fil>=0)
        {
            if(tablero[fil][columna-1]==0)
            {
                tablero[fil][columna-1]= ficha;
                turno=1;
            }
        }
        fil--;
    }
}


void pintartablero(int tablero[6][7])
{
    int i, j;
    for(i=0;i<=5;i++)
    {
        printf("|");
        for(j=0;j<=6;j++)
        {
            printf("%c|",(!tablero[i][j])?' ':(tablero[i][j]==1)?'X':'O');
        }
        printf("\n");
    }
    for(j=1;j<=7;j++)
        printf(" %d", j);
}

void portada()
    {

    printf("\n\n    ////           \n   ////            \n  ////  ////       \n ////   ////       \n////////////       \n////////////       \n        ////       \n        ////       EN       RAYA\n\n");

    }

int turnoComienzo(int *turno)
    {
    srand (time (NULL));//aleatorio para el turnno
    *turno = rand()%2+1;
    return turno;
    }


int enrayahorizontal(int tablero[6][7], int fil, int col, int turno)
{
    int horizontal=0;
    if(col<4)
    {
        if((tablero[fil][col]==turno) && (tablero[fil][col+1]==turno) && (tablero[fil][col+2]==turno) &&
            (tablero[fil][col+3]==turno))    horizontal=1;
        else horizontal=0;
    }
    else horizontal=0;
    return horizontal;
}

int enrayavertical(int tablero[][7], int fil, int col, int turno)
{
    int vertical=0;
    if (fil<3)
    {
        if((tablero[fil][col]==turno) && (tablero[fil+1][col]==turno) && (tablero[fil+2][col]==turno) &&
           (tablero[fil+3][col]==turno))vertical=1;
        else vertical=0;
    }
    return vertical;
}

int enrayaDiagonalIzquierda(int tablero[6][7], int fil, int col, int turno)
{
    int diagonalIzquierda=0;
     if((col>2) && (fil<3))
    {
        if((tablero[fil][col]==turno) && (tablero[fil+1][col-1]==turno) && (tablero[fil+2][col-2]==turno) &&
           (tablero[fil+3][col-3]==turno))  diagonalIzquierda=1;
    }
    return diagonalIzquierda;
}

int enrayaDiagonalDerecha(int tablero[6][7], int fil, int col, int turno)
{
    int diagonalDerecha=0;
    if((col>4) && (fil<3))
    {
        if((tablero[fil][col]==turno) && (tablero[fil+1][col+1]==turno) && (tablero[fil+2][col+2]==turno) &&
           (tablero[fil+3][col+3]==turno))  diagonalDerecha=1;
    }
    return diagonalDerecha;
}

int enraya(int tablero[][7], int turno)
{
    int fil=0;
    int col;
    int raya=0;

    while ((raya==0) && fil<=5)
    {
        col=0;
        while(raya==0 && col<7)
        {
        raya=(enrayaDiagonalDerecha(tablero, fil, col, turno) || enrayaDiagonalIzquierda(tablero, fil, col, turno)
              || enrayavertical(tablero, fil, col, turno) || enrayahorizontal(tablero, fil, col, turno));
              col++;
        }
    fil++;
    }
    return raya;

}
