#include <ncurses.h>
#include <stdlib.h>

int y, x;
char mode;
char * buffer, status, filename;
/* move*() functions move the cursor one space*/
void moveup(); 
void movedown();
void moveleft();
void moveright();

void deleteline(); // delete current line

void insertline(); // insert a line at current position

void printbuffer(); 

void savefile();
