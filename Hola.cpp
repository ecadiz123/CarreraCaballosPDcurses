#include <curses.h>
#include <windows.h>        //Uso de sleep
#include <cstdlib>          //Uso de Rand
#include <ctime>
#include "carreras.hpp"
void carrera();
void escribe_caballo(caballo caballo, WINDOW * ventana);
int main()
{
    initscr();
    cbreak();
    carrera();
    endwin();
    return 0;
}
void carrera()
{

    srand(time(NULL));
    caballo arreglo_caballos[5];
    for(int i=0;i<5;i++)
    {
        arreglo_caballos[i].caracter = 65+i;
        arreglo_caballos[i].posicion_x = 1;
        arreglo_caballos[i].posicion_y = i*2+1;
        arreglo_caballos[i].suerte = 50;
    }
    
    //hipodromo mi_hipodromo;
    noecho(); //No retorno al pulsar tecla
    int meta = 70, ancho = 11;  //Tamaños de la pista
    WINDOW *ventana_carrerra = newwin(ancho,meta,0,0);
    box(ventana_carrerra,0,0);
    for(int i=2;i<ancho;i=i+2)
    {
        for(int j=1;j<meta-1;j++)
        {
            mvwprintw(ventana_carrerra,i,j,"-");
        }
    }
    refresh();
    wrefresh(ventana_carrerra);

    int pos_caballo_x = 1;  //Posicion inicial de caballo x
    int pos_caballo_y = 1;
    int vigilante = 0;  //Vigila quien va en primer lugar 


    //Posiciona los caballos
    mvwprintw(ventana_carrerra,1,pos_caballo_x,"@");
    mvwprintw(ventana_carrerra,3,pos_caballo_x,"#");
    mvwprintw(ventana_carrerra,5,pos_caballo_x,"?");
    mvwprintw(ventana_carrerra,7,pos_caballo_x,"&");
    mvwprintw(ventana_carrerra,9,pos_caballo_x,"¿");
    wrefresh(ventana_carrerra);
   

    getch(); //Despues de ingresar input por teclado inicia carrera
    while(vigilante!=meta-3)
    {
        for(int i=0;i<5;i++)
        {
            if(arreglo_caballos[i].posicion_x>vigilante)
            {
                vigilante = arreglo_caballos[i].posicion_x;
            }
        }
         
        for(int i=0;i<5;i++)
        {
            if(int random =(rand()%100)+1>arreglo_caballos[i].suerte)
            {
                arreglo_caballos[i].posicion_x++;   //Actualizacion de posicion caballo x
            }
            escribe_caballo(arreglo_caballos[i],ventana_carrerra);
        }
        
        wrefresh(ventana_carrerra);
        refresh();
        
        Sleep(50); 
    }
    getch();
}; 

void escribe_caballo(caballo caballo, WINDOW * ventana)
{
    mvwprintw(ventana,caballo.posicion_y,caballo.posicion_x,"%c",caballo.caracter);    //Reimpresion de posicion de x
    mvwprintw(ventana,caballo.posicion_y,caballo.posicion_x-1," ");  //borrado de paso de x por la pista
}