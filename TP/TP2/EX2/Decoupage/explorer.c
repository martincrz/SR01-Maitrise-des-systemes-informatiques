#include "explorer.h"

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
          sprintf(chaine,"Explorer.c modifie, compile par MakefileOpt %d  est un nombre premier. Le PID du processus qui a appelÃ© my_system() est %d et le PID de son pÃ¨re est %d",i,getpid(), getppid());
          my_system(chaine);
          sleep(0);
          exit(0);
        }
        else wait(&etat);// instruction 41
      }

    }
    exit(0);
  } else wait(&etat);// instruction 46
}

