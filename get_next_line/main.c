/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:20:21 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/21 14:51:33 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;
	int		i;	

	i = 6;
	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error\n");
		return (1);
	}
	while (i--)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	return (0);
}
