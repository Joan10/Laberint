#ifndef TAULELL_H
#define TAULELL_H

#define MAX_PARETS 20

#include "Bolla.h"
#include <stdio.h>

struct t_Paret
{
    int pos1X;
    int pos1Y;
    int pos2X;
    int pos2Y;
};

//t_Paret defineix què és una paret, això és, bàsicament, les seves posicions.

struct t_Taulell {

    t_Paret *conj_Parets[MAX_PARETS];

    int angX;
    int angY;
    //definim la inclinació del taulell mitjançant dos angles.
    //En principi els angles seràn graus (per això són enters)

    int midaX;
    int midaY;
    //La longitud és la distància entre punta i punta del taulell.
    //Per tant, el rang de posicions on podem moure la bolla és [0..longX-1],[0..longY-1]
};

bool haCanviat;

void InclinaTaulell(t_Taulell *T, int tmp_angleX, int tmp_angleY);
//Assigna una inclinació al taulell.

void ProcessaTaulell(t_Taulell *T);
//Donada la inclinació del taulell calcula la nova posició per la bolla.

int PosaParet(t_Taulell *T, t_Paret P);
//Col·loca una paret al taulell. Si no es pot col·locar retorna -1.

int PosaBolla(t_Taulell *T, int x, int y);
//Posa la bolla al taulell a la posició indicada. Si no es pot col·locar retorna -1.

void PintaTaulell(t_Taulell T);
//Pinta el taulell.

#endif
