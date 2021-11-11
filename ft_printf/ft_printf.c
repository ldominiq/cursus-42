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

int	ft_countput(t_print vars, char c, int *i)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar_fd(vars.d, 1, i);
	else if (c == 's')
		count = ft_putstr_fd(vars.s, 1, i);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_fd(vars.d, 1, i);
	else if (c == 'u')
		count = ft_putunbr_fd(vars.u, 1, i);
	else if (c == 'x')
		count = ft_puthex_fd(vars.u, 87, 1, i);
	else if (c == 'X')
		count = ft_puthex_fd(vars.u, 55, 1, i);
	else if (c == 'p')
		count = ft_putptr_fd(vars.p, 1, i);
	return (count);
}

int	ft_handler(va_list args, char c, int *i)
{
	int				count;
	t_print			vars;

	count = 0;
	vars = ft_init();
	if (c == 'c' || c == 'd' || c == 'i')
		vars.d = va_arg(args, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		vars.u = va_arg(args, unsigned int);
	else if (c == 'p')
		vars.p = va_arg(args, unsigned long);
	else if (c == 's')
		vars.s = va_arg(args, char *);
	count = ft_countput(vars, c, i);
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
