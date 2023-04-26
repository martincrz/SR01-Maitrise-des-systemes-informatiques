#include <signal.h> /* sigaction... */
#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */

void main(void){
	int status;
	int pid_fils;

	pid_fils = fork();

	if (pid_fils==0){
		printf("ici le fils, mon pid est %d, le pid de mon père %d.\n", getpid(), getppid());
		exit(8);
	}
	else {
		wait(&status);
		printf("ici le pere, mon pid est %d, le pid de mon fils %d.\n", getpid(), pid_fils);
	}

WEXITSTATUS(status);
}
