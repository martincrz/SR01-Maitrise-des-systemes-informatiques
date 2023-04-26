#include <stdio.h>
#include <stdlib.h>

/*Ã‰crire un programme "exec1.c" qui exÃ©cute successivement avec la fonction system() les deux commandes : "/bin/ls -la " et "/bin/ls *.c". */

main(){
	system("/bin/ls -la ");
	system("/bin/ls *.c");

}
