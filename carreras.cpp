#include "carreras.hpp"


	hipodromo::hipodromo(int pos_y,int pos_x, caballo caballos[5])
    {

    };//constructor, toma arreglo 5 caballos y posicion de hipodromo en pantalla
	
	//modificar cantidad caballos
	void hipodromo:: mod_largo(){};
	void hipodromo:: quitar_caballo(caballo caballo_eliminar){};
	void hipodromo:: add_caballo(caballo caballo_add){};
	//modificar tamaño pista
    
	void hipodromo:: mod_largo(){};
	void hipodromo:: add_largo(){};//llamar solo cuando se quiera añadir 1 espacio horizontal
	void hipodromo:: quitar_largo(){};//llamar solo cuando se quiera quitar 1 espacio horizontal

	void hipodromo:: mover_caballo(caballo caballo_que_se_mueve){};
	//comenzar carrera
	void hipodromo:: carrera(){}; //contiene el loop de la carrera , al final ordena en orden de llegada a los caballos.