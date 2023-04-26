/*créer un programme "sortie2.c" qui fait un appel à la fonction atexit(void (*fonc)) pour provoquer l'exécution de la fonction "fonc" juste
avant la sortie du programme par exit(). Faites un test en faisant sortir le programme par exit() ou par envoi d'un "control-C".*/

#include <stdio.h>
#include <stdlib.h>

void fonc(){
	printf("terminaison\n");
}


main() {
	if (atexit(fonc) == 0){
		sleep(10);
		printf("test\n");
		exit(1);
	}
}

/*
atexit(fonc);
sleep(5);
exit(0);
*/
