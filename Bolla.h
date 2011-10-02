#ifndef BOLLA_H
#define BOLLA_H

#include <stdio.h>
#include "t_vector.h"



typedef struct td_Trajectoria{

    t_Vector Pos;
    t_Vector Acc;
    t_Vector Vel;

    t_Vector Pos_Inici_Traj;

    t_Vector Vel_Inici_Traj; //Velocitat que duiem quan hem variat l'acceleració.

    float dTemps; //diferència de temps des de l'inici de la trajectòria.

}t_Traj;

//Una trajectòria és el conjunt de dades que ens permeten definir la posició actual d'un objecte
//juntament amb els valors que definiran les seves pròximes posicions tals com la velocitat actual
//o l'acceleració. Així mateix, cada vegada que modificam l'acceleració del cos cal mantenir la posició
//on hem modificat aquesta acceleració i la velocitat que duiem en aquell moment per realitzar els càlculs.
//A més a més, també guardam el temps des de que hem modificat l'acceleració.


typedef struct td_Bolla
{
    t_Traj Tj;
    int radi;

}*pt_Bolla,t_Bolla;
//Una bolla no és més que un objecte d'un cert radi amb una trajectòria definida.


t_Bolla Inicialitza(t_Vector V, int radi);

void CalculaAcceleracio(t_Bolla *B, t_Vector Incl);
// Donada una inclinació del sòl on hi ha la bolla es calcula l'acceleració que ha de patir la bolla.

t_Vector CalculaNovaPosicio(t_Bolla *B);
// Donada una bolla amb una velocitat es calcula la posició al pròxim instant de temps.

void Mou(t_Bolla *B, t_Vector V);

void Pinta(t_Bolla *B);

#endif
