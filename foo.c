#include <stdio.h>
#include <stdlib.h>

int main()
{
	char read;
	FILE* file = fopen("file.txt", "r");
	
	if (file == NULL){
		printf("No file..\n");
		exit(0);
	}
	
	read = fgetc(file);
	while(read != EOF){
		printf("%c", read);
		read = fgetc(file);
	}
	
	fclose(file);
}
