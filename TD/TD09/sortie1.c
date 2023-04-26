#include <stdio.h>
#include <stdlib.h>

main(){
	int nbre;
	printf("Saisir valeur : ");
	scanf("%d", &nbre);
	if (nbre>=5 && nbre<=10){
		exit(0)	;
	}
	else {
		exit(1);
	}

}
