#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "mystr.h"

void mystrupdown(char *s1, char *s2)          
/* inverse les majuscules et les minuscules de s1 et retourne le resultat dans s2 exemple: s1="TiCtAc"  s2="tIcTaC" */
{
   // int i = 0;
 
    //Tant que nous ne sommes pas arrivés a la fin de la chaine, continuer
    for (int i=0; i<strlen(s1);i++)
    {
	//printf("etudions %c\n", s1[i]);
	//printf("boolean : %d\n",(s1[i]  >= 97 &&  s1[i] <= 122));
        if (s1[i]  >= 'a' &&  s1[i] <= 'z')
  		{
		//printf("t : %d\n", s1[i] - 32);
		//printf("%c remplace par %c\n", s2[i],s1[i] - 32 );
		s2[i] = (s1[i] - 'a')+'A';
		//printf("t\n");
		}
            

	else if (s1[i]  >= 'A' &&  s1[i] <= 'Z')
             
            //Convertir en minuscules
            s2[i] = s1[i] + 32;

	else s2[i] = s1[i];
    }
    
}


void mystrinv(char *s1, char *s2)        
// inverse la chaîne s1 et retoune le résultat dans s2:   exemple  s1="tac" s2="cat"
{
	int k=0;
	int i = strlen(s1)-1;
	while (i>=0)
	{
		s2[k]=s1[i];
		k++;
		i--;
	}
	printf("s2 = %s\n", s2);
	
}


int mystrchrn(char *s, char c)                        
//retourne le nombre d'occurrences de c dans  la chaîne s
{
	int nb=0;
	for (int i=0; i<strlen(s); i++)
	{
		if (s[i]==c) nb++;
	}
	printf("occurences : %d\n", nb);
	return (nb);
}


void mystrncpy(char *s1, char *s2, int n)      
// copie les n derniers caractères de s1 dans s2 et retourne s2 
{
	int k=0;
	for (int i=strlen(s1)-n; i<strlen(s1); i++)
	{
		s2[k]=s1[i];
		k++;
	}
	printf("s2 = %s\n", s2);
}

void mystrncat(char *s1, char *s2, int n)      
//concatène au plus les n derniers caractères de s1 à la chaîne s2 

{
	int k=0;
	for (int i=strlen(s1)-n; i<strlen(s1); i++)
	{
		s2[strlen(s2)+k]=s1[i];
		k++;

	}
	printf("s2 = %s\n", s2);
}


int main(){
	char * s1= "AbcD";
	char *s2 = malloc(sizeof(s1));
	// mystrupdown(s1, s2);
	//mystrinv(s1, s2);
	//printf("%d",mystrchrn(s1, 'b'));
	//printf("%s\n", s2);
	//mystrncpy(s1, s2, 2);
	mystrncat(s1, s2, 2);
	return 0;
	}
