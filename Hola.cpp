#include <curses.h>
#include <windows.h>        //Uso de sleep
#include <cstdlib>          //Uso de Rand

void carrera();

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
        pos_caballo_x ++;   //Actualizacion de posicion caballo x
        vigilante++;    //Cambiar solo de prueba 

        mvwprintw(ventana_carrerra,1,pos_caballo_x,"@");    //Reimpresion de posicion de x
        mvwprintw(ventana_carrerra,1,pos_caballo_x-1," ");  //borrado de paso de x por la pista
       
        wrefresh(ventana_carrerra);
        refresh();
 
        
        Sleep(50); 
    }
    getch();
}; 