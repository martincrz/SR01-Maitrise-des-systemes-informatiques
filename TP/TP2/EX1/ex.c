#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid;
    int i;
    printf("Mon pid est : %d \n", getpid());
    for (i=1;i<=4;i++){
        pid=fork();
        if (pid==-1){
            perror("main/fork");
            return EXIT_FAILURE;
        }
        if (pid==0){
            printf("Mon pid est : %d et le pid de mon père est : %d \n", getpid(), getppid());
        }
        wait(pid);

    }
    return EXIT_SUCCESS;
}
