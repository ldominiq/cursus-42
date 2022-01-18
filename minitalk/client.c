/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:44:35 by ldominiq          #+#    #+#             */
/*   Updated: 2022/01/18 16:14:16 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *str, int pid)
{
	size_t	len;
	size_t	i;
	int		j;
	char	c;

	i = -1;
	len = ft_strlen(str);
	while (++i < len + 1)
	{
		c = str[i];
		j = 8;
		while (--j >= 0)
		{
			if (c & 1 << j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
	}
}

void	handle_response(int sig)
{
	(void)sig;
	ft_printf("Message received !\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;

	signal(SIGUSR1, handle_response);
	if (argc != 3)
		return ((void)ft_printf("Args error !\n"), 1);
	i = -1;
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid);
	while (1)
	{
		pause();
	}
	return (0);
}
