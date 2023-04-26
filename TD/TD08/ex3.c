#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



int main(void){
	int pld[2];
	int pid_fils;
	int nb_lignes;
	pipe(pld);
	pid_fils=fork();
	if (pid_fils==0){
		close(1);
		close(pld[0]);
		dup(pld[1]);
		execlp("ls", "ls",  "-la", 0);
	} 
	else {
		close(pld[1]);
		close(0);
		dup(pld[0]);
	wait(0);
		execlp("wc", "wc", "-l", 0);
		
	}
	
}


