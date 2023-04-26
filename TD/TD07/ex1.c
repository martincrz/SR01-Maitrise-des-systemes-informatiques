#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void)
{

	//PID : pid du processus appelant
	//PPID : pid du père du processus appelant
	//UID : L’identifiant de l’utilisateur correspondant au processus
	//GID : L’identifiant du groupe de l’utilisateur (GID) qui a lancé le processus
	//PGID : Le numéro du groupe du processus
	//SID : Le numéro de session du processus

	printf("Mon PID est : %ld\n", (long) getpid());
	printf("Le PID du mon pre : %ld\n", (long) getppid());
	printf("Processus %d : UID=%d, GID=%d, PGID=%d, SID=%d\n", (long) getpid(), getuid(), getgid(), getpgid(getpid()), getsid(getpid()));

return 0;
}


