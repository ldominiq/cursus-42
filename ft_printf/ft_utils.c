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

int	ft_putchar_fd(char c, int fd, int *i)
{
	write(fd, &c, 1);
	if (i != NULL)
		*i += 1;
	return (1);
}

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

int	ft_puthex_fd(unsigned int n, int upper, int fd, int *idx)
{
	unsigned int	tmp;
	int				i;
	char			*hex;
	int				count;

	i = 0;
	count = 0;
	if (n != 0)
	{
		hex = ft_calloc(sizeof(char), 9);
		while (n != 0)
		{
			tmp = n % 16;
			if (tmp > 9)
				hex[i] = (char)(tmp + upper);
			else
				hex[i] = (char)(tmp + 48);
			n = n / 16;
			i++;
		}
		hex[i] = 0;
		while (--i >= 0)
			count += ft_putchar_fd(hex[i], fd, NULL);
		free(hex);
	}
	else
		count += ft_putchar_fd('0', fd, NULL);
	*idx += 1;
	return (count);
}
