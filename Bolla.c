#include <math.h>
#include "Bolla.h"

#define G_CT -9.8
#define PI 3.14159265

t_Bolla Inicialitza(t_Vector V, int radi)
{

    t_Traj Tj =
       { V,
        {0, 0},
        {0, 0} ,
        V,
        {0, 0},
        0 };


    t_Bolla B;

    B.radi = radi;

    B.Tj = Tj;

    return B;

}

void CalculaAcceleracio(t_Bolla *B, t_Vector Incl)
{

    B->Tj.Pos_Inici_Traj = B->Tj.Pos;

    B->Tj.dTemps = 0.05;

    B->Tj.Vel_Inici_Traj = B->Tj.Vel;

    B->Tj.Acc.x = G_CT * sin(Incl.x*PI/180);
    B->Tj.Acc.y = G_CT * sin(Incl.y*PI/180);

}

t_Vector CalculaNovaPosicio(t_Bolla *B)
{

    t_Vector retV; //Vector a retornar.

    int x0 = B->Tj.Pos_Inici_Traj.x;
    int y0 = B->Tj.Pos_Inici_Traj.y;

    float v0x = B->Tj.Vel_Inici_Traj.x;
    float v0y = B->Tj.Vel_Inici_Traj.y;

    float dt = B->Tj.dTemps;

    //Per facilitar la comprensió reanomenam les variables:

    retV.x = x0+v0x*(dt) + 0.5*B->Tj.Acc.x*pow((dt),2);
    retV.y = y0+v0y*(dt) + 0.5*B->Tj.Acc.y*pow((dt),2);

    B->Tj.Vel.x = v0x + B->Tj.Acc.x*(dt);
    B->Tj.Vel.y = v0y + B->Tj.Acc.y*(dt);

    B->Tj.dTemps = B->Tj.dTemps+0.05;
    //Incrementam la diferència de temps.

    return retV;
}


void Pinta(t_Bolla *B)
{

    printf("%fl %fl %fl %fl %fl %fl",
            B->Tj.Acc.x,
            B->Tj.Acc.y,
            B->Tj.Vel.x,
            B->Tj.Vel.y,
            B->Tj.Pos.x,
            B->Tj.Pos.y);
    printf(" \n \n \n");

}


void Mou(t_Bolla *B, t_Vector P){ B->Tj.Pos.x = P.x; B->Tj.Pos.y = P.y;}
