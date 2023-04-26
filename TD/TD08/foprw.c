#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 80

int main()
{ 
  FILE * in, *out;
  char buf[4]="xxx";
  buf[3]='\n';
char c;
  int n;
  in = fopen("fop.in","r");
  out =fopen("fop.out","a+");
 
  while (!feof(in)){
	
 	n = fread(&c, 1, 1, in);
	if (n==1){
           //printf("test %c", c);
	   if (c!='\n'){
		fwrite(&c, 1, 1, out);
	   }
	   else {
		fwrite(buf, 1, 4, out);
           }
        }
  }


}
