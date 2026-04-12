
#include <curses.h>


int main()
{
	
	initscr();//Inicia curses
	cbreak();//mantiene ctrl-c para terminar
	endwin();//para cerrar curses y que termine sin problemas

	return 0;
}
