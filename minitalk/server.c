/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:44:32 by ldominiq          #+#    #+#             */
/*   Updated: 2022/01/18 16:18:32 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sigusr(int sig, siginfo_t *infos, void *param)
{
	static char	bits = 0;
	static int	count = 0;

	(void)param;
	count++;
	bits = bits << 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	if (count == 8)
	{
		if (bits == 0)
			kill(infos->si_pid, SIGUSR1);
		ft_printf("%c", bits);
		bits = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server pid: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
