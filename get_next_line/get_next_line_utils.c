/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:20:21 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/21 14:51:33 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	if (start + len > ft_strlen(s))
		ptr = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		ptr = malloc(len + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] && j < len && start < ft_strlen(s))
		ptr[j++] = s[i++];
	ptr[j] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	s1len;

	if (s1 == NULL)
		return (NULL);
	s1len = ft_strlen(s1) + 1;
	ptr = malloc(s1len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1len);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*strsrc;
	char	*strdst;
	size_t	i;

	strsrc = (char *)src;
	strdst = dst;
	i = -1;
	if (dst != NULL || src != NULL)
	{
		while (++i < n)
			strdst[i] = strsrc[i];
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}
