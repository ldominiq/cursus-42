/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2021/11/03 10:51:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setuphex(unsigned int n, char *hex, int upper, int *i)
{
	unsigned int	tmp;

	while (n != 0)
	{
		tmp = n % 16;
		if (tmp > 9)
			hex[*i] = (char)(tmp + upper);
		else
			hex[*i] = (char)(tmp + 48);
		n = n / 16;
		*i += 1;
	}
	hex[*i] = 0;
	return (hex);
}

int	ft_puthex_fd(unsigned int n, int upper, int fd, int *idx)
{
	int		i;
	char	*hex;
	int		count;

	i = 0;
	count = 0;
	if (n != 0)
	{
		hex = ft_calloc(sizeof(char), 9);
		hex = ft_setuphex(n, hex, upper, &i);
		while (--i >= 0)
			count += ft_putchar_fd(hex[i], fd, NULL);
		free(hex);
	}
	else
		count += ft_putchar_fd('0', fd, NULL);
	*idx += 1;
	return (count);
}
