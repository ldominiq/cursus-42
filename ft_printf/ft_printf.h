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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr_fd(int n, int fd, int *idx);
int		ft_putchar_fd(char c, int fd, int *i);
int		ft_putstr_fd(char *s, int fd, int *idx);
int		ft_putunbr_fd(unsigned int n, int fd, int *idx);
int		ft_puthex_fd(unsigned int n, int upper, int fd, int *idx);
void	*ft_calloc(size_t count, size_t size);
int		ft_putptr_fd(unsigned long n, int fd, int *idx);
int		ft_handler(va_list args, char c, int *i);

#endif