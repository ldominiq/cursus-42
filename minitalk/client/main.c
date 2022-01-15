#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	value;
	int	i;
	int	sign;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' \
			|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value *= 10;
		value += (str[i] - '0');
		i++;
	}
	return (value * sign);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	send_message(char *str, int pid) {
    size_t	len;
	size_t	i;
	int		j;
	char	c;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		c = str[i];
		j = 8;
		while (--j >= 0)
		{
			if (c & 1 << j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(80);
			//printf("%d : %c = %d\n", 1 << j, c, 1 << j & c);
		}
	}
}

int main(int argc, char *argv[])
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		printf("Args error !\n");
		return (1);
	}
	i = -1;
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	return (0);
}