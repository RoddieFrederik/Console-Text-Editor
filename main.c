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
	/* mode variable is declared in "edit.h"
	default mode is insert mode */
	mode = 'i';
	// open a file with read and write permission
	char read;
	FILE* file = fopen("file.txt", "r+");
	if (file == NULL){
		printw("No file..\n");
		exit(0);
	}
	// display the file in new ncurses window
	read = fgetc(file);
	while(read != EOF){
		printw("%c", read);
		read = fgetc(file);
	}
	// choice: user input
	// y and x used to track and move cursor
	int choice, y, x;
	while(true){
		refresh(); // refresh screen image
		choice = getch(); // take user input
		getyx(stdscr, y, x); // find cursor position
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
			case 10: // 10 = new line character
			if(mode == 'i')
				insertline();
			break;
			default: // if no special cases insert character
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
			case 'I': // disable command mode
			commandmodeoff();
			break;
			case 'X': // delete current line
			deleteline();
			break;
			case 'O': // insert new line
			insertline();
			break;
			default: // invalid
			mvprintw(31, 0, "Invalid Command.");
			move(y, x);
			break;
		}
	}
	endwin();
	
	fclose(file);
	return 0;
}
