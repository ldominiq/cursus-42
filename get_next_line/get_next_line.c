/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:20:21 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/21 14:51:33 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		ret;
	int		i;
	
	i = 0;
	ret = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(buffer) + 1);
	if (buffer == NULL)
		return (NULL);
	while ((ret = read(fd, buffer, BUFFER_SIZE)))
	{
		printf("%d\n", i);
		buffer[ret] = 0;
		i++;
	}
	//ft_putstr_fd(buffer, fd);
	printf("%s\n", buffer);
	return (buffer);
}
