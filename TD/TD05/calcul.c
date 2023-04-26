#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char *argv[])
{
	float result=0 ;
	int i;
	if (!strcmp(argv[1],"-a")) 
		{
			for (i=2; i<argc; i++)
				result = result + atof(argv[i]);
		}
	else if (!strcmp(argv[1],"-p"))
		{
			result=1;
			for (i=2; i<argc; i++)
				result = result * atof(argv[i]);
		}
	else if (!strcmp(argv[1],"-d"))
		{
			if (argc==4)
				result = atof(argv[2])/atof(argv[3]);
		}
	printf("Resultat : %f\n", result);
	return(result);
}

