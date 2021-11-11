/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2021/11/03 10:51:55 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd, int *idx)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count = ft_putstr_fd("-2147483648", fd, NULL);
	else if (n < 0)
	{
		count += ft_putchar_fd('-', fd, NULL);
		count += ft_putnbr_fd(-n, fd, NULL);
	}
	else if (n >= 10)
	{
		count += ft_putnbr_fd(n / 10, fd, NULL);
		count += ft_putchar_fd(n % 10 + '0', fd, NULL);
	}
	else
		count += ft_putchar_fd(n + '0', fd, NULL);
	if (idx != NULL)
		*idx += 1;
	return (count);
}

int	ft_putunbr_fd(unsigned int n, int fd, int *idx)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr_fd(n / 10, fd, NULL);
		count += ft_putchar_fd(n % 10 + '0', fd, NULL);
	}
	else
		count += ft_putchar_fd(n + '0', fd, NULL);
	if (idx != NULL)
		*idx += 1;
	return (count);
}
