#include <math.h>
#include "Bolla.h"

#define G_CT -9.8
#define PI 3.14159265

t_Bolla Inicialitza(t_Vector V, int radi)
{

    t_Traj Tj = {{0, 0}, V, {0, 0}, 0};

    t_Bolla B = {V, {0,0}, Tj, radi};

    return B;

}

t_Vector treuAcceleracio(t_Vector Inclinacio)
{

    t_Vector V;

    V.x = G_CT * sin(Inclinacio.x*PI/180);
    V.y = G_CT * sin(Inclinacio.y*PI/180);

    return V;

}


void ActualitzaTrajectoria(t_Bolla *B, t_Vector Acceleracio)
{

    B->Tj.Pos_Inici_Traj = B->Pos;

    B->Tj.dTemps = 0.05;

    B->Tj.Vel_Inici_Traj = B->Vel;

    B->Tj.Acc.x = Acceleracio.x;
    B->Tj.Acc.y = Acceleracio.y;

}

t_Vector CalculaNovaPosicio(t_Bolla B)
{

    t_Vector retV; //Vector a retornar.

    int x0 = B.Tj.Pos_Inici_Traj.x;
    int y0 = B.Tj.Pos_Inici_Traj.y;

    float v0x = B.Tj.Vel_Inici_Traj.x;
    float v0y = B.Tj.Vel_Inici_Traj.y;

    float dt = B.Tj.dTemps;

    //Per facilitar la comprensió reanomenam les variables:

    retV.x = x0+v0x*(dt) + 0.5*B.Tj.Acc.x*pow((dt),2);
    retV.y = y0+v0y*(dt) + 0.5*B.Tj.Acc.y*pow((dt),2);


    return retV;
}


void Pinta(t_Bolla *B)
{

    printf("%fl %fl %fl %fl %fl %fl",
            B->Tj.Acc.x,
            B->Tj.Acc.y,
            B->Vel.x,
            B->Vel.y,
            B->Pos.x,
            B->Pos.y);
    printf(" \n \n \n");

}


void Mou(t_Bolla *B, t_Vector Pos)
{

    float v0x = B->Tj.Vel_Inici_Traj.x;
    float v0y = B->Tj.Vel_Inici_Traj.y;
    float dt = B->Tj.dTemps;

    B->Pos.x = Pos.x; B->Pos.y = Pos.y;

    B->Vel.x = v0x + B->Tj.Acc.x*(dt);
    B->Vel.y = v0y + B->Tj.Acc.y*(dt);
    //Calculam la nova velocitat de la bolla.


    B->Tj.dTemps = B->Tj.dTemps+0.05;
    //Incrementam la diferència de temps.
}

void ModificaVelocitat(t_Bolla *B, t_Vector Vel){
    B->Vel = Vel;
}

void FesRebotar(t_Bolla *B, t_Vector n){
//n: Vector normal del plà de rebot.
    B->Vel = Vel;
}
