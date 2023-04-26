#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void my_system(char *path, char *argv[]){
	execv(path, argv);
}

void main(){
	char *tab[]= {"ls", "-la",NULL};
	my_system("/bin/ls", tab);

	char *tab2[]={"ls", "*.c",NULL};
	my_system("/bin/ls", tab2);
}

