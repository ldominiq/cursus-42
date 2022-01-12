#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "0", 1);
		
	}
	else if (sig == SIGUSR2)
	{
		write(1, "1", 1);

	}
}

int main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					x;
	int					*bin;

	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	bin = malloc(8);
	printf("Server pid: %d\n", getpid());
	while(1)
	{
		pause();
	}
	return (0);
}
