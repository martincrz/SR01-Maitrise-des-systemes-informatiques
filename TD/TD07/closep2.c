#include <stdio.h>
#include <fcntl.h>

main() {
	int pid,i,status;
	int fd,fd2;

	fd=open("toto.txt",O_RDWR|O_CREAT,0666);
	printf( "avant close\n");

	fd2 = dup(1);
	close(1);
	printf("apres close\n");
	dup (fd);
	printf("apres dup\n");
	close(fd);


	close(1);
	dup(fd2);	
	
	printf("Le 4eme printf...\n");
}
