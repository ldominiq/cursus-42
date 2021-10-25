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

char	*ft_str_construct(char *str, char *tmp)
{
	if (!str)
		str = ft_strdup(tmp);
	else
		str = ft_strjoin(str, tmp);
	return (str);
}

char	*ft_newline_lookup(int idx, char *str, char *buffer, int fd)
{
	int		j;
	char	*tmp;

	j = 0;
	while (idx)
	{
		idx = read(fd, buffer, BUFFER_SIZE);
		buffer[idx] = 0;
		tmp = ft_strdup(buffer);
		while (tmp[j])
		{
			if (tmp[j] == '\n')
			{
				tmp = ft_substr(tmp, 0, j + 1);
				str = ft_str_construct(str, tmp);
				buffer = ft_substr(buffer, j + 1, BUFFER_SIZE - j);
				return (str);
			}
			j++;
		}
		j = 0;
		str = ft_str_construct(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*str;
	static int	idx;

	idx = 1;
	if (fd < 0)
		return (NULL);
	if (buffer != NULL)
		str = ft_strdup(buffer);
	if (!idx)
		return (str);
	buffer = malloc(BUFFER_SIZE * sizeof(buffer) + 1);
	if (buffer == NULL)
		return (NULL);
	str = ft_newline_lookup(idx, str, buffer, fd);
	return (str);
}
