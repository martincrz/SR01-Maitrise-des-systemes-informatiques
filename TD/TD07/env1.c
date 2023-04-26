//connaitre si TCSH ou BASH : echo $0
//si TCSH : setenv var val
//si BASH : export var val

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//setenv SR01TD8 Un_exemple_de_variable

void main(void){
	char nom_var[50], ex[50];
	printf("Saisir nom de la variable : ");
	scanf("%s", nom_var);

	printf("getenv(variable)=%s\n", getenv(nom_var));

	strcpy(ex,nom_var);
	strcat(ex,"=Un_exemple_de_variable_modifiee");
	putenv(ex);
	//putenv("$nom_var=Un_exemple_de_variable_modifiee");

	printf("Apres modif,\ngetenv(variable)=%s\n", getenv(nom_var));
	
	
	
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 main ()
{
	char var[50] , ex[50], *result;
	//var="SR01TD1=un_example_de_var_env_mofif";
	printf("nom variable :");
	scanf("%s",var);
	
	result=getenv(var);
	if(result!=NULL)
	{
	printf("notre variable initiale est %s\n", result);
	
	strcpy(ex,var);
	strcat(ex,"=val_modif");
	//printf("notre variable initiale est %s\n", getenv("SR01TD1"));
	putenv(ex);
	//printf("notre variable modifier est %s\n", getenv("SR01TD1"));
	printf("notre variable modifier est %s\n", getenv(var));
	}
	else 
	printf("\n c'est pas  une variable d'env \n");	
}*/

