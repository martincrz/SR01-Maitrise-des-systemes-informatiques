#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int premier(int nb)
{
    int r=0;

    for(int i = 1 ; i <= nb ; i++ )
    {
        if(nb % i == 0)
        {
           r++;
        }
    }

    if(r>2)
       return 0;
    else
       return 1;

}

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


void explorer(int debut, int fin){
  int etat,pid,pid2;
  pid=fork();
  if(pid==0){
    for (int i=debut; i<=fin;i++){
      if (premier(i)==1) {
        pid2=fork();
        fflush(stdout);
        if (pid2==0){
          char chaine[234];
          sprintf(chaine,"%d  est un nombre premier. Le PID du processus qui a appelé my_system() est %d et le PID de son père est %d",i,getpid(), getppid());
          my_system(chaine);
          sleep(2);
          exit(0);
        }
        else wait(&etat);// instruction 41
      }

    }
    exit(0);
  } else wait(&etat);// instruction 46
}


int main(){
  int grp=1;
  while(grp<=11){
    explorer(grp+1,grp+10);
    grp=grp+10;

  }
}

