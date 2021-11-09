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
#include <stdarg.h>

int	ft_countput(char *s, int d, char c, int *i)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_fd(d, 1, i);
	//TODO: fix last 's' test
	else if (c == 's')
		count = ft_putstr_fd(s, 1, i);
	//TODO: fix 'd' and 'i'
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_fd(d, 1, i);
	else if (c == 'u')
		count = ft_putunbr_fd(d, 1, i);
	else if (c == 'x')
		count = ft_puthex_fd(d, 87, 1, i);
	else if (c == 'X')
		count = ft_puthex_fd(d, 55, 1, i);
	else if (c == 'p')
		count = ft_putptr_fd(d, 1, i);
	return (count);
}

int	ft_handler(va_list args, char c, int *i)
{
	int		d;
	int		count;
	char	*s;

	count = 0;
	if (c == 'c' || c == 'd' || c == 'i')
		d = va_arg(args, int);
	else if (c == 'u' || c == 'x' || c == 'X' || c == 'p')
		d = va_arg(args, unsigned int);
	else if (c == 's')
		s = va_arg(args, char *);
	if (c == 's')
		count = ft_countput(s, d, c, i);
	else
		count = ft_countput(s, d, c, i);
	return (count);
}

int	ft_process_str(const char *str, va_list args, int count, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '%' && str[*i + 1] == '%')
			count += ft_putchar_fd('%', 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'c')
			count += ft_handler(args, 'c', i);
		else if (str[*i] == '%' && str[*i + 1] == 's')
			count += ft_handler(args, 's', i);
		else if (str[*i] == '%' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
			count += ft_handler(args, 'd', i);
		else if (str[*i] == '%' && str[*i + 1] == 'u')
			count += ft_handler(args, 'u', i);
		else if (str[*i] == '%' && str[*i + 1] == 'x')
			count += ft_handler(args, 'x', i);
		else if (str[*i] == '%' && str[*i + 1] == 'X')
			count += ft_handler(args, 'X', i);
		else if (str[*i] == '%' && str[*i + 1] == 'p')
			count += ft_handler(args, 'p', i);
		else
			count += ft_putchar_fd(str[*i], 1, NULL);
		*i += 1;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;
	static int	i = 0;

	count = 0;
	va_start(args, str);
	count += ft_process_str(str, args, count, &i);
	va_end(args);
	return (count);
}
