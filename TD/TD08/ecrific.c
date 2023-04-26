#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main() {
int tab1[10]={11,22,33,44,55,66,77,88,99,1000};
int tab2[10];
int i;
//int fd;
int pfd[2];
pipe(pfd);

//fd=open("titi.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
//write (fd,tab1,10*sizeof(int));
write(pfd[1], tab1, 10*sizeof(int));
/*
close(fd);
fd=open("titi.txt",O_RDWR,0666);
for (i=0;i<10;i++){
	read(fd, &tab2[i], sizeof(int));
}
//read (fd,tab2,10*sizeof(int));
close(fd);*/



for (i=0;i<10;i++){
	read(pfd[0], &tab2[i], sizeof(int));
	printf("%d,%d\n",tab2[i],tab1[i]);
}
}
