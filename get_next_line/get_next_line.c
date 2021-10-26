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
		if (idx == -1)
			return (NULL);
		if (idx <= 0)
		{
			free(str);
			return (NULL);
		}
		buffer[idx] = 0;
		tmp = ft_strdup(buffer);
		while (tmp[j])
		{
			if (tmp[j] == '\n')
			{
				tmp = ft_substr(tmp, 0, j + 1);
				str = ft_str_construct(str, tmp);
				free(tmp);
				buffer = ft_substr(buffer, j + 1, BUFFER_SIZE - j);
				return (str);
			}
			j++;
		}
		j = 0;
		str = ft_str_construct(str, tmp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*str;
	static int	idx = 1;

	if (!idx)
		return (str);
	str = ft_newline_lookup(idx, str, buffer, fd);
	if (str == NULL)
		free(str);
	return (str);
}
