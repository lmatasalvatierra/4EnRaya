#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

    void portada();
    void pintarFicha(int tablero[6][7], int ficha, int columna);
    void pintartablero(int tablero[6][7]);
    void vaciartablero(int tablero[6][7]);
    int llenotablero(int tablero[6][7]);
    int llenaColumna(int tablero[6][7], int columna);
    int turnoComienzo(int *turno);
    int enrayaDiagonalDerecha(int tablero[6][7], int fil, int col, int turno);
    int enrayaDiagonalIzquierda(int tablero[6][7], int fil, int col, int turno);
    int enrayavertical(int tablero[6][7], int fil, int col, int turno);
    int enrayahorizontal(int tablero[6][7], int fil, int col, int turno);
    int enraya(int tablero[6][7], int turno);

#endif // CABECERA_H_INCLUDED
