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

char	*check_str_content(char *str, char *src, char *tmp)
{
	if (!str)
		str = ft_strdup(src);
	else
		str = ft_strjoin(str, tmp);
	return (str);
}

char	*set_str_content(size_t index, char *str, char *src)
{
	char	*tmp;

	if (index == ft_strlen(src))
		str = check_str_content(str, src, src);
	else
	{
		tmp = ft_substr(src, 0, index + 1);
		str = check_str_content(str, tmp, tmp);
		free(tmp);
	}
	return (str);
}

char	*get_file_content(char *str, char *buffer, int fd)
{
	static int	idx = 1;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (buffer[0] != 0 && idx > 0)
	{
		if (buffer[0] == '\n')
		{
			str = set_str_content(0, str, buffer);
			ft_memcpy(buffer, buffer + 1, BUFFER_SIZE);
			return (str);
		}
		while (buffer[j])
		{
			if (buffer[j] == '\n')
			{
				str = set_str_content(j, str, buffer);
				ft_memcpy(buffer, buffer + j + 1, BUFFER_SIZE - j);
				return (str);
			}
			j++;
		}
		str = check_str_content(str, buffer, buffer);
	}
	while (idx)
	{
		idx = read(fd, buffer, BUFFER_SIZE);
		if (idx <= 0 && str)
			return (str);
		if (idx <= 0)
		{
			free(str);
			return (NULL);
		}
		buffer[idx] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				str = set_str_content(i, str, buffer);
				ft_memcpy(buffer, buffer + i + 1, BUFFER_SIZE - i);
				return (str);
			}
			i++;
		}
		i = 0;
		str = check_str_content(str, buffer, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	str = get_file_content(str, buffer, fd);
	return (str);
}
