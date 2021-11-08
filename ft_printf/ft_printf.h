#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_puthex_fd(unsigned int n, int upper, int fd);
void	*ft_calloc(size_t count, size_t size);
void	ft_putptr_fd(unsigned int n, int fd);

#endif