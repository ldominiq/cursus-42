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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		ret;
	char	*str;
	int		i;

	ret = 0;
	buffer = malloc(BUFFER_SIZE * sizeof(buffer) + 1);
	if (buffer == NULL)
		return (NULL);
	
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = 0;
	while ()
	{

	}
	return (str);
}
