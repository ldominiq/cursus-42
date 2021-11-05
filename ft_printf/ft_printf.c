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

int	ft_process_str(const char *str, va_list args)
{
	int	d;
	int	count;
	int	i;
	//char	c;
	//char	*s;
	count = 0;
	i = 0; 
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			d = va_arg(args, int);
			ft_putchar_fd(d, 1);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			d = va_arg(args, int);
			ft_putstr_fd((char *)d, 1);
			i++;
		}
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			d = va_arg(args, int);
			ft_putnbr_fd(d, 1);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	count += ft_process_str(str, args);
	va_end(args);
	return (count);
}
