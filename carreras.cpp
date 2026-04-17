#include "carreras.hpp"


	hipodromo::hipodromo(int pos_y_ingreso,int pos_x_ingreso, caballo caballos_ingreso[5])
    {
        largo_x=10;
        largo_y=11;//valores minimos x e y
        pos_x=pos_x_ingreso;
        pos_y=pos_y_ingreso;
        pista=newwin(largo_y,largo_x,pos_y,pos_x);//se crea ventana 
        refresh();
        box(pista,0,0);
        wrefresh(pista);//muestra pista
        for(int i=0;i<5;i++)
        {
        caballos[i]=caballos_ingreso[i];
        }
        n_caballos=5;//comienza con 5 por defecto
        pos_llegada_x=getmaxx(pista)-1;//llegada por defecto es el anterior a llegar al borde

    };//constructor, toma arreglo 5 caballos y posicion de hipodromo en pantalla
	
	//modificar cantidad caballos
	void hipodromo:: quitar_caballo(caballo caballo_eliminar){};
	void hipodromo:: add_caballo(caballo caballo_add){};
	//modificar tamaño pista
    
	void hipodromo:: mod_largo(){
        
        keypad(pista,true);//activa flechas para largo
        bool salida = false;
        while(salida!=true)
        {
        int input=wgetch(pista);
        switch (input)
        {
        case KEY_LEFT:
            quitar_largo(); // quita un largo
            break;
        case KEY_RIGHT:
            add_largo(); // añade un largo
        case 'E':
            salida == true;
            break;
        case 'e':
            salida == true;
            break;
        default:
            break;
        }
        }
    };
    void hipodromo::add_largo() {
        
        int max_x_pantalla=getmaxx(stdscr);//largo maximo 
        if(largo_x+1<max_x_pantalla)//si no se pasa de tamaño pantalla;
        {
            largo_x++;
            pos_llegada_x++;
            wresize(pista,largo_y,largo_x);
            wclear(pista);//limpia la linea que queda atras
            wrefresh(pista);
            box(pista,0,0);
            wrefresh(pista);//aparece caja


        }

        //si se pasa no hace nada

    };    // llamar solo cuando se quiera añadir 1 espacio horizontal
    void hipodromo::quitar_largo() {
        

        int max_x_pantalla=5;
        //largo minimo=5
        if(largo_x+1<max_x_pantalla)//si no se pasa de tamaño pantalla;
        {
            largo_x--;
            pos_llegada_x--;
            wresize(pista,largo_y,largo_x);
            wclear(pista);//limpia la linea que queda atras
            wrefresh(pista);
            box(pista,0,0);
            wrefresh(pista);//aparece caja


        }

    }; // llamar solo cuando se quiera quitar 1 espacio horizontal

    void hipodromo::mover_caballo(caballo caballo_que_se_mueve) {};
    // comenzar carrera
    void hipodromo::carrera() {}; // contiene el loop de la carrera , al final ordena en orden de llegada a los caballos.