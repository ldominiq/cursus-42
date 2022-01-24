/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2022/01/18 16:11:47 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar_fd(char c, int fd, int *i)
{
	write(fd, &c, 1);
	if (i != NULL)
		*i += 1;
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	while (++i < count * size)
		ptr[i] = 0;
	return (ptr);
}

int	ft_printf_putstr_fd(char *s, int fd, int *idx)
{
	int	i;
	int	count;

	count = 0;
	if (s)
	{
		i = -1;
		while (s[++i])
			count += ft_printf_putchar_fd(s[i], fd, NULL);
	}
	else if (s == NULL)
		count = ft_printf_putstr_fd("(null)", fd, NULL);
	if (idx != NULL)
		*idx += 1;
	return (count);
}
