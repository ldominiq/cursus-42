/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2021/11/03 10:51:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(unsigned long n, int fd, int *idx)
{
	unsigned long	tmp;
	int				i;
	char			*hex;
	int				count;

	i = 0;
	count = 0;
	hex = malloc(sizeof(char) * 12);
	while (n)
	{
		tmp = n % 16;
		if (tmp > 9)
			hex[i] = (char)(tmp + 87);
		else
			hex[i] = (char)(tmp + 48);
		n = n / 16;
		i++;
	}
	count += ft_putstr_fd("0x", fd, NULL);
	while (--i >= 0)
		count += ft_putchar_fd(hex[i], fd, NULL);
	*idx += 1;
	free(hex);
	return (count);
}

int	ft_putstr_fd(char *s, int fd, int *idx)
{
	int	i;
	int	count;

	count = 0;
	if (s)
	{
		i = -1;
		while (s[++i])
			count += ft_putchar_fd(s[i], fd, NULL);
	}
	if (idx != NULL)
		*idx += 1;
	return (count);
}
