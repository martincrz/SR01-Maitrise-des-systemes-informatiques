/* premier progamme*/
#include <stdio.h>
#define MAX 4


int main(void)
{
    int tab1[MAX]={1,2,3,4};
          int tab2[MAX]={1,2,3,4};
          int tab3[MAX];
      int i;
      int *p1,*p2,*p3;
      p1=tab1;
      p2=tab2+MAX-1;
      p3=tab3;
      for (i=0;i<MAX;i++)
      {
          //tab3[i]=tab1[i]+tab2[MAX-i-1];
          *p3=*p1+*p2;
          p1++;
          p2--;
          p3++;
      }
      
      printf("TAB3= [");
      for (i=0;i<MAX;i++)
          printf("%d ",tab3[i]);
      printf("]\n");
      return(0);


}
