/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:30:38 by ldominiq          #+#    #+#             */
/*   Updated: 2021/10/13 14:19:06 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = haystack;
	needlelen = ft_strlen(needle);
	if (!needlelen)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i++] == needle[j++])
		{
			ptr = (char *)&haystack[i - 1];
			while (haystack[i++] == needle[j++])
			{	
				if (!needle[j])
					return (ptr);
			}
		}
		j = 0;
	}
	return (NULL);
}
