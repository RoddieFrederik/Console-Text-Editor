#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	initscr();
	raw();
	char read;
	FILE* file = fopen("file.txt", "r");
	
	if (file == NULL){
		printw("No file..\n");
		exit(0);
	}
	
	read = fgetc(file);
	while(read != EOF){
		printw("%c", read);
		read = fgetc(file);
	}
	
	getch();
	endwin();
	
	fclose(file);
	return 0;
}
