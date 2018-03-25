#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "edit.h"

int main()
{
	initscr();
	cbreak();	
	noecho();
	keypad(stdscr, true);

	char read;
	FILE* file = fopen("file.txt", "r+");
	
	if (file == NULL){
		printw("No file..\n");
		exit(0);
	}
	
	read = fgetc(file);
	while(read != EOF){
		printw("%c", read);
		read = fgetc(file);
	}
	
	int choice, y, x;
	while(true){
		choice = getch();
		switch(choice){
			case KEY_LEFT:
			moveleft();
			break;
			case KEY_RIGHT:
			moveright();
			break;	
			case KEY_UP:
			moveup();
			break;
			case KEY_DOWN:
			movedown();
			break;
			case 'x':
			deleteline();
			break;
			case KEY_BACKSPACE:
			backspace();
			break;
			case 10:
			insertline();
			break;
			default:	
			break;
		}
	}
	endwin();
	
	fclose(file);
	return 0;
}
