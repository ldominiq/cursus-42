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

char	*str_to_binary(char *str, int pid) {
    size_t	len;
    char	*binary;
	size_t	i;
	int		j;
	char	c;
	int		test;

	if (str == NULL)
		return (0);
	i = -1;
	len = ft_strlen(str);
	binary = malloc((len * 8) + 1);
    binary[0] = '\0';
	while (++i < len)
	{
		c = str[i];
		j = 8;
		while (--j >= 0)
		{
			if (c & 1 << j)
				strcat(binary, "1");
			else
				strcat(binary, "0");
			//printf("%d : %c = %d\n", 1 << j, c, 1 << j & c);
		}
	}
	return (binary);
}

int main(int argc, char *argv[])
{
	int		pid;
	char	*bin;
	int		i;

	if (argc != 3)
	{
		printf("Args error !\n");
		return (1);
	}
	i = -1;
	pid = ft_atoi(argv[1]);
	bin = str_to_binary(argv[2], pid);
	printf("text: %s | binary: %s\n", argv[2], bin);
	while (bin[++i])
	{
		if (bin[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(10);
	}
	free(bin);
	return (0);
}