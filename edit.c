#include "edit.h"
// move the cursor up one position
void moveup()
{	
	getyx(stdscr, y, x);
	move(y - 1, x);
}
// move the cursor down one position
void movedown(){
	getyx(stdscr, y, x);
	move(y + 1, x);
}
// move the cursor left one postion
void moveleft(){
	getyx(stdscr, y, x);
	move(y, x - 1);
}
// move the cursor right one position
void moveright(){
	getyx(stdscr, y, x);
	move(y, x + 1);
}
// delete the current line
void deleteline(){
	deleteln();
}
// insert a line at the current position
void insertline(){
	getyx(stdscr, y, x);
	move(y + 1, 0);
	insertln();
}
// delete the character to the left of the cursor
void backspace(){
	getyx(stdscr, y, x);
	mvdelch(y, x - 1);
}
// insert a character and shift line to the right
void insertchar(char c){
	getyx(stdscr, y, x);
	insch(c);
	move(y, x + 1);	
}
// enable command mode
void commandmodeon(){
	wclear(stdscr);
	printw("%s\n", buffer); 
	getyx(stdscr, y, x);
	move(30, 0);
	deleteline();
	printw("Command Mode: 'I': Enable Insert Mode 'X': Delete Line 'O': Insert Line 'S': Save File");
	move(y, x);
	mode = 'c';
}
// disable command mode
void commandmodeoff(){
	getyx(stdscr, y,x);
	move(30, 0);
	deleteline();
	deleteline();
	printw("Insert Mode:");
	move(y, x);
	mode = 'i';
}
