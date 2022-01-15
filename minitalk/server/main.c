#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*strsrc;
	char	*strdst;
	size_t	i;

	strsrc = (char *)src;
	strdst = dst;
	i = -1;
	if (dst != NULL || src != NULL)
	{
		while (++i < n)
			strdst[i] = strsrc[i];
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1len;

	s1len = ft_strlen(s1) + 1;
	ptr = malloc(s1len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1len);
	return (ptr);
}

static void	convert_sig(char *s)
{
	int				pow;
	unsigned char	c;
	int				i;

	pow = 1;
	c = 0;
	i = 8;
	while (--i > 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
	}
	write(1, &c, 1);
}

static void	handle_sigusr(int sig)
{
	static char	*bits;
	static int	count;

	count++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		count = 1;
	}
	if (sig == SIGUSR1)
		bits = strcat(bits, "1");
	else
		bits = strcat(bits, "0");
	if (count == 8)
	{
		convert_sig(bits);
		free(bits);
		bits = NULL;
	}
}

int main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server pid: %d\n", getpid());
	while(1)
	{
		pause();
	}
	return (0);
}
