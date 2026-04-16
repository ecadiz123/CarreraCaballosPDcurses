#include <curses.h>

class caballo{

    public :
    int posicion;
    int suerte;
    char caracter;



};
class hipodromo{
    private:
	caballo caballos[5];
	int n_caballos;
	int pos_x;
	int pos_y;
	int largo_y;
	int largo_x;
	WINDOW *pista;
	int pos_llegada_x;

    public:
	hipodromo(int pos_y,int pos_x, caballo caballos[5]);//constructor, toma arreglo 5 caballos y posicion de hipodromo en pantalla
	
	//modificar cantidad caballos
	void quitar_caballo(caballo caballo_eliminar);
	void add_caballo(caballo caballo_add);
	//modificar tamaño pista
	void add_largo();//llamar solo cuando se quiera añadir 1 espacio horizontal
	void quitar_largo();//llamar solo cuando se quiera quitar 1 espacio horizontal
	//decidir ganador
	//hacer el roll
	//mover el caballo 
	//comenzar carrera
	//terminar carrera



	
};
