/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2021/11/03 10:51:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setupptr(unsigned long n, char *hex, int *i)
{
	unsigned long	tmp;

	while (n)
	{
		tmp = n % 16;
		if (tmp > 9)
			hex[*i] = (char)(tmp + 87);
		else
			hex[*i] = (char)(tmp + 48);
		n = n / 16;
		*i += 1;
	}
	return (hex);
}

int	ft_putptr_fd(unsigned long n, int fd, int *idx)
{
	int		i;
	char	*hex;
	int		count;

	i = 0;
	count = 0;
	hex = malloc(sizeof(char) * 12);
	count += ft_putstr_fd("0x", fd, NULL);
	if (!n)
		count += ft_putchar_fd('0', fd, NULL);
	hex = ft_setupptr(n, hex, &i);
	while (--i >= 0)
		count += ft_putchar_fd(hex[i], fd, NULL);
	*idx += 1;
	free(hex);
	return (count);
}
