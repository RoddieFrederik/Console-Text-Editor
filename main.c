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
	// mode variable is declared in "edit.h"
	mode = 'i';
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
		refresh();
		choice = getch();
		getyx(stdscr, y, x);
		//if insert mode
		if(mode == 'i')
		switch(choice){
			case 27:
			commandmodeon();
			break;
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
			case KEY_BACKSPACE:
				backspace();
			break;
			case 10:
			if(mode == 'i')
				insertline();
			break;
			default:
				insertchar(choice);
			break;
		}
		//if command mode
		else
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
			case 'I':
			commandmodeoff();
			break;
			case 'X':
			deleteline();
			break;
			case 'O':
			insertline();
			break;
			default:
			mvprintw(31, 0, "Invalid Command.");
			move(y, x);
			break;
		}
	}
	endwin();
	
	fclose(file);
	return 0;
}
