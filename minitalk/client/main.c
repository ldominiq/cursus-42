#include <stdio.h>
#include <signal.h>

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

int main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		printf("Args error !\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}