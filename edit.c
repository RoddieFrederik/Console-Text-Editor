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
	insertln();
}
