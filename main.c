#include <stdio.h>
#include <stdlib.h>

//#include "Taulell.h";
#include "Bolla.h"
#include "t_vector.h"

#include <allegro.h>

int main()
{

    allegro_init();
    install_keyboard();
    install_mouse();


   if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 400, 400, 0, 0) != 0) {
       printf("error");
   }

    set_palette(desktop_palette);

    clear_to_color(screen, makecol(255, 255, 255));


    t_Bolla B;

    t_Vector V = {200,200};
    B=Inicialitza( V, 2);

    t_Vector Pitch, BollaAnt, NovaPos, Grav;

    int pitch1,pitch2, pos, posant; pos = 0; pitch1=0; pitch2=0;

    while (!key[KEY_ESC])
    {

        posant = pos; pos = mouse_pos;

        Pitch.x = ((pos >> 16)-200)/4.444;
        Pitch.y = ((pos & 0x0000ffff)-200)/4.444;

        if (posant != pos){
            Grav = treuAcceleracio(Pitch);
            ActualitzaTrajectoria(&B,Grav);
        }

        BollaAnt = B.Pos;
        NovaPos = CalculaNovaPosicio(B);

        if (NovaPos.x > 400 || NovaPos.x < 0 ){
            t_Vector VelColisio = {-1*B.Vel.x/CT_DURESA, B.Vel.y};
            ModificaVelocitat(&B, VelColisio);
            ActualitzaTrajectoria(&B,Grav);
        }

        if (NovaPos.y > 400 || NovaPos.y < 0 ){
            t_Vector VelColisio = {B.Vel.x, -1*B.Vel.y/CT_DURESA};
            ModificaVelocitat(&B, VelColisio);
            ActualitzaTrajectoria(&B,Grav);
        }

        Mou(&B, NovaPos);

        //Pinta(&B);

            acquire_screen();

           // if ( !Iguals(BollaAnt, B.Tj.Pos)) {
                circle(screen, BollaAnt.x, BollaAnt.y, 8, makecol(255, 255, 255));
                circle(screen, B.Pos.x, B.Pos.y, 8, makecol(0, 0, 0));
         //   }
           // if (posant != pos){
             circle(screen, (posant >> 16),(posant & 0x0000ffff), 2, makecol(255, 255, 255));
             circle(screen, (pos >> 16),(pos & 0x0000ffff), 2, makecol(0, 0, 0));
          //  }

            release_screen();
            usleep(20000);

    }


    return 0;
}
END_OF_MAIN()
