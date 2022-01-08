#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigusr1(int sig)
{
	printf("SIGNAL RECEIVED\n");
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	int x;

	sa.sa_handler = &handle_sigusr1;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);

	printf("pid: %d\n", getpid());
	while(1)
	{
		printf("Waiting for signal\n");
		pause();
		sleep(1);
	}
	return (0);
}
