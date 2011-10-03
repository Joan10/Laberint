#ifndef BOLLA_H
#define BOLLA_H

#define CT_DURESA 2

#include <stdio.h>
#include "t_vector.h"



typedef struct td_Trajectoria{

    t_Vector Acc;
    t_Vector Pos_Inici_Traj;
    t_Vector Vel_Inici_Traj; //Velocitat que duiem quan hem variat l'acceleració.

    float dTemps; //diferència de temps des de l'inici de la trajectòria.

}t_Traj;

//Una trajectòria és el conjunt de dades que ens permeten definir la posició actual d'un objecte
//juntament amb els valors que definiran les seves pròximes posicions tals com l'acceleració actual
//i el temps que fa que duim aquesta acceleració. Així mateix, cada vegada que modificam l'acceleració del cos cal mantenir la posició
//on hem modificat aquesta acceleració i la velocitat que duiem en aquell moment per realitzar els càlculs.
//A més a més, també guardam el temps des de que hem modificat l'acceleració.

//Cal tenir en compte que una trajectòria és en línia recta, per això la modificació contínua de trajectòries implica fer girar la bolla.

//Un canvi de trajectòria suposa un canvi en la direcció de la bolla i per tant una corva. Això implica haver de refer la trajectòria
//de la bolla i les equacions que defineixen aquesta trajectòria.


typedef struct td_Bolla
{
    t_Vector Pos;
    t_Vector Vel;

    t_Traj Tj;
    int radi;

}*pt_Bolla,t_Bolla;
//Una bolla no és més que un objecte d'un cert radi amb una posició i una velocitat determinades.


t_Bolla Inicialitza(t_Vector V, int radi);

t_Vector treuAcceleracio(t_Vector Inclinacio);
// Transforma la inclinació en una acceleració, en funció de l'acceleració de la gravetat.

t_Vector CalculaNovaPosicio(t_Bolla B);
// Donada una bolla amb una trajectòria es calcula la posició al pròxim instant de temps.

//Operacions sobre la bolla.

void ActualitzaTrajectoria(t_Bolla *B, t_Vector Acceleracio);
// Refà la trajectòria de la bolla, assignant-li una nova acceleració.

void ModificaVelocitat(t_Bolla *B, t_Vector Vel);
//Donada una bolla li canvia el valor de la velocitat. Útil per simular rebots i col·lisions.

void Mou(t_Bolla *B, t_Vector Pos);
//Desplaça la bolla a la posicio indicada

void Pinta(t_Bolla *B);

#endif
