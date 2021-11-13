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

int	ft_process_str(const char *str, va_list args, int count, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '%' && str[*i + 1] == '%')
			count += ft_putchar_fd('%', 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'c')
			count += ft_putchar_fd(va_arg(args, int), 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 's')
			count += ft_putstr_fd(va_arg(args, char *), 1, i);
		else if (str[*i] == '%' && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
			count += ft_putnbr_fd(va_arg(args, int), 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'u')
			count += ft_putunbr_fd(va_arg(args, unsigned int), 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'x')
			count += ft_puthex_fd(va_arg(args, unsigned int), 87, 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'X')
			count += ft_puthex_fd(va_arg(args, unsigned int), 55, 1, i);
		else if (str[*i] == '%' && str[*i + 1] == 'p')
			count += ft_putptr_fd(va_arg(args, unsigned long), 1, i);
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
	int			i;

	i = 0;
	count = 0;
	va_start(args, str);
	count += ft_process_str(str, args, count, &i);
	va_end(args);
	return (count);
}
