#include <curses.h>
#include <string>
//#include "carrera.hpp"

using namespace std;
void editar_caballos();
void editar_hipodromo();
void editar_largo_pista(int &largo_pista);
void editar_cantidad_caballos();
void editar_suerte_caballos();
void editar_valor_suerte(int caballo, int suerte[]);

void editar_hipodromo()
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 16) / 2, "EDITAR PISTA");

    int ancho = 50;
    WINDOW * menuwin = newwin(8, xMax-10 , 12, 5);
    box(menuwin, 0, 0);

    string choices[2] = {"Editar largo de pista","Volver"};
    int choice;
    int highlight = 0;

    keypad(menuwin, true);

    static int largo_pista = 50;

    while(1){
        box(menuwin, 0, 0);
        int ancho = getmaxx(menuwin);
        for (int i = 0; i < 2; i++){
            int x = (ancho - choices[i].length()) / 2;
            if (i == highlight)
            wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 2, x, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + 2) % 2;
            break;
        case KEY_DOWN:
            highlight = (highlight + 1) % 2;
            break;
        case 10:
            if (highlight == 0){
                editar_largo_pista(largo_pista);
            }
            else if (highlight ==1 ) {
                delwin(menuwin);
                return;
            }
            break;
        }
    }

    mvwprintw(menuwin, 2, (ancho - 30) / 2, "Aqui se editara el largo de pista");

    wrefresh(menuwin);
    wgetch(menuwin); // esperar tecla
}

void editar_largo_pista(int &largo_pista)
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 22) / 2, "EDITAR LARGO PISTA");

    WINDOW *menuwin = newwin(8, 50, 12, (xMax - 50) / 2);
    keypad(menuwin, true);

    int valor = largo_pista;
    int choice;

    while (1)
    {
        werase(menuwin);
        box(menuwin, 0, 0);

        string texto = "Largo: " + to_string(valor) + "%";
        mvwprintw(menuwin, 2, (50 - texto.length()) / 2, texto.c_str());

        int ancho_barra = (valor * (50 - 6)) / 100; // -6 por bordes

        mvwprintw(menuwin, 4, 2, "[");
        for (int i = 0; i < ancho_barra; i++)
            mvwprintw(menuwin, 4, 3 + i, "=");
        mvwprintw(menuwin, 4, 3 + ancho_barra, "]");

        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_LEFT:
            if (valor > 1) valor--;
            break;
        case KEY_RIGHT:
            if (valor < 100) valor++;
            break;
        case 10:
            largo_pista = valor;
            delwin(menuwin);
            return;
        }
    }
}

void editar_caballos()
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 20) / 2, "EDITAR CABALLOS");

 
    WINDOW * menuwin = newwin (8, xMax-10, 12, 5);  
    box(menuwin, 0, 0);

    string choices[3] = {"Cantidad de caballos","Suerte de caballos","Volver"};
    int choice;
    int highlight = 0;

    keypad(menuwin, true);

    while(1){
        box(menuwin,0,0);
        int ancho = getmaxx(menuwin);
        for (int i = 0; i < 3; i++){
            int x = (ancho - choices[i].length()) / 2;
            if (i == highlight)
            wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 2, x, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + 3) % 3;
            break;
        case KEY_DOWN:
            highlight = (highlight + 1) % 3;
            break;
        case 10:
            if (highlight == 0)
                editar_cantidad_caballos();
            else if (highlight == 1)
                editar_suerte_caballos();
            else if (highlight == 2)
                return;
            break;
        }
    }
}

void editar_cantidad_caballos()
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 28) / 2, "CANTIDAD DE CABALLOS");

    WINDOW * menuwin = newwin(8, 30, 12, (xMax - 30) / 2);
    keypad(menuwin, true);

    int opciones[4] = {2, 3, 4, 5};
    int highlight = 0;
    int choice;

    while (1)
    {
        werase(menuwin);
        box(menuwin, 0, 0);

        for (int i = 0; i < 4; i++)
        {
            string texto = to_string(opciones[i]);
            int x = (30 - texto.length()) / 2;
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, x, texto.c_str());
            wattroff(menuwin, A_REVERSE);
        }

        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + 4) % 4;
            break;
        case KEY_DOWN:
            highlight = (highlight + 1) % 4;
            break;
        case 10:
            delwin(menuwin);
            return; // vuelve a editar_caballos
        }
    }
}

void editar_suerte_caballos()
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 26) / 2, "SELECCIONAR CABALLO");

    WINDOW * menuwin = newwin(8, 30, 12, (xMax - 30) / 2);
    keypad(menuwin, true);

    static int suerte [5] = {50,50,50,50,50};

    string caballos[6] = {
        "Caballo 1",
        "Caballo 2",
        "Caballo 3",
        "Caballo 4",
        "Caballo 5",
        "Volver"
    };

    int highlight = 0;
    int choice;

    while (1)
    {
        werase(menuwin);
        box(menuwin, 0, 0);

        int ancho = getmaxx(menuwin);

        for (int i = 0; i < 6; i++)
        {
            string texto;
            if (i < 5)
                texto = caballos[i] + " (" + to_string(suerte[i]) + ")";
            else
                texto = caballos[i];
            int x = (ancho - texto.length()) / 2;
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, x, texto.c_str());
            wattroff(menuwin, A_REVERSE);
        }

        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + 6) % 6;
            break;

        case KEY_DOWN:
            highlight = (highlight + 1) % 6;
            break;
        case 10:
            if (highlight == 5){
                delwin(menuwin);
                return;
            }
            else{
                editar_valor_suerte(highlight, suerte);
            }
    break;
        }
    }
}

void editar_valor_suerte(int caballo, int suerte[])
{
    clear();
    box(stdscr, 0, 0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(2, (xMax - 22) / 2, "EDITAR SUERTE");

    WINDOW * menuwin = newwin(8, 40, (yMax - 5) / 2, (xMax - 40) / 2);
    keypad(menuwin, true);

    int valor = suerte [caballo]; // valor de suerte
    int choice;

    while (1)
    {
        werase(menuwin);
        box(menuwin, 0, 0);

        string texto1 = "Caballo " + to_string(caballo + 1);
        string texto2 = "Valor: " + to_string(valor);

        mvwprintw(menuwin, 2, (40 - texto1.length()) / 2, texto1.c_str());
        mvwprintw(menuwin, 4, (40 - texto2.length()) / 2, texto2.c_str());

        wrefresh(menuwin);
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_LEFT:
            if (valor > 1) valor--;
            break;

        case KEY_RIGHT:
            if (valor < 100) valor++;
            break;

        case 10:
            suerte[caballo] = valor; //guardamos la suerte
            return; // vuelve a selección de caballo
        }
    }
}

int main()
{
    initscr();               //iniciar curses
    noecho();               //no mostrar teclas
    cbreak();               // input inmediato

    //Obtener tamaño de pantalla
    int yMax, xMax;
    getmaxyx (stdscr, yMax, xMax);
    box(stdscr, 0, 0);

    //TITULO
    string titulo[] = {
"  ____    _    ____  ____  _____ ____    _    ",
" / ___|  / \\  |  _ \\|  _ \\| ____|  _ \\  / \\   ",
"| |     / _ \\ | |_) | |_) |  _| | |_)  / _ \\  ",
"| |___ / ___ \\|  _ <|  _ <| |___|  _ </ ___ \\ ",
"  \\____/_/   \\_\\_| \\_\\_| \\_\\_____|_| \\/_/   \\_\\",
"   ____    _    ____    _    _     _     ___  ____  ",
"  / ___|  / \\  | __ )  / \\  | |   | |   / _ \\/ ___| ",
" | |     / _ \\ |  _ \\ / _ \\ | |   | |  | | | \\___ \\ ",
" | |___ / ___ \\| |_) / ___ \\| |___| |__| |_| |___) |",
"  \\____/_/   \\_\\____/_/   \\_\\_____|_____\\___/|____/ "
};
int altura_titulo = 10;

    attron(A_BOLD);
    for (int i = 0; i < 10; i++) {
        mvprintw(i + 1, (xMax - titulo[i].length()) / 2, titulo[i].c_str());
    }
    attroff(A_BOLD);

    //crear ventana
    WINDOW * menuwin = newwin (8, xMax-10, altura_titulo + 2 , 5); // (altura, ancho, coordY, coordX)
    box (menuwin ,0,0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);   // habilitar flechas

    string choices [4] = {"Competir", "Editar Caballo", "Editar Hipodromo", "Salir"};
    int choice;
    int highlight = 0;

    while(1){
        box(menuwin,0,0);

        int ancho = getmaxx(menuwin);
        for (int i = 0; i < 4 ; i++){
            int x = (ancho - choices[i].length()) / 2;
            if(i==highlight)
            wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, x, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + 4) % 4;
            break;
        case KEY_DOWN:
            highlight = (highlight + 1) % 4;
            break;
        default:
            break;
        }
        if (choice == 10){
            switch (highlight){
                case 0:
                //carrera();
                break;
                
                case 1:
                editar_caballos();
                break;
                
                case 2:
                editar_hipodromo();
                break;
                
                case 3:
                endwin();
                return 0;
            }
        }
    }




    getch();
    endwin();

    return 0;
}