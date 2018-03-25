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
	insertln();
	move(y + 1, x);
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
// handles all command mode input
void commandmode(){
	char command;
	getmaxyx(stdscr, y, x);
	mvprintw(y, x, "Entering Command Mode");
	do{
		command = getch();
		move(y, x);
		switch(command){
			case 'i':
			printw("Entering Insert Mode.");
			return;
			default:
			mvprintw(y, x, "Invalid Command");
			break;
		}
	}while(true);
}
