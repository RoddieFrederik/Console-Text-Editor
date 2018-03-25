#include <ncurses.h>
#include <stdlib.h>

int y, x;
char mode; // stores the current mode of the editor
char * buffer, filename;
/* move*() functions move the cursor one space*/
void moveup(); 
void movedown();
void moveleft();
void moveright();

void deleteline(); // delete current line
void backspace(); // delete the character to the left of the cursor

void insertline(); // insert a line at current position
void insertchar(char c); // inserts a character 'c' at current position

void printbuffer(); 

void savefile();

void commandmodeon(); // enable command mode
void commandmodeoff(); // disable command mode
