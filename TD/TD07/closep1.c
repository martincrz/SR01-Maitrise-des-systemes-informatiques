#include <stdio.h>
#include <fcntl.h>

int main() {
	int pid,i,status;
	int fd,fd2;

	fd=open("toto.txt",O_RDWR|O_CREAT,0666); //emplacement libre > 3
	printf( "avant close\n");
	close(1); //ferme le stdout
	printf("apres close\n");
	dup (fd); //duplique un descripteur de fichier, le duplique dans la table de descripteur >> emplacement stdout
	printf("apres dup\n");
	close(fd); //ferme fd (pas le 1 !!! mais le 3)

	//on ferme le fd en 1
	close(1);
	//on ouvre le stdout
	open("/dev/tty", O_RDWR, 0666);
	printf("Le 4eme printf...\n");
}
