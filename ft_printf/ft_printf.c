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

int	ft_process_str(char *str, va_list list, int idx, int count)
{
	int		d;
	//char	c;
	//char	*s;

	if (str[idx] == '%' && str[idx + 1] == 'd')
	{
		d = va_arg(list, int);
		ft_putnbr_fd(d, 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		count = ft_process_str((char *)str, list, i, count);
		i++;
	}
	va_end(list);
	return (count);
}
