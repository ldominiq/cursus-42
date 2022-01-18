/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldominiq <ldominiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:51:52 by ldominiq          #+#    #+#             */
/*   Updated: 2022/01/18 16:11:47 by ldominiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_printf_putnbr_fd(int n, int fd, int *idx);
int		ft_printf_putchar_fd(char c, int fd, int *i);
int		ft_printf_putstr_fd(char *s, int fd, int *idx);
int		ft_putunbr_fd(unsigned int n, int fd, int *idx);
int		ft_puthex_fd(unsigned int n, int upper, int fd, int *idx);
void	*ft_calloc(size_t count, size_t size);
int		ft_putptr_fd(unsigned long n, int fd, int *idx);
int		ft_handler(va_list args, char c, int *i);
char	*ft_setuphex(unsigned int n, char *hex, int upper, int *i);
char	*ft_setupptr(unsigned long n, char *hex, int *i);

#endif