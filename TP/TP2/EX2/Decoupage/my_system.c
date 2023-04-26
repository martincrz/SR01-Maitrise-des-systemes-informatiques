#include "my_system.h"

int my_system(char *chaine) {
    char *args[] = {"/bin/echo", chaine, NULL};
    int fd, etat;
    pid_t pid;

    close(1); // fermeture du stdout

    if ((fd = open("nbr_premiers.txt", O_RDWR | O_APPEND | O_CREAT)) == -1) {
        perror("open");
        return 1;
    }

    pid=fork();

	if(pid == 0) execv(args[0], args);
	else wait(&etat);
}
