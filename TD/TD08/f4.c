#include <stdio.h>

void main(void){
	int pid_fils;

	pid_fils = fork();

	if (pid_fils==0){
		printf("ici le fils, mon pid est %d, le pid de mon père %d.\n", getpid(), getppid());
	}
	else {
		waitpid(pid_fils);

		pid_fils=fork();
		
		if (pid_fils==0){
			printf("ici le fils, mon pid est %d, le pid de mon père %d.\n", getpid(), getppid());
		}
		else{
			waitpid(pid_fils);
			printf("ici le pere, mon pid est %d, le pid de mon fils %d.\n", getpid(), pid_fils);
		}
		
		
	}
}
