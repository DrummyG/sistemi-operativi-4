#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
    initscr(); noecho(); curs_set(0); nodelay(stdscr, true);
    int maxy = LINES, maxx = COLS, newx = 0, newy = 0, dirx = 1, diry = 1;
    int y = maxy/2, x = maxx/2;
    int UDELAY = 200000;

    //ESERCIZIO 1

    /*while(true) {
        getmaxyx(stdscr, maxy, maxx); // Lettura dinamica dimensione finestra
        clear();
        mvaddch(y, x, 'o'); // Stampa del carattere 'o' alla posizione x,y
        refresh(); // Aggiornamento schermo
        usleep(UDELAY); // Attesa in microsecondi

        newx = x + dirx; newy = y + diry; // Calcolo nuova posizione

        if(newx >= maxx || newx < 0){ // Controllo collisione con bordi x
            dirx *= -1;
            beep();
            flash();
            if(UDELAY > 10000) UDELAY -= 10000;
        }
        x += dirx;

        if(newy >= maxy || newy < 0){ // Controllo collisione con bordi y
            diry *= -1;
            beep();
            flash();
            if(UDELAY > 10000) UDELAY -= 10000;
        }
        y += diry;
        if(getch() == (int)'q') break; // Uscita con 'q'
    }
    endwin();*/

    //ESERCIZIO 2

    /*int y2 = maxy/3, x2 = maxx/3;
    int dirx2 = 2, diry2 = 2, newx2 = 0, newy2 = 0;

    while(true) {
        getmaxyx(stdscr, maxy, maxx); // Lettura dinamica dimensione finestra
        clear();
        mvaddch(y, x, 'o');
        mvaddch(y2, x2, '#'); // Stampa del carattere '#' alla posizione x2,y2
        refresh();
        usleep(UDELAY);

        newx = x + dirx; newy = y + diry; // Calcolo nuova posizione
        newx2 = x2 + dirx2; newy2 = y2 + diry2;

        if(newx >= maxx || newx < 0) dirx *= -1; // Controllo collisione con bordi
        if(newx2 >= maxx || newx2 < 0) dirx2 *= -1;
        if(newy >= maxy || newy < 0) diry *= -1;
        if(newy2 >= maxy || newy2 < 0) diry2 *= -1;

        if(abs(newy - newy2) <= 1 && abs(newx - newx2) <= 1){ // Controllo collisione tra i due caratteri
            flash();
            dirx *= -1;
            dirx2 *= -1;
            diry *= -1;
            diry2 *= -1;
        }

        x += dirx; // Aggiornamento posizione
        x2 += dirx2;
        y += diry;
        y2 += diry2;

        if(getch() == (int)'q') break;
    }
    endwin();*/

    //ESERCIZIO 3

    char sprite1[6]={"<-|->"}; // Dichiarazione sprite

    while(true) {
        getmaxyx(stdscr, maxy, maxx); // Lettura dinamica dimensione finestra
        clear();
        for(int i = 0; i < strlen(sprite1); i++){ // Stampa sprite
            mvaddch(y, x+i, sprite1[i]);
        }
        refresh();
        usleep(UDELAY);

        newx = x + dirx; // Calcolo nuova posizione
        newy = y + diry;

        if(newx >= maxx || newx < 0) dirx *= -1; // Controllo collisione con bordi
        x += dirx;
        newy = y + diry;
        if(newy >= maxy || newy < 0) diry *= -1;
        y += diry;

        if(getch() == (int)'q') break;
    }
    endwin();
}
