#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigusr1(int sig)
{
	printf("Yehee\n");
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	int x;

//	sleep(5);
//	kill(getpid(), SIGUSR1);
	sa.sa_handler = &handle_sigusr1;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);

	//signal(SIGTSTP, &handle_sigstp);
//	printf("Input: ");
//	scanf("%d", &x);
//	printf("Result %d * 5 = %d\n", x, x * 5);
//	int pid;
//
//	pid = fork();
//	if (pid == -1)
//		return (1);
	//printf("%d\n", getpid());
	//printf("Hello from id: %d\n", id);
//	if (pid == 0)
//	{
//	}
//	else
//	{
//		sleep(1);
//		kill(pid, SIGKILL);
//		wait(NULL);
//		printf("Hello from main process: %d\n", getpid());
//	}
	return (0);
}
